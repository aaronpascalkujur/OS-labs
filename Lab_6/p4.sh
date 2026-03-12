#!/bin/bash

if [ ! -f "$1" ]; then 
    echo "File not found!"
    exit 1
fi

count_lines() { wc -l < "$1"; }
count_words() { wc -w < "$1"; }
count_chars() { wc -m < "$1"; }
most_frequent() { tr -cs A-Za-z '\n' < "$1" | tr A-Z a-z | sort | uniq -c | sort -nr | head -1; }
search_pattern() { grep -c "$2" "$1"; }

echo "Lines: $(count_lines)"
echo "Words: $(count_words)"
echo "Characters: $(count_chars)"
echo "Most frequent word: $(most_frequent)"
echo "Pattern '$2' found $(search_pattern) times."