	.data
vetor:	.word	-3,5,11,7,4,-6
tamanho:.word	6

	.text
main:
	la a0,vetor
	la t0,tamanho
	lw a1,0(t0)
	call ordena
	li a7,10
	ecall
	
ordena:
	li t0,0
	
laco_ext:
	beq t0,a1,fim_ordena
	addi t1,t0,1

laco_int:
	beq t1,a1,fim_laco_int
	slli s0,t0,2
	add s0,a0,s0
	slli s1,t1,2
	add s1,a0,s1
	lw s2,0(s0)
	lw s3,0(s1)
	bgt s3,s2,prox_interno
	sw s3,0(s0)
	sw s2,0(s1)
	
prox_interno:
	addi t1,t1,1
	j laco_int
	
fim_laco_int:
	addi t0,t0,1
	j laco_ext
fim_ordena:
	ret
	