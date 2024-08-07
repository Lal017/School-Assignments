###########################################################################
#  Name: Eduardo Salazar
#  NSHE ID: 5005695833
#  Section: 1003
#  Assignment: MIPS #3
#  Description: sort a series of lists and output min, max, etc.

#  MIPS assembly language main program and functions:

#  * MIPS assembly language function, prtHeaders() to 
#    display some headers as per assignment format example.

#  * MIPS assembly language function, surfaceAreas(), 
#    to calculate the surface area for each hexagonal prism
#    in a series of hexagonal prisms
#    NOTE: this function must call the shellSort() function.

#  * MIPS assembly language function, shellSort(), to sort
#    the surface areas array (small to large).

#  * MIPS assembly language function, surfaceAreasStats(),
#    that will find the minimum, maximum, median, and
#    average (float) of the diagonals array.

#  * MIPS assembly language function, displayStats(), to
#    display the areas[] array statistical information:
#    minimum, maximum, median, and average (float)
#    in the format shown in the example.  The numbers should
#    be printed six (6) per line (see example).

#####################################################################
#  data segment

.data

# -----
#  Data declarations for main.

bases1:		.word	129, 127, 125, 123, 121, 129, 127, 125, 123, 121
		.word	122, 124, 126, 128, 120
apothems1:	.word	 44,  42,  41,  45,  44,  43,  42,  47,  48,  49
		.word	 42,  40,  46,  48,  40
heights1:	.word	119, 117, 115, 113, 111, 119, 117, 115, 113, 111
		.word	112, 114, 116, 118, 110
areas1:		.space	60
len1:		.word	15
min1:		.word	0
med1:		.word	0
max1:		.word	0
fAve1:		.double	0.0

bases2:		.word	155, 165, 153, 164, 178, 169, 152, 166, 159, 151
		.word	157, 151, 167, 151, 167, 157, 157, 161, 161, 159
		.word	152, 159, 155, 159, 153, 155, 151, 152, 154, 159
		.word	156, 152, 152, 151, 156, 160, 164, 158, 168, 162
		.word	167, 157, 169, 154, 153, 154, 155, 156, 155, 154
		.word	161, 163, 156, 169, 161, 152, 160, 168, 151, 159
		.word	169, 164, 167, 169, 162, 164, 156, 168, 162, 163
		.word	152, 161, 166, 167, 156
apothems2:	.word	 52,  81,  86,  67,  55,  60,  51,  63,  52,  55
		.word	 54,  62,  54,  86,  67,  54,  56,  50,  56,  63
		.word	 62,  63,  52,  79,  54,  61,  71,  88,  56,  57
		.word	 63,  55,  61,  79,  58,  69,  72,  84,  60,  61
		.word	 50,  54,  56,  67,  64,  65,  56,  59,  58,  62
		.word	 51,  53,  54,  66,  60,  66,  85,  67,  60,  66
		.word	 52,  75,  77,  62,  57,  57,  77,  89,  58,  54
		.word	 60,  51,  53,  52,  55
heights2:	.word	145, 155, 143, 154, 168, 159, 142, 156, 149, 141
		.word	147, 141, 157, 141, 157, 147, 147, 151, 151, 149
		.word	142, 149, 145, 149, 143, 145, 141, 142, 144, 149
		.word	146, 142, 142, 141, 146, 150, 154, 148, 158, 152
		.word	157, 147, 159, 144, 143, 144, 145, 146, 145, 144
		.word	151, 153, 146, 159, 151, 142, 150, 158, 141, 149
		.word	159, 144, 147, 149, 152, 154, 146, 148, 152, 153
		.word	142, 151, 156, 157, 146
areas2:		.space	300
len2:		.word	75
min2:		.word	0
med2:		.word	0
max2:		.word	0
fAve2:		.double	0.0

apothems3:	.word	153, 152, 151, 151, 151, 154, 152, 156, 168, 153
		.word	152, 159, 155, 159, 151, 165, 159, 152, 154, 159
		.word	150, 154, 156, 167, 154, 145, 156, 139, 158, 152
		.word	151, 153, 156, 159, 161, 162, 164, 168, 171, 175
		.word	179, 184, 137, 189, 162, 151, 154, 166, 152, 143
		.word	151, 163, 164, 156, 150, 166, 185, 177, 160, 156
		.word	164, 165, 155, 172, 162, 161, 163, 166, 166, 153
		.word	178, 169, 161, 152, 163, 163, 196, 161, 159, 166
		.word	156, 189, 159, 147, 176, 164, 164, 166, 174, 152
bases3:		.word	 81,  58,  65,  53,  62,  50,  68,  81,  64,  62
		.word	 45,  72,  86,  62,  63,  69,  66,  52,  68,  51
		.word	 82,  55,  56,  57,  55,  44,  56,  40,  66,  63
		.word	 63,  52,  41,  41,  61,  44,  52,  56,  68,  63
		.word	 62,  69,  55,  49,  64,  55,  49,  52,  54,  59
		.word	 60,  54,  56,  87,  64,  35,  36,  39,  58,  72
		.word	 51,  53,  56,  59,  61,  72,  74,  68,  51,  75
		.word	 79,  84,  49,  62,  87,  74,  66,  61,  62,  63
		.word	 51,  63,  44,  46,  61,  66, 105,  57,  50,  56
heights3:	.word	143, 142, 141, 141, 141, 144, 142, 146, 158, 143
		.word	142, 149, 145, 149, 141, 155, 149, 142, 144, 149
		.word	140, 144, 146, 157, 144, 135, 146, 129, 148, 142
		.word	141, 143, 146, 149, 151, 152, 154, 158, 161, 165
		.word	169, 174, 127, 179, 152, 141, 144, 156, 142, 133
		.word	141, 153, 154, 146, 140, 156, 175, 167, 150, 146
		.word	154, 155, 145, 162, 152, 141, 142, 156, 156, 143
		.word	168, 159, 151, 142, 153, 141, 176, 151, 149, 156
		.word	146, 179, 149, 137, 146, 154, 154, 156, 164, 142

areas3:		.space	360
len3:		.word	90
min3:		.word	0
med3:		.word	0
max3:		.word	0
fAve3:		.double	0.0

apothems4:	.word	155, 154, 153, 167, 163, 164, 164, 166, 174, 152
		.word	176, 162, 162, 161, 156, 160, 164, 188, 188, 202
		.word	192, 205, 167, 162, 167, 157, 177, 189, 198, 204
		.word	164, 162, 184, 196, 207, 164, 166, 160, 166, 163
		.word	162, 161, 166, 197, 204, 160, 161, 163, 162, 155
		.word	167, 197, 209, 161, 163, 164, 165, 166, 185, 204
		.word	159, 166, 172, 161, 167, 187, 207, 203, 185, 164
		.word	174, 151, 152, 163, 176, 164, 156, 163, 166, 173
		.word	161, 168, 187, 153, 188, 162, 161, 160, 165, 160
		.word	167, 154, 160, 182, 164, 165, 166, 172, 168, 202
		.word	163, 162, 156, 186, 161, 166, 174, 175, 205, 166
		.word	167, 163, 163, 150, 165, 161, 164, 168, 163, 162
		.word	179, 166, 172, 137, 167, 167, 169, 187, 185, 164
		.word	191, 165, 165, 162, 167, 165, 160, 169, 162, 164
		.word	171, 162, 161, 162, 181, 169, 164, 162, 165, 161
bases4:		.word	 63,  62,  56,  86,  60,  66,  74,  75,  65,  66
		.word	 81,  57,  60,  37,  84,  75,  61,  77,  71,  69
		.word	 63,  62,  56,  66,  60,  66,  74,  66,  65,  62
		.word	 61,  73,  63,  60,  65,  69,  65,  68,  63,  65
		.word	 74,  51,  52,  63,  76,  64,  56,  63,  66,  73
		.word	 37,  74,  60,  82,  64,  65,  66,  72,  68,  72
		.word	 61,  63,  63,  60,  67,  61,  65,  68,  63,  65
		.word	 67,  36,  72,  67,  67,  77,  79,  87,  85,  64
		.word	 63,  64,  62,  53,  86,  64,  66,  62,  66,  73
		.word	 64,  69,  62,  63,  60,  71,  62,  69,  69,  62
		.word	 65,  66,  72,  67,  67,  67,  69,  87,  85,  54
		.word	 89,  63,  66,  50,  65,  62,  64,  68,  63,  62
		.word	 71,  82,  61,  63,  66,  79,  64,  62,  65,  61
		.word	 74,  64,  64,  53,  86,  64,  66,  62,  66,  73
		.word	 59,  54,  64,  64,  77,  53,  69,  71,  75,  66
heights4:	.word	145, 144, 143, 157, 153, 154, 154, 156, 164, 142
		.word	166, 152, 152, 151, 146, 150, 154, 178, 178, 192
		.word	182, 195, 157, 152, 157, 147, 167, 179, 188, 194
		.word	154, 152, 174, 186, 197, 154, 156, 150, 156, 153
		.word	152, 151, 156, 187, 190, 150, 151, 153, 152, 145
		.word	157, 187, 199, 151, 153, 154, 155, 156, 175, 194
		.word	149, 156, 162, 151, 157, 177, 199, 197, 175, 154
		.word	164, 141, 142, 153, 166, 154, 146, 153, 156, 163
		.word	151, 158, 177, 143, 178, 152, 151, 150, 155, 150
		.word	157, 144, 150, 172, 154, 155, 156, 162, 158, 192
		.word	153, 152, 146, 176, 151, 156, 164, 165, 195, 156
		.word	157, 153, 153, 140, 155, 151, 154, 158, 153, 152
		.word	169, 156, 162, 127, 157, 157, 159, 177, 175, 154
		.word	181, 155, 155, 152, 157, 155, 150, 159, 152, 154
		.word	161, 152, 151, 152, 171, 159, 154, 152, 155, 151
len4:		.word	150
areas4:		.space	600
min4:		.word	0
med4:		.word	0
max4:		.word	0
fAve4:		.double	0.0

apothems5:	.word	862, 169, 165, 169, 171, 165, 189, 172, 154, 159
		.word	172, 175, 167, 162, 177, 157, 187, 179, 178, 184
		.word	169, 164, 166, 167, 174, 165, 186, 179, 158, 192
		.word	151, 153, 156, 169, 161, 162, 184, 178, 171, 185
		.word	169, 163, 164, 166, 160, 166, 185, 197, 175, 196
		.word	162, 161, 186, 197, 190, 160, 181, 193, 172, 185
		.word	157, 163, 163, 160, 175, 161, 184, 198, 173, 182
		.word	161, 163, 164, 166, 170, 166, 185, 197, 180, 206
		.word	144, 162, 184, 196, 187, 164, 186, 160, 186, 173
		.word	192, 175, 167, 162, 167, 167, 187, 199, 188, 204
		.word	169, 161, 169, 161, 169, 161, 189, 191, 189, 201
		.word	163, 163, 163, 160, 165, 169, 183, 198, 183, 175
		.word	161, 165, 167, 173, 176, 178, 181, 197, 194, 176
		.word	162, 169, 165, 179, 161, 175, 189, 192, 194, 179
		.word	451, 453, 466, 459, 461, 472, 484, 478, 491, 485
		.word	362, 362, 362, 362, 362, 372, 382, 372, 392, 382
		.word	362, 362, 362, 362, 372, 372, 382, 372, 362, 382
		.word	272, 275, 267, 262, 277, 277, 287, 279, 288, 284
		.word	162, 169, 165, 169, 171, 175, 189, 172, 174, 199
		.word	162, 164, 168, 171, 175, 171, 282, 577, 271, 191
		.word	151, 153, 166, 159, 181, 172, 184, 178, 171, 275
bases5:		.word	103,  84,  87,  89,  82,  74,  76,  78,  72,  83
		.word	 60,  64,  66,  67,  64,  65,  66,  69,  58,  82
		.word	 55,  85,  65,  62,  67,  65,  60,  69,  62,  64
		.word	 60,  61,  69,  69,  50,  65,  71,  74,  68,  83
		.word	 61,  63,  63,  66,  55,  66,  75,  77,  81,  86
		.word	 54,  64,  64,  53,  86,  64,  66,  62,  66,  73
		.word	 64,  62,  67,  76,  87,  64,  66,  60,  46,  63
		.word	 79,  84,  87,  89,  92,  74,  76,  78,  82,  83
		.word	 65,  62,  66,  65,  50,  67,  73,  89,  62,  84
		.word	 66,  62,  62,  61,  56,  60,  64,  88,  68,  82
		.word	 67,  67,  67,  67,  57,  67,  77,  87,  67,  87
		.word	 67,  77,  69,  61,  63,  64,  65,  66,  85,  84
		.word	 64,  62,  84   76,  77,  64,  66,  60,  46,  63
		.word	 72,  75,  67,  62,  67,  57,  77,  69,  68,  83
		.word	 95,  92, 106, 105,  70,  97,  33,  79,  52,  94
		.word	 99, 100, 101, 102,  99, 101, 110, 104, 102, 100
		.word	 93, 102, 102, 109, 100, 107, 111, 105, 108, 101
		.word	 92,  74,  75,  77,  61,  78,  83,  86,  96, 103
		.word	 91,  73,  84, 106, 110,  36, 105, 107, 109, 106
		.word	 69,  61,  69,  41,  59,  61,  79,  81,  89,  81
		.word	 51,  53,  56,  59,  61,  33,  88,  92,  31,  97
heights5:	.word	852, 159, 155, 159, 151, 155, 159, 152, 144, 149
		.word	162, 165, 157, 152, 157, 147, 167, 159, 168, 174
		.word	159, 154, 156, 157, 154, 155, 156, 159, 148, 172
		.word	141, 143, 146, 149, 151, 152, 154, 158, 161, 165
		.word	159, 153, 154, 156, 140, 156, 175, 187, 155, 156
		.word	152, 151, 176, 187, 170, 150, 151, 153, 152, 145
		.word	147, 153, 153, 140, 165, 151, 154, 158, 153, 152
		.word	151, 153, 154, 156, 140, 156, 175, 187, 160, 196
		.word	134, 152, 174, 186, 167, 154, 156, 150, 156, 153
		.word	182, 165, 157, 152, 157, 147, 167, 179, 168, 194
		.word	159, 151, 159, 151, 149, 151, 169, 171, 169, 191
		.word	153, 153, 153, 150, 155, 159, 143, 148, 153, 155
		.word	151, 155, 157, 163, 166, 168, 171, 177, 164, 176
		.word	152, 159, 155, 159, 151, 155, 159, 142, 144, 149
		.word	441, 443, 446, 449, 451, 452, 454, 458, 461, 465
		.word	352, 352, 352, 352, 352, 352, 352, 352, 352, 352
		.word	352, 352, 352, 352, 352, 352, 352, 352, 352, 352
		.word	262, 265, 257, 252, 257, 247, 267, 259, 268, 274
		.word	152, 159, 155, 159, 151, 155, 159, 152, 154, 159
		.word	152, 154, 158, 161, 165, 121, 232, 567, 211, 121
		.word	141, 143, 146, 149, 151, 152, 154, 158, 161, 265
areas5:		.space	840
len5:		.word	210
min5:		.word	0
med5:		.word	0
max5:		.word	0
fAve5:		.double	0.0

# -----
#  Variables for main.

asstHeader:	.ascii	"\nMIPS Assignment #3\n"
		.asciiz	"Hexagonal Prism Surface Areas Program\n\n"

# -----
#  Variables/constants for prtHeaders() procedure.

hdrTitle:	.ascii	"\n*******************************************************************"
		.asciiz	"\nHexagonal Prisms "
hdrLength:	.asciiz	"\nLength: "

hdrStats:	.asciiz	"\nSurface Areas - Stats: \n"
hdrVolumes:	.asciiz	"\n\nSurface Areas - Values: \n"

# -----
#  Variables/constants for surfaceAreas() function (if any).


# -----
#  Variables/constants for shellSort() function (if any).

h:		.word	0
i:		.word	0
tmp:	.word	0
J:		.word	0

# -----
#  Variables/constants for areasStats() function.


# -----
#  Variables/constants for displayStats() function.

NUMS_PER_ROW = 6

spc:		.asciiz	"     "
newLine:	.asciiz	"\n"

str1:		.asciiz	"   min  = "
str2:		.asciiz	"\n   max  = "
str3:		.asciiz	"\n   med  = "
str4:		.asciiz	"\n   ave = "

#####################################################################
#  text/code segment

# -----
#  Basic flow:
#	for each data set:
#	  * display headers
#	  * calculate surface areas, including sort
#	  * calculate surface areas stats (min, max, med, sum, and fAve)
#	  * display surface areas and surface areas stats

.text
.globl	main
main:

# --------------------------------------------------------
#  Display Program Header.

	la	$a0, asstHeader
	li	$v0, 4
	syscall					# print header
	li	$s0, 1				# counter, data set number

# --------------------------------------------------------
#  Data Set #1

	move	$a0, $s0
	lw	$a1, len1
	jal	prtHeaders
	add	$s0, $s0, 1

#  Hexagonal Prisms surface areas calculation function
#  Note, function also calls the shellSort() function to
#  sort the surface araes array.
#	surfaceAreas(apothems, bases, heights, len, diags)

	la	$a0, apothems1
	la	$a1, bases1
	la	$a2, heights1
	lw	$a3, len1
	subu	$sp, $sp, 4
	la	$t0, areas1
	sw	$t0, ($sp)			# arg 5, on stack
	jal	surfaceAreas
	addu	$sp, $sp, 4			# clear stack

#  Generate surface areas stats.
#  Note, function also calls the findSum() and findAverage() functions.
#	diagonalsStats(diags, len, min, max, med, fAve)

	la	$a0, areas1			# arg 1
	lw	$a1, len1			# arg 2
	la	$a2, min1			# arg 3
	la	$a3, max1			# arg 4
	subu	$sp, $sp, 8
	la	$t0, med1
	sw	$t0, ($sp)			# arg 5, on stack
	la	$t6, fAve1
	sw	$t6, 4($sp)			# arg 6, on stack
	jal	surfaceAreasStats
	addu	$sp, $sp, 8			# clear stack

#  Display final surface areas array stats.
#	displayStats(diags, len, min, max, med, fAve)

	la	$a0, areas1			# arg 1
	lw	$a1, len1			# arg 2
	lw	$a2, min1			# arg 3
	lw	$a3, max1			# arg 4
	subu	$sp, $sp, 8
	lw	$t0, med1
	sw	$t0, ($sp)			# arg 5, on stack
	l.d	$f6, fAve1
	s.d	$f6, 4($sp)			# arg 6, on stack
	jal	showAreasStats
	addu	$sp, $sp, 8			# clear stack

# --------------------------------------------------------
#  Data Set #2

	move	$a0, $s0
	lw	$a1, len2
	jal	prtHeaders
	add	$s0, $s0, 1

#  Hexagonal Prisms surface areas calculation function
#  Note, function also calls the shellSort() function to
#  sort the surface araes array.
#	surfaceAreas(apothems, bases, heights, len, diags)

	la	$a0, apothems2
	la	$a1, bases2
	la	$a2, heights2
	lw	$a3, len2
	subu	$sp, $sp, 4
	la	$t0, areas2
	sw	$t0, ($sp)			# arg 5, on stack
	jal	surfaceAreas
	addu	$sp, $sp, 4			# clear stack

#  Generate surface areas stats.
#  Note, function also calls the findSum() and findAverage() functions.
#	diagonalsStats(diags, len, min, max, med, fAve)

	la	$a0, areas2			# arg 1
	lw	$a1, len2			# arg 2
	la	$a2, min2			# arg 3
	la	$a3, max2			# arg 4
	subu	$sp, $sp, 8
	la	$t0, med2
	sw	$t0, ($sp)			# arg 5, on stack
	la	$t6, fAve2
	sw	$t6, 4($sp)			# arg 6, on stack
	jal	surfaceAreasStats
	addu	$sp, $sp, 8			# clear stack

#  Display final surface areas array stats.
#	displayStats(diags, len, min, max, med, fAve)

	la	$a0, areas2			# arg 1
	lw	$a1, len2			# arg 2
	lw	$a2, min2			# arg 3
	lw	$a3, max2			# arg 4
	subu	$sp, $sp, 8
	lw	$t0, med2
	sw	$t0, ($sp)			# arg 5, on stack
	l.d	$f6, fAve2
	s.d	$f6, 4($sp)			# arg 6, on stack
	jal	showAreasStats
	addu	$sp, $sp, 8			# clear stack

# --------------------------------------------------------
#  Data Set #3

	move	$a0, $s0
	lw	$a1, len3
	jal	prtHeaders
	add	$s0, $s0, 1

#  Hexagonal Prisms surface areas calculation function
#  Note, function also calls the shellSort() function to
#  sort the surface araes array.
#	surfaceAreas(apothems, bases, heights, len, diags)

	la	$a0, apothems3
	la	$a1, bases3
	la	$a2, heights3
	lw	$a3, len3
	subu	$sp, $sp, 4
	la	$t0, areas3
	sw	$t0, ($sp)			# arg 5, on stack
	jal	surfaceAreas
	addu	$sp, $sp, 4			# clear stack

#  Generate surface areas stats.
#  Note, function also calls the findSum() and findAverage() functions.
#	diagonalsStats(diags, len, min, max, med, fAve)

	la	$a0, areas3			# arg 1
	lw	$a1, len3			# arg 2
	la	$a2, min3			# arg 3
	la	$a3, max3			# arg 4
	subu	$sp, $sp, 8
	la	$t0, med3
	sw	$t0, ($sp)			# arg 5, on stack
	la	$t6, fAve3
	sw	$t6, 4($sp)			# arg 6, on stack
	jal	surfaceAreasStats
	addu	$sp, $sp, 8			# clear stack

#  Display final surface areas array stats.
#	displayStats(diags, len, min, max, med, fAve)

	la	$a0, areas3			# arg 1
	lw	$a1, len3			# arg 2
	lw	$a2, min3			# arg 3
	lw	$a3, max3			# arg 4
	subu	$sp, $sp, 8
	lw	$t0, med3
	sw	$t0, ($sp)			# arg 5, on stack
	l.d	$f6, fAve3
	s.d	$f6, 4($sp)			# arg 6, on stack
	jal	showAreasStats
	addu	$sp, $sp, 8			# clear stack

# --------------------------------------------------------
#  Data Set #4

	move	$a0, $s0
	lw	$a1, len4
	jal	prtHeaders
	add	$s0, $s0, 1

#  Hexagonal Prisms surface areas calculation function
#  Note, function also calls the shellSort() function to
#  sort the surface araes array.
#	surfaceAreas(apothems, bases, heights, len, diags)

	la	$a0, apothems4
	la	$a1, bases4
	la	$a2, heights4
	lw	$a3, len4
	subu	$sp, $sp, 4
	la	$t0, areas4
	sw	$t0, ($sp)			# arg 5, on stack
	jal	surfaceAreas
	addu	$sp, $sp, 4			# clear stack

#  Generate surface areas stats.
#  Note, function also calls the findSum() and findAverage() functions.
#	diagonalsStats(diags, len, min, max, med, fAve)

	la	$a0, areas4			# arg 1
	lw	$a1, len4			# arg 2
	la	$a2, min4			# arg 3
	la	$a3, max4			# arg 4
	subu	$sp, $sp, 8
	la	$t0, med4
	sw	$t0, ($sp)			# arg 5, on stack
	la	$t6, fAve4
	sw	$t6, 4($sp)			# arg 6, on stack
	jal	surfaceAreasStats
	addu	$sp, $sp, 8			# clear stack

#  Display final surface areas array stats.
#	displayStats(diags, len, min, max, med, fAve)

	la	$a0, areas4			# arg 1
	lw	$a1, len4			# arg 2
	lw	$a2, min4			# arg 3
	lw	$a3, max4			# arg 4
	subu	$sp, $sp, 8
	lw	$t0, med4
	sw	$t0, ($sp)			# arg 5, on stack
	l.d	$f6, fAve4
	s.d	$f6, 4($sp)			# arg 6, on stack
	jal	showAreasStats
	addu	$sp, $sp, 8			# clear stack

# --------------------------------------------------------
#  Data Set #5

	move	$a0, $s0
	lw	$a1, len5
	jal	prtHeaders
	add	$s0, $s0, 1

#  Hexagonal Prisms surface areas calculation function
#  Note, function also calls the shellSort() function to
#  sort the surface araes array.
#	surfaceAreas(apothems, bases, heights, len, diags)

	la	$a0, apothems5
	la	$a1, bases5
	la	$a2, heights5
	lw	$a3, len5
	subu	$sp, $sp, 4
	la	$t0, areas5
	sw	$t0, ($sp)			# arg 5, on stack
	jal	surfaceAreas
	addu	$sp, $sp, 4			# clear stack

#  Generate surface areas stats.
#  Note, function also calls the findSum() and findAverage() functions.
#	diagonalsStats(diags, len, min, max, med, fAve)

	la	$a0, areas5			# arg 1
	lw	$a1, len5			# arg 2
	la	$a2, min5			# arg 3
	la	$a3, max5			# arg 4
	subu	$sp, $sp, 8
	la	$t0, med5
	sw	$t0, ($sp)			# arg 5, on stack
	la	$t6, fAve5
	sw	$t6, 4($sp)			# arg 6, on stack
	jal	surfaceAreasStats
	addu	$sp, $sp, 8			# clear stack

#  Display final surface areas array stats.
#	displayStats(diags, len, min, max, med, fAve)

	la	$a0, areas5			# arg 1
	lw	$a1, len5			# arg 2
	lw	$a2, min5			# arg 3
	lw	$a3, max5			# arg 4
	subu	$sp, $sp, 8
	lw	$t0, med5
	sw	$t0, ($sp)			# arg 5, on stack
	l.d	$f6, fAve5
	s.d	$f6, 4($sp)			# arg 6, on stack
	jal	showAreasStats
	addu	$sp, $sp, 8			# clear stack

# --------------------------------------------------------
#  Done, terminate program.

	li	$v0, 10
	syscall					# au revoir...
.end

#####################################################################
#  Display headers.

.globl	prtHeaders
prtHeaders:
	sub	$sp, $sp, 8
	sw	$s0, ($sp)
	sw	$s1, 4($sp)

	move	$s0, $a0
	move	$s1, $a1

	la	$a0, hdrTitle
	li	$v0, 4
	syscall

	move	$a0, $s0
	li	$v0, 1
	syscall

	la	$a0, hdrLength
	li	$v0, 4
	syscall

	move	$a0, $s1
	li	$v0, 1
	syscall

	lw	$s0, ($sp)
	lw	$s1, 4($sp)
	add	$sp, $sp, 8

	jr	$ra
.end	prtHeaders

#####################################################################
#  MIPS assembly language function to calculate the
#  surface area for each hexagonal prism in a series of hexagonal prisms.

#  Note, this function also calls the shellSort() function
#        after the surface areas are calculated.

#    Arguments:
#	$a0	- starting address of the apothems array
#	$a1	- starting address of the bases array
#	$a2	- starting address of the heights array
#	$a3	- length
#	($fp)	- starting address of the areas array

#    Returns:
#	areas[] surface areas array via passed address

.globl surfaceAreas
surfaceAreas:

	subu $sp, $sp, 8							# preserve register
	sw	$fp, ($sp)
	sw	$ra, 4($sp)								# push ra

	addu $fp, $sp, 8								# set frame pointer

	li	$t4, 0									# index

calcLoop:

	bge	$t4, $a3, calcBreak						# check to exit loop

	move $t0, $a0								# get address of apothems array
	move $t1, $a1								# get address of bases array
	move $t2, $a2								# get address of heights array
	lw	 $t8, ($fp)								# get address of areas array

	mul $t5, $t4, 4
	add $t0, $t0, $t5							# get apothems address of current index
	add $t1, $t1, $t5							# get bases address of current index
	add $t2, $t2, $t5							# get heights address of current index
	add $t8, $t8, $t5							# get areas address of current index

	lw	$t5, ($t0)								# get apothems value
	lw	$t6, ($t2)								# get heights value
	add $t5, $t5, $t6							# (apothems + heights)
	li	$t6, 6
	lw	$t7, ($t1)								# get bases value
	mul	$t6, $t6, $t7							# 6 * bases
	mul $t6, $t6, $t5							# multiply together

	sw	$t6, ($t8)

	add	$t4, $t4, 1								# increment index
	j calcLoop

calcBreak:

	lw	$a0, ($fp)								# get address of areas array
	move $a1, $a3								# get length
	jal shellSort								# call shellsort function

	move $v0, $a0								# set return value

	lw	$ra, 4($sp)								# pop ra
	lw	$fp, ($sp)
	addu $sp, $sp, 8							# restore registers

	jr	$ra

.end surfaceAreas

#####################################################################
#  Sort a list of numbers using shell sort algorithm.

# -----
#    Arguments:
#	$a0 - starting address of the list
#	$a1 - list length

#    Returns:
#	sorted list (via reference)

.globl shellSort
shellSort:

	li	$t0, 1
	sw	$t0, h						# h = 1

whileOne:							# first while loop

	lw	$t0, h						# get h value
	mul	$t0, $t0, 3					# h * 3
	add $t0, $t0, 1					#		+ 1

	bge	$t0, $a1, whileTwo			# check to break out of loop (h*3+1 >= length)
	sw	$t0, h						# update h
	j whileOne						# loop again

whileTwo:							# second while loop

	lw	$t0, h						# get h value
	ble	$t0, $zero, whileBreak2		# check to break out of while loop

	sub $t1, $t0, 1					# h-1
	sw	$t1, i						# 	  = i

forOne:								# first for loop

	lw	$t1, i						# get i
	bge	$t1, $a1, forBreak1			# break if i >= length

	mul $t2, $t1, 4					# multiply i * 4 to increment address
	move $t3, $a0					# get address of list
	add $t3, $t3, $t2				# increment address
	lw	$t4, ($t3)					# get lst[i]
	sw	$t4, tmp					# store in tmp
	sw	$t1, J						# j = i

ForTwo:

	lw	$t2, J						# get j
	lw	$t3, h						# get h
	blt	$t2, $t3, forBreak2			# check first condition

	move $t4, $a0					# get address of list
	sub $t5, $t2, $t3				# j-h
	mul $t5, $t5, 4
	add $t4, $t4, $t5				# set address at lst[j-h]
	lw	$t6, ($t4)					# get lst[j-h]
	lw	$t7, tmp					# get temp
	ble	$t6, $t7, forBreak2			# check second condition

	mul	$t4, $t2, 4					# j * 4 to increment address
	move $t5, $a0					# get address of list
	add $t5, $t4, $t5				# increment address
	sw	$t6, ($t5)					# lst[j] = lst[j-h]

	sub	$t4, $t2, $t3				# j-h
	sw	$t4, J						# j = j-h
	j	ForTwo						# jump to for two

forBreak2:

	lw	$t4, J						# get j
	mul	$t2, $t4, 4					# j * 4 to increment address
	move $t3, $a0					# get address of list
	add $t3, $t3, $t2				# increment address
	lw	$t5, tmp					# get tmp
	sw	$t5, ($t3)					# lst[j] = tmp

	add $t1, $t1, 1					# i++
	sw	$t1, i
	j	forOne

forBreak1:							# break out of first for loop

	div	$t0, $t0, 3					# h = h / 3
	sw	$t0, h						# store h
	j	whileTwo

whileBreak2:						# break out of second while loop

	jr $ra
	
.end shellSort

#####################################################################
#  Find sum function.
#	Find sum of passed array.

#    Arguments:
#	$a0   - address
#	$a1   - len

#    Returns:
#	$f0   - float average

.globl findSum
findSum:

	li	$t1, 0					# index
	li	$t4, 0					# set sum to 0

calcSum:

	move $t0, $a0				# get address
	mul	$t2, $t1, 4
	add $t0, $t0, $t2			# get arr[i] address
	lw	$t3, ($t0)				# get value at arr[i]
	add $t4, $t4, $t3			# add to sum

	add $t1, $t1, 1				# i++
	blt	$t1, $a1, calcSum

	mtc1 $t4, $f0
	cvt.d.w $f0, $f0			# convert to float

	jr $ra

.end findSum

#####################################################################
#  Find floating point average function.
#  Includes performing the required type conversions.
#  Note, must call findSum() function.

#    Arguments:
#	$a0   - integer
#	$a1   - len

#    Returns:
#	$v0   - sum

.globl findAverage
findAverage:

	subu $sp, $sp, 4			# preserve register
	sw	$ra, ($sp)				# push register

	jal	findSum

	mtc1 $a1, $f2
	cvt.d.w	$f2, $f2			# conver to double
	div.d $f0, $f0, $f2			# sum / length

	lw	$ra, ($sp)				# pop register
	addu $sp, $sp, 4			# restore register

	jr	$ra
.end findAverage

#####################################################################
#  MIPS assembly language procedure, surfaceAreasStats() to find the
#    sum, average, minimum, maximum, median, and floating point
#    average of list.
#  Note, must call the findAverage() function.

# -----
#  HLL Call:
#	surfaceAreasStats(areas, len, min, max, med, fAve)

# -----
#    Arguments:
#	$a0	- starting address of the diagonals array
#	$a1	- list length
#	$a2	- addr of min
#	$a3	- addr of max
#	($fp)	- addr of med
#	4($fp)	- addr of fAve

#    Returns (via reference):
#	min, max, med, fAve

.globl surfaceAreasStats
surfaceAreasStats:

	subu $sp, $sp, 8					# preserve register
	sw	$fp, ($sp)
	sw	$ra, 4($sp)						# push
	addu $fp, $sp, 8					# set frame pointer

	li	$t1, 0							# index
	lw	$t0, ($a0)						# get first value
	sw	$t0, ($a2)						# store in min

statsLoop:

	move $t0, $a0						# get address of areas array
	mul	$t2, $t1, 4
	add $t0, $t0, $t2					# increment address
	lw	$t2, ($t0)						# get value at lst[i]

	lw	$t3, ($a2)						# get min value
	bge	$t2, $t3, minSkip				# check if current value is less than min
	sw	$t2, ($a2)						# store if less than min
minSkip:

	lw	$t3, ($a3)						# get max
	ble	$t2, $t3, maxSkip				# check if current value is more than max
	sw	$t2, ($a3)						# store if more than max
maxSkip:

	add	$t1, $t1, 1						# i++
	blt $t1, $a1, statsLoop				# loop condition

	move $t1, $a0						# get address of lst
	move $t0, $a1						# get length
	div	$t3, $t0, 2						# divide list by 2
	mul $t3, $t3, 4
	add $t1, $t1, $t3					# get middle value address
	lw	$t2, ($t1)						# get middle value

	rem $t0, $t0, 2						# check if list is even number
	bne	$t0, $zero, evenSkip
	sub $t3, $t1, 4						# get address of second middle value
	lw	$t5, ($t3)						# get second middle value
	add $t2, $t5, $t2					# add values together
	div $t2, $t2, 2						# divide by 2
evenSkip:

	lw	$t4, ($fp)						# get address of med
	sw	$t2, ($t4)						# store med

	jal findAverage						# call findaverage function
	lw	$t4, 4($fp)
	s.d	$f0, ($t4)						# store average

	lw	$ra, 4($sp)						# pop
	lw	$fp, ($sp)
	addu $sp, $sp, 8					# restore registers

	jr $ra

.end surfaceAreasStats

#####################################################################
#  MIPS assembly language procedure, displayStats(), to display
#    the statistical information to console.

#  Note, due to the system calls, the saved registers must be used.
#	As such, push/pop saved registers altered.

# HLL Call
#	showAreasStats(diags, len, min, max, med, fAve)

# -----
#    Arguments:
#	$a0	- starting address of diags[]
#	$a1	- length
#	$a2	- min
#	$a3	- max
#	($fp)	- med
#	4($fp)	- fAve

#    Returns:
#	N/A

.globl showAreasStats
showAreasStats:

	subu $sp, $sp, 32					# preserve register
	sw	$fp, ($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	sw	$s2, 12($sp)
	sw	$s3, 16($sp)
	sw	$s4, 20($sp)
	sw	$s5, 24($sp)
	sw	$s6, 28($sp)
	addu $fp, $sp, 32						# set frame pointer

	move $s0, $a0						# get address of areas array
	move $s1, $a1						# get length

	la	$a0, newLine
	li	$v0, 4
	syscall

	la	$a0, hdrVolumes
	li	$v0, 4
	syscall

	li	$s2, 0							# index
	li	$s5, 0							# line count index
	li	$s6, 5							# line count

arrPrint:								# array print loop

	move $s4, $s0						# get starting address of areas array
	mul	$s3, $s2, 4
	add $s4, $s4, $s3					# increment address

	lw	$a0, ($s4)
	li	$v0, 1							# call code print int
	syscall

	la	$a0, spc
	li	$v0, 4							# call code print string
	syscall

	blt	$s5, $s6, skipLine

	la	$a0, newLine
	li	$v0, 4
	syscall

	li	$s5, -1							# reset line count

skipLine:

	add $s5, $s5, 1						# increment line count
	add $s2, $s2, 1						# i++
	blt	$s2, $s1, arrPrint				# condition

	la	$a0, newLine
	li	$v0, 4
	syscall

	la	$a0, hdrStats
	li	$v0, 4
	syscall

	la	$a0, str1						# set address
	li	$v0, 4							# call code to print string
	syscall
	
	move $a0, $a2						# set min to display
	li	$v0, 1							# call code
	syscall

	la	$a0, str2						# set address
	li	$v0, 4							# call code to print string
	syscall

	move $a0, $a3						# set max to display
	li	$v0, 1							# call code
	syscall

	la	$a0, str3
	li	$v0, 4
	syscall

	lw	$a0, ($fp)
	li	$v0, 1
	syscall

	la	$a0, str4						# set address
	li	$v0, 4
	syscall

	l.d $f12, 4($fp)						# set average value to display
	li	$v0, 3
	syscall

	lw	$s6, 28($sp)
	lw	$s5, 24($sp)
	lw	$s4, 20($sp)
	lw	$s3, 16($sp)
	lw	$s2, 12($sp)
	lw	$s1, 8($sp)
	lw	$s0, 4($sp)
	lw	$fp, ($sp)
	addu $sp, $sp, 32					# restore registers

	jr $ra

.end showAreasStats

#####################################################################

