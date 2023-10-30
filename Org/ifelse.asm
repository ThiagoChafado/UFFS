	.data
x:	.space	4
y:	.word	-5
z:	.space	4

	.text
main:
	la t0,x
	lw s0,0(t0)
	la t1,y
	lw s1,0(t1)
	bgt s0,s1,maior

else:
	li t2,-10
	j fim

maior:
	li t2,10

fim:
	la t3,z
	sw t2,0(t3)
