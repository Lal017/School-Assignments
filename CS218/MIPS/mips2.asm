###########################################################################
#  Name: Eduardo Salazar
#  NSHE ID: 5005695833
#  Section: 1003
#  Assignment: MIPS #2
#  Description: output volumes of arrays and calculate min, max, sum etc for these volumes


###########################################################
#  data segment

.data

apothems:	.word	  110,   114,   113,   137,   154
		.word	  131,   113,   120,   161,   136
		.word	  114,   153,   144,   119,   142
		.word	  127,   141,   153,   162,   110
		.word	  119,   128,   114,   110,   115
		.word	  115,   111,   122,   133,   170
		.word	  115,   123,   115,   163,   126
		.word	  124,   133,   110,   161,   115
		.word	  114,   134,   113,   171,   181
		.word	  138,   173,   129,   117,   193
		.word	  125,   124,   113,   117,   123
		.word	  134,   134,   156,   164,   142
		.word	  206,   212,   112,   131,   246
		.word	  150,   154,   178,   188,   192
		.word	  182,   195,   117,   112,   127
		.word	  117,   167,   179,   188,   194
		.word	  134,   152,   174,   186,   197
		.word	  104,   116,   112,   136,   153
		.word	  132,   151,   136,   187,   190
		.word	  120,   111,   123,   132,   145

bases:		.word	  233,   214,   273,   231,   215
		.word	  264,   273,   274,   223,   256
		.word	  157,   187,   199,   111,   123
		.word	  124,   125,   126,   175,   194
		.word	  149,   126,   162,   131,   127
		.word	  177,   199,   197,   175,   114
		.word	  244,   252,   231,   242,   256
		.word	  164,   141,   142,   173,   166
		.word	  104,   146,   123,   156,   163
		.word	  121,   118,   177,   143,   178
		.word	  112,   111,   110,   135,   110
		.word	  127,   144,   210,   172,   124
		.word	  125,   116,   162,   128,   192
		.word	  215,   224,   236,   275,   246
		.word	  213,   223,   253,   267,   235
		.word	  204,   229,   264,   267,   234
		.word	  216,   213,   264,   253,   265
		.word	  226,   212,   257,   267,   234
		.word	  217,   214,   217,   225,   253
		.word	  223,   273,   215,   206,   213

heights:	.word	  117,   114,   115,   172,   124
		.word	  125,   116,   162,   138,   192
		.word	  111,   183,   133,   130,   127
		.word	  111,   115,   158,   113,   115
		.word	  117,   126,   116,   117,   227
		.word	  177,   199,   177,   175,   114
		.word	  194,   124,   112,   143,   176
		.word	  134,   126,   132,   156,   163
		.word	  124,   119,   122,   183,   110
		.word	  191,   192,   129,   129,   122
		.word	  135,   226,   162,   137,   127
		.word	  127,   159,   177,   175,   144
		.word	  179,   153,   136,   140,   235
		.word	  112,   154,   128,   113,   132
		.word	  161,   192,   151,   213,   126
		.word	  169,   114,   122,   115,   131
		.word	  194,   124,   114,   143,   176
		.word	  134,   126,   122,   156,   163
		.word	  149,   144,   114,   134,   167
		.word	  143,   129,   161,   165,   136

hexVolumes:	.space	400

len:		.word	100

volMin:		.word	0
volEMid:	.word	0
volMax:		.word	0
volSum:		.word	0
volAve:		.word	0

LN_CNTR	= 4


# -----

hdr:	.ascii	"MIPS Assignment #2 \n"
	.ascii	"  Hexagonal Volumes Program:\n"
	.ascii	"  Also finds minimum, middle value, maximum, \n"
	.asciiz	"  sum, and average for the volumes.\n\n"

a1_st:	.asciiz	"\nHexagon Volumes Minimum = "
a2_st:	.asciiz	"\nHexagon Volumes Est Med  = "
a3_st:	.asciiz	"\nHexagon Volumes Maximum = "
a4_st:	.asciiz	"\nHexagon Volumes Sum     = "
a5_st:	.asciiz	"\nHexagon Volumes Average = "

newLn:	.asciiz	"\n"
blnks:	.asciiz	"  "

###########################################################
#  text/code segment

# --------------------
#  Compute volumes:
#  Then find middle, max, sum, and average for volumes.

.text
.globl main
.ent main
main:

# -----
#  Display header.

	la	$a0, hdr
	li	$v0, 4
	syscall				# print header

# -------------------------------------------------------

	la	$t0, apothems					# get address of apothems
	la	$t1, heights					# get address of heights
	la	$t2, bases						# get address of bases
	la	$t3, hexVolumes					# get address of hexVolumes
	li	$t4, 0							# increment/index
	lw	$t5, len						# get length of array
	li	$t6, 0							# set sum

calcLoop:

	bge	$t4, $t5, calcExit				# if i < len keep looping

	lw	$t7, ($t0)						# get apothems[i]
	lw	$t8, ($t1)						# get heights[i]
	mul $t7, $t7, $t8					# $t7 = apothems * heights
	lw	$t8, ($t2)						# get bases[i]
	mul $t7, $t7, $t8					# $t7 = $t7 * bases
	mul $t7, $t7, 3						# multiply everything by 3
	sw	$t7, ($t3)						# store answer in hexVolumes[i]

	lw	$t8, volMax						# get volMax
	ble	$t7, $t8, isLess				# check if current area less than volMax
	sw	$t7, volMax						# store if greater than
isLess:									# skip if less than

	bne $t4, $zero, minSkip				# check if index is 0
	sw	$t7, volMin						# store if index is 0
minSkip:								# skip if greater than 0
	lw	$t8, volMin						# get volMin
	bge $t7, $t8, isMore				# check if current area is more than volMin
	sw	$t7, volMin						# store if less than
isMore:									# skip if greater than

	add	$t6, $t6, $t7					# add to sum

	add $t0, $t0, 4						# increment address of apothems
	add $t1, $t1, 4						# increment address of heights
	add $t2, $t2, 4						# increment address of bases
	add $t3, $t3, 4						# increment addres of hexVolumes
	add $t4, $t4, 1
	j calcLoop

calcExit:

	sw	$t6, volSum						# store sum

	div $t6, $t6, $t5					# calculate average
	sw	$t6, volAve						# store average

	la	$t3, hexVolumes					# get address of array
	lw	$t1, ($t3)						# get first value
	lw	$t4, 396($t3)					# get last value
	add $t4, $t4, $t1					# add together
	lw	$t1, 196($t3)					# get first middle value
	add	$t4, $t4, $t1					# add first middle value
	lw	$t1, 200($t3)					# get second middle value
	add $t4, $t4, $t1					# add second middle value
	div $t4, $t4, 4						# divide sum by 4
	sw	$t4, volEMid					# store med

	li	$t0, 0							# index
	li	$t4, 4
	li	$t2, 1							# line count

printLoop:

	beq	$t0, $t5, printExit			# exit loop if i = len

	lw	$a0, ($t3)					# get variable
	li	$v0, 1						# call code to print int
	syscall							# perform system call

	la	$a0, blnks					# get address for space
	li	$v0, 4						# call code for print string
	syscall

	bne $t2, $t4, lineSkip
	la	$a0, newLn					# print a newline
	li	$v0, 4
	syscall
	li	$t2, 0						# reset line count
lineSkip:

	add $t3, $t3, 4					# increment address
	add $t0, $t0, 1					# increment i
	add $t2, $t2, 1					# increment line count
	j	printLoop

printExit:

##########################################################
#  Display results.

	la	$a0, newLn		# print a newline
	li	$v0, 4
	syscall

#  Print min message followed by result.

	la	$a0, a1_st
	li	$v0, 4
	syscall				# print "min = "

	lw	$a0, volMin
	li	$v0, 1
	syscall				# print min

# -----
#  Print middle message followed by result.

	la	$a0, a2_st
	li	$v0, 4
	syscall				# print "med = "

	lw	$a0, volEMid
	li	$v0, 1
	syscall				# print mid

# -----
#  Print max message followed by result.

	la	$a0, a3_st
	li	$v0, 4
	syscall				# print "max = "

	lw	$a0, volMax
	li	$v0, 1
	syscall				# print max

# -----
#  Print sum message followed by result.

	la	$a0, a4_st
	li	$v0, 4
	syscall				# print "sum = "

	lw	$a0, volSum
	li	$v0, 1
	syscall				# print sum

# -----
#  Print average message followed by result.

	la	$a0, a5_st
	li	$v0, 4
	syscall				# print "ave = "

	lw	$a0, volAve
	li	$v0, 1
	syscall				# print average

# -----
#  Done, terminate program.

endit:
	la	$a0, newLn		# print a newline
	li	$v0, 4
	syscall

	li	$v0, 10
	syscall				# all done!

.end main

