#!/bin/bash

echo "What's your name?"
read name
echo "What's your age?"
read age

echo "Hello, $name, you are $age years old."

richage=$(( ($RANDOM % 20) + $age ))

sleep 2

echo "Calculating..."
echo "----------"
sleep 1
echo "**--------"
sleep 2
echo "****------"
sleep 5
echo "*******---"
sleep 2
echo "*********-"
sleep 3
echo "**********"

echo "$name, you are going to be a billionaire at $richage years old"
