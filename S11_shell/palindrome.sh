#! /bin/bash

function isPalandrome() {
    number=$1
    reverse=0

    while [ $number -gt 0 ]; do
        rem=$(( number % 10 ))
        number=$(( number / 10 ))
        reverse=$(( reverse * 10 + rem ))
    done


    if [ $reverse -eq $1 ]
    then
        echo "True"
    else 
        echo "False"
    fi

    exit
}

read -p "Enter a number: " num
isPalandrome $num
