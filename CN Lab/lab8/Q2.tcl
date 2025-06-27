#This program will create two nodes and pass traffice from one node to other node using TCP protocol

#Creating simulator object 
set ns [new Simulator]   

#Creating the nam file
set nf [open out.nam w]      
#It opens the file 'out.nam' for writing and gives it the file handle 'nf'. 
$ns namtrace-all $nf

# Open the trace file
#  set nf [open out.tr w]
#  $ns trace-all $nf

#    we are opening a newtrace file named as "out" and also telling that data must be stored in .tr [trace] format.
#   "nf" is the file handler that we are used here to handle the trace file.
#   "w" means write i.e the file out.tr is opened for writing.
#   "r" means reading 
#   The second line tells the simulator to trace each packet on every link in the topology and for that we give file handler nf for the simulator ns.

#Finish Procedure  (closes the trace file and starts nam)
proc finish {} {
        global ns nf
        $ns flush-trace
        close $nf
        exec nam out.nam &
        exit 0
        }
			
#The trace data is flushed into the file by using command $ns flush-trace and then file is closed.
        
#Creating 4 nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

#Creating a duplex link between nodes 
#(connect the nodes n0 and n1 with a duplex link with the bandwidth 1Megabit, 
#a delay of 10ms and a SFQ queue)
$ns duplex-link $n0 $n2 2Mb 10ms DropTail -maxq 10
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link $n1 $n2 2Mb 10ms DropTail -maxq 10     
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link $n2 $n3 1.7Mb 20ms DropTail -maxq 10 
$ns duplex-link-op $n1 $n2 orient right  

#Creating a TCP agent and connecting it to n1 (Basically it defines source node of TCP)
set tcp0 [new Agent/TCP]
$tcp0 set fid_ 0
$ns attach-agent $n1 $tcp0        

#Creating a Sink Agent and attaching it to n3
set sink0 [new Agent/TCPSink]
$ns attach-agent $n3 $sink0

#Connecting TCP agent with Sink agent
$ns connect $tcp0 $sink0

#Creating FTP agent for traffic and attching it to tcp0
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0

#Specifying the UDP agent
set udp0 [new Agent/UDP]
$udp0 set fid_ 1

#Attaching the UDP agent with n0
$ns attach-agent $n0 $udp0

#Specifying the Null agent
set null0 [new Agent/Null]

#Attaching the NULL agent with n1
$ns attach-agent $n3 $null0
$ns connect $udp0 $null0

#Specifying the CBR agent to generate the traffic over udp0 agent
set cbr0 [new Application/Traffic/CBR]

#Each packet having 100 bytes
$cbr0 set packetSize_ 100


#Attaching cbr0 with udp0
$cbr0 attach-agent $udp0

#Starting the FTP Traffic
$ns at 0.1 "$cbr0 start"
$ns at 0.5 "$ftp0 start"
$ns at 4.0 "$ftp0 stop"
$ns at 4.5 "$cbr0 stop"

#Calling the finish procedure
$ns at 5.0 "finish"

#Run the simulation
$ns run
