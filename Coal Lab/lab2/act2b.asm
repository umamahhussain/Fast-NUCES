[org 0x0100]

mov ax, [n1]
mov bx, [n1+2]
add bx, ax
mov ax, [n1+4]
add bx, ax
mov bx, [n1+6]
add bx,ax
mov bx, [n1+8]
add bx,ax

mov ax,0x4c00
int 0x21

n1: dw 10, 20, 30, 40, 50