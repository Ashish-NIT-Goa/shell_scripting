#!/usr/bin/bash

read -p "Enter a number: " n

m=$n

x=1

while [ $n -ne 1 ]
do
	x=`expr $x \* $n`
	((n-=1))
done

echo "$m! =  $x"


