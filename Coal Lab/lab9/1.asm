[org 0x0100]

jmp start
msg1: db 'I am Umamah'
msg2: db 'I am happy'
msg3: db 'I study in Fast'
msg4: db 'Roll Num 21L-1858'

cls:
push es
push ax
push cx
push di
mov ax,0xb800
mov es,ax
mov ax, 0x0720
mov cx,2000		;loop will run 2000 times
cld		;clear direction flag
rep stosw
pop di
pop cx
pop ax
pop es
ret



start:

call cls

mov ah,0 
int 16h

mov ah,0x13
mov al,1
mov bh,0
mov bl,7
mov dx,0x0903
mov cx,11
push cs
pop es
mov bp,msg1
int 0x10

mov ah,0 
int 16h

mov ah,0x13
mov al,1
mov bh,0
mov bl,7
mov dx,0x0A03
mov cx,10
push cs
pop es
mov bp,msg2
int 0x10

mov ah,0 
int 16h

mov ah,0x13
mov al,1
mov bh,0
mov bl,7
mov dx,0x0B03
mov cx,15
push cs
pop es
mov bp,msg3
int 0x10

mov ah,0 
int 16h

mov ah,0x13
mov al,1
mov bh,0
mov bl,7
mov dx,0x0C03
mov cx,17
push cs
pop es
mov bp,msg4
int 0x10


mov ax, 0x4c00
int 21h