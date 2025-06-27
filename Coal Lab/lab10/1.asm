[org 0x0100]
jmp start
msg1: db 'I Am From Pak'

stringy:
mov ah,0x13
mov al,1
mov bh,0
mov bl,11
mov dx,0x0020
mov cx,13
push cs
pop es
mov bp,msg1
int 0x10

mov ah, 2 ; set cursor position service
mov dh, 10 ; row #
mov dl, 20 ; column #
mov bh, 0 ; first video page
int 10h

mov dl, 'I' 
int 21h 

mov dl, 'A'
int 21h
mov dl, 'm'
int 21h

mov dl, 'F'
int 21h
mov dl, 'r'
int 21h
mov dl, 'o'
int 21h
mov dl, 'm'
int 21h

mov dl, 'P'
int 21h
mov dl, 'a'
int 21h
mov dl, 'k'
int 21h

ret

start:
call stringy

mov ax,0x4c00
int 0x21
