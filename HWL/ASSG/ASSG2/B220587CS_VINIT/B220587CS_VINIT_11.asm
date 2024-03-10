# Change the case (upper to lower and vice versa) of all the alphabets in a given string.

# print prompt and input string
# loop through the string
# if the character is a letter with ascii between 65 and 90, add 32 to it to make it lowercase
# else if the character is a letter with ascii between 97 and 122, subtract 32 to make it uppercase
.data 

    prompt: .asciiz"Enter a the string "
    str: .space 100


.text
.globl main

main:

    # print prompt
    li $v0, 4
    la $a0, prompt
    syscall

    # read string
    li $v0, 8
    la $a0, str
    li $a1, 100
    syscall

    la $t0, str # load the address of the string into $t0
    li $t1 , 0 # initialize $t1 to 0 for the loop

    loop:
        lb $t2, ($t0) # load the byte data at the address in $t0 into $t2
        beqz $t2, end # loop ender

        blt $t2, 65, else1  
            bge $t2, 90, else1 # >=65 && <=90 : uppercase
                addi $t2, $t2, 32
                sb $t2, ($t0)
                j loopend

        else1: # not uppercase, check if lowercase

            blt $t2, 97,  loopend 
            bge $t2, 122, loopend # <97 && >122 : not a letter
                addi $t2, $t2, -32
                sb $t2, ($t0)
                j loopend

        loopend:
            addi $t0, $t0, 1 # increment the address in $t0 to the next byte
            addi $t1, $t1, 1 # increment the counter
            j loop

    end:

    # print the string
    li $v0, 4
    la $a0, str
    syscall

    li $v0, 10
    syscall
