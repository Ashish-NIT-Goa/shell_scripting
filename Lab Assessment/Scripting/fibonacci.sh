#!/usr/bin/bash

a=0
b=1

read -p "Enter a number: " n

echo -n $a $b

i=2

while [ $i -lt $n ]
do
	c=`expr $a + $b`
	echo -n " $c"
	a=$b
	b=$c
	((i+=1))
done
