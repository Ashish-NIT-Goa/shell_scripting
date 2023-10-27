#!/usr/bin/bash

read -p "Enter year: " year

echo "You entered " $year

a=`expr $year % 4`
b=`expr $year % 400`
c=`expr $year % 100`

if [ $a -eq 0 -a $b -ne 0 -o $c -eq 0 ]
then echo "Leap year"
else echo "Not a leap year"
fi
