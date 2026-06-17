# Value Modifier Tool Using Pointers

## What it does
This is a menu-based C program that takes two integer values and allows the user to display, update, swap, and reset them.
The main purpose of this project is to practice pointers by passing variable addresses to functions and modifying the original values.

## Features

- Takes two integer values from the user
- Shows current values
- Updates the first value using a pointer
- Updates the second value using a pointer
- Swaps both values using pointers
- Resets both values to zero
- Repeats the menu until the user exits
- Handles invalid menu choices

## Concepts used

- Functions
- Pointers
- Address operator `&`
- Dereference operator `*`
- `scanf`
- `do while` loop
- `while` loop
- `stdbool.h`
- Menu-based programming

## Why it matters for Embedded C

Pointers are important in Embedded C because functions often need to modify real values directly.
For example, later in embedded systems, a function may update:

- sensor readings
- device states
- motor speed values

This project helped me understand how a function can change the original variable by receiving its memory address.

## Mistakes I fixed

- Used `&` when passing variables to pointer functions
- Used `*` inside functions to access and modify the original value
- Fixed the menu loop so it exits only when the user selects option 6
- Added success messages after update, swap, and reset operations

## How to compile and run

Compile the program:

```bash
gcc main.c -o value_modifier
```

Run the program:

```bash
./value_modifier
```

On Windows PowerShell, run:

```powershell
./value_modifier.exe
```

