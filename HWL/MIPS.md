## How to write any MIPS program:

[Link](https://minnie.tuhs.org/CompArch/Resources/mips_quick_tutorial.html)

### Any MIPS program has 2 sections:
#### 1. Data Declaration
  - Placed after ```.data```
  - declares variable names used in program; storage allocated in RAM( main memory)

#### 2. Code
- Place in ```.text```
- Contains program code(instructions)
- Code excutes only after ```main:```
- ending point of main code should use exit system call


### Template for a MIPS assembly language program:

```MIPS
# Comment giving name of program and description of function
# Template.s
# Bare-bones outline of MIPS assembly language program

           .data       # variable declarations follow this line
                       # ...
														
           .text       # instructions follow this line	
																	
main:                  # indicates start of code (first instruction to execute)
                       # ...
									
# End of program, leave a blank line afterwards to make SPIM happy

```

## Data Declarations
format for declarations:

```name:	storage_type	value(s)	```
create storage for variable of specified type with given name and specified value
value(s) usually gives initial value(s); for storage type .space, gives number of spaces to be allocated
Note: labels always followed by colon ( : )

example
	
var1:		.word	3	# create a single integer variable with initial value 3
array1:		.byte	'a','b'	# create a 2-element character array with elements initialized
				#   to  a  and  b
array2:		.space	40	# allocate 40 consecutive bytes, with storage uninitialized
				#   could be used as a 40-element character array, or a
				#   10-element integer array; a comment should indicate which!	
