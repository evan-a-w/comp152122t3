	.text

	# int x in $t0, int y in $t1
main:
	li	$v0, 4
	la	$a0, str # load the address of the string into $a0
	syscall

	li	$v0, 5 # read int
	syscall	# after this, $v0 has an integer in it
	move	$t0, $v0 # x = read in int

	mul	$t1, $t0, $t0 # $t1 = $t0 * $t0 - mul = multiplication

	move	$a0, $t1
	li	$v0, 1
	syscall

	li	$a0, '\n'
	li	$v0, 11
	syscall

	li	$v0, 0
	jr	$ra

	.data
str:
	# ascii z - zero terminated - null terminated
	.asciiz "Enter a number: "
	.word 4 # number 4 here
	.byte 4
	.space 100

