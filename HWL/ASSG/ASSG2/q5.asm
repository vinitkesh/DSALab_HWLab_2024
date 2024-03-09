# 5. Determine if a given integer is a perfect number. 
# A perfect number is a positive integer that is equal 
#   to the sum of its proper divisors, excluding itself. 
# For example, 6 is a perfect number because the sum of 
#   its proper divisors (1, 2, and 3) equals 6.

# print promt
# get input number
# go through a for loop 1 to number-1
# if number % i == 0, add to sum
# if sum == number, print "perfect number"

.data 

    promt: .asciiz "Enter a number: "
    perfect: .asciiz "Perfect number"
    notPerfect: .asciiz "Not a perfect number"

.text

    main:
        li $v0, 4
        la $a0, promt
        syscall

        li $v0, 5
        syscall
        move $t0, $v0

        li $t1, 1
        li $t2, 0

        loop:
            beq $t1, $t0, end
            div $t0, $t1
            mfhi $t3
            beq $t3, 0, add
            j next

            add:
                add $t2, $t2, $t1

            next:
                addi $t1, $t1, 1
                j loop

        end:
            beq $t2, $t0, perfectNum # if perfect
            j notPerfectNum     # else

        perfectNum:
            li $v0, 4
            la $a0, perfect
            syscall
            j exit

        notPerfectNum:
            li $v0, 4
            la $a0, notPerfect
            syscall
            j exit

        exit:
            li $v0, 10
            syscall
