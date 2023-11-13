	.data
vector:	.word	3,-5,10,5,7,1
size:	.word	6
	.text

main:
	#a0 - endereco vector
	#a1 - tamanho vetor
	
	la a0,vector
	la t0,size
	lw a1,0(t0)
	li tp,-1
	
	
init:
	#t0 -> x=0
	li t0,0
	
for:
	beq t0,a1,endFor
	lw t2,0(a0)
	blt tp,zero,first
	call checks
	addi a0,a0,4
	
	addi t0,t0,1   #x++
	j for
	
checks:
	#t3=maior atual
	#t2=atual valor comparado
	bgt t2,t3,saveGreater
	ret

first:
	add t3,t2,zero
	mv tp,zero
	j for
	
saveGreater:
	add t3,t2,zero
	ret
	
endFor:	
	add a0,t3,zero
	li a7,1
	ecall 
	
	
