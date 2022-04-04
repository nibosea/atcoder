#!/bin/bash

mv problems/* pastproblem/
mv pastproblem/normal problems/
rm problems/normal -r
./contest.sh normal
