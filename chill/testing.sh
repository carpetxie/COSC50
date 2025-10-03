#!/usr/bin/
# Use bash -v testing.sh >& testing.out

# zero arguments
./chill
# one argument
./chill 32
# two arguments
./chill 32.5 10
# temp out of range (too high)
./chill 55
# wind out of range (too low)
./chill 10 0

# -------- Boundary tests for temperature --------
./chill 50
# just below upper bound
./chill 49.9
# exactly at lower bound (

# -------- Boundary tests for wind speed --------
# exactly at lower bound (>= 0.5 should be accepted)
./chill 32 0.5
# just below lower bound (should be rejected)
./chill 32 0.49

# -------- One-argument table generation checks --------
# non-integer temperature should still print with one decimal place
./chill 17.25
# negative but valid temperature
./chill -10


# -------- Some random tests --------

./chill 0 5
./chill 0 10
./chill 0 15
./chill 10 5
./chill 20 15

