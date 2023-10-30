	.data
z: 	.word 	0
x:	.word	10
msg: 	.ascii 	"Result: "

	.text
main:
	la t0,z
	lw s0,0(t0)
	la t1,x
	lw s1,0(t1)
	
	
test:	
	beq s1,zero,endLoop
	add s0,s0,s1
	addi s1,s1,-1
	j test
	
endLoop:
	sw s0,0(t0)
	la a0,msg
	li a7,4
	ecall
	mv a0,s0
	li a7,1
	ecall 