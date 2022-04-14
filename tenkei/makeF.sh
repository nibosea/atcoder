#!/bin/sh
for i in `seq 4 90`
do
	touch $i.cpp
	cp main.cpp $i.cpp
done
