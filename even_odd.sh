echo "Check if a number is even or odd"

read -p "Enter a number: " x

echo "you entered $x"

r=`expr $x % 2`

if [ $r -eq 0 ]
then echo "$x is even"
else echo "$x is odd"
fi

echo "done"
