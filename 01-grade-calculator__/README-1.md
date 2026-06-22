# Grade Calculator

## What it does
This is a basic C program that calculates a student's percentage and grade.
The program takes marks as input, calculates the total percentage, and displays the final grade based on the percentage.

## Features
* Takes marks from the user
* Calculates total percentage
* Displays the final grade
* Uses simple if-else conditions
* Shows basic input and output handling in C

## Concepts used
* Variables
* Data types
* `printf`
* `scanf`
* Arithmetic operations
* If-else conditions
* Basic decision making

## Grade logic
The program assigns grades based on the calculated percentage.
Example logic:

* `90` and above means `A+`
* `80` to `89` means `A`
* `70` to `79` means `B`
* `60` to `69` means `C`
* `50` to `59` means `D`
* Below `50` means `Fail`

## Why it matters for Embedded C
Embedded systems often check values and make decisions based on limits.
For example:
* If temperature is too high, turn on a fan
* If battery is low, show a warning
* If sensor value crosses a limit, activate an alarm
This project builds the basic decision-making logic needed for embedded systems.

## Mistakes I fixed
* Used variables correctly to store marks and percentage
* Used `scanf()` to take input from the user
* Used if-else conditions to assign grades
* Organized the logic in a simple and readable way

## How to compile and run
Compile the program:

```bash
gcc main.c -o grade_calculator
```

Run the program:

```bash
./grade_calculator
```

On Windows PowerShell, run:

```powershell
./grade_calculator.exe
```
