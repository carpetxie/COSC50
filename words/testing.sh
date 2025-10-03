#!/bin/bash

# Testing standard input
./words <<< 'I like to eat pineapple'
echo "---"
./words <<< 'I like to eat pineapple and pizza without any doubt'
echo "---"
./words <<< 'I enjoy them pizza and orange chicken, and I just dont know what I want in life'
echo "---"
./words <<< 'I mean. I think I do but I lowkey dont know what I want to do'

# Testing a file
touch test.txt
echo "I like to eat pineapple and pizza and marshmallows singular value decomposition" > test.txt
./words test.txt

# Clean up
rm test.txt
