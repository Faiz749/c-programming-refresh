# Sensor Reading Analyzer
## What it does
This is a C program that analyzes temperature sensor readings using arrays, functions, and a menu system.
The user enters multiple temperature readings, and the program provides useful analysis such as average temperature, highest and lowest readings, status counts, threshold checking, searching, and a full summary report.

## Features
- Stores temperature readings in an array
- Validates reading count and temperature range
- Shows all recorded readings
- Calculates average, highest, and lowest temperature
- Counts normal, warning, and danger readings
- Counts readings above a custom threshold
- Searches for a specific reading
- Displays a full sensor report

## Temperature Rules
- Below 30 = Normal
- 30 to 39.99 = Warning
- 40 or above = Danger

## Concepts used
- Arrays and variable length arrays
- Functions and function prototypes
- Loops and conditional statements
- Menu-based programming
- Input validation
- Searching and counting in arrays
- Float calculations
- `stdbool.h` for boolean values

## Mistakes I fixed
- Fixed `scanf` by using `&number[i]` for float input.
- Initialized the threshold counter before using it.
- Corrected the threshold comparison logic.
- Used float typecasting for danger percentage.
- Improved output formatting with new lines.


## How to compile and run
Compile the program:

```bash
gcc main.c -o sensor_analyzer
```

Run the program:
```bash
./sensor_analyzer
```
