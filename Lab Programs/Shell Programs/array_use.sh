array=($@)

echo "Enter the elements of the array, one per line:"

while read -r line; do
    if [ "$line" == "exit" ]; then
        break  # Exit the while loop if "exit" is entered
    fi

    array+=($line)
done

echo "The array is:"
echo "${array[@]}"