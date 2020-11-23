#! /bin/bash

os=(60 20 30 40 50)

sum=0

for i in "${os[@]}"; do
    sum=$(( i + sum ))
    printf "Current sum = ${sum}\n"
done
