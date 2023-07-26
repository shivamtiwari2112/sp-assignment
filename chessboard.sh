#!/bin/bash

echo -e "enter the size of chessboard: \c"
read size
echo "## is used of black square, and ** is used for white square"
echo

for((i=1; i<=$size; i++))
do
	for((j=1; j<=$size; j++))
	do
		if (( ($1 + $j) % 2 == 0 )); then

			echo -n "##"  # for black square
		else
			echo -n "**"  # for white square
		fi
	done
	echo
done

