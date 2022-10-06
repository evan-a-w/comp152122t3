// int sum_to_n(int n) {
//     if (n == 0 || n == 1) {
//         return 1;
//     }
// 
//     return n + sum_to_n(n - 1);
// }

	.text
sum_to_n: # takes int n in $a0
sum_to_n__prologue:
	beq	$a0, 0, return_one
	beq	$a0, 1, return_one
	j	dont_return_one

return_one:
	li	$v0, 1
	j	sum_to_n__epilogue
dont_return_one:

	# compute sum_to_n(n - 1)
	sub	$a0, $a0, 1
	jal	sum_to_n # in $v0 is sum_to_n(n - 1)

	# now its no different to a regular, non recursive function


sum_to_n__epilogue:
	jr	$ra
