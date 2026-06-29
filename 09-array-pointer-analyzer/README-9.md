# Day 9: Array Pointer Analyzer

## Project Overview

This project analyzes sensor-style readings using arrays and pointers in C.

The program stores multiple readings, processes them using pointer-based access, and generates a small report showing useful information such as average value, highest value, lowest value, and danger readings.

This project was created as part of my C programming refresh before moving toward Embedded C and ESP32-based hardware projects.

## Purpose

The purpose of this project is to understand how arrays and pointers are connected in C.

In embedded systems, arrays are often used to store multiple sensor readings, and pointers are commonly used to pass arrays to functions efficiently.

## Features

* Stores multiple sensor-style readings
* Accesses array elements using pointers
* Calculates average reading
* Finds highest and lowest reading
* Counts readings above danger threshold
* Demonstrates how arrays are passed to functions
* Uses embedded-style threshold logic

## Concepts Used

* Arrays
* Pointers
* Pointer arithmetic
* Functions
* Loops
* Threshold checking
* Sensor-style data processing

## Embedded Systems Connection

This project connects directly to embedded systems because sensor readings are often stored and processed in arrays.

For example, an ESP32 project may collect multiple ADC readings from a sensor and then calculate:

* Average sensor value
* Maximum reading
* Minimum reading
* Number of unsafe readings
* Whether the system should trigger an alert

Pointers are important because embedded C often uses them to pass arrays, buffers, strings, and hardware-related data efficiently.

## Sample Program Flow

```text
Sensor readings:
120 350 780 910 430

Average reading: 518.00
Highest reading: 910
Lowest reading: 120
Danger readings: 2
System status: WARNING
```

## Mistakes Fixed

During this project, I fixed and improved:

* Used pointer-based array access instead of only index-based access
* Improved function structure for cleaner code
* Added proper threshold checking for danger readings
* Made the output more readable
* Ensured average calculation uses correct numeric type
* Added complete compile and run instructions

## How to Compile

```bash
gcc main.c -o array_pointer_analyzer
```

## How to Run

```bash
./array_pointer_analyzer
```

On Windows Command Prompt or PowerShell:

```bash
array_pointer_analyzer.exe
```

## What I Learned

Through this project, I understood how arrays and pointers work together in C.

This is important for Embedded C because pointer-based logic is commonly used for sensor buffers, device data, memory handling, and passing arrays to functions.
