N_SIZE = 10

	.data
numbers:
	.align 2
	.word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9

	.text
main:
	li	$t0, 0 # i in $t0

loop:
	# break if i >= N_SIZE	
	bge	$t0, N_SIZE, end

	# if (numbers[i] < 0)
	mul	$t2, $t0, 4 # i * 4 in $t2
	lw	$t1, numbers($t2) # $t1 = numbers[i]
	
	bge	$t1, 0, dont_add
add_42:
	add	$t1, $t1, 42
	sw	$t1, numbers($t2) # numbers[i] = $t1

dont_add:
	add	$t0, $t0, 1 # i++;
	b loop
end:

	# numbers[5] == -5 + 42 == 37
	lw	$a0, numbers + 20 # $t0 = numbers[5]
	li	$v0, 1	
	syscall
	
	li	$v0, 0
	jr	$ra
