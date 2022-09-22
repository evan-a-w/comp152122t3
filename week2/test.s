main:
before:
	# l stands for load, i stands for immediate
	li	$t0, 1 # x in $t0
	li	$t1, 2 # y in $t1
after:

	# li	$t3, '\n'
	# la	$t2, main # load address of str into $t2
	# move	$t3, $t0 # $t3 = $t0

	# add $t0 and $t1 and store in $t2
	add	$t2, $t0, $t1 # z in $t2

	li	$v0, 1
	move	$a0, $t2
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

	li	$v0, 0	
	jr	$ra

# int main(void) {
#	int x = 0;
#	int y = 2;
#	// int z = x + y;
#	x = x + y;
# 	return 0;
# }
