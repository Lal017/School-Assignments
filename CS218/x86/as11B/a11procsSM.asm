;  CS 218 - Assignment #11
;  Functions Template
; *****************************************************************
;  Name: Eduardo Salazar
;  NSHE ID: 5005695833
;  Section: 1003
;  Assignment: 11
;  Description: read in an image, compress it and then output the image

; ***********************************************************************
;  Data declarations
;	Note, the error message strings should NOT be changed.
;	All other variables may changed or ignored...

section	.data

; -----
;  Define standard constants.

LF		equ	10			; line feed
NULL		equ	0			; end of string
SPACE		equ	0x20			; space

TRUE		equ	1
FALSE		equ	0

SUCCESS		equ	0			; Successful operation
NOSUCCESS	equ	1			; Unsuccessful operation

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

O_CREAT		equ	0x40
O_TRUNC		equ	0x200
O_APPEND	equ	0x400

O_RDONLY	equ	000000q			; file permission - read only
O_WRONLY	equ	000001q			; file permission - write only
O_RDWR		equ	000002q			; file permission - read and write

S_IRUSR		equ	00400q
S_IWUSR		equ	00200q
S_IXUSR		equ	00100q

; -----
;  Define program specific constants.

MIN_FILE_LEN	equ	5

; buffer size (part A) - DO NOT CHANGE THE NEXT LINE.
BUFF_SIZE	equ	3

; -----
;  Variables for getImageFileName() function.

eof		db	FALSE

usageMsg	db	"Usage: ./makeThumb <inputFile.bmp> "
		db	"<outputFile.bmp>", LF, NULL
errIncomplete	db	"Error, incomplete command line arguments.", LF, NULL
errExtra	db	"Error, too many command line arguments.", LF, NULL
errReadName	db	"Error, invalid source file name.  Must be '.bmp' file.", LF, NULL
errWriteName	db	"Error, invalid output file name.  Must be '.bmp' file.", LF, NULL
errReadFile	db	"Error, unable to open input file.", LF, NULL
errWriteFile	db	"Error, unable to open output file.", LF, NULL

; -----
;  Variables for setImageInfo() function.

HEADER_SIZE	equ	138

errReadHdr	db	"Error, unable to read header from source image file."
		db	LF, NULL
errFileType	db	"Error, invalid file signature.", LF, NULL
errDepth	db	"Error, unsupported color depth.  Must be 24-bit color."
		db	LF, NULL
errCompType	db	"Error, only non-compressed images are supported."
		db	LF, NULL
errSize		db	"Error, bitmap block size inconsistent.", LF, NULL
errWriteHdr	db	"Error, unable to write header to output image file.", LF,
		db	"Program terminated.", LF, NULL

; -----
;  Variables for readRow() function.

buffMax		dq	BUFF_SIZE
curr		dq	BUFF_SIZE
wasEOF		db	FALSE
pixelCount	dq	0

errRead		db	"Error, reading from source image file.", LF,
		db	"Program terminated.", LF, NULL

; -----
;  Variables for writeRow() function.

errWrite	db	"Error, writting to output image file.", LF,
		db	"Program terminated.", LF, NULL

; ------------------------------------------------------------------------
;  Unitialized data

section	.bss

buffer		resb	BUFF_SIZE
header		resb	HEADER_SIZE

; ############################################################################

section	.text

; ***************************************************************
;  Routine to get image file names (from command line)
;	Verify files by atemptting to open the files (to make
;	sure they are valid and available).

;  Command Line format:
;	./makeThumb <inputFileName> <outputFileName>

; -----
;  Arguments:
;	- argc (value) - rdi
;	- argv table (address) - rsi
;	- read file descriptor (address) - rdx
;	- write file descriptor (address) -rcx
;  Returns:
;	read file descriptor (via reference)
;	write file descriptor (via reference)
;	TRUE or FALSE

global getImageFileNames
getImageFileNames:

	push r12
	push r13
	push r14
	push r15

	mov r15, rcx					; set address of write file descriptor to r15
	mov r12, rsi					; set address of argv to r12

	cmp rdi, 1						; if only 1 input was entered
	je usgError

	cmp rdi, 3						; if not enough inputs were entered
	jl incError

	cmp rdi, 3						; if too many inputs were entered
	jg extError

	mov r13, qword [r12+8]			; get 2nd command line argument
	mov r14, 0						; increment

checkString:

	mov al, byte [r13+r14]			; get char
	cmp al, "."						; check for "." char
	je foundChar
	cmp al, NULL
	je readErr
	inc r14							; i++
	jmp checkString

foundChar:

	inc r14							; i++
	mov al, byte [r13+r14]			; get char
	cmp al, "b"						; compare with "c"
	jne readErr						; jump to error
	inc r14							; i++
	mov al, byte [r13+r14]			; get char
	cmp al, "m"						; compare with "m"
	jne readErr						; jump to error
	inc r14							; i++
	mov al, byte [r13+r14]			; get char
	cmp al, "p"						; compare with "p"
	jne readErr						; jump to error
	inc r14							; i++
	mov al, byte [r13+r14]			; get char
	cmp al, NULL					; compare with NULL
	jne readErr						; jump to error

	mov rax, SYS_open				; file open
	mov rdi, r13					; file name
	mov rsi, O_RDONLY				; read only
	syscall							; system call
	cmp rax, 0						; if file did not open (rax < 0)
	jl inFileOpenErr				; jump to error message
	mov qword [rdx], rax			; store file descriptor in rdx

	mov r13, qword [r12+16]			; get 3rd command line argument
	mov r14, 0						; increment

checkString2:

	mov al, byte [r13+r14]			; get char
	cmp al, "."						; check for "." char
	je foundChar2
	cmp al, NULL
	je writeErr
	inc r14							; i++
	jmp checkString2

foundChar2:

	inc r14							; i++
	mov al, byte [r13+r14]			; get char
	cmp al, "b"						; compare with "c"
	jne writeErr					; jump to error
	inc r14							; i++
	mov al, byte [r13+r14]			; get char
	cmp al, "m"						; compare with "m"
	jne writeErr					; jump to error
	inc r14							; i++
	mov al, byte [r13+r14]			; get char
	cmp al, "p"						; compare with "p"
	jne writeErr					; jump to error
	inc r14							; i++
	mov al, byte [r13+r14]			; get char
	cmp al, NULL					; compare with NULL
	jne writeErr					; jump to error

	mov rax, SYS_creat				; file create
	mov rdi, r13					; file name
	mov rsi, S_IRUSR | S_IWUSR		; read and write to file
	syscall							; system call
	cmp rax, 0						; if file did not open (rax < 0)
	jl outFileOpenErr				; jump to error message
	mov qword [r15], rax			; store file descripto in r15

	mov rax, TRUE					; set return to true
	jmp endFuncTrue					; jump to end of function

usgError:							; error messages

	mov rdi, usageMsg
	call printString
	jmp endFuncFalse

incError:

	mov rdi, errIncomplete
	call printString
	jmp endFuncFalse

extError:

	mov rdi, errExtra
	call printString
	jmp endFuncFalse

readErr:

	mov rdi, errReadName
	call printString
	jmp endFuncFalse

writeErr:

	mov rdi, errWriteName
	call printString
	jmp endFuncFalse

inFileOpenErr:

	mov rdi, errReadFile
	call printString
	jmp endFuncFalse

outFileOpenErr:

	mov rdi, errWriteFile
	call printString
	jmp endFuncFalse

endFuncFalse:
	mov rax, FALSE					; set return to false
endFuncTrue:

	pop r15
	pop r14
	pop r13
	pop r12

	ret

; ***************************************************************
;  Read, verify, and set header information

;  HLL Call:
;	bool = setImageInfo(readFileDesc, writeFileDesc,
;		&picWidth, &picHeight, thumbWidth, thumbHeight)

;  If correct, also modifies header information and writes modified
;  header information to output file (i.e., thumbnail file).

; -----
;  2 -> BM				(+0)
;  4 file size				(+2)
;  4 skip				(+6)
;  4 header size			(+10)
;  4 skip				(+14)
;  4 width				(+18)
;  4 height				(+22)
;  2 skip				(+26)
;  2 depth (16/24/32)			(+28)
;  4 compression method code		(+30)
;  4 bytes of pixel data		(+34)
;  skip remaing header entries

; -----
;   Arguments:
;	- read file descriptor (value) - rdi
;	- write file descriptor (value)	- rsi
;	- old image width (address) - rdx
;	- old image height (address) -rcx
;	- new image width (value) -r8
;	- new image height (value) -r9

;  Returns:
;	file size (via reference)
;	old image width (via reference)
;	old image height (via reference)
;	TRUE or FALSE

global setImageInfo
setImageInfo:

	push rbx
	push r12
	push r13
	push r14
	push r15

	mov r12, rdi								; read file descriptor
	mov r10, rsi								; write file descriptor
	mov r14, rdx								; width
	mov r15, rcx								; height

	mov rax, SYS_read							; read file
	mov rdi, r12								; address of file
	mov rsi, header								; store in buffer
	mov rdx, HEADER_SIZE						; how many characters read
	syscall

	cmp rax, 0									; if error opening
	jl hdrErr									; jump to error

	mov rbx, header

	cmp byte [rbx], "B"							; check signature
	jne signErr
	cmp byte [rbx+1], "M"
	jne signErr									; if not = "BM" jump to error

	cmp word [rbx+28], 24						; check depth
	jne depthErr

	cmp dword [rbx+30], 0						; check compression
	jne compErr

	mov eax, dword [rbx+18]
	mul dword [rbx+22]
	mov r13d, 3
	mul r13d
	add eax, HEADER_SIZE						; width*height*3+138
	cmp dword [rbx+2], eax						; check if file size is correct
	jne bitSizeErr

	mov r13d, dword [rbx+18]					; get width
	mov dword [r14], r13d						; set width via reference

	mov r13d, dword [rbx+22]					; get height
	mov dword [r15], r13d						; set height via reference

	mov dword [rbx+18],	r8d						; set new width 
	mov dword [rbx+22],	r9d						; set new height

	mov eax, r8d
	mul r9d
	mov r13d, 3
	mul r13d
	add eax, HEADER_SIZE						; width*height*3+138
	mov dword [rbx+2], eax						; set new file size

	mov rax, SYS_write							; write
	mov rdi, r10								; address of file descriptor
	mov rsi, header								; address of what im writing
	mov rdx, HEADER_SIZE						; how many bytes im writing
	syscall

	cmp rax, 0									; check if write is successful
	jl writeHdrErr

	mov rax, TRUE								; set return to true
	jmp endFuncTrue2

hdrErr:											; error outputs

	mov rdi, errReadHdr
	call printString
	jmp endFuncFalse2

signErr:

	mov rdi, errFileType
	call printString
	jmp endFuncFalse2

depthErr:

	mov rdi, errDepth
	call printString
	jmp endFuncFalse2

compErr:

	mov rdi, errCompType
	call printString
	jmp endFuncFalse2

writeHdrErr:

	mov rdi, errWriteHdr
	call printString
	jmp endFuncFalse2

bitSizeErr:

	mov rdi, errSize
	call printString

endFuncFalse2:
	mov rax, FALSE							; set return to false
endFuncTrue2:

	pop r15
	pop r14
	pop r13
	pop r12
	pop rbx

	ret

; ***************************************************************
;  Return a row from read buffer
;	This routine performs all buffer management

; ----
;  HLL Call:
;	bool = readRow(readFileDesc, picWidth, rowBuffer[]);

;   Arguments:
;	- read file descriptor (value)
;	- image width (value)
;	- row buffer (address)
;  Returns:
;	TRUE or FALSE

; -----
;  This routine returns TRUE when row has been returned
;	and returns FALSE if there is no more data to
;	return (i.e., all data has been read) or if there
;	is an error on read (which would not normally occur).

;  The read buffer itself and some misc. variables are used
;  ONLY by this routine and as such are not passed.

global readRow
readRow:

	push rbx
	push r12
	push r13
	push r14

	mov r8, rdi									; get file descriptor
	mov r9, rsi									; get image width
	mov r10, rdx								; get row buffer

	mov r13, 0									; i = 0

buffLoop:

	mov rbx, qword [buffMax]
	cmp qword [curr], rbx						; if currIndex >= buffMax
	jl skipRead

	cmp byte [wasEOF], TRUE						; if eof is TRUE
	jne skipRet

	jmp endFuncFalse3

skipRet:

	mov rax, SYS_read							; system read
	mov rdi, r8									; where to read char from
	mov rsi, buffer								; where to put char read
	mov rdx, BUFF_SIZE							; number of char to be read
	syscall

	cmp rax, 0									; check if read was successful
	jl readErr2

	cmp rax, BUFF_SIZE							; check if reached end of file
	je skipEOF

	mov byte [wasEOF], TRUE					; set end of file to true
	mov qword [buffMax], rax					; update buffMax

skipEOF:

	mov qword [curr], 0

skipRead:

	mov r12, qword [curr]						; get index
	mov r11b, byte [buffer+r12]					; get char from buffer
	inc qword [curr]							; increment current index

	mov byte [r10+r13], r11b					; put char into rowBuff
	inc r13

	mov r14d, 3
	mov eax, r9d
	mul r14d

	cmp r13, rax								; if i < charRead
	jl buffLoop

	mov rax, TRUE								; set return to true
	jmp endFuncTrue3

readErr2:										; error output

	mov rdi, errRead
	call printString
	jmp endFuncFalse3

endFuncFalse3:
	mov rax, FALSE
endFuncTrue3:

	pop r14
	pop r13
	pop r12
	pop rbx

	ret

; ***************************************************************
;  Write image row to output file.
;	Writes exactly (width*3) bytes to file.
;	No requirement to buffer here.

; -----
;  HLL Call:
;	bool = writeRow(writeFileDesc, picWidth, rowBuffer);

;  Arguments are:
;	- write file descriptor (value)
;	- image width (value)
;	- row buffer (address)

;  Returns:
;	N/A

; -----
;  This routine returns TRUE when row has been written
;	and returns FALSE only if there is an
;	error on write (which would not normally occur).

;  The read buffer itself and some misc. variables are used
;  ONLY by this routine and as such are not passed.

global writeRow
writeRow:

	mov r8, rdi
	mov r9, rsi
	mov r10, rdx

	mov r11d, 3
	mov eax, r9d
	mul r11d
	mov r9, rax							; set width*3

	mov rax, SYS_write					; write
	mov rdi, r8							; address of file to write too
	mov rsi, r10						; address of what im writing
	mov rdx, r9							; number of chars being written
	syscall

	cmp rax, 0							; check if successful
	jl wrtErr

	mov rax, TRUE
	jmp endFunc

wrtErr:

	mov rdi, errWrite
	call printString
	mov rax, FALSE

endFunc:

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

