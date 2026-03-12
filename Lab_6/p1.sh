#!/bin/bash

is_prime() {
    if [ $1 -lt 2 ]; then return 1; fi
    for ((j=2; j<=$1/2; j++)); do
        if [ $(($1%j)) -eq 0 ]; then return 1; fi
    done
    return 0
}

print_primes() {
    echo -n "Primes in range: "
    for ((i=$1; i<=$2; i++)); do
        if is_prime $i; then echo -n "$i "; fi
    done
    echo ""
}

count_primes() {
    count=0
    for ((i=$1; i<=$2; i++)); do
        if is_prime $i; then count=$((count+1)); fi
    done
    echo "Total primes: $count"
}

is_prime $1 && echo "$1 is Prime" || echo "$1 is Not Prime"
print_primes $1 $2
count_primes $1 $2