#! /bin/bash
touch $1.cpp
touch $1_1.txt
touch $1_2.txt
touch $1_3.txt

echo "g++ -O2 "$1.cpp "-o "$1
echo "./"$1 "< "$1"_1.txt"
