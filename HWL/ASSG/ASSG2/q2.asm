# q2 : Compute the factorial of a given positive number
# take input number
# store it in s0
# set t0 = 1
# set t1 = 1
# do:
#     t1 = t1 * t0
#     t0 = t0 + 1
# while t1 != s0
# print t1


.data
	prompt: .asciiz "Enter your number: "
	result: .asciiz "Factorial is : "

.text
.globl main
main:
    # Get input value
    li $v0,4    # Print Prompt
    la $a0, prompt
    syscall

    li $v0, 5    # Retrieve input
    syscall
    move $s0, $v0 #s0 has n now

    addi $t0 , $zero , 1 # factorial = 1
    addi $t1 , $zero , 1 # i = 1

    do :
        mul $t0 , $t0 , $t1 # factorial = factorial * i
        addi $t1 , $t1 , 1 # i = i + 1

    ble $t1 , $s0 , do 

    # Print result
    li $v0, 4
    la $a0, result
    syscall

    li $v0, 1
    move $a0, $t0
    syscall



    

  


