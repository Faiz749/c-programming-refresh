# Marks Array Analyzer

## What it does
This is a C program that analyzes marks using arrays.
The user can enter the number of subjects, then enter marks for each subject.
The program calculates total marks, average marks, highest marks, lowest marks, passed subjects, and failed subjects.

## Features
- User decides the number of subjects
- Stores marks in an array
- Validates subject count
- Validates marks between 0 and 100
- Calculates total marks
- Calculates average marks
- Finds highest marks
- Finds lowest marks
- Counts passed subjects
- Counts failed subjects
- Uses functions to keep the code clean

## Concepts used
- Arrays
- Variable length arrays
- Functions
- Function prototypes
- Parameters
- Return values
- For loop
- While loop
- If-else conditions
- Float calculations
- Input validation
- Basic input/output using `printf` and `scanf`
- Library used: `stdbool.h`

## Mistakes I fixed
- I changed marks input from `int` to `float` because marks can be in decimals.
- I fixed the format specifiers and used `%d` for integers and `%f` for float values.
- I fixed the output alignment to make the summary easier to read.
- I added `return 0;` at the end of `main`.
- I changed the passing condition from `> 50` to `>= 50`.

## How to compile and run
Compile the program:

```bash
gcc main.c -o marks_analyzer