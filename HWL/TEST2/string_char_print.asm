# q9 Find the nth Fibonacci number for the given number n.

# print prompt
# 
# get input from user
# for loop 0 to n
#     if i == 0
#         fib = 0
#     else if i == 1
#         fib = 1
#     else
#         fib = fib + fib2
#         fib2 = fib
# print fib

.data 
    prompt: .asciiz "Enter the number n: "
    fib: .asciiz "The nth Fibonacci number is: "

    prev: .word 0
    prev1: .word 1

.text
    main:
        li $v0, 4 # print prompt
        la $a0, prompt
        syscall

        li $v0, 5 # get input from user
        syscall

        move $t0, $v0 # t0 = n
 
        li $t1, 0 # t1 = 0 ,  counter
        li $t2, 0 # t2 = 0 , prev
        li $t3, 1 # t3 = 1 , prev1

        li $t4, 0 # t4 = 0 , answer

        beqz $t0,  end # if n == 0, print 0

        loop:
            beq $t1, $t0, end
            add $t4, $t2, $t3

            addi $t3, $t2, 0
            addi $t2, $t4, 0

            addi $t1, $t1, 1
            j loop
        
        end:
            li $v0, 4 # print output string
            la $a0, fib
            syscall

            li $v0, 1 # print nth fib number
            move $a0, $t4
            syscall

            li $v0, 10
            syscall