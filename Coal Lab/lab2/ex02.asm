[org 0x0100]
mov ax,[num]
add [num1],ax
add [num2],ax
add [num3],ax
add [num4],ax

mov ax,0x4c00
int 0x21

num : db 10,20,30,40,50
