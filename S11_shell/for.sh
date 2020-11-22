#!/bin/sh

counter=0

for i in 3 4 5 6 7
do
  counter=$(( counter + i ))
done

printf "Total= ${counter}\n"