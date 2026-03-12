#!/bin/bash

echo "Enter number of elements:"
read n
echo "Enter numbers:"

for ((i=0; i<n; i++))
do
    read arr[$i]
done

echo "1. Ascending"
echo "2. Descending"
read order

for ((i=0; i<n; i++))
do
    for ((j=0; j<n-i-1; j++))
    do
        if [ $order -eq 1 ]
        then
            if [ ${arr[j]} -gt ${arr[$((j+1))]} ]
            then
                temp=${arr[j]}
                arr[j]=${arr[$((j+1))]}
                arr[$((j+1))]=$temp
            fi
        else
            if [ ${arr[j]} -lt ${arr[$((j+1))]} ]
            then
                temp=${arr[j]}
                arr[j]=${arr[$((j+1))]}
                arr[$((j+1))]=$temp
            fi
        fi
    done
done

echo "Sorted: ${arr[*]}"