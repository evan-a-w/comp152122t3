main:
	j	here # jumps to here (goto here;)
	b	here

	blt	$t0, $t1, here # branches if $t0 < $t1
	bge	$t0, $t1, here # branches if $t0 >= $t1
	# if ($t0 < $t1) {
	# 	goto here;
	# }
here:

	li	$v0, 0
	jr	$ra
