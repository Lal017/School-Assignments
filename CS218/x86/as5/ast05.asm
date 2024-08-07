; *****************************************************************
;  Name: Eduardo Salazar
;  NSHE ID: 5005695833
;  Section: 1003
;  Assignment: 5
;  Description: calculate and output surface area and volume values

; *****************************************************************

section	.data

; -----
;  Define constants.

NULL		equ	0			; end of string

TRUE		equ	1
FALSE		equ	0

EXIT_SUCCESS	equ	0			; successful operation
SYS_exit	equ	60			; call code for terminate

; -----
;  Provided Data

lengths		dd	 1355,  1037,  1123,  1024,  1453
		dd	 1115,  1135,  1123,  1123,  1123
		dd	 1254,  1454,  1152,  1164,  1542
		dd	-1353,  1457,  1182, -1142,  1354
		dd	 1364,  1134,  1154,  1344,  1142
		dd	 1173, -1543, -1151,  1352, -1434
		dd	 1134,  2134,  1156,  1134,  1142
		dd	 1267,  1104,  1134,  1246,  1123
		dd	 1134, -1161,  1176,  1157, -1142
		dd	-1153,  1193,  1184,  1142

widths		dw	  367,   316,   542,   240,   677
		dw	  635,   426,   820,   146,  -333
		dw	  317,  -115,   226,   140,   565
		dw	  871,   614,   218,   313,   422	
		dw	 -119,   215,  -525,  -712,   441
		dw	 -622,  -731,  -729,   615,   724
		dw	  217,  -224,   580,   147,   324
		dw	  425,   816,   262,  -718,   192
		dw	 -432,   235,   764,  -615,   310
		dw	  765,   954,  -967,   515

heights		db	   42,    21,    56,    27,    35
		db	  -27,    82,    65,    55,    35
		db	  -25,   -19,   -34,   -15,    67
		db	   15,    61,    35,    56,    53
  		db	  -32,    35,    64,    15,   -10
		db	   65,    54,   -27,    15,    56
		db	   92,   -25,    25,    12,    25
		db	  -17,    98,   -77,    75,    34
		db	   23,    83,   -73,    50,    15
		db	   35,    25,    18,    13

count		dd	49

vMin		dd	0
vEstMed		dd	0
vMax		dd	0
vSum		dd	0
vAve		dd	0

saMin		dd	0
saEstMed	dd	0
saMax		dd	0
saSum		dd	0
saAve		dd	0

; -----
; Additional variables (if any)

temp        dd  0
tempTwo		dw	0
saCurr		dd	0			; holds current surface area value

; --------------------------------------------------------------
; Uninitialized data

section	.bss

volumes		resd	49
surfaceAreas	resd	49

; **********************************************************

section	.text
global _start
_start:

; *******************************************************
; Code

mov ecx, dword [count]         ; Length of lists put into decrement counter
mov rsi, 0                      ; increment

loopOne:                        ; Label
; -----
; find vSum

movsx ax, byte [heights+rsi]    ; sign extend byte to word
imul word [widths+rsi*2]        ; multiply ax(height) by width
mov word [temp], ax             ; store product in temp variable
mov word [temp+2], dx

mov eax, dword [temp]           ; store temp variable in eax
imul dword [lengths+rsi*4]      ; multiply prev product by length
add dword [vSum], eax           ; add answer to vSum

; -----
; find vMax

cmp dword [vMax], eax           ; if A >= B
jge jumpOne                     ; jump to jumpOne
mov dword [vMax], eax           ; set new vMax
jumpOne:                        ; Label

; -----
; find vMin

cmp dword [vMin], eax           ; if A <= B
jle jumpTwo                     ; jump to jumpTwo
mov dword [vMin], eax           ; set new vMin
jumpTwo:                        ; Label

; -----
; find estMed

mov dword [volumes+rsi*4], eax

inc rsi                         ; increment rsi

loop loopOne

; -----
; Find estMed

mov r12d, 3								; set r12d to 3
mov r10d, dword [volumes]				; get first element in volumes
add dword [vEstMed], r10d				; add first element to vEstMed
mov r11d, dword [count]				; set r11d to length
mov r10d, dword [volumes+(r11d-1)*4]	; get last element in volumes
add dword [vEstMed], r10d				; add last element to vEstMed
mov r11d, 25							; set r11d to 25 (middle of the list)
mov r10d, dword [volumes+(r11d-1)*4]	; get 25th element in list
add dword [vEstMed], r10d				; add element to vEstMed

mov eax, dword [vEstMed]				; set sum to eax
cdq										; convert double to quadword
idiv r12d								; divide by 3
mov dword [vEstMed], eax				; set vEstMed to answer

; -----
; Find vAve

mov eax, dword [vSum]					; set vSum to eax
cdq										; convert double to quadword
idiv dword [count]						; divide by length of list
mov dword [vAve], eax					; set vAve to answer

; -----
; Second Loop

mov rsi, 0								; set increment counter
mov ecx, dword [count]					; set decrement counter

loopTwo:								; Label

mov al, 2								; Set al to 2
imul byte [heights+rsi]					; 2 x Height = ax
imul word [widths+rsi*2]				; ax x Width = dx:ax
mov word [saCurr], ax					; store product in saCurr
mov word [saCurr+2], dx

mov al, 2								; set al to 2
imul byte [heights+rsi]					; 2 x Height = ax
mov word [tempTwo], ax
movsx eax, word [tempTwo]				; sign extend product
imul dword [lengths+rsi*4]				; eax x Length
add dword [saCurr], eax					; add product to saCurr

mov ax, 2								; set ax to 2
imul word [widths+rsi*2]				; 2 x Width = dx:ax
mov word [temp], ax						
mov word [temp+2], dx
mov eax, dword [temp]
imul dword [lengths+rsi*4]				; eax x Length = edx:eax
add dword [saCurr], eax					; add product to saCurr

; -----
; find saSum

mov eax, dword [saCurr]
add dword [saSum], eax						; Add sa to sum

; -----
; find saEstMed

mov dword [surfaceAreas+rsi*4], eax

; -----
; find saMax

cmp dword [saMax], eax						; if A >= B
jge jumpThree								; jump to jumpThree
mov dword [saMax], eax						; update saMax
jumpThree:									; Label

; -----
; find saMin

cmp dword [saMin], eax						; if A <= B
jle jumpFour								; jump to jumpFour
mov dword [saMin], eax						; update saMin
jumpFour:									; Label

; -----
; find saAve

mov eax, dword [saSum]
cdq											; convert double to quadword
idiv dword [count]							; divide sum by length of array
mov dword [saAve], eax						; set saAve

inc rsi										; increment rsi

dec ecx
cmp ecx, 0									; Loop instruction
jne loopTwo

; -----
; find saEstMed

mov r8d, 3									; set r8d to 3
mov r9d, dword [surfaceAreas]				; get first surface area in array
add dword [saEstMed], r9d					; add first element to saEstMed
mov r10d, dword [count]					; move size of array to r10d
mov r9d, dword [surfaceAreas+(r10d-1)*4]	; get last element in array
add dword [saEstMed], r9d					; add to saEstMed
mov r10d, 25
mov r9d, dword [surfaceAreas+(r10d-1)*4]	; get middle element in array
add dword [saEstMed], r9d					; add to saEstMed

mov eax, dword [saEstMed]
cdq
idiv r8d									; divide total by 3
mov dword [saEstMed], eax					; set saEstMed

; *****************************************************************
;	Done, terminate program.

last:
	mov	rax, SYS_exit		; call call for exit (SYS_exit)
	mov	rbx, EXIT_SUCCESS	; return code of 0 (no error)
	syscall
