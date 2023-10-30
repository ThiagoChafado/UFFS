	.data
	
number:	.asciz	"Type the value of y:"


	.text
	
	la a0,number
	li a7,4
	ecall
	li a7,5
	ecall 
	li a7,1
	ecall