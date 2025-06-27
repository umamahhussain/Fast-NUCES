[org 0x0100]

jmp start

sum1:
pop ax
pop bx	;power
pop dx	;num

sum2:
mov ax,word[numb]
mov cx,bx
sub bx,1
cmp bx,0
je end

loopi:
mul dx
mov dx,word[numb]
sub cx,1
cmp cx,1
jne loopi
add si,ax
jmp sum2

start:
mov ax,2	;num
mov bx,5	;power
mov cx,0
mov si,0
push ax
push bx
call sum1

end:
add si,word[numb]
mov ax,0x4c00
int 0x21

total: dw 0
numb: dw 2
