#!/bin/bash
g++ $1.cpp -std=c++17 -I ./../../ac-library -o $1 && ./$1
