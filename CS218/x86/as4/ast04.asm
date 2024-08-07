; *****************************************************************
;  Name: Eduardo Salazar
;  NSHE ID: 5005695833
;  Section: 1003
;  Assignment: 4
;  Description: find  the average of a list of numbers

; ***************************************************************

section	.data

; -----
;  Define constants.

NULL		equ	0			; end of string

TRUE		equ	1
FALSE		equ	0

EXIT_SUCCESS	equ	0			; successful operation
SYS_exit	equ	60			; call code for terminate

; -----

lst		dd	4224, 1116, 1542, 1240, 1677
		dd	1635, 2420, 1820, 1246, 1333 
		dd	2315, 1215, 2726, 1140, 2565
		dd	2871, 1614, 2418, 2513, 1422 
		dd	1119, 1215, 1525, 1712, 1441
		dd	3622, 1731, 1729, 1615, 2724 
		dd	1217, 1224, 1580, 1147, 2324
		dd	1425, 1816, 1262, 2718, 1192 
		dd	1435, 1235, 2764, 1615, 1310
		dd	1765, 1954, 1967, 1515, 1556 
		dd	1342, 7321, 1556, 2727, 1227
		dd	1927, 1382, 1465, 3955, 1435 
		dd	1225, 2419, 2534, 1345, 2467
		dd	1615, 1959, 1335, 2856, 2553 
		dd	1035, 1833, 1464, 1915, 1810
		dd	1465, 1554, 1267, 1615, 1656 
		dd	2192, 1825, 1925, 2312, 1725
		dd	2517, 1498, 1677, 1475, 2034 
		dd	1223, 1883, 1173, 1350, 2415
		dd	1335, 1125, 1118, 1713, 3025

length		dd	100
half        dd  2
nines       dd  9

lstMin		dd	0
estMed		dd	0
lstMax		dd	0
lstSum		dd	0
lstAve		dd	0

oddCnt		dd	0
oddSum		dd	0
oddAve		dd	0

nineCnt		dd	0
nineSum		dd	0
nineAve		dd	0

; **********************************************************

section	.text
global _start
_start:

; *******************************************************

mov r8d, dword [lst]        ; gets first element in list
mov ecx, dword [length]     ; decrement counter
mov rsi, 0                  ; set increment counter to 0

mov dword [lstMin], r8d     ; fill list minimum with first element
mov dword [lstMax], r8d     ; fill list maximum with first element

; -----
; First loop

loopOne:                    ; Label

add r8d, dword [lst+rsi*4]  ; adds elements in list (note: might be adding first element twice)

mov r14d, dword [lst+rsi*4] ; set r14d to next item in list
cmp r14d, dword [lstMin]    ; If (A >= B)
jae jumpOne                 ; Jump to loop two
mov dword [lstMin], r14d    ; sets list minimum
jumpOne:                    ; Label

mov r9d, dword [lst+rsi*4]  ; set r9d to next item in list
cmp r9d, dword [lstMax]     ; if (A <= B)
jbe jumpTwo               ; jump to loop three
mov dword [lstMax], r9d     ; sets list maximum
jumpTwo:                  ; Label

mov eax, dword [lst+rsi*4]  ; sets eax to next item in list
mov edx, 0                  ; sets edx to 0
div dword [half]            ; divides the current number in list (eax) by 2

cmp edx, 0                  ; if remainder is equal to 0
je jumpThree               ; jump to loop five
add dword [oddSum], r14d    ; adds current element to odd number sum
inc dword [oddCnt]          ; increments odd number count
jumpThree:                   ; Label

inc rsi                     ; increment rsi
loop loopOne                ; jump to loopOne

; -----
; Second Loop

mov ecx, dword [length]     ; decrement counter
mov rsi, 0                  ; set increment counter to 0

loopTwo:                    ; Label

mov r13d, dword [lst+rsi*4]	; holds current element

mov eax, dword [lst+rsi*4]
mov edx, 0
div dword [nines]
cmp edx, 0
jne jumpFour
add dword [nineSum], r13d	; adds element to nine sum
inc dword [nineCnt]			; increments nine count
jumpFour:

inc rsi
loop loopTwo

sub r8d, dword [lst]		; subtract first element
mov dword [lstSum], r8d     ; set list sum

; -----
; divide sum by total for average 

mov eax, dword [lstSum]
mov edx, 0
div dword [length]
mov dword [lstAve], eax     ; set list average

mov eax, dword [oddSum]
mov edx, 0
div dword [oddCnt]
mov dword [oddAve], eax     ; set odd average

mov eax, dword [nineSum]
mov edx, 0
div dword [nineCnt]
mov dword [nineAve], eax    ; set nine average

; -----
; find estimated median

mov eax, dword [length]
mov edx, 0
div dword [half]

mov r10d, dword [lst]           ; first element in list
add dword [estMed], r10d        ; add to estimated med
mov r11d, dword [length]      ; length of list (100)
mov r10d, dword [lst+(r11d-1)*4]    ; last element in list
add dword [estMed], r10d        ; add to estimated med
mov r10d, dword [lst+(eax-1)*4]     ; first middle element in list
add dword [estMed], r10d        ; add to estimated med 
mov r10d, dword [lst+eax*4] ; second middle element in list
add dword [estMed], r10d        ; add to estimated med

mov r8d, 4
mov eax, dword [estMed]
mov edx, 0
div r8d                         ; divide estimated median by 4
mov dword [estMed], eax         ; set estimated median

; *****************************************************************
;	Done, terminate program.

last:
	mov	rax, SYS_exit		; call call for exit (SYS_exit)
	mov	rbx, EXIT_SUCCESS	; return code of 0 (no error)
	syscall
