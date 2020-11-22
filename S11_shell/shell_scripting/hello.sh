#! /bin/bash

# print hello world
echo "hello world!"

# variables 
name="Ahmed"
echo "My name is $name"

# PWD 
echo "Working dir: $PWD"

# Get user name 
read -p "username: " name
echo "Your username: $name"
# silent variable 
read -sp "Password: " password
echo "Successful!"
