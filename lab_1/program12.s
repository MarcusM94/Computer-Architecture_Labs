.data
	array: .word 24
	message: .asciiz "The highest number is: "
	prompt: .asciiz "Enter a number: "

.text

	# Find the highest number in the array above
	
	# $t0 = Index of loop in bits
	
	# $s0 = Max variable
	# $s1 = Temp variable to hold the value of current index of array
	
	
	main:
		# Initate som values to 0
		addi $t0, $zero, 0
		addi $s0, $zero, 0
		
		jal initiateArray
		
		# Start loop
		jal while
	
	initiateArray:
		# While i != 6
		beq $t0, 24, exit1
		
		li $v0, 4
		la $a0, prompt
		syscall
		
		li $v0, 5
		syscall
		
		sw $v0, array($t0)
		addi $t0, $t0, 4
		
		j initiateArray
		
		arrayComplete:
		jr $ra
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
		
	exit1:
		addi $t0, $zero, 0
		
		li $v0, 1
		addi $a0, $zero, 23
		syscall
		
		j arrayComplete
	updateMax:
		move $s0, $s1
		jr $ra
