#!/bin/bash
echo "Choose an option"
echo "1. List files"
echo "2. List users"
echo "3. Create a file"
echo "4. Delete a file"
read choice

case $choice in 
    1)
        echo "Files in directory:"
        ls
        ;;
    2)
        echo "Current users:"
        who
        ;;
    3)
        echo "Enter filename:"
        read filename
        touch "$filename"
        echo "File '$filename' created"
        ;;
    4)
        echo "Enter filename:"
        read filename
        if [ -e "$filename" ]; then
            rm "$filename"
            echo "File '$filename' deleted"
        else 
            echo "File not found"
        fi
        ;;
    *)
        echo "Invalid option"
        ;;
esac

