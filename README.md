# About

StrToArr is an application written in C that takes in a string supplied by the user and converts it into a declaration of a char hex array with trailing null byte `0x00`. This can be used to encode a string into an array for C and C++ programs to be included in a header file, or to encode strings for a profanity filter so you don't have source files with "ugly" strings hardcoded in it: simply encode the blacklisted words into a char array and use comparison functions upon it.

The format of the array will be:
`char val[] = { ..... 0x00 };`

# Compiling
Compilation is simple, no extra linking is needed. Simply compile with your prefered compiler (preferably GCC):
` gcc main.c -o StrToArr `

# Forking and Merging
Users are welcome to fork and merge features requested. Although this is a simple program, by all means if someone finds a bug or a feature they'd like to add feel free to create a pull request of it.
