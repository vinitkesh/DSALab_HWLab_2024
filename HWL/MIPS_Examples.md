| Program Name | Link | Code |
| --- | --- | --- |
| Reversing a number                | [Link]() | [Code]() |
| Calculating average marks         | [Link]() | [Code]() |
| Print String                      | [Link]() | [Code]() |



## Program to print some integer(without variable):
```asm
.text
main:
    li $v0, 1 # Syscall code 1 prints integer
    li $a0, 10
    syscall
```
## Program to print some integer(without variable):

```asm
.data 
	var: .word 10
.text
main:
    li $v0, 1
    lw $a0, var
    syscall
    
    
```
