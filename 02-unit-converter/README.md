# Unit Converter

## What it does
This is a menu-based unit converter written in C. It can convert temperatures, distances, and calculate electrical power using voltage and current.

## Features
- Celsius to Fahrenheit
- Fahrenheit to Celsius
- Kilometers to Miles
- Miles to Kilometers
- Voltage and Current to Power
- Repeated menu until exit
- Invalid choice handling

## Concepts used
- Functions
- Parameters
- Return values
- If-else conditions
- Do-while loop
- While loop
- Float calculations
- Menu-based program
- Basic input/output using printf and scanf
- New library used: `stdbool.h` for using `true` inside the input validation loop

## Mistakes I fixed
- I missed semicolons in some places.
- I had naming mistakes, especially with `fahrenheit`.
- I forgot to add `\n` in the first menu print, so the output looked messy.
- I forgot to ask for current in the power calculation at first.

## How to compile and run
Compile the program:
```bash
gcc main.c -o unit_converter

```

Run the program:

```bash
./unit_converter
```

## What I learned
- I practiced using parameters and return values.
- I used a `do-while` loop to keep the menu running.
- I used `stdbool.h` and `true` for input validation.
- I learned to be careful with small C mistakes like semicolons, names, and `\n`.
- I understood how to make a simple project cleaner and easier to debug.