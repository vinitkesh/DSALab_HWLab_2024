# 3. Check whether the given positive number is a palindrome or not.

# print prompt to take input
# take input from user

# s0 = n
# t0 = n
# t1 = 0

# do: 
# 	t1 = t1*10 + t0%10
# 	t0 = t0/10
# while(t0>0);

.data 

    prompt: .asciiz "Enter a number: "
    is: .asciiz "the number is a palindrome"
    not:  .asciiz "the number is not a palindrome"

.text 


    # printing prompt
    li $v0 , 4
    la $a0,prompt
    syscall

    # taking input
    li $v0,5
    syscall

    move $s0,$v0 # s0 = n
    add $t0,$zero,$s0 # t0 = n
    li $t1,0 # t1 = 0
    

    do:
    mul $t1,$t1,10       # t1 = t1 * 10
    div $t0,$t0,10       # t0 = t0 / 10
    mfhi $s1             # s1 = t0 % 10 (remainder)
    add $t1,$t1,$s1      # t1 = t1 * 10 + s1 (add current digit)
    bgt $t0,$zero,do     # loop while t0 != 0


    beq $t1,$s0,printIs

    printNot:
        li $v0,4
        la $a0,not
        syscall
        j end

    printIs:
        li $v0,4
        la $a0,is
        syscall

    end:
        li $v0,10
        syscall
