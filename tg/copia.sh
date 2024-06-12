#!/bin/bash

# $1 é a pasta onde estão os ficheiro a copiar
DISCO="./backup"

for i in `seq 20`
do
	ca="$1/F$i"
	echo $ca
	cp $ca $DISCO
done
