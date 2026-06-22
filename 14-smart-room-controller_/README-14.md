# Smart Room Controller

## What it does
This is a menu-based C program that simulates a smart room controller.
The program reads sensor values from a file, analyzes room conditions, controls output devices automatically, writes system logs, and resets device states.

## Features
* Load sensor readings from `room_readings.txt`
* Show all sensor readings
* Detect invalid or unloaded sensor readings
* Analyze room conditions
* Show output device status
* Run automatic device control
* Write system logs to `room_log.txt`
* Reset all devices to OFF

## Sensors used
The program simulates four input sensors:
* `TEMP`
* `LIGHT`
* `MOTION`
* `GAS`

## Output devices used
The program controls four output devices:
* `FAN`
* `ROOM_LIGHT`
* `BUZZER`
* `ALARM`

## Input file
The program reads sensor values from:

```text
room_readings.txt
```
Example file content:

```text
TEMP 42.5
LIGHT 20
MOTION 1
GAS 65
```

## Automatic control logic
The program controls devices based on sensor values.
* If `TEMP > 35`, the `FAN` turns ON
* If `LIGHT < 30`, the `ROOM_LIGHT` turns ON
* If `MOTION == 1`, the `BUZZER` turns ON
* If `GAS > 50`, the `ALARM` turns ON
If the conditions are not met, the related devices turn OFF.

## Concepts used
* Structs
* Arrays of structs
* Functions
* Loops
* `strcmp`
* File reading
* File writing
* `FILE *`
* `fopen`
* `fscanf`
* `fprintf`
* `fclose`
* Menu-based programming
* Embedded-style automatic control logic

## Why it matters for Embedded C
Embedded systems usually read input sensors and control output devices.

For example:

* A temperature sensor can control a fan
* An LDR light sensor can control a room light
* A PIR motion sensor can control a buzzer
* A gas sensor can control an alarm

This project simulates the same logic in normal C before moving to real ESP32 hardware.

## Mistakes I fixed

* Added a separate struct for sensors
* Added a separate struct for output devices
* Used arrays of structs to store multiple sensors and devices
* Used `strcmp()` to match sensor names from the file
* Used `fopen()` and `fscanf()` to read sensor values from a file
* Used `fprintf()` to write system logs to a file
* Fixed menu options for writing logs and resetting devices
* Used `room_readings.txt` as the Day 14 input file
* Connected sensor readings with automatic device control logic

## How to compile and run
Compile the program:

```bash
gcc main.c -o smart_room_controller
```

Run the program:

```bash
./smart_room_controller
```

On Windows PowerShell, run:

```powershell
./smart_room_controller.exe
```
