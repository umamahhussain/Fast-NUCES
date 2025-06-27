[org 0x0100]

jmp start

check:
push bp
mov bp,sp

mov bx,[bp+6]
mov cx,[bp+4]
mov si,0
mov di,0

loopi:
mov ax,[bx+si]
add si,2
mov dx,[bx+si]
add si,2
mov cx,[bx+si]

call terminator

cmp dx,-1
je addition
cmp dx,-2
je subtract
cmp dx,-3
je multiply

;---------------------
terminator:
push bp
mov bp,sp
push ax
push bx
push cx
push dx

mov bx,2
mov ax, word[sizee]
mov dx,0
div bx
cmp ax,1
je end1
mov word[sizee],ax

pop dx
pop cx
pop bx
pop ax
pop bp
ret

;---------------------
addition:
push bp
mov bp,sp
push ax
push bx
push cx
push dx

add ax,cx
mov [bx+di],ax
add di,2
mov [bx+di],dx
add di,2
jmp loopi

pop dx
pop cx
pop bx
pop ax
pop bp
ret
;-------------------
subtract:
push bp
mov bp,sp
push ax
push bx
push cx
push dx

sub ax,cx
mov [bx+di],ax
add di,2
mov [bx+di],dx
add di,2
jmp loopi

pop dx
pop cx
pop bx
pop ax
pop bp
ret
;---------------------
end1:
add word[temp],1
cmp word[temp],2
je end
jmp start
;-------------------
multiply:
push bp
mov bp,sp
push ax
push bx
push cx
push dx

mul cx
mov [bx+di],ax
add di,2
mov [bx+di],dx
add di,2
jmp loopi

pop dx
pop cx
pop bx
pop ax
pop bp
ret
;-------------------------------------------;
start:
mov bx,arr
mov ax,word[sizee]
mov cx,2 	;size of array
mul cx
mov word[sizee],ax
push arr
push cx
call check

end:
mov ax,0x4c00
int 0x21

arr:dw 1,-1,2,-3,2
sizee: dw 5
res: dw 0,0,0,0
temp: dw 0
;assigning values to the operators
;+ is -1
;- is -2
;* is -3