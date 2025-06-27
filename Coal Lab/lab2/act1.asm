; Actitivity1
[org 0x0100]

mov ax,25h
mov bx, 0h
mov cx, ax
mov ax, bx
mov bx, cx
mov cx, [0x270]

mov ax,[num1]
mov ax,[num1+2]
mov ax,[num1+4]

int 0x21

num1: dw 12,25,10


