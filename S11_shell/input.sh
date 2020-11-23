#! /bin/bash

# print hello world
echo "hello world!"

# variables 
name="Ahmed"
echo "My name is $name"

# print the current working directory from env var
echo "$PWD"
# print the current working using command pwd
echo $(pwd)

# Get user name 
read -p "username: " name
echo "Your username: $name"
# silent variable 
read -sp "Password: " password
printf "\nSuccessful!\n"
