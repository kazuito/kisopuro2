#!/bin/bash

test() {
  INPUT=$1
  EXPECTED=$2

  ACTUAL=$(echo $INPUT | "./bin/leap")


  if [ "$ACTUAL" = "$EXPECTED" ]; then
    echo "$INPUT => $ACTUAL"
  else
    echo "FAIL: $INPUT => $EXPECTED expected, but got $ACTUAL"
    exit 1
  fi

}

test 1900 "1900"
test 2040 "2040 leap"
test 2023 "2023"
test 2024 "2024 leap"
test 2025 "2025"
echo OK
