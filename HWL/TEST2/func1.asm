# FINDING THE SUM OF ELEMENTS OF AN ARRAY
.data
    arr: .space 100
    msg1: .asciiz "Enter N:"
    msg2: .asciiz "Enter integer:"
    msg3: .asciiz "Sum of the numbers is:"


.text
.globl main
    main:
        li $v0,4 # print string
        la $a0,msg1
        syscall

        li $v0,5 # read integer
        syscall
        move $s1,$v0 # s1 = n
        sll $s1,$s1,2 # s1 = s1 * 4

        li $t0,0 # t0 is the counter = 0 
    input:
        beq $t0,$s1,end_input  # if t0 == n then end_input

        li $v0,4
        la $a0,msg2
        syscall

        li $v0,5
        syscall
        sw $v0,arr($t0) # store the integer in the array

        addi $t0,$t0,4 # t0 = t0 + 4
        j input

    end_input:
        li $t1,0
        li $t0,0
    sum:
        beq $t0,$s1,end
        sll $t2,$t0,2
        lw $t3,arr($t2)
        add $t1,$t1,$t3
        addi $t0,$t0,1
        j sum

    end:

        li $v0,4
        la $a0,msg3
        syscall
        li $v0,1
        move $a0,$t1
        syscall

        li $v0,10
        syscall





