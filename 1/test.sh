#!/bin/bash

test() {
  F=$1
  INPUT=$2
  EXPECTED=$3

  ACTUAL=$(echo $INPUT | "./bin/$F")


  if [ "$ACTUAL" = "$EXPECTED" ]; then
    echo "$INPUT => $ACTUAL"
  else
    echo "FAIL: $INPUT => $EXPECTED expected, but got $ACTUAL"
    exit 1
  fi

}

F="calc02"
test "$F" "1 2" 3
test "$F" "134 59" 193
test "$F" "52 99" 151

F="larger2"
test "$F" "1 2 3" 3
test "$F" "134 59 394" 394
test "$F" "52 99 44" 99
test "$F" "10000 100 1000" 10000
echo "OK"
