#! /bin/bash 

counter=10

while [[ $counter > 1 ]]
do 
    printf "val: ${counter}\n"
    counter=$(( counter - 1 ))
done