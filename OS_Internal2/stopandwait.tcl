
# Create simulator object
set ns [new Simulator]

# Open trace and NAM files
set tracefile [open stopwait.tr w]
$ns trace-all $tracefile

set namfile [open stopwait.nam w]
$ns namtrace-all $namfile

# Define finish procedure
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam stopwait.nam &
    exit 0
}

# Create two nodes
set n0 [$ns node]
set n1 [$ns node]

# Create duplex link
$ns duplex-link $n0 $n1 1Mb 10ms DropTail

# Configure TCP agent at sender
set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp

# Configure TCP sink at receiver
set sink [new Agent/TCPSink]
$ns attach-agent $n1 $sink

# Connect TCP and sink
$ns connect $tcp $sink

# Configure FTP application
set ftp [new Application/FTP]
$ftp attach-agent $tcp

# Schedule data transmission
$ns at 0.5 "$ftp start"
$ns at 4.0 "$ftp stop"

# End simulation
$ns at 5.0 "finish"

# Run simulation
$ns run
