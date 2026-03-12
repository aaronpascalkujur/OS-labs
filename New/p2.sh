#!/bin/bash

non_recursive() {
num=$1
a=0
b=1
echo "Non-Recursive Series:"
for ((i=0; i<num; i++))
do
echo "$a"
fn=$((a + b))
a=$b
b=$fn
done
}

recursive() {
a=$1
b=$2
n=$n
if [ $n -gt 0 ]
then
echo "$a"
recursive_fib $b $((a + b)) $((n - 1))
fi
}

echo "Enter number of terms:"
read -r n
echo "1. Non-Recursive"
echo "2. Recursive"
read -r choice

if [ $choice -eq 1 ]
then
non_recursive $n
elif [ $choice -eq 2 ]
then
echo "Recursive Series:"
recursive 0 1 $n
else
echo "Invalid choice"
fi  
