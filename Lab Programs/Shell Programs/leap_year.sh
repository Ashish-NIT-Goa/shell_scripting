echo "enter year:"
read n
if [ $((n % 4)) -eq 0 ]; then
    if [ $((n % 100)) -eq 0 ]; then
        if [ $((n % 400)) -eq 0 ]; then
            echo "Leap Year"
        else
            echo "Not"
        fi
    else
        echo "Leap Year"
    fi
else
    echo "Not Leap Year"
fi
