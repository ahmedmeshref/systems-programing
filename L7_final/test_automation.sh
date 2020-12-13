#! /bin/bash

function testFile() {
    printf 'FILE RUNNING -> %s\n' $1
    gcc $1 -lpthread
    ./a.out 2
    ./a.out 4
    ./a.out 8
}

fileName='processes.c'
testFile $fileName
