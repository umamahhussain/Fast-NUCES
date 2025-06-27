[org 0x0100]

l2:
mov ax,0x0123
cmp ah,1	
je l1 	
jne l2 	

l1:
mov ax,0x4c00
int 0x21

ans: dw 0