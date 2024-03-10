# Perform an addition operation on two numbers, A and B. Where A is a signed number and B is the 2's complement of A.

.data
    prompt_A: .asciiz "Enter a number A: "
    result_msg: .asciiz "The result of A + B is: "

.text
    main:
        # Prompt user to enter A
        li $v0, 4
        la $a0, prompt_A
        syscall

        # Read A from input
        li $v0, 5
        syscall
        move $t0, $v0     # Store A in $t0

        # Calculate two's complement of A
        li $t1, 0          # Temporary register for loop
        li $t2, 1          # Two's complement mask
        li $t3, 32         # Number of bits

    complement_loop:
        sll $t1, $t1, 1    # Shift left to make room for the next bit
        and $t4, $t0, $t2  # Extract the least significant bit of A
        xor $t4, $t4, $t2  # Flip the bit
        or $t1, $t1, $t4   # Add the flipped bit to the two's complement
        srl $t0, $t0, 1    # Shift A right to process the next bit
        addi $t3, $t3, -1  # Decrease the bit count
        bnez $t3, complement_loop  # Loop until all bits are processed

        # Perform addition of A and its two's complement
        add $t2, $t0, $t1   # Perform addition

        # Print the result
        li $v0, 4            # syscall code for printing a string
        la $a0, result_msg   # Load address of the result message
        syscall

        li $v0, 1            # syscall code for printing an integer
        move $a0, $t2        # Load the result into argument register $a0
        syscall

        # Exit program
        li $v0, 10           # syscall code for exit
        syscall
