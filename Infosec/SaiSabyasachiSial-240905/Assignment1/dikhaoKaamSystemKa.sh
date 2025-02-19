#!/bin/sh

# Create or overwrite the log file
touch systemusage.txt
echo "SYSTEM STATS REPORT - $(date)\n" > systemusage.txt

echo "------------------------------" >> systemusage.txt
echo "CPU USAGE:" >> systemusage.txt
grep 'cpu' /proc/stat >> systemusage.txt
echo "\n" >> systemusage.txt

echo "------------------------------" >> systemusage.txt
echo "MEMORY USAGE:" >> systemusage.txt
free -h >> systemusage.txt
echo "\n" >> systemusage.txt

echo "------------------------------" >> systemusage.txt
echo "DISK SPACE USAGE:" >> systemusage.txt
df -h >> systemusage.txt
echo "\n" >> systemusage.txt

echo "------------------------------" >> systemusage.txt
echo "CURRENT DIRECTORY SIZE USAGE:" >> systemusage.txt
du -sh * >> systemusage.txt
echo "\n" >> systemusage.txt

echo "------------------------------" >> systemusage.txt
echo "TOP 10 PROCESSES BY MEMORY USAGE:" >> systemusage.txt
ps aux --sort=-%mem | head -11 >> systemusage.txt
echo "\n" >> systemusage.txt

echo "------------------------------" >> systemusage.txt
echo "NETWORK INTERFACE STATUS:" >> systemusage.txt
ip -s link >> systemusage.txt
echo "\n" >> systemusage.txt

echo "------------------------------" >> systemusage.txt
echo "ACTIVE NETWORK CONNECTIONS:" >> systemusage.txt
netstat -tunapl >> systemusage.txt
echo "\n" >> systemusage.txt

echo "System stats logged successfully to dekhoSystemKaKaam.txt"