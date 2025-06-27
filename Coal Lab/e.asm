[org 0x0100]

jmp start
fname : dw 'e1.txt',0
fhandle: dw 0
buffer: times 100 db 0
msg:db 'The Value stored in AX is: 3456'	;31
rollnum:dw 0,0,0,0
ind: dw 0

start:
mov ah,3dh
mov al,0
mov dx,fname
int 21h
mov word[fhandle],ax

;reading 
mov ah,3fh
mov bx,[fhandle]
mov cx,100
mov dx,buffer
mov si,buffer
int 21h

mov cx,ax
mov ax,0xb800
mov es,ax
mov bx,0
mov di,800
mov dx,0

print:
cmp bx,cx
jae end
mov al,[bx+si]
mov ah,0x03
mov word[es:di],ax
add bx,1
add di,2
cmp al,'#'
je check1
jmp print

check1:
cmp bx,cx
jae end
mov al,[bx+si]
mov ah,0x03
mov word[es:di],ax
add bx,1
add di,2
cmp al,'-'
je store
jmp check1

store:
cmp bx,cx
jae end
xor ax,ax
mov al,[bx+si]
mov ah,0x03
mov word[es:di],ax
add bx,1
add di,2
push ax
add word[ind],1
jmp store  

end:
mov ah,0x13
mov al,1
mov bh,0
mov bl,07
mov dx,0x818
mov cx,31
push cs
pop es
mov bp,msg
int 0x10

mov di,0
mov cx,4
loopi:
pop ax
mov word[rollnum+di],ax
sub cx,1
add di,2
jnz loopi

mov cx,4
mov di,0
loopi2:
mov ax,word[rollnum+di]
push ax
add di,2
sub cx,1
jnz loopi2


mov cx,4
mov di,3400

loopi3:
pop ax
mov ah,0x03
;mov word[ind], ax
;call digit
;add al, 0x30
mov word[es:di],ax
add di,2
sub cx,1
jnz loopi3
jmp term



digit:
push di
mov cl, 0        ; counter for number of digits
;mov ax, [ind]
mov bx, 10       ; divisor
div_loop1:
mov dx, 0        ; upper half of dividend is zero in our case
div bx           ; DX_AX / BX => remainder DX, quotient AX
push dx          
inc cl           ; counter++
cmp ax, 0        ; continue until quotient gets to zero
jne div_loop1
    
; Now print those digits on stack, one at a time
    
mov di, 3850      ; video memory offset (top left of screen)
mov ah, 0x07     ; attribute: white on black
                     
print_loop1:          
pop bx           ; get the digit
mov al, bl       ; copy the digit to AL (being < 10 it fits in one byte)
add al, 0x30     ; convert digit to char   
mov [es:di], ax  ; print it
add di, 2        ; advance offset
dec cl           ; counter--
jnz print_loop1

pop di
ret




term:
mov ax,0x4c00
int 0x21