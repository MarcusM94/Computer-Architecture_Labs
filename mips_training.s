.data

.text
	main:
	 jal func_1
	 
	 
	 
	 li $v0, 10
	 syscall
	 
	
	func_1:
	
		addi $sp, $sp, -8
		sw $s0, 0($sp)
		sw $ra, 4($sp)					# Sparar addressen till att gå tillbaka till main i stacken, tar addressen från $ra
		addi $s0, $zero, 50
		
		jal func_2
		
		lw $ra, 4($sp)					# Ger tillbaka $ra gamla värdet
		jr $ra
		
	
	func_2:
	
		li $v0, 1
		move $a0, $s0
		syscall
		
		jr $ra
