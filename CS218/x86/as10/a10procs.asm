; *****************************************************************
;  Name: Eduardo Salazar
;  NSHE ID: 5005695833
;  Section: 1003
;  Assignment: 10
;  Description: make a rotating wheel by using floating point operations

; -----
;  Function: getParams
;	Gets, checks, converts, and returns command line arguments.

;  Function drawWheels()
;	Plots functions

; ---------------------------------------------------------
; macro to check command line sept numbers
; %1 - address of char array
; %2 - ret value
; %3 - valid bool

%macro checkCl 3

	mov r9, 0				; increment
	mov r10, 0
	mov eax, 0

%%checkSep:					; loop to check if numbers are valid sept numbers

	mov r10b, byte [%1+r9]	; move char into r10b
	
	cmp r10b, NULL			; exit loop if NULL
	je %%loopBreak

	cmp r10b, "0"			; check if less than "0"
	jl %%inputError
	cmp r10b, "6"			; check if greater than "6"
	jg %%inputError

	sub r10b, "0"			; convert to int

	mov r11d, 7				; convert from sept to decimal
	imul r11d
	add eax, r10d

	inc r9					; increment index
	jmp %%checkSep

%%loopBreak:

	mov %2, rax				; set value to return
	mov %3, 1				; set bool to true
	jmp %%endMac

%%inputError:

	mov %3, 0				; set bool to false

%%endMac:

%endmacro

; ---------------------------------------------------------

section  .data

; -----
;  Define standard constants.

TRUE		equ	1
FALSE		equ	0

SUCCESS		equ	0			; successful operation
NOSUCCESS	equ	1

STDIN		equ	0			; standard input
STDOUT		equ	1			; standard output
STDERR		equ	2			; standard error

SYS_read	equ	0			; code for read
SYS_write	equ	1			; code for write
SYS_open	equ	2			; code for file open
SYS_close	equ	3			; code for file close
SYS_fork	equ	57			; code for fork
SYS_exit	equ	60			; code for terminate
SYS_creat	equ	85			; code for file open/create
SYS_time	equ	201			; code for get time

LF		equ	10
SPACE		equ	" "
NULL		equ	0
ESC		equ	27

; -----
;  OpenGL constants

GL_COLOR_BUFFER_BIT	equ	16384
GL_POINTS		equ	0
GL_POLYGON		equ	9
GL_PROJECTION		equ	5889

GLUT_RGB		equ	0
GLUT_SINGLE		equ	0

; -----
;  Define program specific constants.

SPD_MIN		equ	1
SPD_MAX		equ	50			; 101(7) = 50

CLR_MIN		equ	0
CLR_MAX		equ	0xFFFFFF		; 0xFFFFFF = 262414110(7)

SIZ_MIN		equ	100			; 202(7) = 100
SIZ_MAX		equ	2000			; 5555(7) = 2000

; -----
;  Local variables for getParams functions.

STR_LENGTH	equ	12

errUsage	db	"Usage: ./wheels -sp <septNumber> -cl <septNumber> "
		db	"-sz <septNumber>"
		db	LF, NULL
errBadCL	db	"Error, invalid or incomplete command line argument."
		db	LF, NULL

errSpdSpec	db	"Error, speed specifier incorrect."
		db	LF, NULL
errSpdValue	db	"Error, speed value must be between 1 and 101(7)."
		db	LF, NULL

errClrSpec	db	"Error, color specifier incorrect."
		db	LF, NULL
errClrValue	db	"Error, color value must be between 0 and 262414110(7)."
		db	LF, NULL

errSizSpec	db	"Error, size specifier incorrect."
		db	LF, NULL
errSizValue	db	"Error, size value must be between 202(7) and 5555(7)."
		db	LF, NULL

; -----
;  Local variables for drawWheels routine.

t		dq	0.0			; loop variable
s		dq	0.0
tStep		dq	0.001			; t step
sStep		dq	0.0
x		dq	0			; current x
y		dq	0			; current y
scale		dq	7500.0			; speed scale

fltZero		dq	0.0
fltOne		dq	1.0
fltTwo		dq	2.0
fltThree	dq	3.0
fltFour		dq	4.0
fltSix		dq	6.0
fltTwoPiS	dq	0.0

pi		dq	3.14159265358

fltTmp1		dq	0.0
fltTmp2		dq	0.0
fltTmp3		dq	0.0
fltTmp4		dq	0.0

red		dd	0			; 0-255
green		dd	0			; 0-255
blue		dd	0			; 0-255


; ------------------------------------------------------------

section  .text

; -----
; Open GL routines.

extern	glutInit, glutInitDisplayMode, glutInitWindowSize, glutInitWindowPosition
extern	glutCreateWindow, glutMainLoop
extern	glutDisplayFunc, glutIdleFunc, glutReshapeFunc, glutKeyboardFunc
extern	glutSwapBuffers, gluPerspective, glutPostRedisplay
extern	glClearColor, glClearDepth, glDepthFunc, glEnable, glShadeModel
extern	glClear, glLoadIdentity, glMatrixMode, glViewport
extern	glTranslatef, glRotatef, glBegin, glEnd, glVertex3f, glColor3f
extern	glVertex2f, glVertex2i, glColor3ub, glOrtho, glFlush, glVertex2d

extern	cos, sin


; ******************************************************************
;  Function getParams()
;	Gets draw speed, draw color, and screen size
;	from the command line arguments.

;	Performs error checking, converts ASCII/septenary to integer.
;	Command line format (fixed order):
;	  "-sp <septNumber> -cl <septNumber> -sz <septyNumber>"

; -----
;  Arguments:
;	ARGC, double-word, value - rdi
;	ARGV, double-word, address - rsi
;	speed, double-word, address - rdx
;	color, double-word, address - rcx
;	size, double-word, address - r8

; Returns:
;	speed, color, and size via reference (of all valid)
;	TRUE or FALSE

global getParams
getParams:

	push rdx
	push rbx
	push r12
	push r13

	mov r14, rdx

	cmp rdi, 1									; if only 1 value was entered
	je usageError

	cmp rdi, 7									; check if all values were entered
	jne clError

	mov rbx, qword [rsi+8]						; check 2nd cl arg
	mov al, byte [rbx]
	cmp al, "-"
	jne spdInErr
	mov al, byte [rbx+1]
	cmp al, "s"
	jne spdInErr
	mov al, byte [rbx+2]
	cmp al, "p"
	jne spdInErr								; if argv[1] !=  "-sp"

	; call macro here
	mov rbx, qword [rsi+16]						; set address to rbx
	mov r12, 0
	mov r13, 0
	checkCl rbx, r12, r13						; checks and converts value to int (returned in r12)

	cmp r13, 0									; returns 0 if not a valid sept number
	je spdRgeErr								; jump to output error

	cmp r12, SPD_MIN							; if less than min
	jl spdRgeErr

	cmp r12, SPD_MAX							; if greater than max
	jg spdRgeErr

	mov dword [r14], r12d						; set speed

	mov rbx, qword [rsi+24]						; check 4th cl arg
	mov al, byte [rbx]
	cmp al, "-"
	jne colInErr
	mov al, byte [rbx+1]
	cmp al, "c"
	jne colInErr
	mov al, byte [rbx+2]
	cmp al, "l"
	jne colInErr								; if argv[3] != "-cl"

	; call macro here
	mov rbx, qword [rsi+32]
	mov r12, 0
	mov r13, 0
	checkCl rbx, r12, r13						; checks and converts number to int (returned in r12)

	cmp r13, 0									; returns 0 if not a valid sept number
	je colRgeErr								; jump to output error

	cmp r12, CLR_MIN							; if less than min
	jl colRgeErr

	cmp r12, CLR_MAX							; if greater than max
	jg colRgeErr

	mov dword [rcx], r12d						; set color

	mov rbx, qword [rsi+40]						; check 6th cl arg
	mov al, byte [rbx]
	cmp al, "-"
	jne sizInErr
	mov al, byte [rbx+1]
	cmp al, "s"
	jne sizInErr
	mov al, byte [rbx+2]
	cmp al, "z"
	jne sizInErr								; if argv[5] != "-sz"

	; call macro here
	mov rbx, qword [rsi+48]
	mov r12, 0
	mov r13, 0
	checkCl rbx, r12, r13						; checks and converts to int (returned in r12)

	cmp r13, 0									; returns 0 if not a valid sept number
	je sizRgeErr								; jump to output error

	cmp r12, SIZ_MIN							; if less than min
	jl sizRgeErr

	cmp r12, SIZ_MAX							; if greater than max
	jg sizRgeErr

	mov dword [r8], r12d							; set size
	
	mov rax, TRUE								; set return to true
	jmp trueFunc								; if everything is valid skip error msg

usageError:										; error messages

	push rdi
	mov rdi, errUsage
	call printString
	pop rdi
	jmp endFunc

clError:

	push rdi
	mov rdi, errBadCL
	call printString
	pop rdi
	jmp endFunc

spdInErr:

	push rdi
	mov rdi, errSpdSpec
	call printString
	pop rdi
	jmp endFunc

spdRgeErr:

	push rdi
	mov rdi, errSpdValue
	call printString
	pop rdi
	jmp endFunc

colInErr:

	push rdi
	mov rdi, errClrSpec
	call printString
	pop rdi
	jmp endFunc

colRgeErr:

	push rdi
	mov rdi, errClrValue
	call printString
	pop rdi
	jmp endFunc

sizInErr:

	push rdi
	mov rdi, errSizSpec
	call printString
	pop rdi
	jmp endFunc

sizRgeErr:

	push rdi
	mov rdi, errSizValue
	call printString
	pop rdi
	jmp endFunc

endFunc:
	mov rax, FALSE						; set return to false
trueFunc:

	pop r13
	pop r12
	pop rbx
	pop rdx

	ret

; ******************************************************************
;  Draw wheels function.
;	Plot the provided functions (see PDF).

; -----
;  Arguments:
;	none -> accesses global variables.
;	nothing -> is void

; -----
;  Gloabl variables Accessed:

common	speed		1:4			; draw speed, dword, integer value
common	color		1:4			; draw color, dword, integer value
common	size		1:4			; screen size, dword, integer value

global drawWheels
drawWheels:
	push	rbp

; do NOT push any additional registers.
; If needed, save regitser to quad variable...

; -----
;  Set draw speed step
;	sStep = speed / scale

	cvtsi2sd xmm0, dword [speed]
	divsd xmm0, qword [scale]
	movsd qword [sStep], xmm0						; set sStep

; -----
;  Prepare for drawing
	; glClear(GL_COLOR_BUFFER_BIT);
	mov	rdi, GL_COLOR_BUFFER_BIT
	call	glClear

	; glBegin();
	mov	rdi, GL_POINTS
	call	glBegin

; -----
;  Set draw color(r,g,b)
;	uses glColor3ub(r,g,b)

	mov rdi, 0
	mov rsi, 0
	mov rdx, 0
	mov r12, qword [color]							; save color
	mov dl, byte [color]
	shr dword [color], 8
	mov sil, byte [color]
	shr dword [color], 8
	mov dil, byte [color]
	call glColor3ub									; set color
	mov qword [color], r12							; reset color

; -----
;  main plot loop
;	iterate t from 0.0 to 2*pi by tStep
;	uses glVertex2d(x,y) for each formula

	movsd xmm0, qword [fltTwo]
	mulsd xmm0, qword [pi]						; 2*pi
	movsd qword [fltTmp1], xmm0					; Sets compare value
	mulsd xmm0, qword [s]
	movsd qword [fltTwoPiS], xmm0				; sets 2*pi*s

	movsd xmm0, qword [fltZero]					; resets t to 0
	movsd qword [t], xmm0

mainLoop:

	movsd xmm3, qword [t]
	ucomisd xmm3, qword [fltTmp1]				; for(t > 2pi)
	jae breakMain

	movsd xmm0, qword [t]
	call cos
	movsd qword [x], xmm0						; x = cos(t)

	movsd xmm0, qword [t]
	call sin
	movsd qword [y], xmm0						; y = sin(t)

	movsd xmm0, qword [x]
	movsd xmm1, qword [y]
	call glVertex2d								; plot(x1,y1)
	; -----
	movsd xmm1, qword [x]
	divsd xmm1, qword [fltThree]				; cos(t)/3
	movsd qword [fltTmp2], xmm1					; left side of equation
	movsd xmm0, qword [fltTwoPiS]
	call cos									; cos(2pi*s)
	mulsd xmm0, qword [fltTwo]					; 2cos()
	divsd xmm0, qword [fltThree]				; divide by 3
	movsd qword [fltTmp3], xmm0					; set for later equation
	addsd xmm0, qword [fltTmp2]
	movsd qword [x], xmm0

	movsd xmm1, qword [y]
	divsd xmm1, qword [fltThree]				; sin(t)/3
	movsd qword [fltTmp2], xmm1					; left side of equation
	movsd xmm0, qword [fltTwoPiS]
	call sin									; sin(2pi*s)
	mulsd xmm0, qword [fltTwo]					; 2sin()
	divsd xmm0, qword [fltThree]				; divide by 3
	movsd qword [fltTmp4], xmm0					; set for later equation
	addsd xmm0, qword [fltTmp2]
	movsd qword [y], xmm0

	movsd xmm0, qword [x]
	movsd xmm1, qword [y]
	call glVertex2d								; plot(x2,y2)
	; -----
	movsd xmm0, qword [fltFour]
	mulsd xmm0, qword [pi]
	mulsd xmm0, qword [s]						; 4*pi*s
	call cos
	mulsd xmm0, qword [t]						; t*cos()
	movsd xmm1, qword [fltSix]
	mulsd xmm1, qword [pi]						; 6*pi
	divsd xmm0, xmm1
	addsd xmm0, qword [fltTmp3]					; add both sides together
	movsd qword [x], xmm0

	movsd xmm0, qword [fltFour]
	mulsd xmm0, qword [pi]
	mulsd xmm0, qword [s]						; 4*pi*s
	call sin
	mulsd xmm0, qword [t]						; t*sin()
	movsd xmm1, qword [fltSix]
	mulsd xmm1, qword [pi]						; 6*pi
	divsd xmm0, xmm1
	addsd xmm0, qword [fltTmp4]					; subtract both sides
	movsd qword [y], xmm0

	movsd xmm0, qword [x]
	movsd xmm1, qword [y]
	call glVertex2d								; plot(x3,y3)
	; -----
	movsd xmm0, qword [fltFour]
	mulsd xmm0, qword [pi]
	mulsd xmm0, qword [s]						; 4*pi*s
	movsd xmm1, qword [fltTwo]
	mulsd xmm1, qword [pi]
	divsd xmm1, qword [fltThree]				; 2*pi/3
	addsd xmm0, xmm1
	call cos
	mulsd xmm0, qword [t]						; t*cos()
	movsd xmm1, qword [fltSix]
	mulsd xmm1, qword [pi]
	divsd xmm0, xmm1
	addsd xmm0, qword [fltTmp3]
	movsd qword [x], xmm0

	movsd xmm0, qword [fltFour]
	mulsd xmm0, qword [pi]
	mulsd xmm0, qword [s]						; 4*pi*s
	movsd xmm1, qword [fltTwo]
	mulsd xmm1, qword [pi]
	divsd xmm1, qword [fltThree]				; 2*pi/3
	addsd xmm0, xmm1
	call sin
	mulsd xmm0, qword [t]						; t*cos()
	movsd xmm1, qword [fltSix]
	mulsd xmm1, qword [pi]
	divsd xmm0, xmm1
	addsd xmm0, qword [fltTmp4]
	movsd qword [y], xmm0

	movsd xmm0, qword [x]
	movsd xmm1, qword [y]
	call glVertex2d								; plot(x4,y4)
	; -----
	movsd xmm0, qword [fltFour]
	mulsd xmm0, qword [pi]
	mulsd xmm0, qword [s]						; 4*pi*s
	movsd xmm1, qword [fltTwo]
	mulsd xmm1, qword [pi]
	divsd xmm1, qword [fltThree]				; 2*pi/3
	subsd xmm0, xmm1
	call cos
	mulsd xmm0, qword [t]						; t*cos()
	movsd xmm1, qword [fltSix]
	mulsd xmm1, qword [pi]
	divsd xmm0, xmm1
	addsd xmm0, qword [fltTmp3]
	movsd qword [x], xmm0

	movsd xmm0, qword [fltFour]
	mulsd xmm0, qword [pi]
	mulsd xmm0, qword [s]						; 4*pi*s
	movsd xmm1, qword [fltTwo]
	mulsd xmm1, qword [pi]
	divsd xmm1, qword [fltThree]				; 2*pi/3
	subsd xmm0, xmm1
	call sin
	mulsd xmm0, qword [t]						; t*cos()
	movsd xmm1, qword [fltSix]
	mulsd xmm1, qword [pi]
	divsd xmm0, xmm1
	addsd xmm0, qword [fltTmp4]
	movsd qword [y], xmm0

	movsd xmm0, qword [x]
	movsd xmm1, qword [y]
	call glVertex2d								; plot(x5,y5)
	; -----
	movsd xmm2, qword [t]
	addsd xmm2, qword [tStep]
	movsd qword [t], xmm2						; increment t by tStep

	jmp mainLoop								; loop

breakMain:

; -----
;  Display image

	call	glEnd
	call	glFlush

; -----
;  Update s, s += sStep;
;  if (s > 1.0)
;	s = 0.0;

	movsd	xmm0, qword [s]			; s+= sStep
	addsd	xmm0, qword [sStep]
	movsd	qword [s], xmm0

	movsd	xmm0, qword [s]
	movsd	xmm1, qword [fltOne]
	ucomisd	xmm0, xmm1			; if (s > 1.0)
	jbe	resetDone

	movsd	xmm0, qword [fltZero]
	movsd	qword [sStep], xmm0
resetDone:

	call	glutPostRedisplay

; -----

	pop	rbp
	ret

; ******************************************************************
;  Generic function to display a string to the screen.
;  String must be NULL terminated.
;  Algorithm:
;	Count characters in string (excluding NULL)
;	Use syscall to output characters

;  Arguments:
;	1) address, string
;  Returns:
;	nothing

global	printString
printString:
	push	rbx

; -----
;  Count characters in string.

	mov	rbx, rdi			; str addr
	mov	rdx, 0
strCountLoop:
	cmp	byte [rbx], NULL
	je	strCountDone
	inc	rbx
	inc	rdx
	jmp	strCountLoop
strCountDone:

	cmp	rdx, 0
	je	prtDone

; -----
;  Call OS to output string.

	mov	rax, SYS_write			; system code for write()
	mov	rsi, rdi			; address of characters to write
	mov	rdi, STDOUT			; file descriptor for standard in
						; EDX=count to write, set above
	syscall					; system call

; -----
;  String printed, return to calling routine.

prtDone:
	pop	rbx
	ret

; ******************************************************************

