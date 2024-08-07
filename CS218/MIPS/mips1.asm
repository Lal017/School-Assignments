###########################################################################
#  Name: Eduardo Salazar
#  NSHE ID: 5005695833
#  Section: 1003
#  Assignment: MIPS #1
#  Description: calculate the areas of hexagons and then find the min, max, sum etc.


################################################################################
#  data segment

.data

sideLens:
	.word	  15,   25,   33,   44,   58,   69,   72,   86,   99,  101
	.word	 369,  374,  377,  379,  382,  384,  386,  388,  392,  393
	.word	 501,  513,  524,  536,  540,  556,  575,  587,  590,  596
	.word	 634,  652,  674,  686,  697,  704,  716,  720,  736,  753
	.word	 107,  121,  137,  141,  157,  167,  177,  181,  191,  199
	.word	 102,  113,  122,  139,  144,  151,  161,  178,  186,  197
	.word	   1,    2,    3,    4,    5,    6,    7,    8,    9,   10
	.word	 202,  209,  215,  219,  223,  225,  231,  242,  244,  249
	.word	 203,  215,  221,  239,  248,  259,  262,  274,  280,  291
	.word	 251,  253,  266,  269,  271,  272,  280,  288,  291,  299
	.word	1469, 2474, 3477, 4479, 5482, 5484, 6486, 7788, 8492

apothemLens:
	.word	  32,   51,   76,   87,   90,  100,  111,  123,  132,  145
	.word	 634,  652,  674,  686,  697,  704,  716,  720,  736,  753
	.word	 782,  795,  807,  812,  827,  847,  867,  879,  888,  894
	.word	 102,  113,  122,  139,  144,  151,  161,  178,  186,  197
	.word	1782, 2795, 3807, 3812, 4827, 5847, 6867, 7879, 7888, 1894
	.word	 206,  212,  222,  231,  246,  250,  254,  278,  288,  292
	.word	 332,  351,  376,  387,  390,  400,  411,  423,  432,  445
	.word	  10,   12,   14,   15,   16,   22,   25,   26,   28,   29
	.word	 400,  404,  406,  407,  424,  425,  426,  429,  448,  492
	.word	 457,  487,  499,  501,  523,  524,  525,  526,  575,  594
	.word	1912, 2925, 3927, 4932, 5447, 5957, 6967, 7979, 7988

hexAreas:
	.space	436

len:	.word	109

haMin:	.word	0
haEMid:	.word	0
haMax:	.word	0
haSum:	.word	0
haAve:	.word	0

LN_CNTR	= 7

# -----

hdr:	.ascii	"MIPS Assignment #1 \n"
	.ascii	"Program to calculate area of each hexagon in a series "
	.ascii	"of hexagons. \n"
	.ascii	"Also finds min, est mid, max, sum, and average for the "
	.asciiz	"hexagon areas. \n\n"

new_ln:	.asciiz	"\n"
blnks:	.asciiz	"  "

a1_st:	.asciiz	"\nHexagon min = "
a2_st:	.asciiz	"\nHexagon emid = "
a3_st:	.asciiz	"\nHexagon max = "
a4_st:	.asciiz	"\nHexagon sum = "
a5_st:	.asciiz	"\nHexagon ave = "


###########################################################
#  text/code segment

.text

.globl main
.ent main
main:

# -----
#  Display header.

	la	$a0, hdr
	li	$v0, 4
	syscall				# print header

# --------------------------------------------------

	la	$t0, sideLens					# get address of sideLens
	la	$t1, apothemLens				# get address of apothemLens
	la	$t2, hexAreas					# get address of hexAreas
	li	$t3, 0							# set index
	lw	$t5, len						# get length value
	li	$t6, 0							# set sum to 0

calcLoop:

	bge $t3, $t5, calcExit				# continue loop if index < length

	lw $t6, ($t0)						# get value of sideLens[i]
	lw $t7, ($t1)						# get value of apothemLens[i]
	mul $t4, $t6, $t7					# sideLens[i] * apothemLens[i] = $t4
	div $t4, $t4, 2						# divide by 2
	mul $t4, $t4, 6						# multiply by 6
	sw	$t4, ($t2)						# store answer in hecAreas[i]

	lw	$t9, haMax						# get haMax
	ble	$t4, $t9, isLess				# check if current area less than haMax
	sw	$t4, haMax						# store if greater than
isLess:									# skip if less than

	bne $t3, $zero, minSkip				# check if index is 0
	sw	$t4, haMin						# store if index is 0
minSkip:								# skip if greater than 0
	lw	$t9, haMin						# get haMin
	bge $t4, $t9, isMore				# check if current area is more than haMin
	sw	$t4, haMin						# store if less than
isMore:									# skip if greater than

	add $t8, $t8, $t4					# add to get sum

	add $t0, $t0, 4						# increment address of sideLens
	add $t1, $t1, 4						# increment address of apothemLens
	add $t2, $t2, 4						# increment address of hexAreas
	add $t3, $t3, 1						# increment index
	j calcLoop

calcExit:

	sw	$t8, haSum						# store sum

	div $t8, $t8, $t5					# calculate average
	sw	$t8, haAve						# store average

	la	$t2, hexAreas					# get address of array
	lw	$t1, ($t2)
	lw	$t3, 432($t2)
	add $t3, $t3, $t1
	lw	$t1, 216($t2)
	add	$t3, $t3, $t1					# add up first last and middle value
	div $t3, $t3, 3						# divide sum by 3
	sw	$t3, haEMid

	li	$t0, 0							# index
	li	$t4, 7
	li	$t3, 1							# line count

printLoop:

	beq	$t0, $t5, printExit			# exit loop if i = len

	lw	$a0, ($t2)					# get variable
	li	$v0, 1						# call code to print int
	syscall							# perform system call

	la	$a0, blnks					# get address for space
	li	$v0, 4						# call code for print string
	syscall

	bne $t3, $t4, lineSkip
	la	$a0, new_ln					# print a newline
	li	$v0, 4
	syscall
	li	$t3, 0						# reset line count
lineSkip:

	add $t2, $t2, 4					# increment address
	add $t0, $t0, 1					# increment i
	add $t3, $t3, 1					# increment line count

	j	printLoop

printExit:

##########################################################
#  Display results.

	la	$a0, new_ln		# print a newline
	li	$v0, 4
	syscall
	la	$a0, new_ln		# print a newline
	li	$v0, 4
	syscall

#  Print min message followed by result.

	la	$a0, a1_st
	li	$v0, 4
	syscall				# print "min = "

	lw	$a0, haMin
	li	$v0, 1
	syscall				# print min

# -----
#  Print middle message followed by result.

	la	$a0, a2_st
	li	$v0, 4
	syscall				# print "emid = "

	lw	$a0, haEMid
	li	$v0, 1
	syscall				# print emid

# -----
#  Print max message followed by result.

	la	$a0, a3_st
	li	$v0, 4
	syscall				# print "max = "

	lw	$a0, haMax
	li	$v0, 1
	syscall				# print max

# -----
#  Print sum message followed by result.

	la	$a0, a4_st
	li	$v0, 4
	syscall				# print "sum = "

	lw	$a0, haSum
	li	$v0, 1
	syscall				# print sum

# -----
#  Print average message followed by result.

	la	$a0, a5_st
	li	$v0, 4
	syscall				# print "ave = "

	lw	$a0, haAve
	li	$v0, 1
	syscall				# print average

# -----
#  Done, terminate program.

endit:
	la	$a0, new_ln		# print a newline
	li	$v0, 4
	syscall

	li	$v0, 10
	syscall				# all done!

.end main

