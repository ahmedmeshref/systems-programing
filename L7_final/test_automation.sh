#! /bin/bash

function testFile() {
    gcc $1 -lpthread
    ./a.out 2
    ./a.out 4
    ./a.out 8
}


testFile $processes.c
