#!/bin/bash

echo "Enter your number"
read num
if [ $num -lt 2 ]; then
    echo "not prime"
    exit
fi
is_prime=1
for (( i=2; i<=num/2; i++ )); do
    if [ $((num % i)) -eq 0 ]; then
        is_prime=0
        break
    fi
done
if [ $is_prime -eq 0 ]; then
    echo "Its not a prime"
else
    echo "Its a prime"  
fi
