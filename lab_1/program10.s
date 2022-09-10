.data
	prompt: .asciiz "Enter the first integer: "
	prompt2: .asciiz "\nEnter the second integer: "
	answerMessage: .asciiz "\nThe highest number is: \n"
.text
	main:
	
	# $s0 the first entered number
	# $s1 the second entered number
	# $s2 the biggest number
	# $t0 will be 0 or 1 after conditional statements
	
	
	
	# Get two integers from the user
	jal Read_Int
	
	
	# If the numbers are equal, print one of the numbers
	seq $t0, $s0, $s1
	move $s2, $s0
	bne $t0, $zero, Print_Int
	
	
	# If the last number is the highest print that
	sgt $t0, $s0, $s1	
	move $s2, $s0			
	bne $t0, $zero, Print_Int


	# If the first number is the highest print that
	sgt $t0, $s1, $s0
	move $s2, $s1
	bne $t0, $zero, Print_Int
		

	Read_Int:
		# Get first integer
		li $v0, 4
		la $a0, prompt
		syscall
		
		li $v0, 5
		syscall
		
		move $s0, $v0		
		
		# Get second integer
		li $v0, 4
		la $a0, prompt2
		syscall
		
		li $v0, 5
		syscall
		
		move $s1, $v0 		
		
		# Return to main
		jr $ra
	
	Print_Int:
		li $v0, 4
		la $a0, answerMessage
		syscall

		li $v0, 1
		move $a0, $s2
		syscall
		
		# End the program here after printing as we only want to print once, hence why no "jr $ra"
		li $v0, 10
		syscall
