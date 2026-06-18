# Device Record System Using Structs

## What it does
This is a menu-based C program that stores device records using structs.
Each device has a name, pin number, value, and status.
The user can add devices, display all devices, update device values, search by device name, and count active/inactive devices.

## Features
- Adds new device records
- Stores device name, pin number, value, and status
- Displays all saved devices
- Updates a device value by searching its name
- Searches a device by name
- Shows active and inactive device count
- Validates device status as 1 for active and 0 for inactive
- Uses a menu that repeats until exit

## Concepts used
- Structs
- Array of structs
- Functions
- Strings
- `strcmp`
- `stdbool.h`
- `string.h`
- Loops
- Menu-based programming
- Search and update logic

## Why it matters for Embedded C
Structs are useful in Embedded C because real devices usually have multiple properties.
For example, a device may have:
- name
- pin number
- sensor value
- ON/OFF or active/inactive status
This project helped me understand how to group related device data together and manage multiple devices using an array of structs.

## Mistakes I fixed
- Used `devices[count]` to store each new device correctly
- Used `strcmp` to compare device names instead of `==`
- Used `%f` for updating float values
- Added status validation for active and inactive devices
- Added active/inactive device counting logic

## How to compile and run

Compile the program:

```bash
gcc main.c -o device_record_system
```

Run the program:

```bash
./device_record_system
```

On Windows PowerShell, run:

```powershell
./device_record_system.exe
```
