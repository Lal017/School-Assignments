; *****************************************************************
;  Name: Eduardo Salazar
;  NSHE ID: 5005695833
;  Section: 1003
;  Assignment: 9
;  Description: Read an input sept value and perform linear regression
;               equations.

; -----------------------------------------------------------------------------
;  Write assembly language functions.

;  Function, shellSort(), sorts the numbers into ascending
;  order (small to large).  Uses the shell sort algorithm
;  modified to sort in ascending order.

;  Function lstSum() to return the sum of a list.

;  Function lstAverage() to return the average of a list.
;  Must call the lstSum() function.

;  Fucntion basicStats() finds the minimum, median, and maximum,
;  sum, and average for a list of numbers.
;  The median is determined after the list is sorted.
;  Must call the lstSum() and lstAverage() functions.

;  Function linearRegression() computes the linear regression.
;  for the two data sets.  Must call the lstAverage() function.

;  Function readSeptNum() should read a septenary number
;  from the user (STDIN) and perform apprpriate error checking.


; ******************************************************************************

section	.data

; -----
;  Define standard constants.

TRUE		equ	1
FALSE		equ	0

EXIT_SUCCESS	equ	0			; Successful operation

STDIN		equ	0			; standard input
STDOUT		equ	1			; standard output
STDERR		equ	2			; standard error

SYS_read	equ	0			; system call code for read
SYS_write	equ	1			; system call code for write
SYS_open	equ	2			; system call code for file open
SYS_close	equ	3			; system call code for file close
SYS_fork	equ	57			; system call code for fork
SYS_exit	equ	60			; system call code for terminate
SYS_creat	equ	85			; system call code for file open/create
SYS_time	equ	201			; system call code for get time

LF		equ	10
SPACE		equ	" "
NULL		equ	0
ESC		equ	27

; -----
;  Define program specific constants.

SUCCESS 	equ	0
NOSUCCESS	equ	1
OUTOFRANGEMIN	equ	2
OUTOFRANGEMAX	equ	3
INPUTOVERFLOW	equ	4
ENDOFINPUT	equ	5

LIMIT		equ	1510

MIN		equ	-100000
MAX		equ	100000

BUFFSIZE	equ	50			; 50 chars including NULL

; -----
;  NO static local variables allowed...


; ******************************************************************************

section	.text

; -----------------------------------------------------------------------------
;  Read an ASCII septenary number from the user.

;  Return codes:
;	SUCCESS			Successful conversion
;	NOSUCCESS		Invalid input entered
;	OUTOFRANGEMIN		Input below minimum value
;	OUTOFRANGEMAX		Input above maximum value
;	INPUTOVERFLOW		User entry character count exceeds maximum length
;	ENDOFINPUT		End of the input

; -----
;  Call:
;	status = readSeptNum(&numberRead);

;  Arguments Passed:
;	1) numberRead, addr - rdi

;  Returns:
;	number read (via reference)
;	status code (as above)

global readSeptNum
readSeptNum:

    push rbp
    mov rbp, rsp
    sub rsp, 51

    push rbx
    push r12
    push r13
    push r14

    mov r12, rdi                    ; set numberRead address to r12
    lea rbx, byte [rbp-50]          ; mov buffer address to rbx
    mov r13, 0                      ; inc for char

charLoop:

    mov rax, SYS_read
    mov rdi, STDIN
    lea rsi, byte [rbp-51]
    mov rdx, 1
    syscall

    mov r14b, byte [rbp-51]           ; store char in r14b
    cmp r14b, LF                      ; compare with line feed
    je breakRead                      ; jump if equal

    cmp r13, BUFFSIZE                 ; if char size >= 50
    jae skipStore

    mov byte [rbx+r13], r14b
    inc r13
skipStore:
    jmp charLoop
breakRead:

    cmp r13, 0                      ; if only linefeed was entered
    je endInput

    cmp r13, BUFFSIZE               ; check if too many characters were entered
    jb nullInput

    mov rax, INPUTOVERFLOW          ; error message
    jmp funcDone

nullInput:

    mov byte [rbx+r13], NULL        ; input NULL
    mov r14, 0
    mov r11, 0

convertLoop:

	mov r11b, byte [rbx+r14]	; sets r11b to current char in aSeptLength
	cmp r11b, " "			    ; if char != " "
	jne next				    ; jump to next
	inc r14					    ; increment address by 1
	jmp convertLoop				; loop back to blanks

next:

    mov r8, 1				    ; set sign value to positive
	cmp r11b, "+"			    ; compare sign value char to negative
	je positive 			    ; jump if positive
	
	cmp r11b, "-"
	jne setNoSucc
	mov r8, -1				    ; set sign value to negative

positive:

    inc r14
    mov eax, 0				    ; set eax to 0

convLoop:
	mov r11b, byte [rbx+r14]	; get next char

	cmp r11b, NULL			    ; if char = NULL
	je loopExit 			    ; jump to setSucc

    cmp r11b, 0x30              ; if char is below "0"
    jl setNoSucc                ; jump to setNoSucc

    cmp r11b, 0x36              ; if char is above "6"
    jg setNoSucc                ; jump to setNoSucc

	sub r11b, 0x30			    ; subtraxt ASCII value of char by 0x30

	mov r9d, 7				    ; set r9d to 7
	mul r9d					    ; multiply eax by 7
	add eax, r11d			    ; add r11d (r11b) to eax

	inc r14					    ; increment address by 1
	jmp convLoop			    ; jump to start of loop

setNoSucc:

    mov rax, NOSUCCESS
    jmp funcDone

loopExit:

    imul r8d
    mov dword [r12], eax        ; store value in address of r12

    cmp dword [r12], MIN        ; if (value <= MIN)
    jl minError

    cmp dword [r12], MAX        ; if (value >= MAX)
    jg maxError

    mov rax, SUCCESS            ; else { set return to success }
    jmp funcDone

minError:

    mov rax, OUTOFRANGEMIN
    jmp funcDone

maxError:

    mov rax, OUTOFRANGEMAX
    jmp funcDone

endInput:

    mov rax, ENDOFINPUT

funcDone:

    pop r14
    pop r13
    pop r12
    pop rbx

    mov rsp, rbp
    pop rbp

    ret

; -----------------------------------------------------------------------------
;  Shell sort function.

; -----
;  HLL Call:
;	call shellSort(list, len)

;  Arguments Passed:
;	1) list, addr - rdi
;	2) length, value - rsi

;  Returns:
;	sorted list (list passed by reference)

global	shellSort
shellSort:

push rbp
mov rbp, rsp
sub rsp, 16

push r12
push r8
push r11

mov dword [rbp-4], 1						; move 1 into h
mov r8d, 3									; move 3 into r8d

loopOne:									; while loop

	mov eax, dword [rbp-4]					; copy h into eax
	imul r8d								; multiply h * 3 (eax * r8d)
	add eax, 1								; add 1 to product (eax*r8d+1)

	cmp eax, esi							; if h >= length
	jge jumpOne								; break out of loop
	mov dword [rbp-4], eax					; update h
	jmp loopOne								; loop again
jumpOne:									; label to break loop

mov r10d, esi

loopTwo:									; while loop

	cmp dword [rbp-4], 0					; if h > 0
	jle jumpTwo								; break out of loop

	mov eax, dword [rbp-4]		            ; eax = h
	sub eax, 1								; h - 1
	mov dword [rbp-8], eax					; i = h - 1

	loopThree:								; for loop

		cmp dword [rbp-8], r10d				; i < length
		jge jumpThree						; break out of loop

		mov r11d, dword [rbp-8]             ; r11d = i

		mov r8d, dword [rdi+r11*4]			; tmp = lst[i]
		mov dword [rbp-12], r8d             ; tmp = rbp-12

		mov dword [rbp-16], r11d					    ; j = i

		loopFour:									    ; for loop 2
			mov r11d, dword [rbp-16]
			cmp r11d, dword [rbp-4]						; first condition
			jl jumpFour								    ; if j >= h

			mov r11d, dword [rbp-12]					; set r11d to temp
			mov r12d, dword [rbp-16]
			sub r12d, dword [rbp-4]						; j - h
			cmp dword [rdi+r12*4], r11d			    ; second condition
			jle jumpFour								; if lst[j-h] > tmp

			mov r9d, dword [rdi+r12*4]				    ; lst[j-h]
			mov r11d, dword [rbp-16]
			mov dword [rdi+r11*4], r9d 			    ; lst[j] = lst[j-h]

			mov r11d, dword [rbp-4]
			sub dword [rbp-16], r11d					; decrement (j=j-h)

			jmp loopFour
		jumpFour:

		mov r8d, dword [rbp-12]
		mov r11d, dword [rbp-16]					; lst[j] = tmp
		mov dword [rdi+r11*4], r8d

		inc dword [rbp-8]						; increment i (i++)

		jmp loopThree
	jumpThree:								; for loop break
	
	mov r9d, 3								; set r9d to 3
	mov eax, dword [rbp-4]					; set eax to h
	cdq										; convert double to quadword
	idiv r9d								; eax/r9d
	mov dword [rbp-4], eax					; update h value

	jmp loopTwo 
jumpTwo:									; while loop break

    pop r11
    pop r8
    pop r12

    mov rsp, rbp
    pop rbp

	ret

; -----------------------------------------------------------------------------
;  Find basic statistical information for a list of integers:
;	minimum, median, maximum, sum, and average

;  Note, for an odd number of items, the median value is defined as
;  the middle value.  For an even number of values, it is the integer
;  average of the two middle values.

;  This function must call the lstSum() and lstAvergae() functions
;  to get the corresponding values.

;  Note, assumes the list is already sorted.

; -----
;  HLL Call:
;	call basicStats(list, len, min, med, max, sum, ave)
;                    rdi  rsi  rdx  rcx  r8  r9  rbp+16
;  Returns:
;	minimum, median, maximum, sum, and average
;	via pass-by-reference (addresses on stack)

global basicStats
basicStats:

	push rbp
	mov rbp, rsp
	push r9
	push rbx							; push registers that i will be using
	push rdx
	push r8
	push rcx

	mov eax, dword [rdi]		        ; get min
	mov dword [rdx], eax				; set min

	mov eax, dword [rdi+(rsi-1)*4]		; get max
	mov dword [r8], eax					; set max

	mov r10d, 2							; set r10d to 2
	mov eax, esi						; set eax to length
	cdq									; convert to quad
	idiv r10d							; divide length by 2
	mov r11d, eax						; set r11d to answer

	cmp edx, 0							; compare remainder to 0
	je jumpFive							; jump if remainder is 0
	mov r10d, dword [rdi+r11*4] 		; get middle value
	mov dword [rcx], r10d				; set median to middle value
	jmp jumpSix							; jump to skip next code block
jumpFive:
	mov eax, dword [rdi+r11*4]			; get first middle value
	add eax, dword [rdi+(r11-1)*4]		; add both middle values together
	idiv r10d							; divide by 2
	mov dword [rcx], eax				; set median to eax
jumpSix:

	call lstSum							; call sum function
	mov dword [r9], eax					; set sum

	call lstAve							; call ave function
	mov rbx, qword [rbp+16]				; get ave
	mov dword [rbx], eax				; set ave

	pop rcx
	pop r8
	pop rdx								; restore values of registers
	pop rbx
	pop r9
	pop rbp

	ret

; -----------------------------------------------------------------------------
;  Function to calculate the sum of a list.

; -----
;  Call:
;	ans = lstSum(lst, len)

;  Arguments Passed:
;	1) list, address
;	2) length, value

;  Returns:
;	sum (in eax)

global	lstSum
lstSum:

	mov r8, 0				; increment/index
	mov ecx, esi			; decrement length
	mov rax, 0				; sum starting value

loopFive:
	add eax, dword [rdi+r8*4]			; add current value to eax

	inc r8								; increment index
	loop loopFive						; decrement ecx and loop if not 0

	ret

; -----------------------------------------------------------------------------
;  Function to calculate the average of a list.
;  Note, must call the lstSum() fucntion.

; -----
;  Call:
;	ans = lstAve(lst, len)

;  Arguments Passed:
;	1) list, address
;	2) length, value

;  Returns:
;	average (in eax)

global	lstAve
lstAve:

	call lstSum						; call sum function to get sum in eax

	cdq								; convert eax to quad
	idiv esi						; divide eax by length

	ret

; -----------------------------------------------------------------------------
;  Function to calculate the linear regression
;  between two lists (of equal size).

; -----
;  Call:
;	linearRegression(xList, yList, len, xAve, yAve, b0, b1)

;  Arguments Passed:
;	1) xList, address - rdi
;	2) yList, address - rsi 
;	3) length, value - edx
;	4) xList average, value - ecx
;	5) yList average, value - r8d
;	6) b0, address - r9
;	7) b1, address - stack, rbp+16

;  Returns:
;	b0 and b1 via reference

global linearRegression
linearRegression:

	push rbp
	mov rbp, rsp
    sub rsp, 12
    
	push rdx
	push r8
	push r9
	push r10
	push r11
	
	mov qword [rbp-8], 0            ; qSum = rbp - 8
	mov dword [rbp-12], 0           ; dSum = rbp - 12
	mov r10d, edx					; decrement
	push r10						; save value for later
	mov r11, 0						; index/inc
	mov r14, 0						; total of top dividend

loopSix:							; top dividend

	mov r12d, dword [rdi+r11*4]
	sub r12d, ecx					; (x[i]-x[ave]) = r12d

	mov r13d, dword [rsi+r11*4]
	sub r13d, r8d 					; (y[i]-y[ave]) = r13d

	mov eax, r12d
	mov edx, 0
	imul r13d						; r12d * r13d = rax
	mov dword [rbp-8], eax			; add answer to sum
	mov dword [rbp-4], edx
	add r14, qword [rbp-8]			; add total to r14

	inc r11

	dec r10d
	cmp r10d, 0						; break loop when r10d is 0
	jne loopSix

	mov qword [rbp-8], r14			; set qSum
	mov r11d, 0						; index/inc
	pop r10							; restore same length value for decrement

loopSeven:							; bottom dividend

	mov r12d, dword [rdi+r11*4]
	sub r12d, ecx					; (x[i]-x[ave]) = r12d

	mov eax, r12d
	imul eax						; (r12d)^2 = rax
	add dword [rbp-12], eax			; add total to dSum

	inc r11d						; increment index

	dec r10d
	cmp r10d, 0						; break loop when r10d is 0
	jne loopSeven

	mov rax, qword [rbp-8]			; mov qSum to edx:eax
    cqo
    movsxd r15, dword [rbp-12]
	idiv r15        				; divide edx:eax by dSum

	mov r10, rax

	imul ecx						; b1 * x[ave] = edx:eax
	sub r8d, eax					; y[ave] - eax = r8d
	mov qword [r9], r8			; set b0

	mov rbx, qword [rbp+16]
	mov qword [rbx], r10			; set b1

	pop r11
	pop r10
	pop r9
	pop r8							; reset registers
	pop rdx

    mov rsp, rbp
	pop rbp

	ret

; -----------------------------------------------------------------------------
last:
	mov	rax, SYS_exit
	mov	rdi, EXIT_SUCCESS
	syscall
