# Array Pointer Analyzer

## What it does
This is a menu-based C program that stores sensor readings in an array and allows the user to analyze them.
The main purpose of this project is to practice arrays with pointers by passing the array to functions and accessing values using pointer-style logic.

## Features
- Takes sensor readings from the user
- Stores readings in an array
- Displays all readings
- Calculates average reading
- Finds highest reading
- Finds lowest reading
- Adds calibration value to all readings
- Counts readings above a danger threshold
- Shows system status as NORMAL, WARNING, or DANGER
- Prevents analysis before readings are entered

## Concepts used
- Arrays
- Pointers
- Pointer-style array access
- Functions
- `arr + i`
- `*(arr + i)`
- `scanf`
- `do while` loop
- `while` loop
- `stdbool.h`
- Menu-based programming

## Why it matters for Embedded C
Arrays and pointers are important in Embedded C because sensor readings are often stored in arrays and passed to functions for analysis.

For example, later in embedded systems, a program may:
- store temperature readings
- calculate average sensor value
- find highest or lowest readings
- apply calibration to sensor data
- check if readings cross a danger threshold

This project helped me understand how arrays can be passed to functions using pointers.

## Mistakes I fixed
- Used `%f` for float input and output instead of `%d`
- Returned the average value properly from the average function
- Fixed danger count logic to count readings above the threshold
- Passed danger count to the status function instead of menu choice

## How to compile and run

Compile the program:

```bash
gcc main.c -o array_pointer_analyzer