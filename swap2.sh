#!/usr/bin/bash

echo "befor swap: a = $1 b = $2"

temp=$1
$1=$2
$2=$temp

echo "After swap: a = $1 b = $2"
