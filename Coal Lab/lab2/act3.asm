[org 0x0100]

mov ax,200h
mov bx,150h

mov cx,50h
mov [0x0250],cx

mov cx,50h
mov [0x0200],cx

mov ax,[bx]
mov ax,[0x0250]

int 0x21

arr: dw 1, 2, 7, 5, 10
