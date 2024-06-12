#!/bin/bash

x=1
while [[ ($x -le 10) || (1 == 1 && $x -le 10) ]]
do
	echo $x
	(( x ++ ))
done
