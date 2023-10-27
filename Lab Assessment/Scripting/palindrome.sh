#!/usr/bin/bash

read -p "Enter a string: " s

if [[ $(rev <<< "$s") == "$s" ]]
then echo "Palindrom"
else echo "Not Palindrom"
fi
