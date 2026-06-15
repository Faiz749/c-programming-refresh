# Text Analyzer

## What it does
This is a C program that analyzes a sentence using strings, character arrays, and functions.
The user enters a sentence, and the program calculates useful information such as total
characters,vowels, consonants, digits, spaces, uppercase letters, and lowercase letters.

## Features
- Takes a full sentence as input
- Calculates sentence length manually
- Counts vowels
- Counts consonants
- Counts digits
- Counts spaces
- Counts uppercase letters
- Counts lowercase letters
- Uses functions to keep the code organized

## Concepts used
- Strings
- Character arrays
- Functions and function prototypes
- Parameters and return values
- For loop
- While loop
- If-else conditions
- Character comparison
- Manual string length calculation
- Input using `fgets`
- Basic input/output using `printf`

## Mistakes I fixed
- I learned that `fgets` can store a newline character `\n`.
- I fixed the length function by stopping at both `\n` and `\0`.
- I fixed digit checking by comparing characters from `'0'` to `'9'`.
- I initialized count variables before using them.
- I improved consonant counting by checking letters first and then excluding vowels.

## How to compile and run

Compile the program:

```bash
gcc main.c -o text_analyzer
```

Run the program:

```bash
./text_analyzer
```
