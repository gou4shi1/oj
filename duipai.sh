#!/bin/bash
cnt=0
while true; do
    ./$1_dataMaker > $1.in
    ./$1 < $1.in > $1.out
    ./$1_2 < $1.in > $1_2.out
    diff $1.out $1_2.out
    if [ $? -ne 0 ] ; then break; fi
    let "cnt+=1"
    echo $cnt
done
