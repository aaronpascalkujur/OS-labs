#!/bin/bash

echo "Enter array elements: "
read -a arr
len=${#arr[@]}
echo "Reversed Ararry"
for (( i=$len-1; i>=0; i-- )); do
    echo -n "${arr[$i]} "
done
echo ""