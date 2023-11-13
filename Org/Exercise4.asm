	.data
	
vec1:	.word 	3,5,7,8,10
vec2: 	.word	5,2,1,8,6
size:	.word	5
	.text
	
main:
	#a0,a1,a2 endereço vetores
	#a3 tamanho
	li a7,9
	la t0,size
	li t4,4
	
	#multiplicar 
	mul t3,t0,t4
	
	lw a3,0(t0)
	add t0,t3,zero
	ecall
	
	add a2,a0,zero	#Endereço C
	add s5,a2,zero 	#Salvando pra usar no fim
	la a0,vec1	#Endereço A
	la a1,vec2	#Endereço B
	
	
	
init:
	
	#t0 = x=0
	li t0,0
	
for:
	beq t0,a3,endFor
	lw s1,0(a0)#A
	lw s2,0(a1)#B
	lw t3,0(a2)#C
	call checks
	
	addi a0,a0,4
	addi a1,a1,4 #proximo indice
	addi a2,a2,4
	addi t0,t0,1 #x++
	j for
	
checks:
	bgt s1,s2,save1#A>B
	bgt s2,s1,save2 #B>A
	beq s1,s2,save0 #B=A
	ret
	
save1:
	li t6,1
	sw t6,0(a2)
	ret
save2:
	li t6,-1
	sw t6,0(a2)
	ret
save0:
	li t6,0
	sw t6,0(a2)
	ret
endFor:
	li t0,0
	add a1,s5,zero
	
endFor2:
	beq t0,a3,exit
	li a7,1
	lw t1,0(a1)
	add a0,t1,zero
	ecall
	addi t0,t0,1
	addi a1,a1,4
	j endFor2

exit:
	li a7,10
	ecall
	

	