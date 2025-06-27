[org 0x0100]

mov si,0
mov cx,0
mov di,0
mov bx,-1

while1:		;mov num1 array into union array
mov ax,[num1+si]
mov [union+si],ax
add si,2
add cx,1
cmp [num1+si],bx		;comparing whether the end of set is reached or not
jne while1

mov dx,cx		;storing the count in dx
mov cx,0		;setting count as zero again

while2:		;mov num2 array into union array
mov ax,[num2+di]
mov [union+si],ax
add si,2
add di,2
add cx,1
cmp [num2+di],bx
jne while2

add cx,dx		;the total count of elements
mov dx,cx		;total count stored in dx
mov di,0

display:		;displays the union array in ax register
mov ax,[union+di]
add di,2
sub cx,1
jnz display


mov bx,0
mov si,0
mov di,0 
;removing dupes from union array

for1:
mov ax,[union+si]
add si,2
mov di,si	;one index ahead of si
mov cx,dx	;storing count in cx
sub cx,1
sub dx,1
jz end

for2:
cmp ax,[union+di]
je for1		;if equal then do not store
add di,2
sub cx,1
jnz for2

mov [union2+bx],ax		;if distinct element then store in final array
add bx,2		;used for indexing of final array
jmp for1


end:	;storing last number of array in the final union array
sub di,2
mov ax,[union+di]
mov [union2+di],ax
mov ax,0x4c00
int 0x21

num1:dw 2,3,4,-1
num2:dw 7,4,-1
union: dw 0,0,0,0,0,0,0
union2: dw 0,0,0,0,0,0,0
 