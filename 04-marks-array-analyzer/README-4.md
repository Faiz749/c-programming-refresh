# Day 4: Marks Array Analyzer

## Project Overview

This project analyzes marks entered by the user and generates a simple academic report.

It takes marks for multiple students, stores them in an array, and calculates:

* Total marks
* Average marks
* Highest marks
* Lowest marks
* Number of passed students
* Number of failed students

This project was created as part of my C programming refresh before moving deeper into Embedded C and ESP32 development.

## Purpose

The purpose of this project is to practice arrays, loops, input validation, and basic data analysis in C.

Arrays are important in embedded systems because sensor readings, stored samples, ADC values, and logs are often handled as groups of values rather than single variables.

## Features

* Takes number of students as input
* Stores marks in an array
* Validates marks between 0 and 100
* Calculates total and average
* Finds highest and lowest marks
* Counts pass and fail cases
* Displays a clean result summary

## Concepts Used

* Arrays
* Loops
* Conditional statements
* Input validation
* Total and average calculation
* Maximum and minimum value search
* Pass/fail threshold logic

## Embedded Systems Connection

This project is similar to analyzing sensor readings in embedded systems.

For example, instead of student marks, an embedded device may store:

* Temperature readings
* Light sensor values
* Gas sensor values
* Battery voltage samples
* ADC readings

The same logic can be used to calculate average sensor value, highest reading, lowest reading, and warning conditions.

## Sample Program Flow

```text
Enter number of students: 5

Enter marks for student 1: 78
Enter marks for student 2: 45
Enter marks for student 3: 90
Enter marks for student 4: 32
Enter marks for student 5: 66

Total marks: 311
Average marks: 62.20
Highest marks: 90
Lowest marks: 32
Passed students: 4
Failed students: 1
```

## Mistakes Fixed

During this project, I fixed and improved:

* Added input validation so marks outside 0 to 100 are not accepted
* Used loops properly to avoid repeated code
* Initialized highest and lowest values correctly before comparison
* Used clear variable names for readability
* Improved output formatting for a cleaner report
* Added proper compile and run instructions

## How to Compile

```bash
gcc main.c -o marks_analyzer
```

## How to Run

```bash
./marks_analyzer
```

On Windows Command Prompt or PowerShell:

```bash
marks_analyzer.exe
```

## What I Learned

Through this project, I practiced how to store multiple values in an array and process them using loops.

I also understood how simple data analysis logic can later be reused in embedded systems for sensor reading analysis and threshold-based decisions.
