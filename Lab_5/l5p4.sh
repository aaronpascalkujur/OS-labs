#!/bin/bash
echo "Enter array elements:"
read -r -a arr
mapfile -t sorted_unique < <(printf "%s\n" "${arr[@]}" | sort -nu)
len=${#sorted_unique[@]}
if [ "$len" -lt 2 ]
then
echo "Array must have at least 2 unique elements."
else
echo "Second Smallest: ${sorted_unique[1]}"
echo "Second Largest: ${sorted_unique[$((len-2))]}"
fi