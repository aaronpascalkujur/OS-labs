#!/bin/bash

echo "Enter array elements:"
read -a arr
echo "Frequency of elements:"
for i in "${arr[@]}"
do
    echo "$i"
done | sort | uniq -c
