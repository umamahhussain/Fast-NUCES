[org 0x0100]

jmp start

fac:
pop cx
pop bx
push cx
mov ax,bx

fac2:
sub bx,1
mul bx
cmp bx,1
jne fac2 
push ax
jmp end

start:
mov ax,3	;number to calc fac
push ax
call fac


end:
mov ax,0
mov bx,0
mov cx,0
pop dx
mov ax,0x4c00
int 0x21
