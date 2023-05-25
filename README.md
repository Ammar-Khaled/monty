# Monty
`monty` is an Interpreter of Monty ByteCode files

## The Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

## Monty ByteCode files
Files containing Monty byte codes usually have the `.m` extension. There is not more than one instruction per line.

### Example (file.m)
The bytecodes directory contains a sample of these files.
```bash
$ cat file.m
# Pushing element to the stack
push 0
push 1
push 2
# Printing all elements
pall
push 3
push 4
pop
# Rotating the stack to the bottom
rotr
pall
rotl
# Setting FIFO
queue
push 5
# Setting LIFO
stack
push 5
$
```
## Usage
To compile all file:
```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
Then use:
```bash
$ ./monty [filename.m]
```

## Output of the running the example file
```bash
$ ./monty file.m
2
1
0
0
3
2
1
$
```

## Technologies
* Interpreter was written with C language
* C files are compiled using `gcc 4.8.4`
* C files are written according to the C89 standard
* Tested on Ubuntu 20.04 LTS

## Monty opcodes
| Opcode | Description |
| ------ | ----------- |
| `push` | Pushes an element to the stack |
| `pall` | Prints all the values on the stack |
| `pint` | Prints the value at the top of the stack |
| `pop` | Removes the top element of the stack |
| `swap` | Swaps the top two elements of the stack |
| `queue` | Sets the format of the data to a queue (FIFO) |
| `stack` | Sets the format of the data to a stack (LIFO) |
| `nop` | Doesn't do anything |
| `add` | Adds the top two elements of the stack |
| `sub` | Subtracts the top element of the stack from the second top element of the stack |
| `mul` | Multiplies the second top element of the stack with the top element of the stack |
| `div` | Divides the second top element of the stack by the top element of the stack |
| `mod` | Computes the rest of the division of the second top element of the stack by the top element of the stack |
| `pchar` | Prints the char at the top of the stack |
| `pstr` | Prints the string starting at the top of the stack |
| `rotl` | Rotates the stack to the top |
| `rotr` | Rotates the stack to the bottom |

## Monty Comments
Comments, indicated with '#', are not excuted by the interpreter

## Return Value
When success, the program returns 0. Otherwise, returns EXIT_FAILURE
and prints an error message.

## Authors
* Ammar-Khaled
* Ahmed-D007A
