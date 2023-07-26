#!/bin/bash

for((i=1; i<=8; i++))
do
	for((j=1; j<=8; j++))
	do
		if (( ($1 + $j) % 2 == 0 )); then

			echo -n "##"  # for black square
		else
			echo -n "**"  # for white square
		fi
	done
	echo
done

