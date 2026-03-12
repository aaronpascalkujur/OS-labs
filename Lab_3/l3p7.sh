#!/bin/bash

echo "Enter range start and end:"
read start end
echo "Primes between $start and $end:"

for ((n=start; n<=end; n++))
do
    if [ $n -le 1 ]
    then
        continue
    fi
    
    flag=1
    for ((i=2; i*i<=n; i++))
    do
        if [ $((n % i)) -eq 0 ]
        then
            flag=0
            break
        fi
    done
    
    case $flag in
        1) echo "$n" ;;
    esac
done