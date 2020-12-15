#! /bin/bash

GREEN='\e[92m'
NC='\033[0m' # No Color


function testFile() {
    printf "${GREEN}FILE RUNNING -> %s${NC}\n" $1
    gcc $1 -lpthread
    ./a.out 2
    ./a.out 4
    ./a.out 8
}

fileName='processes.c'
testFile $fileName
