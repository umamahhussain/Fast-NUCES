[org 0x0100]

mov cx,[num]
sub cx,1	
mov ax,[num]

while: 
add ax,[num]
sub cx,1
jne while

mov ax,0x4c00
int 0x21

num:dw 2