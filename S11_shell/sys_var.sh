#! /bin/bash

# the shell used by the user
curr_shell=$SHELL
printf "Shell: ${curr_shell}\n"

# the user name
user=$(whoami)
printf "Username: ${user}\n"

# user id
echo "UserId: $UID"
# OR
id=$(id)
echo ${id} | cut -c1-8

# home directory
echo "Home: $HOME"

# calender
calender=`cal`
echo -e "---- My Calender ---- \n ${calender}\n"

