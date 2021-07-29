#!/bin/bash

arch=$(uname -a)
cpu_p=$(lscpu | grep Socket | awk '{print $2}')
cpu_v=$(cat /proc/cpuinfo | grep processor | wc -l)
mem_us=$(free -m | awk NR==2 | awk '{print $3}')
mem_tot=$(free -m | awk NR==2 | awk '{print $2}')
mem_usage=$(free -t | tail -n 1 | awk '{printf "%.1f", $3*100/$2}')
disk_used=$(df -m | awk '{if (NR>1) print $3}' | awk '{n += $1}; END{print n}')
disk_tot=$(df -m | awk '{if (NR>1) print $4}' | awk '{n += $1}; END{printf "%.1f", n/1000}')
disk_tot_m=$(df -m | awk '{if (NR>1) print $4}' | awk '{n += $1}; END{print n}')
let "disk_usage = disk_used * 100 / disk_tot_m"
cpu_load=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf "%.1f", $1 + $3}')
last_boot=$(who -b | grep -oP '\d.+')
ip=$(hostname -I)
mac=$(ip -a link | awk '{print $2}' | tail -n -1)
lvm=$(sudo pvdisplay | grep Allocatable | awk '{print $2}')
tcp=$(netstat -an | grep ESTABLISHED | wc -l)
sudo=$(sudo journalctl _COMM=sudo | grep COMMAND | wc -l)
users=$(who | wc -l)
wall "  #Architecture: $arch
        #CPU physical: $cpu_p
        #vCPU: $cpu_v
        #Memory Usage: $mem_us/$mem_tot MB ($mem_usage%)
        #Disk Usage: $disk_used/$disk_tot Gb ($disk_usage%)
        #CPU load: $cpu_load%
        #Last boot: $last_boot
        #LVM use: $lvm
        #Connections TCP: $tcp ESTABLISHED
        #User log: $users
        #Network: IP $ip ($mac)
        #Sudo: $sudo cmd
        "
