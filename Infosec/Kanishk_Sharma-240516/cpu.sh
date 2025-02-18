#!/bin/bash
get_cpu_usage() {
    echo "CPU Usage:"
    top -bn1 | grep "Cpu(s)" | \
    sed "s/.*, *\([0-9.]*\)%* id.*/\1/" | \
    awk '{print 100 - $1"% used"}'
}
get_ram_usage() {
    echo "RAM Usage:"
    free -h | awk '/Mem:/ {print $3 " used / " $2 " total (" $3/$2*100 "%)"}'
}
display_usage() {
    echo "-------------------------"
    echo " System Usage Overview"
    echo "-------------------------"
    get_cpu_usage
    get_ram_usage
    echo "-------------------------"
}
display_usage

