	.data
numbers:
	.align 2
	.word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9

lw	$t0, numbers # int *numbers; $t0 = *numbers;
sw	$t0, numbers # *numbers = $t0
lb	$t0, numbers # char *numbers; (load one byte from the address)
sb	$t0, numbers

lw	$t0, ($t1)	# $t1 is an int pointer
# save numbers[3] into t0

# calculate &numbers[3] (the address of numbers[3])
# address of numbers[3] = &numbers[3] = numbers + 3 * 4 = numbers + 12
lw	$t0, numbers + 12 # $t0 = numbers[3]


# i is in $t1
# load numbers[i] into $t0
# lw	$t0, numbers + i * 4

mul	$t2, $t1, 4 # i * 4 in $t2
# add	$t2, $t2, numbers # i think this doesn't work
la	$t3, numbers # address of numbers -> $t3
add	$t2, $t3, $t2 # numbers + i * 4 in $t2
lw	$t0, ($t2) # numbers[i] is in $t0


# nicest way
mul	$t2, $t1, 4 # i * 4 in $t2
lw	$t0, numbers($t2)

# &arr[i] = arr + i * element_size





# 1 2 3
# 4 5 6
# works as 1 2 3 4 5 6
# int arr[2][3]; rows are stored sequentially in memory
# arr[1][1] = 1;
# arr + (1 * 3 + 1) * 4
# 
# arr[r][c] = arr + (r * col_count + c) * element_size (DONT REMEMBER)
# 
# int *arr[2] is different
