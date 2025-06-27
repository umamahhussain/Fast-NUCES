[org 0x0100]

jmp start

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

print:
mov ax,0xb800
mov es,ax
push bp,
mov bp,sp
mov si,0

;(row*80+col)*2

;top upper corner calculation: 710
mov ax,[bp+10]
mov bx,80
mul bx
mov bx,[bp+8]
add ax,bx
mov bx,2
mul bx
mov word[loc+si],ax
mov di,word[loc+si]
add si,2

;left corner calculation: 1330
mov ax,[bp+6]
mov bx,80
mul bx
mov bx,[bp+4]
add ax,bx
mov bx,2
mul bx
mov word[loc+si],ax
mov di,word[loc+si]
add si,2

;right corner calculation: 
mov ax,[bp+18]
mov bx,80
mul bx
mov bx,[bp+16]
add ax,bx
mov bx,2
mul bx
mov di,ax
mov word[loc+si],ax
mov di,word[loc+si]
add si,2

;bottom corner calculation
mov ax,[bp+14]
mov bx,80
mul bx
mov bx,[bp+12]
add ax,bx
mov bx,2
mul bx
mov word[loc+si],ax
mov di,word[loc+si]
add si,2

;-------------------------------------------------;
; top	left	right	 bottom
; loc+0 loc+2	loc+4	 loc+6	

mov ah,0 
int 16h
;for printing top to left line
mov ax,word[bp+10]
mov bx,word[bp+6]
sub bx,ax
mov cx,bx
mov di,word[loc+0]
add cx,1
loop1:
mov word[es:di],0x892A
add di,160
sub di,4
sub cx,1
jnz loop1

mov ah,0 
int 16h
;for printing top to right line
mov ax,word[bp+10]
mov bx,word[bp+6]
sub bx,ax
mov cx,bx
mov di,word[loc+0]
add cx,1
loop2:
mov word[es:di],0x892A
add di,160
add di,4
sub cx,1
jnz loop2
 
mov ah,0 
int 16h
;for printing bottom to right line
mov ax,word[bp+18]
mov bx,word[bp+14]
sub bx,ax
mov cx,bx
mov di,word[loc+6]
add cx,1
loop4:
mov word[es:di],0x892A
sub di,160
sub di,4
sub cx,1
jnz loop4

mov ah,0 
int 16h
;for printing bottom to left line
mov ax,word[bp+18]
mov bx,word[bp+14]
sub bx,ax
mov cx,bx
mov di,word[loc+6]
add cx,1
loop3:
mov word[es:di],0x892A
sub di,160
add di,4
sub cx,1
jnz loop3

pop bp
ret 18

start:
call cls

mov ax,8	;right corner of diamond, x row
mov bx,45	;right corner of diamond, y col
push ax		;right corner, x row, bp+18
push bx		;right corner, y col, bp+16

mov ax,12	;bottom corner of diamond, x row
mov bx,35	;bottom corner of diamond, y col
push ax		;bottom corner,x row, bp+14
push bx		;bottom corner, y col, bp+12

mov ax,4	;upper corner of diamond, x row
mov bx,35	;upper corner of diamond, y column
push ax		;upper corner, x row, bp+10
push bx		;upper corner, y column, bp+8

mov ax,8	;left corner of diamond, x row
mov bx,25	;left corner of diamond, y col
push ax		;left corner, x row, bp+6
push bx		;left corner, y row, bp+4

call print		;bp+2

end:
mov ax,0x4c00
int 0x21

loc dw 0,0,0,0