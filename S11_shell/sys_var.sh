#! /bin/bash

curr_shell=$SHELL
printf "shell: ${curr_shell}\n"

user=$(whoami)
printf "username: ${user}\n"

user_id=$(id)
# split the id from the string 
printf "${user_id}"
