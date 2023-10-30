	.data
number:	.asciz 	"\n Type the value of N:"
greater:.asciz "\n The greater is:" 
smaller:.asciz "\n The smaller is:"
avg:	.asciz "\n The avg is:"
	.text
main:
	li t3,0
	li tp, -1
	li t5,0
	li t6,0
	
	
while:
	la a0,number
	li a7,4
	ecall
	li a7,5
	ecall
	add t1,a0, zero
	blt tp, zero, init
	j checks
	
init:
	add t4,t1,zero
	add t3,t1,zero
	add t5,t1,zero
	addi t6,t6,1
	mv tp, zero
	j while

checks:
	blt t1,zero,end
	bgt t1,t3,saveGreater
	blt t1,t4,saveSmaller
	addi t6,t6,1
	add t5,t5,t1
	j while
	
saveSmaller:
	add t4,t1,zero
	add t5,t5,t1
	addi t6,t6,1
	j while
saveGreater:
	add t3,t1,zero
	add t5,t5,t1
	addi t6,t6,1
	j while
	
end:
	#print greater
	la a0,greater
	li a7,4
	ecall
	add a0,t3,zero
	li a7,1
	ecall
	#print smaller
	la a0,smaller
	li a7,4
	ecall
	add a0,t4,zero
	li a7,1
	ecall
	#print avg
	la a0,avg
	li a7,4
	ecall
	div a0,t5,t6
	li a7,1
	ecall
