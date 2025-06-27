#This program will create two nodes and pass traffice from one node to other node using TCP protocol

#Creating simulator object 
set ns [new Simulator]   

$ns color 0 blue
$ns color 1 red

#Creating the nam file
set nf [open out.nam w]      
#It opens the file 'out.nam' for writing and gives it the file handle 'nf'. 
$ns namtrace-all $nf
$ns rtproto DV
proc finish {} {
        global ns nf
       		 $ns flush-trace
        close $nf
        exec nam out.nam &
        exit 0
        }
# Open the trace file
#  set nf [open out.tr w]
#  $ns trace-all $nf

#    we are opening a newtrace file named as "out" and also telling that data must be stored in .tr [trace] format.
#   "nf" is the file handler that we are used here to handle the trace file.
#   "w" means write i.e the file out.tr is opened for writing.
#   "r" means reading 
#   The second line tells the simulator to trace each packet on every link in the topology and for that we give file handler nf for the simulator ns.



#The trace data is flushed into the file by using command $ns flush-trace and then file is closed.
        
#Creating Two nodes

for {set i 0} {$i < 7} {incr i} {
set n($i) [$ns node]
}

for {set i 1} {$i <= 6} {incr i} {
$ns duplex-link $n(0) $n($i) 512Kb 10ms SFQ 
}

#$ns duplex-link $n0 $n1 512Kb 10ms SFQ

#$ns duplex-link $n0 $n2 512Kb 10ms SFQ
#$ns duplex-link $n0 $n3 512Kb 10ms SFQ

#$ns duplex-link $n0 $n4 512Kb 10ms SFQ
#$ns duplex-link $n0 $n5 512Kb 10ms SFQ

#$ns duplex-link $n0 $n6 512Kb 10ms SFQ


$ns duplex-link-op $n(0) $n(1) orient right-up
$ns duplex-link-op $n(0) $n(2) orient right 
$ns duplex-link-op $n(0) $n(3) orient right-down
$ns duplex-link-op $n(0) $n(4) orient left-down
$ns duplex-link-op $n(0) $n(5) orient left  
$ns duplex-link-op $n(0) $n(6) orient left-up  


set tcp0 [new Agent/TCP]
$ns attach-agent $n(1) $tcp0        

#Creating a Sink Agent and attaching it to n1
set sink0 [new Agent/TCPSink]
$ns attach-agent $n(4) $sink0

#Connecting TCP agent with Sink agent
$ns connect $tcp0 $sink0

$tcp0 set fid_ 1



set udp0 [new Agent/UDP]


#Attaching the UDP agent with n0
$ns attach-agent $n(2) $udp0

#Specifying the Null agent
set null0 [new Agent/Null]

#Attaching the NULL agent with n1
$ns attach-agent $n(5) $null0

#Connecting both udp0 and null0 agents for transferring data between n0 and n1
$ns connect $udp0 $null0

$udp0 set fid_ 0

#Creating FTP agent for traffic and attching it to tcp0
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0


set cbr0 [new Application/Traffic/CBR]

$cbr0 set packetSize_ 1024
$cbr0 set interval 0.01
$cbr0 attach-agent $udp0


$ns at 0.1 "$ftp0 start"
$ns rtmodel-at 0.7 down $n(0) $n(4)
$ns rtmodel-at 1.2 up $n(0) $n(4)
$ns at 1.5 "$ftp0 stop"

$ns at 0.2 "$cbr0 start"
$ns rtmodel-at 0.5 down $n(0) $n(5)
$ns rtmodel-at 0.9 up $n(0) $n(5)
$ns at 1.3 "$cbr0 stop"


#Calling the finish procedure
$ns at 2.0 "finish"

#Run the simulation
$ns run
