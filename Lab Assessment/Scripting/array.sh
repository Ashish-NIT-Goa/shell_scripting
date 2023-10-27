#!/bin/bash

# Initialize an empty array
array=()

# Prompt the user to enter values and store them in the array
echo "Enter values (type 'done' to finish):"

while true; do
	read -p "Enter a value: " inputValue
	if [ "$inputValue" = "done" ]; then
		break
	fi
	array+=("$inputValue")
done

# Display the array elements
echo "Array elements:"

for i in "${array[@]}"; do
	echo "$i"
done
