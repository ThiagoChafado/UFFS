	.data
vector:	.word	3,5,8,1,2,6
size:	.word	6
pairString: .asciz "\nPairs:"
umpairString: .asciz	"\nUnpairs:"

	.text
	
main:
	#s1 pair
	#s2 umpair
	li s1,0
	li s2,0
	la a0,vector
	la a1,size
	lw t0,0(a1)
	call function
	j print
	#godbolt.org
function:
	j init
init:
	li  t1,0
	
for:
	beq t1,t0,endFor
	lw t2,0(a0)
	addi a0,a0,4
	addi t1,t1,1
	j divider
	
	
divider:
	li tp,2
	rem s0,t2,tp
	beq s0,zero,acumulatorPair
	
acumulatorUmpair:
	addi s2,s2,1
	j for
	
acumulatorPair:
	addi s1,s1,1
	j for
	
endFor:
	ret

print:
	la a0,pairString
	li a7,4
	ecall
	add a0,s1,zero
	li a7,1
	ecall
	la a0,umpairString
	li a7,4
	ecall
	add a0,s2,zero
	li a7,1
	ecall
	
	
	