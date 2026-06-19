# Automatic Embedded Device Manager

## What it does
This is a menu-based C program that simulates a simple embedded device manager.
The program allows the user to add input and output devices, update input values, control output devices, and run automatic control using a threshold value.

## Features
* Add input and output devices
* Display all devices
* Update values for input devices
* Control ON/OFF status of output devices
* Run automatic control based on a threshold
* Turn all outputs ON when any input value crosses the threshold
* Turn all outputs OFF when input values are safe

## Concepts used
* Structs
* Array of structs
* Functions
* Loops
* `scanf`
* `strcmp`
* Input validation
* Menu-based programming
* Threshold-based control logic

## Why it matters for Embedded C
Embedded systems usually read input devices and control output devices.

For example:

* Input devices: sensors such as temperature, gas, LDR, or PIR
* Output devices: LED, buzzer, fan, or relay

This project simulates the basic embedded logic of reading an input value, checking a condition, and controlling an output device.

## Mistakes I fixed
* Used `&` correctly in `scanf`
* Placed `get_choice()` inside the loop so the menu repeats
* Returned the selected choice from `get_choice()`
* Used `d1[i]` while looping through devices
* Used a `found` variable to avoid repeated not-found messages
* Compared the threshold with input device values instead of device type
* Separated input device updates from output device control

## How to compile and run
Compile the program:

```bash
gcc main.c -o embedded_device_manager
```

Run the program:

```bash
./embedded_device_manager
```

On Windows PowerShell, run:

```powershell
./embedded_device_manager.exe
```
