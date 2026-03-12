#!/bin/bash

check_perms() {
echo "Files/Dirs with Read & Write permissions:"
for file in *
do
if [ -r "$file" ] && [ -w "$file" ]
then
echo "$file"
fi
done
}

check_perms
