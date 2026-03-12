#!/bin/bash

echo "Enter file or directory name:"
read name

if [ -f "$name" ]
then
    echo "It is a file."
    size=$(du -k "$name" | cut -f1)
    echo "Size: $size KB"
    
    if [ -r "$name" ]
    then
        echo "File is Readable"
    fi
    
    if [ -w "$name" ]
    then
        echo "File is Writable"
    fi
    
    if [ -x "$name" ]
    then
        echo "File is Executable"
    fi

elif [ -d "$name" ]
then
    echo "It is a directory."
    echo "Contents:"
    ls "$name"
    
    files=$(find "$name" -maxdepth 1 -type f | wc -l)
    dirs=$(find "$name" -maxdepth 1 -type d | wc -l)
    
    dirs=$((dirs - 1))
    
    echo "Number of files: $files"
    echo "Number of subdirectories: $dirs"

else
    echo "Invalid name or file does not exist."
fi