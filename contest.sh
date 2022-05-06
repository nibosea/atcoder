#!/bin/bash
#source contest.sh abcXXXのほうがいいよ
ARRAY=(a.cpp b.cpp c.cpp d.cpp e.cpp f.cpp g.cpp h.cpp)

if [ -e ./problems/$1 ]; then
	echo exists
elif [ -e ./pastproblems/$1 ]; then
	echo past_exists
else 
	mkdir problems/$1
	cp go.sh problems/$1/
	for i in ${ARRAY[@]}
	do
#mv $i bef_$i
	touch problems/$1/$i
	cp main.cpp problems/$1/$i
	done
fi
cd problems/$1
chmod +x go.sh
