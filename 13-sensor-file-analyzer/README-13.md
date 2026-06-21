# Sensor File Analyzer

## What it does
This is a menu-based C program that reads sensor readings from a text file and analyzes them.
The program reads data from `readings.txt`, skips invalid entries, and works only with valid numeric sensor readings.

## Features
* Show all valid readings
* Count valid and invalid entries
* Calculate average reading
* Find highest and lowest reading
* Count danger readings using a threshold
* Show system status based on danger readings
* Skip invalid data from the file

## Concepts used
* File reading in C
* `FILE *`
* `fopen`
* `fscanf`
* `sscanf`
* `fclose`
* Read mode `"r"`
* Functions
* Loops
* Menu-based programming
* Input validation
* Sensor threshold logic

## Input file
The program reads data from:
```text
readings.txt
```
Example file content:

```text
25.5
hello
31.2
45.0
bad
28.9
50.5
```
Valid numeric values are used for analysis. Invalid entries such as text are skipped.

## Why it matters for Embedded C
Embedded systems often read sensor values and analyze them to decide system behavior.
For example:
* temperature readings
* gas sensor values
* light sensor values
* motion sensor data

This project simulates reading stored sensor data from a file and analyzing it like an embedded monitoring system.

## Mistakes I fixed
* Used `fscanf()` correctly to read data from a file
* Used `sscanf()` to check whether a token is a valid float
* Added file opening checks using `file == NULL`
* Used `return` when the file could not be opened
* Used `fclose()` after reading from the file
* Fixed highest and lowest value comparison logic
* Fixed danger reading count logic

## How to compile and run
Compile the program:

```bash
gcc main.c -o sensor_file_analyzer
```

Run the program:

```bash
./sensor_file_analyzer
```

On Windows PowerShell, run:

```powershell
./sensor_file_analyzer.exe
```
