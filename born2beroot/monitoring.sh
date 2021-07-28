#!/bin/bash

arch=$(uname -a)
cpu_p=$(nproc --all)
last_boot=$(who -b | grep -oP '\d.+')
ip=$(hostname -I)
mac=$(ip -a link | awk '{print $2}' | tail -n -1)
sudo=$(sudo grep sudo /var/log/auth.log | wc -l)
wall "  #Architecture: $arch
#CPU physical:
#Memory Usage:
#Disk Usage:
#CPU load:
#Last boot: $last_boot
#LVM use:
#Connections TCP:
#User log:
#Network: IP $ip ($mac)
#Sudo: $sudo cmd
"




