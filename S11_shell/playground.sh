#! /bin/bash

# try io
read -p "Name: " name

# if statment
if [ $name == "ahmed" ]; then
    printf "Welcome ${name}!\n"
    while [ $name == "ahmed" ]; do
        read -p "Well, I hate that name. New_Name: " name
    done
    echo "All is good now, $name!"
else
    printf "Go away!\n"
fi


num=10

for i in 2 3 4 
do 
    (( num++ ))
done

echo "Num= $num"
