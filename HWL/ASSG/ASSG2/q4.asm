# q4 Convert a given 32-bit binary number to its decimal equivalent.
.data
    prompt: .asciiz "Enter a 32-bit binary number: "
    decimal: .asciiz "The decimal equivalent is: "
    buffer: .space 33  # Increase buffer size by 1 to store null terminator

.text
    main:
        # Prompt user to enter a 32-bit binary number
        li $v0, 4
        la $a0, prompt
        syscall

        # Read the binary number
        li $v0, 8
        la $a0, buffer
        li $a1, 33  # Read up to 33 characters plus null terminator
        syscall

        # Convert the binary number to decimal
        la $s0, buffer   # Address of the buffer
        addi $s0, $s0, 31  # Move to the last character (32nd character)
        li $t1, 0        # Decimal result
        li $t2, 1        # Tracks power of 2

    loop:
        lb $t0, 0($s0)   # Load the current bit
        beqz $t0, end    # If the bit is null (end of string), exit loop
        sub $t0, $t0, 48 # Convert from ASCII to integer ('0' = 48)
        mul $t0, $t0, $t2  # Multiply the bit by 2^i
        add $t1, $t1, $t0  # Add the result to the decimal

        mul $t2, $t2, 2  # Update the power of 2
        subi $s0, $s0, 1  # Move to the previous bit
        j loop           # Repeat the loop

    end:
        # Print the decimal equivalent
        li $v0, 4
        la $a0, decimal
        syscall

        li $v0, 1
        move $a0, $t1
        syscall

        # Exit program
        li $v0, 10
        syscall
