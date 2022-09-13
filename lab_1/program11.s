.data
	message: .asciiz "The highest number is: "
	array: .word 5, 6, 3, 11, 2, 9

.text
	
	# $t0 = Index of loop
	
	# $s0 = Max variable
	# $s1 = Temp variable to hold the value of current index of array
	
	
	main:
		addi $t0, $zero, 0
		addi $s0, $zero, 0
		
		jal while
	
	while: 
		beq $t0, 24, exit
		
		lw $s1, array($t0)
		addi $t0, $t0, 4
		
		bgt $s1, $s0, updateMax
		
		j while
	exit: 
		li $v0, 4
		la $a0, message
		syscall
	
		li $v0, 1
		move $a0, $s0
		syscall
		
		li $v0, 10
		syscall
		
		
	updateMax:
		move $s0, $s1
		jr $ra
