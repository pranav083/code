#!/bin/bash

# Compile the C program
gcc max_diag_sum.c -O0 -o max_diag_sum

# Run the program three times, printing the command and adding a delay
for i in {1..3}; do
    echo "Running : time ./max_diag_sum"
    time ./max_diag_sum
    sleep 0.25
done

# Run the performance statistics script
echo "running : sh ./perf-stat.sh ./max_diag_sum"
sh ./perf-stat.sh ./max_diag_sum
