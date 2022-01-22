#!/bin/bash
make re
echo "Test how many times each philosopher eats"

n_philos=$1
t_death=$2
t_eat=$3
t_sleep=$4
n_eats=$5

if [ $# -le 4 ]
  then
    echo "\nInsufficient arguments, running default case...\n"
    n_philos=5
    t_death=800
    t_eat=200
    t_sleep=200
    n_eats=7
fi

echo "\n--------------------------------
 Running $n_philos $t_death $t_eat $t_sleep $n_eats \n
--------------------------------\n"

echo "Writing output to file...\n"
./philo $n_philos $t_death $t_eat $t_sleep $n_eats > output

x=1
while [ $x -le $n_philos ]
do
  echo "N. $x eats:"
  cat output | grep "$x is eating" |  wc -l
  x=$(( $x + 1 ))
done

echo "\nDeleting output file...\n"
rm -rf output