#! /bin/bash

num1=20
num2=0
num3=12

echo "Sum = $(( num1 + num3 ))"


# make division
if [[ $num2 < 1 ]]; then 
    echo "Can't do division"
fi

echo "Mult = $(( num2 * num3 ))"
