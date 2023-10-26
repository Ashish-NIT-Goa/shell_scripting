echo "Enter number"
read n
r=$((n%2))
if [ $r -eq 0 ] 
then
    echo "Even"
else
    echo "Odd"

fi
