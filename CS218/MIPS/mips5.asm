###########################################################################
#  Name: Eduardo Salazar
#  NSHE ID: 5005695833
#  Section: 1003
#  Assignment: MIPS #5
#  Description: use recursion to determine how many ways to traverse a grid


###########################################################################
#  data segment

.data

# -----
#  Constants

TRUE = 1
FALSE = 0
COORD_MAX = 100

# -----
#  Variables for main

hdr:		.ascii	"\n**********************************************\n"
		.ascii	"\nMIPS Assignment #5\n"
		.asciiz	"Count Grid Paths Program\n"

startRow:	.word	0
startCol:	.word	0
endRow:		.word	0
endCol:		.word	0

totalCount:	.word	0

endMsg:		.ascii	"\nYou have reached recursive nirvana.\n"
		.asciiz	"Program Terminated.\n"

# -----
#  Local variables for prtResults() function.

cntMsg1:	.asciiz	"\nFrom a start coordinate of ("
cntMsgComma:	.asciiz	","
cntMsg2:	.asciiz	"), to an end coordinate of ("
cntMsg3:	.asciiz	"), \nthere are "
cntMsg4:	.asciiz	" ways traverse the grid.\n"

# -----
#  Local variables for readCoords() function.

strtRowPmt:	.asciiz	"  Enter Start Coordinates ROW: "
strtColPmt:	.asciiz	"  Enter Start Coordinates COL: "

endRowPmt:	.asciiz	"  Enter End Coordinates ROW: "
endColPmt:	.asciiz	"  Enter End Coordinates COL: "

err0:		.ascii	"\nError, invalid coordinate value.\n"
		.asciiz	"Please re-enter.\n"

err1:		.ascii	"\nError, end coordinates must be > then "
		.ascii	"the start coordinates. \n"
		.asciiz	"Please re-enter.\n"

spc:		.asciiz	"   "

# -----
#  Local variables for prtNewline function.

newLine:	.asciiz	"\n"


###########################################################################
#  text/code segment

.text
.globl main
.ent main
main:

# -----
#  Display program header.

	la	$a0, hdr
	li	$v0, 4
	syscall					# print header

# -----
#  Function to read and return initial coordinates.

	la	$a0, startRow
	la	$a1, startCol
	la	$a2, endRow
	la	$a3, endCol
	jal	readCoords

# -----
#  countPaths - determine the number of possible
#		paths through a two-dimensional grid.
#	returns integer answer.

#  HLL Call:
#	totalCount = countPaths(startRow, startCol, endRow, endCol)

	lw	$a0, startRow
	lw	$a1, startCol
	lw	$a2, endRow
	lw	$a3, endCol
	jal	countPaths
	sw	$v0, totalCount

# ----
#  Display results (formatted).

	lw	$a0, startRow
	lw	$a1, startCol
	lw	$a2, endRow
	lw	$a3, endCol
	subu	$sp, $sp, 4
	lw	$t0, totalCount
	sw	$t0, ($sp)
	jal	prtResults
	addu	$sp, $sp, 4

# -----
#  Done, show message and terminate program.

	li	$v0, 4
	la	$a0, endMsg
	syscall

	li	$v0, 10
	syscall					# all done...
.end main

# =========================================================================
#  Very simple function to print a new line.
#	Note, this routine is optional.

.globl	prtNewline
.ent	prtNewline
prtNewline:
	la	$a0, newLine
	li	$v0, 4
	syscall

	jr	$ra
.end	prtNewline

# =========================================================================
#  Function to print final results (formatted).

# -----
#    Arguments:
#	startRow, value - a0
#	startCol, value - a1
#	endRow, value - a2
#	endCol, value - a3
#	totalCount, value - ($fp)
#    Returns:

.globl	prtResults
.ent	prtResults
prtResults:

	subu $sp, $sp, 24
	sw	$fp, ($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	sw	$s2, 12($sp)
	sw	$s3, 16($sp)
	sw	$s4, 20($sp)
	addu $fp, $sp, 24

	move $s0, $a0						# get start row value
	move $s1, $a1						# get start col value
	move $s2, $a2						# get end row value
	move $s3, $a3						# get end col value
	lw $s4, ($fp)						# get totat count value

	la	$a0, newLine
	li	$v0, 4
	syscall

	la	$a0, cntMsg1					# address of message 1
	li	$v0, 4							# call code print string
	syscall

	move $a0, $s0						# start row
	li	$v0, 1							# call code to print int
	syscall

	la	$a0, cntMsgComma				# comma address
	li	$v0, 4							# print string call code
	syscall

	move $a0, $s1						# start col
	li	$v0, 1							# call code print int
	syscall

	la	$a0, cntMsg2					# address of message 2
	li	$v0, 4							# call code string
	syscall

	move $a0, $s2						# end row
	li	$v0, 1							# call code print int
	syscall

	la	$a0, cntMsgComma				# comma address
	li	$v0, 4							# print string call code
	syscall

	move $a0, $s3						# end col
	li	$v0, 1							# print int call code
	syscall

	la	$a0, cntMsg3					# address of message 3
	li	$v0, 4							# print string call code
	syscall

	move $a0, $s4						# count
	li	$v0, 1							# print int call code
	syscall

	la	$a0, cntMsg4					# address of message 4
	li	$v0, 4							# print string call code
	syscall

	lw	$s4, 20($sp)
	lw	$s3, 16($sp)
	lw	$s2, 12($sp)
	lw	$s1, 8($sp)
	lw	$s0, 4($sp)
	lw	$fp, ($sp)
	addu $sp, $sp, 24

	jr	$ra
.end	prtResults

# =========================================================================
#  Prompt for and read start and end coordinates.
#  Also, must ensure that:
#	each value is between 0 and COORD_MAX
#	start coordinates are < end coordinates

# -----
#    Arguments:
#	startRow, address
#	startCol, address
#	endRow, address
#	endCol, address
#    Returns:
#	startRow, startCol, endRow, endCol via reference

.globl	readCoords
.ent	readCoords
readCoords:

	subu $sp, $sp, 20
	sw	$s0, ($sp)						# preserve registers
	sw	$s1, 4($sp)
	sw	$s2, 8($sp)
	sw	$s3, 12($sp)
	sw	$s4, 16($sp)

	move $s0, $a0						# get startRow address
	move $s1, $a1						# get startCol address
	move $s2, $a2						# get endRow address
	move $s3, $a3						# get endCol address
	li	$s4, COORD_MAX					# get max cord value

rowInput:

	la	$a0, strtRowPmt					# address to print prompt message
	li	$v0, 4							# call code to print string
	syscall

	move $a0, $s0						# address to store start row
	li	$v0, 5							# call code to read int
	syscall

	bge	$v0, $s4, cordErr				# if input > MAX
	bge	$v0, $zero, ErrSkip				# if input > 0
cordErr:

	la	$a0, err0						# error address 1
	li	$v0, 4							# call code to print string
	syscall
	j	rowInput
ErrSkip:								# skip if input is valid
	sw	$v0, ($s0)						# store answer in startRow

colInput:

	la	$a0, strtColPmt					# address to print prompt message
	li	$v0, 4							# call code to print string
	syscall

	move $a0, $s1						# address to store start col
	li	$v0, 5							# call code to read int
	syscall

	bge	$v0, $s4, cordErr2			# if input > MAX
	bge	$v0, $zero, ErrSkip2			# if input > 0
cordErr2:

	la	$a0, err0						# error address 1
	li	$v0, 4							# call code to print string
	syscall
	j	colInput
ErrSkip2:								# skip if input is valid
	sw	$v0, ($s1)						# store answer in startCol	

rowInput2:

	la	$a0, endRowPmt					# address to print prompt message
	li	$v0, 4							# call code to print string
	syscall

	move $a0, $s2						# address to store start row
	li	$v0, 5							# call code to read int
	syscall

	bge	$v0, $s4, cordErr3				# if input > MAX
	bge	$v0, $zero, ErrSkip3				# if input > 0
cordErr3:

	la	$a0, err0						# error address 1
	li	$v0, 4							# call code to print string
	syscall
	j	rowInput2
ErrSkip3:								# skip if input is valid
	sw	$v0, ($s2)						# store answer in startRow

colInput2:

	la	$a0, endColPmt					# address to print prompt message
	li	$v0, 4							# call code to print string
	syscall

	move $a0, $s3						# address to store start col
	li	$v0, 5							# call code to read int
	syscall

	bge	$v0, $s4, cordErr4			# if input > MAX
	bge	$v0, $zero, ErrSkip4			# if input > 0
cordErr4:

	la	$a0, err0						# error address 1
	li	$v0, 4							# call code to print string
	syscall
	j	colInput2
ErrSkip4:								# skip if input is valid
	sw	$v0, ($s3)						# store answer in startCol
#	-----

	lw	$t0, ($s0)						# get start row
	lw	$t1, ($s2)						# get end row
	bge	$t0, $t1, rangeErr

	lw	$t0, ($s1)						# get end col
	lw	$t1, ($s3)						# get end col
	bge	$t0, $t1, rangeErr

	j	endFunc							# jump to end function
rangeErr:

	la	$a0, err1						# error address 2
	li	$v0, 4							# call code to print string
	syscall

	j	rowInput						# jump to top of function
endFunc:

	lw	$s4, 16($sp)
	lw	$s3, 12($sp)
	lw	$s2, 8($sp)
	lw	$s1, 4($sp)
	lw	$s0, ($sp)
	addu $sp, $sp, 20					# restore registers

	jr	$ra
.end	readCoords

#####################################################################
#  Function to recursivly determine the number of possible
#  paths through a two-dimensional grid.
#  Only allowed moves are one step to the right or one step down.  

#  HLL Call:
#	totalCount = countPaths(startRow, startCol, endRow, endCol)

# -----
#  Arguments:
#	startRow, value	- a0
#	startCol, value - a1
#	endRow, value - a2
#	endCol, value - a3

#  Returns:
#	$v0 - paths count

.globl	countPaths
.ent	countPaths
countPaths:

	subu $sp, $sp, 28
	sw	$s0, ($sp)
	sw	$s1, 4($sp)
	sw	$s2, 8($sp)
	sw	$s3, 12($sp)
	sw	$s4, 16($sp)
	sw	$s5, 20($sp)
	sw	$ra, 24($sp)						# save registers

	move $s0, $a0							# get start row value
	move $s1, $a1							# get start col value
	move $s2, $a2							# get end row value
	move $s3, $a3							# get end col value

	bgt	$s0, $s2, retZer					# check to return 0
	bgt	$s1, $s3, retZer					# check to return 0

	beq	$s0, $s2, retOne					# check to return 1
	beq	$s1, $s3, retOne					# check to return 1

	move $a0, $s0
	move $a1, $s1
	addu $a1, $a1, 1						# column++
	move $a2, $s2
	move $a3, $s3
	jal	countPaths							# call recursive function
	move $s4, $v0							# store return in $s4
	
	move $a0, $s0
	addu $a0, $a0, 1						# row++ 
	move $a1, $s1
	move $a2, $s2
	move $a3, $s3
	jal	countPaths							# call recursive function
	move $s5, $v0							# store return in $s5

	add	$v0, $s4, $s5						# add recursive functions together

	j	funcEnd

retZer:
	li	$v0, 0								# set return to 0
	j	funcEnd
retOne:
	li	$v0, 1								# set return to 1
funcEnd:

	lw	$ra, 24($sp)						# restore register
	lw	$s5, 20($sp)
	lw	$s4, 16($sp)
	lw	$s3, 12($sp)
	lw	$s2, 8($sp)
	lw	$s1, 4($sp)
	lw	$s0, ($sp)
	add	$sp, $sp, 28

	jr	$ra
.end countPaths

#####################################################################

