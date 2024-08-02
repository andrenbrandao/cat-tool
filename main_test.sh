#!/bin/bash

# Grabs the arguments from Bazel
echo "input txt file: $1"
echo "cmd: $2"
INPUT_TXT=$1
CMD=$2
EXPECTED_TXT=./testdata/expected_output.txt

# Creates expected result by running the 
# cat command.
if [ ! -f $EXPECTED_TXT ]; then
  sed G "$INPUT_TXT" | cat -b > $EXPECTED_TXT
fi

# Executes the same input with ccat and compares
# if the result is the same.
sed G "$INPUT_TXT" | $CMD -b > test_output.txt
if cmp test_output.txt $EXPECTED_TXT
then
  echo '---' test: PASS
else
  echo '---' output is not the same as expected_output.txt
  echo '---' test: FAIL
  exit 1
fi
