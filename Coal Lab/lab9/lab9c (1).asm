[org 0x0100]

jmp start

message: db '  ',0
length: dw 2

;-------------------------------------------------------

clrsr: 	push es
push ax
push di
mov ax,0xb800
mov es,ax
mov di,0

nextchar: mov word [es:di],0x0720
add di, 2
cmp di, 4000
jne nextchar

pop di
pop ax
pop es

ret
;--------------------- PRINTS COLOR IN A CELL
printstr:	
push bp
mov bp, sp
push es
push ax
push cx
push si
push di

mov ax, 0xb800
mov es, ax
mov al, 80
mul byte [bp+10]
add ax, [bp+12]
shl ax, 1
mov di,ax
mov si, [bp+6] ; address
mov cx, [bp+4] ; length
mov ah, [bp+8] ; attribute

nextl: 		
mov al, [si]
mov [es:di], ax
add di, 2
add si, 1
loop nextl
pop di
pop si
pop cx
pop ax
pop es
pop bp
ret 10

printe: 

; ---------------------------------
mov ax, 10
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 10
push ax
mov ax, 5
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 10
push ax
mov ax, 6
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 10
push ax
mov ax, 7
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 10
push ax
mov ax, 8
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

;------------------------------------------------------
mov ax, 12
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 14
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 16
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

;-------------------------------
mov ax, 12
push ax
mov ax, 6
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 14
push ax
mov ax, 6
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 16
push ax
mov ax, 6
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

;-----------------------------

mov ax, 12
push ax
mov ax, 8
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 14
push ax
mov ax, 8
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 16
push ax
mov ax, 8
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

ret

printx:


;------------------------X--------------------

mov ax, 20
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 21
push ax
mov ax, 5
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 22
push ax
mov ax, 6
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 23
push ax
mov ax, 7
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr


mov ax, 24
push ax
mov ax, 8
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

;----------------------

mov ax, 24
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 23
push ax
mov ax, 5
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 22
push ax
mov ax, 6
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 21
push ax
mov ax, 7
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr


mov ax, 20
push ax
mov ax, 8
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 20
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 21
push ax
mov ax, 5
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 22
push ax
mov ax, 6
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 23
push ax
mov ax, 7
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr


mov ax, 28
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 20
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 21
push ax
mov ax, 5
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 22
push ax
mov ax, 6
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 23
push ax
mov ax, 7
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr


mov ax, 24
push ax
mov ax, 8
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr
 
 ret
 
 printt:
;-------------------------------------------
mov ax, 28
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 30
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 32
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 34
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 36
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 32
push ax
mov ax, 5
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 32
push ax
mov ax, 6
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 32
push ax
mov ax, 7
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 32
push ax
mov ax, 8
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

ret

printn:
;------------------N-------------------

mov ax, 40
push ax
mov ax, 5
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 40
push ax
mov ax, 6
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 40
push ax
mov ax, 7
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 40
push ax
mov ax, 8
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

;-----

mov ax,40
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 41
push ax
mov ax, 5
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 42
push ax
mov ax, 6
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 43
push ax
mov ax, 7
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr


mov ax, 44
push ax
mov ax, 8
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

;---------------

mov ax, 44
push ax
mov ax, 4
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 44
push ax
mov ax, 5
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 44
push ax
mov ax, 6
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 44
push ax
mov ax, 7
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr

mov ax, 44
push ax
mov ax, 8
push ax
mov ax, 0x1021
push ax
mov ax, message
push ax
push word [length]
call printstr
ret

start:
call clrsr

call printe
mov ah,0
int 0x16

call printx
mov ah,0
int 0x16

call printt
mov ah,0
int 0x16

call printn
mov ah,0
int 0x16

mov ax,0x4c00
int 0x21

