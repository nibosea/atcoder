(
  sleep 1
  exit 1
) &
PID1=$!

(
  sleep 2
  exit 2
) &
PID2=$!

(
  sleep 3
  exit 3
) &
PID3=$!

wait $PID1 $PID2 $PID3
echo $?
