( g++ a.cpp -o a.out
) &
PID1=$!

( g++ b.cpp -o b.out
) &
PID2=$!

wait $PID1
( ./a.out
) &
PID3=$!

wait $PID2
( ./b.out
) &
PID4=$!

wait $PID4
kill $PID3


