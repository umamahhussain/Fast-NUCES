[org 0x0100]

mov ax,[n1]
add ax,sum
mov bx, sum

mov ax,[n2]
add ax,sum
mov bx, sum

mov ax,[n3]
add ax,sum
mov bx, sum

mov ax,[n4]
add ax,sum
mov bx, sum

mov ax,[n5]
add ax,sum
mov bx, sum


mov ax,0x4c00
int 0x21

n1:dw 10
n2:dw 20
n3:dw 30
n4:dw 40
n5:dw 50
sum:dw 0