<div align="center">

# Monty

0x19. C - Stacks, Queues - LIFO, FIFO

### In this project, I solved tasks about `Stacks & Queues`, the concept to learn how to handle projects and deal with them.

</div>

## Overview

#### The Monty language

`Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.`

#### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```

#### The monty program

```
Usage: `monty file`
    where file is the path to the file containing Monty byte code.

If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE

If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
    where <file> is the name of the file

If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
    where is the line number where the instruction appears.
    Line numbers always start at 1.

The monty program runs the bytecodes line by line and stop if either:
    it executed properly every line of the file
    it finds an error in the file
    an error occured

If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.

You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)
```

## Tasks

### 0. push, pall

#### The push opcode

Implement the `push` and pall opcodes.

The opcode `push` pushes an element to the stack.

- Usage: <span style="color: red">push \<int\></span>

  - where <span style="color: red">\<int\></span> is an integer

- if <span style="color: red">\<int\></span> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status <span style="color: red">EXIT_FAILURE</span>

  - where is the line number in the file

- You won’t have to deal with overflows. Use the <span style="color: red">atoi</span> function

#### The pall opcode

The opcode `pall` prints all the values on the stack, starting from the top of the stack.

- Usage `pall`
- Format: see example
- If the stack is empty, don’t print anything

```
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$
```

### 1. pint

#### The push opcode

Implement the `pint` opcode.

The opcode `pint` prints the value at the top of the stack, followed by a new line.

- Usage: <span style="color: red">pint</span>

  - where <span style="color: red">\<int\></span> is an integer

- If the stack is empty, print the error message <span style="color: red">L\<line_number\>: can't pint, stack empty</span>, followed by a new line, and exit with the status <span style="color: red">EXIT_FAILURE</span>
  - where is the line number in the file

```
julien@ubuntu:~/monty$ cat bytecodes/06.m
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m
1
2
3
julien@ubuntu:~/monty$
```

### 2. pop

Implement the `pop` opcode.

The `pop` opcode

#### The pop opcode

The opcode `pop` removes the top element of the stack.

- Usage: `pop`
- If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

```
julien@ubuntu:~/monty$ cat bytecodes/07.m
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/monty$ ./monty bytecodes/07.m
3
2
1
2
1
1
julien@ubuntu:~/monty$
```

### 3. swap

Implement the `swap` opcode.

#### The swap opcode

The opcode `swap` swaps the top two elements of the stack.

- Usage: `swap`
- If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

```
julien@ubuntu:~/monty$ cat bytecodes/09.m
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/monty$ ./monty bytecodes/09.m
3
2
1
2
3
1
julien@ubuntu:~/monty$
```

### 4. add

Implement the `add` opcode.

#### The add opcode

The opcode `add` adds the top two elements of the stack.

- Usage: `add`
- If the stack contains less than two elements, print the error message L\<line_number\>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  - The top element of the stack contains the result
  - The stack is one element shorter

```
julien@ubuntu:~/monty$ cat bytecodes/12.m
push 1
push 2
push 3
pall
add
pall

julien@ubuntu:~/monty$ ./monty bytecodes/12.m
3
2
1
5
1
julien@ubuntu:~/monty$
```

### 5. nop

Implement the `nop` opcode.

#### The nop opcode

The opcode nop doesn’t do anything.

- Usage: `nop`

### 6. sub

Implement the `sub` opcode.

#### The sub opcode

The opcode `sub` subtracts the top element of the stack from the second top element of the stack.

- Usage: `sub`
- If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

  - The top element of the stack contains the result
  - The stack is one element shorter

```
julien@ubuntu:~/monty$ cat bytecodes/19.m
push 1
push 2
push 10
push 3
sub
pall
julien@ubuntu:~/monty$ ./monty bytecodes/19.m
7
2
1
julien@ubuntu:~/monty$
```

### 7. div

Implement the `div` opcode.

#### The div opcode

The opcode `div` divides the second top element of the stack by the top element of the stack.

- Usage: `div`
- If the stack contains less than two elements, print the error message L\<line_number\>: can't div, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

  - The top element of the stack contains the result
  - The stack is one element shorter

- If the top element of the stack is 0, print the error message L\<line_number\>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

### 8. mul

Implement the `mul` opcode.

#### The mul opcode

The opcode `mul` multiplies the second top element of the stack with the top element of the stack.

- Usage: `mul`
- If the stack contains less than two elements, print the error message L\<line_number\>: can't mul, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  - The top element of the stack contains the result
  - The stack is one element shorter

### 9. mod

Implement the `mod` opcode.

#### The mod opcode

The opcode `mod` computes the rest of the division of the second top element of the stack by the top element of the stack.

- Usage: `mod`
- If the stack contains less than two elements, print the error message L\<line_number\>: can't mod, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

  - The top element of the stack contains the result
  - The stack is one element shorter

- If the top element of the stack is 0, print the error message L\<line_number\>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

### 10. comments

Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything).

### 11. pchar

Implement the `pchar` opcode.

#### The pchar opcode

The opcode `pchar` prints the char at the top of the stack, followed by a new line.

- Usage: `pchar`
- The integer stored at the top of the stack is treated as the ascii value of the character to be printed
- If the value is not in the ascii table (man ascii) print the error message L\<line_number\>: can't pchar, value out of range, followed by a new line, and exit with the status EXIT_FAILURE
- If the stack is empty, print the error message L\<line_number\>: can't pchar, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

```
julien@ubuntu:~/monty$ cat bytecodes/28.m
push 72
pchar
julien@ubuntu:~/monty$ ./monty bytecodes/28.m
H
julien@ubuntu:~/monty$
```

### 12. pstr

Implement the `pstr` opcode.

#### The pstr opcode

The opcode `pstr` prints the string starting at the top of the stack, followed by a new line.

- Usage: `pstr`
- The integer stored in each element of the stack is treated as the ascii value of the character to be printed
- The string stops when either:

  - the stack is over
  - the value of the element is 0
  - the value of the element is not in the ascii table

- If the stack is empty, print only a new line

```
julien@ubuntu:~/monty$ cat bytecodes/31.m
push 1
push 2
push 3
push 4
push 0
push 110
push 0
push 108
push 111
push 111
push 104
push 99
push 83
pstr
julien@ubuntu:~/monty$ ./monty bytecodes/31.m
School
julien@ubuntu:~/monty$
```

### 13. rotl

Implement the `rotl` opcode.

#### The rotl opcode

The opcode `rotl` rotates the stack to the top.

- Usage: `rotl`
- The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
- rotl never fails

```
julien@ubuntu:~/monty$ cat bytecodes/35.m
push 1
push 2
push 3
push 4
push 5
push 6
push 7
push 8
push 9
push 0
pall
rotl
pall
julien@ubuntu:~/monty$ ./monty bytecodes/35.m
0
9
8
7
6
5
4
3
2
1
9
8
7
6
5
4
3
2
1
0
julien@ubuntu:~/monty$
```

### 14. rotr

Implement the `rotr` opcode.

#### The rotr opcode

The opcode `rotr` rotates the stack to the bottom.

- Usage: `rotr`
- The last element of the stack becomes the top element of the stack
- `rotr` never fails

## ! Important

There are more tasks, but I did not complete it.

## Files

This is discription about all files created in this project:

- [monty.h](https://github.com/abdelemjidessaid/monty/blob/main/monty.h) -> This is the header file that is contains all function prototypes, macros, headers included, global variables and structures of whole project.

- [main.c](https://github.com/abdelemjidessaid/monty/blob/main/main.c) -> File that contains the main function which is the `Entnry point` of monty program.

- [read_file.c](https://github.com/abdelemjidessaid/monty/blob/main/read_file.c) -> Files that contains function which read the given file as argument, line by line.

- [line_handler.c](https://github.com/abdelemjidessaid/monty/blob/main/line_handler.c) -> File that contains functions that could splits each line given from other function, to words to check every word if it is an instruction or something else. if this word is an instruction this function calls other function that returns a callback function could Implement this instruction.

- [\_string.c](https://github.com/abdelemjidessaid/monty/blob/main/_strings.c) -> File contains functions to counts words of every line, and duplicates strings.

- [\_instructions.c](https://github.com/abdelemjidessaid/monty/blob/main/_instructions.c) -> File that contains the function which Implements instructions.

- [\_\_instructions.c](https://github.com/abdelemjidessaid/monty/blob/main/__instructions.c) -> The same of the last file.

- [\_\_\_instructions.c](https://github.com/abdelemjidessaid/monty/blob/main/___instructions.c) -> The same of the last file.

- [\_errors.c](https://github.com/abdelemjidessaid/monty/blob/main/_errors.c) -> File contains functions that prints errors about the previous instruction's functions.

- [\_\_errors.c](https://github.com/abdelemjidessaid/monty/blob/main/__errors.c) -> The same of the last file.

- [\_\_\_errors.c](https://github.com/abdelemjidessaid/monty/blob/main/___errors.c) -> The same of the last file.

- [\_insert_start](https://github.com/abdelemjidessaid/monty/blob/main/_insert_start.c) -> File that contains function which inserts nodes at first onto stack.

- [utils.c](https://github.com/abdelemjidessaid/monty/blob/main/utils.c) -> This File contains functions that search for the specified callback that could implement the given instruction's name. And function that check `ascii` codes, and other function that check strings if it contains numbers.

- [bytecodes](https://github.com/abdelemjidessaid/monty/tree/main/bytecodes) -> Directory that contains monty files to check tasks.

## Conclusion

This project given to students of ALX program, time given to this project 3 days for first deadline.

- Goal of this is to learn the `stacks & queues` and the colaboration of each two students. But I did this project alone.

🖐️ Goodbye.
