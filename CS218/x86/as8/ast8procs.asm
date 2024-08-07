; *****************************************************************
;  Name: Eduardo Salazar
;  NSHE ID: 5005695833
;  Section: 1003
;  Assignment: 8
;  Description: use functions to sort lists and calculate equations of
;  those lists. 


; -----------------------------------------------------------------
;  Write some assembly language functions.

;  The function, shellSort(), sorts the numbers into descending
;  order (large to small).  Uses the shell sort algorithm from
;  assignment #7 (modified to sort in descending order).

;  The function, basicStats(), finds the minimum, median, and maximum,
;  sum, and average for a list of numbers.
;  Note, the median is determined after the list is sorted.
;	This function must call the lstSum() and lstAvergae()
;	functions to get the corresponding values.
;	The lstAvergae() function must call the lstSum() function.

;  The function, linearRegression(), computes the linear regression of
;  the two data sets.  Summation and division performed as integer.

; *****************************************************************

section	.data

; -----
;  Define constants.

TRUE		equ	1
FALSE		equ	0

; -----
;  Local variables for shellSort() function (if any).

h		dd	0
i		dd	0
j		dd	0
tmp		dd	0

; -----
;  Local variables for basicStats() function (if any).


; -----------------------------------------------------------------

section	.bss

; -----
;  Local variables for linearRegression() function (if any).

qSum		resq	1
dSum		resd	1


; *****************************************************************

section	.text

; --------------------------------------------------------
;  Shell sort function (form asst #7).
;	Updated to sort in descending order.

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

mov dword [h], 1							; move 1 into h
mov r8d, 3									; move 3 into r8d

loopOne:									; while loop

	mov eax, dword [h]						; copy h into eax
	imul r8d								; multiply h * 3 (eax * r8d)
	add eax, 1								; add 1 to product (eax*r8d+1)

	cmp eax, esi							; if h >= length
	jge jumpOne								; break out of loop
	mov dword [h], eax						; update h
	jmp loopOne								; loop again
jumpOne:									; label to break loop

mov r10d, esi

loopTwo:									; while loop

	cmp dword [h], 0						; if h > 0
	jle jumpTwo								; break out of loop

	mov eax, dword [h]		
	sub eax, 1								; h - 1
	mov dword [i], eax						; i = h - 1

	loopThree:								; for loop

		cmp dword [i], r10d					; i < length
		jge jumpThree						; break out of loop

		mov r11d, dword [i]

		mov r8d, dword [edi+r11d*4]			; tmp = lst[i]
		mov dword [tmp], r8d

		mov dword [j], r11d					; j = i

		loopFour:									; for loop 2
			mov r11d, dword [j]
			cmp r11d, dword [h]						; first condition
			jl jumpFour								; if j >= h

			mov r11d, dword [tmp]					; set r11d to temp
			mov r12d, dword [j]
			sub r12d, dword [h]						; j - h
			cmp dword [edi+r12d*4], r11d			; second condition
			jg jumpFour								; if lst[j-h] > tmp

			mov r9d, dword [edi+r12d*4]				; lst[j-h]
			mov r11d, dword [j]
			mov dword [edi+r11d*4], r9d 			; lst[j] = lst[j-h]

			mov r11d, dword [h]
			sub dword [j], r11d						; decrement (j=j-h)

			jmp loopFour
		jumpFour:

		mov r8d, dword [tmp]
		mov r11d, dword [j]					; lst[j] = tmp
		mov dword [edi+r11d*4], r8d

		inc dword [i]						; increment i (i++)

		jmp loopThree
	jumpThree:								; for loop break
	
	mov r9d, 3								; set r9d to 3
	mov eax, dword [h]						; set eax to h
	cdq										; convert double to quadword
	idiv r9d								; eax/r9d
	mov dword [h], eax						; update h value

	jmp loopTwo 
jumpTwo:									; while loop break

	ret

; --------------------------------------------------------
;  Find basic statistical information for a list of integers:
;	minimum, median, maximum, sum, and average

;  Note, for an odd number of items, the median value is defined as
;  the middle value.  For an even number of values, it is the integer
;  average of the two middle values.

;  This function must call the lstSum() and lstAvergae() functions
;  to get the corresponding values.

;  Note, assumes the list is already sorted.

; -----
;  Call:
;	call basicStats(list, len, min, med, max, sum, ave)

;  Arguments Passed:
;	1) list, addr - rdi
;	2) length, value - rsi
;	3) minimum, addr - rdx
;	4) median, addr - rcx
;	5) maximum, addr - r8
;	6) sum, addr - r9
;	7) ave, addr - stack, rbp+16

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

	mov eax, dword [rdi+(rsi-1)*4]		; get min
	mov dword [rdx], eax				; set min

	mov eax, dword [rdi]				; get max
	mov dword [r8], eax					; set max

	mov r10d, 2							; set r10d to 2
	mov eax, esi						; set eax to length
	cdq									; convert to quad
	idiv r10d							; divide length by 2
	mov r11d, eax						; set r11d to answer

	cmp edx, 0							; compare remainder to 0
	je jumpFive							; jump if remainder is 0
	mov r10d, dword [edi+r11d*4]		; get middle value
	mov dword [ecx], r10d				; set median to middle value
	jmp jumpSix							; jump to skip next code block
jumpFive:
	mov eax, dword [edi+r11d*4]			; get first middle value
	add eax, dword [edi+(r11d-1)*4]		; add both middle values together
	cdq									; convert eax to quad
	idiv r10d							; divide by 2
	mov dword [ecx], eax				; set median to eax
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

; --------------------------------------------------------
;  Function to calculate the sum of a list.

; -----
;  Call:
;	ans = lstSum(lst, len)

;  Arguments Passed:
;	1) list, address - rdi
;	1) length, value - rsi

;  Returns:
;	sum (in eax)


global	lstSum
lstSum:

	mov r8d, 0				; increment/index
	mov ecx, esi			; decrement length
	mov eax, 0				; sum starting value

loopFive:
	add eax, dword [edi+r8d*4]			; add current value to eax

	inc r8d								; increment index
	loop loopFive						; decrement ecx and loop if not 0

	ret

; --------------------------------------------------------
;  Function to calculate the average of a list.
;  Note, must call the lstSum() fucntion.

; -----
;  Call:
;	ans = lstAve(lst, len)

;  Arguments Passed:
;	1) list, address - rdi
;	1) length, value - rsi

;  Returns:
;	average (in eax)


global	lstAve
lstAve:

	call lstSum						; call sum function to get sum in eax

	cdq								; convert eax to quad
	idiv esi						; divide eax by length

	ret

; --------------------------------------------------------
;  Function to calculate the linear regression
;  between two lists (of equal size).
;  Due to the data sizes, the summation for the dividend (top)
;  MUST be performed as a quad-word.

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
;	7) b1, address - stack, rpb+16

;  Returns:
;	b0 and b1 via reference

global linearRegression
linearRegression:

	push rbp
	mov rbp, rsp
	push r9
	push rdx
	
	mov qword [qSum], 0
	mov dword [dSum], 0
	mov r10d, edx					; decrement
	push r10						; save value for later
	mov r11d, 0						; index/inc
	mov r14, 0						; total of top dividend

loopSix:							; top dividend

	mov r12d, dword [edi+r11d*4]
	sub r12d, ecx					; (x[i]-x[ave]) = r12d

	mov r13d, dword [esi+r11d*4]
	sub r13d, r8d					; (y[i]-y[ave]) = r13d

	mov eax, r12d
	mov edx, 0
	imul r13d						; r12d * r13d = rax
	mov dword [qSum], eax			; add answer to sum
	mov dword [qSum+4], edx
	add r14, qword [qSum]			; add total to r14

	inc r11d

	dec r10d
	cmp r10d, 0						; break loop when r10d is 0
	jne loopSix

	mov qword [qSum], r14			; set qSum
	mov r11d, 0						; index/inc
	pop r10							; restore same length value for decrement

loopSeven:							; bottom dividend

	mov r12d, dword [edi+r11d*4]
	sub r12d, ecx					; (x[i]-x[ave]) = r12d

	mov eax, r12d
	imul eax						; (r12d)^2 = rax
	add dword [dSum], eax			; add total to dSum

	inc r11d						; increment index

	dec r10d
	cmp r10d, 0						; break loop when r10d is 0
	jne loopSeven

	mov eax, dword [qSum]			; mov qSum to edx:eax
	mov edx, dword [qSum+4]
	idiv dword [dSum]				; divide edx:eax by dSum

	mov rbx, qword [rbp+16]
	mov dword [rbx], eax			; set b1

	imul ecx						; b1 * x[ave] = edx:eax
	sub r8d, eax					; y[ave] - eax = r8d
	mov dword [r9d], r8d			; set b0

	pop rdx
	pop r9							; reset registers
	pop rbp


	ret

; ********************************************************************************

