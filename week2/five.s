	.text
SQUARE_MAX = 46340

	# int x in $t0, int y in $t1
main:
	li	$v0, 4
	la	$a0, str # load the address of the string into $a0
	syscall

	li	$v0, 5 # read int
	syscall	# after this, $v0 has an integer in it
	move	$t0, $v0 # x = read in int

if_statement:
	bgt	$t0, SQUARE_MAX, greater


	mul	$t1, $t0, $t0 # $t1 = $t0 * $t0 - mul = multiplication
	move	$a0, $t1
	li	$v0, 1
	syscall
	li	$a0, '\n'
	li	$v0, 11
	syscall

	b	skip_greater

greater:
	li	$v0, 4
	la	$a0, greater_str 
	syscall

skip_greater:

	li	$v0, 0
	jr	$ra

	.data
str:
	.asciiz "Enter a number: "
greater_str:
	.asciiz "square too big for 32 bits\n"

