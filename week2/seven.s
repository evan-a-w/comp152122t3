main:
	subi	$sp, $sp, 16
	sw	$s0, 0($sp)
	sw	$s1, 4($sp)
	sw	$s2, 8($sp)
	sw	$s3, 12($sp)

	li	$t0, 24 # x = 24
loop:
	bge	$t0, 42, after_loop

	move	$a0, $t0
	li	$v0, 1
	syscall

	li	$a0, '\n'
	li	$v0, 11
	syscall

	add	$t0, $t0, 3
	j	loop # or b loop
after_loop:	

	lw	$s0, 0($sp)
	lw	$s1, 4($sp)
	lw	$s2, 8($sp)
	lw	$s2, 12($sp)
	addi	$sp, $sp, 16

	li	$v0, 0
	jr	$ra
