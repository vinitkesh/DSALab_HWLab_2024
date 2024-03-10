# Check if the given positive number is odd or even.

.data
	prompt: .asciiz "Enter your number: "
	result: .asciiz "A result of 0 is even, 1 is odd: result = "
	
	odd: .asciiz "Is odd"
	even: .ascii "Is even"

.text
.globl main
main:
    # Get input value
    li $v0,4    # Print Prompt
    la $a0, prompt
    syscall

    li $v0, 5    # Retrieve input
    syscall
    move $s0, $v0
    
    # Check if odd or even
    addi $t0, $zero, 2  # Store 2 in $t0
    div $s0, $t0        # Divide input by 2
    mfhi $s1            # Save remainder in $s1
    
    # Print output        
    
    
    beq $s1 , $zero , Even    
    
    li $v0,4    # Print odd
    la $a0, odd
    syscall
    
    addi $v0, $zero, 10
    syscall
    
    Even:
    	li $v0,4    # Print even
    	la $a0, even
    	syscall
    	
    	addi $v0, $zero, 10
    	syscall