FLAG_ROWS = 6
FLAG_COLS = 12

	.data
flag:
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

# if flag is char[] then flag[i] = flag + i
# flag[0][i] = flag + i
# flag[r][c] = flag + r * NUM_COLS + c

# in general
# int_array[r][c] = int_array + (r * NUM_COLS * 4) + (c * 4)
# -------------------------------------------------------
# int_array[r][c] = int_array + (r * NUM_COLS + c) * 4



	.text
main:

	# row = $t0, col = $t1
	li	$t0, 0
row_loop:
	bge	$t0, FLAG_ROWS, row_loop_end	
	li	$t1, 0
col_loop:
	bge	$t1, FLAG_COLS, col_loop_end	

	# load flag[row][col] and print it
	la	$t3, flag
	mul	$t5, $t0, FLAG_COLS # r * NUM_COLS
	add	$t3, $t3, $t5 # $t3 = flag + r * NUM_COLS
	add	$t3, $t3, $t1 # $t3 = &flag[row][col]

	lb	$a0, 0($t3) # $t4 = flag[row][col]
	li	$v0, 11
	syscall

	add	$t1, $t1, 1
	j	col_loop
col_loop_end:

	li	$a0, '\n'
	li	$v0, 11
	syscall

	add	$t0, $t0, 1
	j	row_loop
row_loop_end:



	li	$v0, 0
	jr	$ra
