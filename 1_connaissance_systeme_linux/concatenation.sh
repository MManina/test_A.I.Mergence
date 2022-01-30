#!/bin/bash

for f in $(find data -name '*.txt')
do
	echo "Processing $f file"
	cat $f >> data.txt
done


