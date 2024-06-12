#!/bin/bash

while :
do
	read origem destino < finfa
	echo $origem #onde estamos a ler
	echo $destino #para onde estamos a copiar

	for i in `seq 20`
	do	
		cp $origem/F$i $destino	
	done
done
