#!/bin/bash
ARRAY=(a.cpp b.cpp c.cpp d.cpp e.cpp f.cpp g.cpp h.cpp)

mkdir problems/$1
cp go.sh problems/$1/
for i in ${ARRAY[@]}
do
	#mv $i bef_$i
	touch problems/$1/$i
	cp main.cpp problems/$1/$i
done
