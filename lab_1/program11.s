.data
	message: .asciiz "The highest number is: "
	array: .word 5, 6, 3, 11, 2, 9

.text

	# Find the highest number in the array above
	
	# $t0 = Index of loop in bits
	
	# $s0 = Max variable
	# $s1 = Temp variable to hold the value of current index of array
	
	
	main:
		# Initate som values to 0
		addi $t0, $zero, 0
		addi $s0, $zero, 0
		
		# Start loop
		jal while
	
	while: 
		# While i != 6
		beq $t0, 24, exit
		
		# x = arr[i]
		lw $s1, array($t0)
		
		# i++
		addi $t0, $t0, 4
		
		# If $s1 > $s0
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
