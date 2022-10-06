# int fn(int a, int b)
# fn(1, 2)
# 

main:
main__prologue:
	push	$ra # on the top of the stack is the value of $ra
	push	$s0 # save old value of $s0

main__body:
	li	$s0, 1 # modify $s0 (but we know the old value so this is fine)

	li	$s1, 2 # THIS IS WRONG BECAUSE WE HAVE MODIFIED AN S REGISTER AND HAVE NOT SAVED IT
	# (we violate the function calling conventions)
	# we dont know if a function that uses $s1 will call our function

	# as a caller, your $s registers should stay the same
	# (if this doesnt happen theres a bug in your code (you arent saving and restoring $s registers you use))

	li	$a0, 1
	li	$a1, 2
	jal	fn	# jal sets $ra to be the next instruction

	# jal is equivalent to
	# $ra = next insturction
	# j fn

	# result in $v0; $v0 = fn(1, 2)

	# $s0 should still be 1
	# $a0 may not be 1 now

	# NEVER jr $ra in the middle, always jump to the epilogue if were returning

	# POP IN REVERSE ORDER BECAUSE OF HOW STACKS OPERATE
main__epilogue:
	pop	$s0 # restore $s0 (take the value off the top of the stack and put in $s0)
	pop	$ra # restore $ra (take the value off the top of the stack and put in $ra)

	li	$v0, 0
	jr	$ra # $ra stores where we need to return to
	# $ra is wrong here because we used jal
	# return 


fn: # leaf function, no need to push and pop $ra (we dont change $ra with a jal)
	li	$v0, 2

	jr	$ra



# after calling a function, all $s registers should not have changed
# all other registers may have changed


# IF WERE IN A FUNCTION AND WE CALL A FUNCTION WE NEED TO PUSH AND POP $ra
# its easier if we also do pushes at the beginning of the function and pops at the end


# whenever we want a value to stay the same after a function call, we need to use a $s register
# (these are guaranteed to the same)
# USE PUSH AND POP TO SAVE AND RESTORE



# FOLLOW THESE RULES AND UR FINE
# if we use jal, push and pop $ra (if we use a function within our function)
# if we need a value to be the same after a function call, use the next $s register (starting from 0), and push and pop this
# IF NOT $S REGISTER, NEVER ASSUME THE VALUE WILL STAY THE SAME AFTER A FUNCTION CALL (this is how we get bugs)



# THIS ALSO WORKS
alternate:
	push	$ra
prologue:
	li	$t0, 1
	li	$t1, 2

	# STILL NEED REVERSE ORDER OF PUSH AND POP
	push	$t0	# save $t0
	push	$t1
	jal	fn # may overwrite $t0
	pop	$t1
	pop	$t0	# restore $t0

	push	$t0	# save $t0
	jal	fn # may overwrite $t0
	pop	$t0	# restore $t0

epilogue:
	pop	$ra
	jr	$ra

# THIS ALSO WORKS
alternate:
prologue:
	li	$t0, 1
	li	$t1, 2

	li	$s0, 0

	push	$ra
	jal	fn # may overwrite $t0
	pop	$ra

epilogue:
	jr	$ra
