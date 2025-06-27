[org 0x0100]

mov ax,0	;comparison
mov bx,0	;comparison
mov cx,0	;calculates frequency
mov dx,0	;works as a counter for loop condition
mov word[count],7	;size of array
mov si,0	;for indexing of original array
mov di,0	;for indexing
mov bp,0


while:
mov ax,[num+si]		;storing num for comparison si
add si,2
mov cx,0
mov di,0
mov dx,6		;size of array
sub word[count],1
jz initialize

while2:
mov bx,[num+di]		;storing second num for comparison
add di,2
cmp ax,bx		;comparing numbers
jz mode			;function call for incrementing freq
sub dx,1
jnz while2
jmp while

mode:
add cx,1
sub si,2		;subtracting as it was incremented in while loop 1 and so that the freq is stored at same index of result as original array
mov [result+si],cx		;storing frequency in result array 
add si,2
jmp while2

initialize:		;setting values for all registers
mov si,0		;for indexing
mov di,0		;for indexing
mov ax,0		;for comparison
mov dx,6	;counter for loop termination
mov cx,0		;for storing mode


max:
mov ax,[result+si]
add si,2
mov di,si
mov bx,[result+di]
cmp ax,bx	;comparing frequencies
ja final	;comparison for greater number
sub dx,1
jnz max
jmp end


final:
sub si,2
mov cx,[num+si]		;storing number having max freq
add si,2
jmp max


end:
mov ax,0x4c00
int 0x21

count: dw 0
num: dw 1,2,3,2,1,2,-1,-1,-1
result: dw 0,0,0,0,0,0,0,0,0

