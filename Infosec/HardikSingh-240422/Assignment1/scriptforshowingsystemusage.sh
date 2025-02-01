#!/bin/sh

touch systemusage.txt

echo "SYSTEM STATS:\n\n" >systemusage.txt

echo "CPU USAGE:" >> systemusage.txt
grep 'cpu' /proc/stat >> systemusage.txt
echo "\n\n" >> systemusage.txt

echo "RAM USAGE:\n" >> systemusage.txt
free -h >> systemusage.txt
echo "\n\n" >> systemusage.txt


echo "DISK SPACE USAGE:\n" >> systemusage.txt
df -h >> systemusage.txt
echo "\n\n" >> systemusage.txt

echo "CURRENT DIRECTORY SIZE USAGE:\n" >>systemusage.txt
du -sh * >> systemusage.txt
