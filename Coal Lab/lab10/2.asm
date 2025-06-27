[org 0x0100]

mov ah,2Ch
int 21h

;ch is hour
;cl is min
;dh is sec

; print time
mov dl,ch
int 21h

mov dl,':'
int 21h

mov dl,cl
int 21h

mov dl,':'
int 21h

mov dl,dh
int 21h

mov ax,0x4c00
int 0x21
