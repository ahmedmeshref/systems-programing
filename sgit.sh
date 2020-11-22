#! /bin/bash

# show current working dir
echo $PWD

# add files to git 
git add .

# define colors needed
RED='\033[0;31m'
NC='\033[0m' # No Color

# check if message was not giving 
if [ $# -eq 0 ]; then
    printf "${RED}Missing msg - zero args was giving${NC}\n"
    exit 
else 
    # commit the message
    git commit -am "$1"
fi

# get the user branch 
read -p "your branch [q to exit]: " branch

if [ "$branch" == "q" ] || [ "$branch" == "Q" ]; then 
    printf "${RED}Quit without push${NC}\n"
    exit 
else
    git push -u origin $branch
fi



