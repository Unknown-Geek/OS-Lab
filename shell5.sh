#!/bin/bash

read -p "Enter the lower bound  : " a
read -p "Enter the upper bound  : " b

echo "Prime numbers between $a and $b (including limits) are:"

for ((i = a; i <= b; i++)); do
    if ((i == 1)); then
        continue  
    fi

    flag=0
    limit=$((i / 2)) 

    for ((j = 2; j <= limit; j++)); do
        if ((i % j == 0)); then  
            flag=1
            break
        fi
    done

    if ((flag == 0)); then
        echo $i
    fi
done
