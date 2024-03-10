# Find a given element (key) from the input array using a linear search.

# print prompt for array
# input n
# print prompt for array elements
# input array
# print prompt for key
# input key
# for i in range n
# if array[i] == key
# print key found at i
# break
# else
# print -1

.data
prompt: .asciiz "Enter the number of elements in the array: "
prompt2: .asciiz "Enter the elements of the array: "
prompt3: .asciiz "Enter the key to be searched: "
foundp: .asciiz "Key found at index: "
notfound: .asciiz "Key not found"

array: .space 400

.text
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall
    move $t0, $v0 # t0 = n

    li $v0, 4
    la $a0, prompt2

    la $t1, array  # pointer to the array

    syscall
    input_loop: 
        beq $t2, $t0, input_done

        li $v0, 5
        syscall
        sw $v0, ($t1)

        addi $t1, $t1, 4 # incrementing the pointer by 4 bytes
        addi $t2, $t2, 1 # incrementing the counter by 1
        bne $t2, $t0, input_loop
    input_done:

    la $t1, array # reset the pointer to the start of the array
    
    li $v0, 4
    la $a0, prompt3
    syscall

    li $v0, 5
    syscall
    move $t3, $v0 # t3 = key

    li $t4, 0 # t4 = i

    for_loop:
        beq $t4, $t0, not_found
        lw $t5, ($t1)
        beq $t5, $t3, found
        addi $t1, $t1, 4
        addi $t4, $t4, 1
        bne $t4, $t0, for_loop
    not_found:
        li $v0, 4
        la $a0, notfound

        syscall
        j end
    found:
        li $v0, 4
        la $a0, foundp
        syscall
        
        li $v0, 1
        move $a0, $t4
        syscall

        j end

    end:
        li $v0, 10
        syscall
