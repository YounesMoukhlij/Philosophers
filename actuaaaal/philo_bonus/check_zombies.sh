#!/bin/bash

# Run the program
./philo_bonus 10 800 500 300

# Wait for the program to finish
wait $!

# Check for zombie processes using ps -aux
zombies=$(ps -aux philo_bonus | grep 'Z')

# Print any zombie processes found
if [ -n "$zombies" ]; then
    echo "Zombie processes found:"
    echo "$zombies"
else
    echo "No zombie processes found."
fi
