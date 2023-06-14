# Compiled Javascript

This project is a development of a version compiled of Javascript, for x86_64 architecture machines. I'm using C language for this project

## Instruction

For compile the code, just use `make`

```
js.exe [input_file]
```
This command will compile the file

## Token definition

```c
    enum 
    {
        braceL,
        braceR,
        dot,
        endOfFile,
        parenL,
        parenR,
        semi,
        statement,
        string,
        tokenID,
    } type;
```
