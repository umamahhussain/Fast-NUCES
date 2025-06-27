[org 0x0100] ;we will see org directive later

mov ax, 3
mov bx, 3 
add ax, bx
add ax, bx 
add ax, bx 
add ax,bx
mov ax, 0x4c00 ;terminate the program
int 0x21