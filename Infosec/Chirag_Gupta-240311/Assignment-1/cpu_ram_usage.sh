#!/bin/bash

echo "CPU Usage:"
top -bn1 | grep "Cpu(s)" | awk '{print "Usage: " $2 + $4 "%"}'

echo -e "\nRAM Usage:"
free -h | awk '/Mem/ {print "Used: "$3" / Total: "$2}'
