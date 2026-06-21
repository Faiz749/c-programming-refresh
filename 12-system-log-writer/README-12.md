# System Log Writer

## What it does
This is a menu-based C program that writes system logs into a text file.
The program allows the user to write startup logs, sensor reading logs, warning logs, device action logs, and clear the log file.

## Features
* Write a system startup log
* Write sensor readings to a file
* Write warning messages to a file
* Write device action logs
* Clear the log file
* Uses write mode for fresh logs
* Uses append mode for adding new logs

## Concepts used
* File handling in C
* `FILE *`
* `fopen`
* `fprintf`
* `fclose`
* Write mode `"w"`
* Append mode `"a"`
* Functions
* Loops
* `scanf`
* `strcmp`
* Menu-based programming

## Why it matters for Embedded C
Embedded systems often need to save important events such as sensor readings, warnings, and device actions.

For example:

* System started
* Sensor value recorded
* Warning detected
* Buzzer turned ON
* Log file cleared

This project simulates basic embedded logging using a normal text file.

## Mistakes I fixed

* Used `FILE *` to create a file pointer
* Used `fopen()` with the correct file modes
* Used `&` correctly when taking numeric input with `scanf`
* Used `strcmp()` to validate device actions such as `ON` and `OFF`
* Fixed small output messages and added new lines where needed

## How to compile and run

Compile the program:

```bash
gcc main.c -o system_log_writer
```

Run the program:

```bash
./system_log_writer
```

On Windows PowerShell, run:

```powershell
./system_log_writer.exe
```
