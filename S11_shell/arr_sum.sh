#! /bin/bash

os=(60 20 30 40 50)

x=0

for i in "${os[@]}"; do
    x=$((x + i))
    printf "Current sum = ${x}\n"
done
