#!/bin/bash

echo -e "Enter the name of the directory: \c"
read dir_name

cnt=0
if [ -d $dir_name ] 
then
	mkdir sorted
	for file in $dir_name/*;
	do
		mv $file sorted/
		(( cnt++ ))
	done
	ls sorted | sort | cat > sorted
	echo "Successfuly moved file form $dir_name directory to sorted directory"
	echo "No. of file moved is $cnt"
else
	echo "Error!!! wrong directory name"
fi

