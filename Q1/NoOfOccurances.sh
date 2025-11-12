#!/bin/bash

read -p "Enter filename: " filename

if [ ! -f "$filename" ]; then
    echo "File does not exist"
    exit 1
fi

read -p "Enter word to search: " word

# Count exact word occurrences (case sensitive)
count=$(grep -wo "$word" "$filename" | wc -l)

echo "The word occurs $count times in '$filename'"

