set num [gets stdin]

if {$num % 2 == 0} {
    puts "Even Number\n"
    for {set x 4} {$x <= $num} {incr x} {
        puts $x
        incr x
    }
} else {
    puts "Odd Number\n"
    for {set x 3} {$x <= $num} {incr x} {
        puts $x
        incr x
    }
}
