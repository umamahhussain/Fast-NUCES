[org 0x0100]
ax, 10
bx, 20
cx, 30
dx, 0
mov dx, cx
mov cx, bx
mov bx, ax
mov ax, dx
mov dx, cx
mov cx, bx
mov bx, ax
mov ax, dx
mov ax, 0x4c00
int 0x21