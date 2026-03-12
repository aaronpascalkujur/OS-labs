#!/bin/bash
echo "Enter first sorted array elements:"
read -r -a arr1
echo "Enter second sorted array elements:"
read -r -a arr2
merged=("${arr1[@]}" "${arr2[@]}")
mapfile -t sorted_merged < <(printf "%s\n" "${merged[@]}" | sort -n)
echo "Merged Sorted Array: ${sorted_merged[*]}"