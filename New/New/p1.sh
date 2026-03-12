#!/bin/bash

echo "Enter first sorted array elements:"
read -a arr1
echo "Enter second sorted array elements:"
read -a arr2
merged=("${arr1[@]}" "${arr2[@]}")
sorted_merged=($(echo "${merged[@]}" | tr ' ' '\n' | sort -n))
echo "Merged Sorted Array: ${sorted_merged[@]}"
