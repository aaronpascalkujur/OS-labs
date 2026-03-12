#!/bin/bash

is_prime() {
n=$1
if [ $n -le 1 ]
then
return 1
fi
for ((i=2; i*i<=n; i++))
do
if [ $((n % i)) -eq 0 ]
then
return 1
fi
done
return 0
}

print_primes() {
start=$1
end=$2
echo "Primes between $start and $end:"
for ((num=start; num<=end; num++))
do
if is_prime $num
then
echo -n "$num "
fi
done
echo ""
}

count_primes() {
start=$1
end=$2
count=0
for ((num=start; num<=end; num++))
do
if is_prime $num
then
count=$((count + 1))
fi
done
echo "Total primes: $count"
}

echo "Enter range (start and end):"
read start end
print_primes $start $end
count_primes $start $end
