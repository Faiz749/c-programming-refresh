# Command Parser

## What it does
This is a C program that works like a simple embedded-style command parser.
The user enters text commands, and the program controls fake devices such as an LED and a buzzer. The program also remembers the current state of both devices and can show their status.

## Features
- Accepts full commands using `fgets`
- Removes newline from user input
- Compares commands using `strcmp`
- Turns LED ON and OFF
- Turns buzzer ON and OFF
- Stores LED and buzzer states
- Shows current device status
- Displays available commands using `HELP`
- Keeps running until `EXIT`
- Handles invalid commands

## Supported Commands
- `LED ON`
- `LED OFF`
- `BUZZER ON`
- `BUZZER OFF`
- `STATUS`
- `HELP`
- `EXIT`

## Concepts used
- Strings
- Character arrays
- `fgets`
- `strcmp`
- `strcspn`
- Boolean variables
- While loop
- If-else conditions
- Functions
- State variables
- Basic input/output using `printf`

## Why it matters for Embedded C
Embedded systems often receive commands from a Serial Monitor or terminal.
Later on, an ESP32 can receive commands like `LED ON`, `BUZZER OFF`, or `STATUS`. This project practices the same command logic without using hardware yet.

## Mistakes I fixed
* Used `strcmp` instead of comparing strings with `==`.
* Added boolean variables to remember LED and buzzer states.
* Fixed the `EXIT` command so the loop stops properly.
* Added a clear message for invalid commands.

## How to compile and run

Compile the program:

```bash
gcc main.c -o command_parser
```

Run the program:

```bash
./command_parser
```
