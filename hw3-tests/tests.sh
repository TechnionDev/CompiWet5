#!/bin/bash
numtests=25
command="./../hw5 < t\$i.in >& t\$i.myout"
i="1"
while [ $i -le $numtests ]
	do
	eval $command
	diff t$i.myout t$i.res &> /dev/null
	if [[ $? != 0 ]]
		then
		echo "Failed test #"$i"!"
	fi
	i=$[$i+1]
done