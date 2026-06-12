# Electricity Bill Calculator

## What it does
This is a menu-based electricity bill calculator written in C. It calculates the electricity bill based on consumed units, applies a fixed service charge, calculates tax, and shows the final bill.

## Features
- Calculate electricity bill
- Show slab information
- Repeated menu until exit
- Invalid choice handling
- Negative units validation
- Rate selection using slabs
- Base bill calculation
- Service charge addition
- Tax calculation
- Final bill calculation

## Bill Slabs
- 0 to 100 units = 10 per unit
- 101 to 200 units = 15 per unit
- 201 to 300 units = 20 per unit
- Above 300 units = 30 per unit

## Extra Charges
- Service charge = 100
- Tax = 10%

## Concepts used
- Functions
- Function prototypes
- Parameters
- Return values
- If-else conditions
- Do-while loop
- While loop
- Float calculations
- Menu-based program
- Input validation
- Basic input/output using `printf` and `scanf`
- library used: `stdbool.h` 

## Mistakes I fixed

- I forgot semicolons in some places.
- I accidentally gave variables the same names as my helper functions.
- I missed a bracket in `printf` while printing the tax.
- In get_units, I accidentally used units instead of u.

## How to compile and run

Compile the program:
Run the program:
./electricity_bill

On Windows, you can also run:
electricity_bill.exe