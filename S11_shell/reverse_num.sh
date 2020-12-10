#! /bin/bash

function reverse() {
    num=$1
    rev=0

    while [[ num -gt 0 ]]; do
        rem=$(( num%10 ))
        num=$(( num/10 ))
        rev=$(( rev*10 + rem ))
    done

    printf "Reverse: ${rev}\n"
}

read -p "Num: " num
reverse $num 