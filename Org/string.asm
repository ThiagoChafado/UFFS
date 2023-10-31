	.data
string: .asciz "palindromo"
	.text
main:
	la a0,string
	
	
init:
	#saves ascii vowels
	li s0,97
	li s1,101
	li s2,105
	li s3,111
	li s4,117
	li tp,0
	call findLenght
	la a0,string
	add a1,t5,zero
	add t6,t5,zero
for:
	
	lb t2,0(a0)
	beq t2,zero,end
	call checks
	addi a0,a0,1
	
	j for
	
	
checks:
	
	beq t2,s0,return
	beq t2,s1,return
	beq t2,s2,return
	beq t2,s3,return
	beq t2,s4,return
	j addLetter
	
	
addLetter:
	sb t2,0(a1)
	addi a1,a1,1

return:
	ret
	
findLenght:
	lb t2,0(a0)
	beq t2,zero,endLenght
	addi a0,a0,1
	addi tp,tp,1
	j findLenght

endLenght:
	add a0,tp,zero
	li a7,9
	ecall
	#t5 is the lenght
	add t5,a0,zero
	ret

end:
	li a7,4
	add a0,t6,zero
	ecall
	li a7,10
	ecall
