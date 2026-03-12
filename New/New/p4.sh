#!/bin/bash

echo "Enter array elements:"
read -a arr
sorted_unique=($(for i in "${arr[@]}"; do echo "$i"; done | sort -nu))
len=${#sorted_unique[@]}
if [ $len -lt 2 ]
then
    echo "Array must have at least 2 unique elements."
else
    echo "Second Smallest: ${sorted_unique[1]}"
    echo "Second Largest: ${sorted_unique[$((len-2))]}"
fi
