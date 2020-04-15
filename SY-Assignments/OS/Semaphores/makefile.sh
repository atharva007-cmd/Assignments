#! /bin/bash
rm $1 0>NUL 1>NUL 2>NUL 
rm NUL
gcc $1.c $2.c -std=c99 -Wall -Werror -pthread -o $1
if [ $? -eq 0 ]
then 
    echo "Running ..."
    echo
    { time ./$1 ; } 2>time_logs
    echo 
    grep [ERROR] time_logs
    echo -e "Executed Successfully\n\nTime required: "
    grep real time_logs
    rm time_logs 
fi