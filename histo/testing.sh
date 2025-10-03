#!/bin/bash

echo "testing basic stuff"
echo "3 5 1 7 0 8 15 12 3 5 3 3 3 3" | ./histo
echo

echo "testing bigger numbers"
echo "1 2 3 18 19 20 50 34 32 19 44" | ./histo
echo

echo "testing really big number"
echo "150" | ./histo
echo

echo "testing with some negatives (should ignore them)"
echo "5 -3 10 15 -1 20 25 30" | ./histo
echo

echo "testing empty input"
echo "" | ./histo
echo

echo "testing file input"
echo "10 20 30 40 50 60 70 80 90 100" > test.txt
./histo < test.txt
rm test.txt
echo

echo "testing huge number"
echo "1000" | ./histo
