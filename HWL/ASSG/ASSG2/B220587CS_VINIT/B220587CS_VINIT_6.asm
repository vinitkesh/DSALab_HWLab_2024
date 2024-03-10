#  6. Check if a given number is an Armstrong number or not. 
#    [Example: Armstrong Number is 153 as (1*1*1) +(5*5*5) +(3*3*3) = 153.]

# print promt
# take number input from user
# run a for loop to iterate through the number
# stire each digit in a variable
# cube it
# add it to a sum 
# until the loop ends

# check if the sum is equal to the input number
# if yes, print "Armstrong number"
# else, print "Not an Armstrong number"

.data 

    prompt: .asciiz"Enter your number"
    armstrong: .asciiz"Armstrong number"
    notArmstrong: .asciiz"Not an Armstrong number"


.text

    li $v0 , 4
    la $a0 , prompt
    syscall

    li $v0 , 5
    syscall
    move $t4 , $v0    # will store the input number
    
    li $v0 , 1
    addi $a0, $t4, 0
    syscall
    

    addi $t0, $t4 , 0 # will go through the number
    li $t3, 0         # will store the sum of cubes
    li $t1, 0         # will store the digit temporarily and also store 10 for division

    loop:
        addi $t1 , $t0 , 0  # t1 = t0
        div $t0 , $t0 , 10
        mflo $t0            # t0 = t0 / 10
        mfhi $t1            # t1 = t0 % 10

        mul $t2 , $t1 , $t1 # t1^2
        mul $t2 , $t2 , $t1 # t2 = t1^3

        add $t3 , $t3 , $t2 # t3 = t3 + t1^3

        bne $t0 , 0 , loop
    
    beq $t3 , $t4 , ISarmstrong

    not:
        li $v0 , 4
        la $a0 , notArmstrong
        syscall
        j end

    ISarmstrong:
        li $v0 , 4
        la $a0 , armstrong
        syscall

    end:
        li $v0 , 10
        syscall
    
    
