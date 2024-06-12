#!/bin/bash

c1=$1
sleep 2
while true
do
	echo "next"
	read c2
	dif=$(( $c2 - $c1))
	if [[ $dif -ge 2 ]];then
		echo ">>> AVISO, DISCO! <<<"
		break
	fi
	c1=$c2
	sleep 2
done
