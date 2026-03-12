#!/bin/bash

echo "Enter directory path:"
read dir

if [ ! -d "$dir" ]
then
    echo "Directory not found."
    exit
fi

cd "$dir" || exit
txt=0
sh=0
jpg=0
other=0

for file in *
do
    if [ -f "$file" ]
    then
        ext="${file##*.}"
        case "$ext" in
            txt) txt=$((txt + 1)) ;;
            sh) sh=$((sh + 1)) ;;
            jpg) jpg=$((jpg + 1)) ;;
            *) other=$((other + 1)) ;;
        esac
    fi
done

echo "Text files: $txt"
echo "Shell scripts: $sh"
echo "JPG images: $jpg"
echo "Others: $other"