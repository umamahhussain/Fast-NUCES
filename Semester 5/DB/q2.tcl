set simulation_instance [new Simulator]

set nam_file [open out.nam w]
$simulation_instance namtrace-all $nam_file

proc finish {} {
    global simulation_instance nam_file
    $simulation_instance flush-trace
    close $nam_file
    exec nam out.nam &
    exit 0
}

set node_0 [$simulation_instance node]
set node_1 [$simulation_instance node]
set node_2 [$simulation_instance node]
set node_3 [$simulation_instance node]

$simulation_instance duplex-link $node_0 $node_2 2Mb 10ms DropTail
$simulation_instance duplex-link-op $node_0 $node_2 orient right-down

$simulation_instance duplex-link $node_1 $node_2 2Mb 10ms DropTail
$simulation_instance duplex-link-op $node_1 $node_2 orient right-up

$simulation_instance duplex-link $node_2 $node_3 1.7Mb 20ms DropTail
$simulation_instance duplex-link-op $node_2 $node_3 orient right

$simulation_instance queue-limit $node_0 $node_2 10
$simulation_instance queue-limit $node_1 $node_2 10
$simulation_instance queue-limit $node_2 $node_3 10

set tcp_agent [new Agent/TCP]
$tcp_agent set fid_ 0
$simulation_instance attach-agent $node_1 $tcp_agent

set tcp_sink [new Agent/TCPSink]
$simulation_instance attach-agent $node_3 $tcp_sink
$simulation_instance connect $tcp_agent $tcp_sink

set udp_agent [new Agent/UDP]
$udp_agent set fid_ 1
$simulation_instance attach-agent $node_0 $udp_agent

set null_agent [new Agent/Null]
$simulation_instance attach-agent $node_3 $null_agent
$simulation_instance connect $udp_agent $null_agent

set ftp_application [new Application/FTP]
$ftp_application attach-agent $tcp_agent

set cbr_application [new Application/Traffic/CBR]
$cbr_application set packetSize_ 1000
$cbr_application set interval 0.010
$cbr_application attach-agent $udp_agent

$simulation_instance at 0.5 "$ftp_application start"
$simulation_instance at 4.0 "$ftp_application stop"

$simulation_instance at 0.1 "$cbr_application start"
$simulation_instance at 4.5 "$cbr_application stop"

$simulation_instance at 5.0 "finish"

$simulation_instance run
