.data

.text
	main:
	 addi $t0, $zero, 5
	 add $a0, $zero, $t0
	 syscall
	 
	 
	 jal func_1
	
	 add $a0, $zero, $t0
	 syscall
	 
	 li $v0, 10
	 syscall
	 
	
	func_1:
	
		addi $t2, $zero, 12
		move $t0, $t2
		jr $ra
		
	
	func_2:
	
		li $v0, 1
		move $a0, $s0
		syscall
		
		jr $ra
