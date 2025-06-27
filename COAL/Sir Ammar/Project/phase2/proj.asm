[org 0x0100]

jmp start
game1: db 'CONGARTS GAME WON WOOHOO'	;24
game2: db 'LOL LOSER'		;9
msg1: db 'BOULDER DASH'
msg2: db 'Arrow keys:move'
msg3: db 'Esc:Quit'
msg4: db 'Score:'
msg5: db 'Level:'
msg7: db 'Lives:'
l1:db'BOULDER DASH' ;12
l2:db'Directed By: ';11
l3:db'Umamah & Faiqa';14
fname : dw 'cave1.txt',0
fhandle: dw 0
buffer: times 2000 db 0
loc: dw 0
fname2 : dw 'a.txt',0
fhandle2: dw 0
buffer2: times 1400 db 0
bufferstr: db 30
		   db 0
		   times 30 db 0
		   
fname3 : dw 'cave2.txt',0
fhandle3: dw 0
buffer3: times 2000 db 0

fname4 : dw 'cave3.txt',0
fhandle4: dw 0
buffer4: times 2000 db 0

error1str: db 'Unable to open file :($'			;23
error2str: db 'Incomplete data in file :($'		;27
score: dw 0
lvl: dw 1
belly: db 'lol$'
lives: dw 3

;subroutine for the bell sound
bell:
mov ah, 2 ; set cursor position service
mov dh, 18 ; row #
mov dl, 30 ; column #
mov bh, 0 ; first video page
int 10h

mov ah,09
mov dx,belly
int 21h
ret

;this cls is for clearing the entire screen, black bg
cls:
push es
push ax
push cx
push di
mov ax,0xb800
mov es,ax
mov di,0
mov ax, 0x0720
mov cx,2000 ;loop will run 2000 times
cld ;clear direction flag
rep stosw
pop di
pop cx
pop ax
pop es
ret


;this cls is for the splash screen, bloo borders
cls2:
push es
push ax
push cx
push di
mov ax,0xb800
mov es,ax
mov di,0
mov ax, 0x3320
mov cx,2000 ;loop will run 2000 times
cld ;clear direction flag
rep stosw
pop di
pop cx
pop ax
pop es
ret

;this cls is for the last screen to print the hearts
cls3:
mov ax,0xb800
mov es,ax
mov ax,0x0303
mov bx,0x0720
mov cx,0
mov di,0

hearty:
mov[es:di],ax
add di,2
mov[es:di],bx
add di,40
call sleep1
cmp di,4000
jle hearty
ret
;------------------------------------------------------;
;first screen, the diagonal stars/suns whatever
sun:
mov ax,0xb800
mov es,ax
mov ax,0x070F
mov bx,0x0720
mov cx,0
mov di,0

sunny:
mov[es:di],ax
add di,2
mov[es:di],bx
add di,40
call sleep1
cmp di,4000
jle sunny
;------------------------------------------------------;

sleep1:
push cx
mov cx, 0x3333
s1: loop s1
pop cx
ret
;-----------------------------------------------------;
;delay for the rocky to enter castle
sleep:
push cx
push dx
mov dx,30	;loop counter
mov cx, 0xFFFF
woo:
delay:
loop delay
sub dx,1
jnz woo
pop dx
pop cx
ret

;----------------------------------------------------;
sleep2:
push cx
push dx
mov dx,99	;loop counter
mov cx, 0xFFFF
woo2:
delayy2:
loop delayy2
sub dx,1
jnz woo2
pop dx
pop cx
ret
;--------------------------------------------------;

rect:
push es
push ax
push cx
push di
mov ax,0xb800
mov es,ax

;upper horizontal line
mov di,992 
mov ax, 0x7720
mov cx,30
cld
rep stosw

;vertical left line
mov cx,6
rect1:
mov word[es:di],0x7720
add di,160
sub cx,1
cmp cx,0
jne rect1
 
;lower horizontal
mov ax,0xb800
mov es,ax
mov di,1954
mov ax, 0x7720
mov cx,30
cld
rep stosw

;vertical right
mov cx,7
mov di,992
rect2:
mov word[es:di],0x7720
add di,160
sub cx,1
cmp cx,0
jne rect2

pop di
pop cx
pop ax
pop es
ret

;----------------------------------------------------;
;this func is used for printing the names on the front screen
names:
mov ah,0x13
mov al,1
mov bh,0
mov bl,07
mov dx,0x818
mov cx,12
push cs
pop es
mov bp,l1
int 0x10
call sleep1

mov ah,0x13
mov al,1
mov bh,0
mov bl,07
mov dx,0x918
mov cx,11
push cs
pop es
mov bp,l2
int 0x10
call sleep1

mov ah,0x13
mov al,1
mov bh,0
mov bl,07
mov dx,0x0A18
mov cx,14
push cs
pop es
mov bp,l3
int 0x10

ret
;---------------------------------------------------------;
;this func is used for printing the go using lines
go:
mov ax,0xb800
mov es,ax

;G straight line
mov cx,5
mov ax,0x7704
mov di,2756
go1:
mov word[es:di],ax
add di,160
sub cx,1
jnz go1

;G upper line
mov cx,11
mov ax,0x7704
mov di,2596
go2:
mov word[es:di],ax
add di,2
sub cx,1
jnz go2

;G lower line
mov cx,11
mov ax,0x7704
mov di,3396
go3:
mov word[es:di],ax
add di,2
sub cx,1
jnz go3

;G smol line
mov cx,4
mov ax,0x7704
mov di,3098
go4:
mov word[es:di],ax
add di,160
sub cx,1
jnz go4

;O upper line
mov cx,10
mov ax,0x7704
mov di,2628
go5:
mov word[es:di],ax
add di,2
sub cx,1
jnz go5

;O lower line
mov cx,10
mov ax,0x7704
mov di,3428
go6:
mov word[es:di],ax
add di,2
sub cx,1
jnz go6

;O first line vertical
mov cx,5
mov ax,0x7704
mov di,2628
go7:
mov word[es:di],ax
add di,160
sub cx,1
jnz go7

;O second line vertical
mov cx,6
mov ax,0x7704
mov di,2648
go8:
mov word[es:di],ax
add di,160
sub cx,1
jnz go8

ret
;------------------------------------------------------;
;this function is for producing a sound when esc is pressed
sound:
mov al, 182        
out 43h, al      
mov ax, 4560        
       
out 42h, al        
mov al, ah        
out 42h, al              
in al, 61h        
                           
or al, 00000011b  
out 61h, al        
mov bx,25

pause1:
mov cx,65535

pause2:
dec cx
jne pause2
dec bx
jne pause1
in al,61h
and al,11111100b
out 61h,al
ret
;-------------------------------------------------------;
;this func is used for printing the static layout like game name, score, level etc
stringy:
mov ah,0x13
mov al,1
mov bh,0
mov bl,11
mov dx,0x0020
mov cx,12
push cs
pop es
mov bp,msg1
int 0x10

mov ah,0x13
mov al,1
mov bh,0
mov bl,11
mov dx,0x0100
mov cx,15
push cs
pop es
mov bp,msg2
int 0x10

mov ah,0x13
mov al,1
mov bh,0
mov bl,11
mov dx,0x0145
mov cx,8
push cs
pop es
mov bp,msg3
int 0x10

mov ah,0x13
mov al,1
mov bh,0
mov bl,11
mov dx,0x0220
mov cx,6
push cs
pop es
mov bp,msg7
int 0x10

mov ah,0x13
mov al,1
mov bh,0
mov bl,11
mov dx,0x01800
mov cx,6
push cs
pop es
mov bp,msg4
int 0x10

mov ah,0x13
mov al,1
mov bh,0
mov bl,11
mov dx,0x01845
mov cx,6
push cs
pop es
mov bp,msg5
int 0x10
ret
;---------------------------------------------------;
border:
push es
push ax
push cx
push di
mov ax,0xb800
mov es,ax
mov di,480 ;upper horizontal
mov ax, 0x4420
mov cx,80
cld
rep stosw
;.................vertical left
mov cx,20
bod1:
mov word[es:di],0x4420
add di,160
sub cx,1
cmp cx,0
jne bod1
 
;........ lower horizontal
mov ax,0xb800
mov es,ax
mov di,3680 ;lower horizontal
mov ax, 0x4420
mov cx,80
cld
rep stosw
;........... vertical right
mov cx,21
mov di,638
bod2:
mov word[es:di],0x4420
add di,160
sub cx,1
cmp cx,0
jne bod2

pop di
pop cx
pop ax
pop es
ret

;----------------------------------------------------;
;for printing the level 3
printing4:
mov ah,3dh
mov al,0
mov dx,fname4
int 21h
mov word[fhandle4],ax

;reading 
mov ah,3fh
mov bx,[fhandle4]
mov cx,1600
mov dx,buffer4
mov si,buffer4
int 21h

jmp p2

;----------------------------------------------------;
;for printing level 2
printing3:
mov ah,3dh
mov al,0
mov dx,fname3
int 21h
mov word[fhandle3],ax

;reading 
mov ah,3fh
mov bx,[fhandle3]
mov cx,1600
mov dx,buffer3
mov si,buffer3
int 21h

jmp p2
;----------------------------------------------------;
printing:
;opening
mov ah,3dh
mov al,0
mov dx,fname
int 21h
mov word[fhandle],ax

;reading 
mov ah,3fh
mov bx,[fhandle]
mov cx,1600
mov dx,buffer
mov si,buffer
int 21h

;ax is bytes read from file, cx is the num of bytes we wanted to read
; if ax is less than 1600 so incomplete data and error
cmp ax,cx
jl error2
jmp p2
error2:
mov ah,09
mov dx,error2str
int 21h
jmp end

p2:
mov ax,0xb800
mov es,ax
mov dx,0
mov bx,0

mov dx,0
mov di,480

;loop for printing the game
charcheck:
cmp bx,1600
je exitcharcheck1
mov dl,[bx+si]
cmp dl,'x'
je dirt
cmp dl,'B'
je boulder
cmp dl,'W'
je wall
cmp dl,'R'
je rockford
cmp dl,'D'
je diamond
cmp dl,'T'
je target
;-----------------------------------------------------;
dirt:
mov word[es:di],0x77b1
add bx,1
add di,2
jmp charcheck
;------------------------------------------------------;
wall:
mov word[es:di],0x06db
add bx,1
add di,2
jmp charcheck
;------------------------------------------------------;
rockford:
mov word[es:di],0x0F02
mov word[loc],di
add bx,1
add di,2
jmp charcheck
;-------------------------------------------------------;
exitcharcheck1:
jmp exitcharcheck2
;-------------------------------------------------------;
diamond:
mov word[es:di],0x0304
add bx,1
add di,2
jmp charcheck
;--------------------------------------------------------;
boulder:
mov word[es:di],0x0509
add bx,1
add di,2
jmp charcheck
;--------------------------------------------------------;
target:
mov word[es:di],0x0F7f
add bx,1
add di,2
jmp charcheck
;----------------------------------------------------;
exitcharcheck2:
mov ah,3eh
int 21h
ret
;------------------------------------------------------;

escpress:
call cls3
call term
;--------------------------------------------------------;
play:
;location of rocky
mov di,word[loc]

play1:
call rockydie
mov ah,0
int 16h
mov bl, ah   ; put scancode in BX
cmp bl,72
je up
cmp bl,1
je escpress
cmp bl,75
je lefty1
cmp bl,77
je r1
cmp bl,80
je down

up:
mov word[es:di],0x77b1
sub di,160
mov si,word[es:di]
cmp si,0x0F7f		;for target
je gamewon
cmp si,0x0304		;for diamond
je up1
cmp si,0x77b1		;for dirt
jne up2
je up1
up1:
mov word[es:di],0x0F02
cmp si,0x0304
je printscorey2
jmp play1
up2:
add di,160
mov word[es:di],0x0F02
jmp play1

playend2:
jmp playend

down:
mov word[es:di],0x77b1
add di,160
mov si,word[es:di]
cmp si,0x0F7f		;for target
je gamewon
cmp si,0x0304		;diamond
je down1
cmp si,0x77b1
jne down2
down1:
mov word[es:di],0x0F02
cmp si,0x0304
je printscorey2
jmp play1
down2:
sub di,160
mov word[es:di],0x0F02
jmp play1

lefty1:
jmp left

printscorey2:
jmp printscorey1

r1:
jmp right

play2:
jmp play1

gamewon:
mov word[es:di],0xFA02
call sleep2
call g1

left:
mov word[es:di],0x77b1
sub di,2
mov si,word[es:di]
cmp si,0x0F7f		;for target
je gamewon
cmp si,0x0304		;for diamond
je left1
cmp si,0x77b1
jne left2
je left1
left1:
mov word[es:di],0x0F02
cmp si,0x0304
je printscorey1
jmp play2
left2:
add di,2
mov word[es:di],0x0F02
jmp play2

printscorey1:
jmp printscorey

right:
mov word[es:di],0x77b1
add di,2
mov si,word[es:di]
cmp si,0x0F7f		;for target
je gamewon
cmp si,0x0304		;for diamond
je right1
cmp si,0x77b1
jne right2
je right1
right1:
mov word[es:di],0x0F02
cmp si,0x0304
je printscorey1
jmp play2
right2:
sub di,2
mov word[es:di],0x0F02
jmp play2

rockydie:	;to check if there is a boulder above rocky head
sub di,160
mov si,word[es:di]
add di,160
cmp si,0x0509		;for boulder
mov ax,0
je playend
ret

playend:	;called when rocky is ded or esc is pressed
mov word[es:di],0xF402
call sleep2
call g2

play3:
jmp play2
;----------------------------------------------------------;
printlvl:
push di
mov cl, 0        ; counter for number of digits
mov word[score],0
mov ax, [lvl]
mov bx, 10       ; divisor
div_loop1:
mov dx, 0        ; upper half of dividend is zero in our case
div bx           ; DX_AX / BX => remainder DX, quotient AX
push dx          
inc cl           ; counter++
cmp ax, 0        ; continue until quotient gets to zero
jne div_loop1
    
; Now print those digits on stack, one at a time
    
mov di, 3990      ; video memory offset (top left of screen)
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
;---------------------------------------------------------;
printscorey:
call bell	;call bell sound whenever score is inc
push di
mov cl, 0        ; counter for number of digits
add word[score],1
mov ax, [score]
mov bx, 10       ; divisor
div_loop:
mov dx, 0        ; upper half of dividend is zero in our case
div bx           ; DX_AX / BX => remainder DX, quotient AX
push dx          
inc cl           ; counter++
cmp ax, 0        ; continue until quotient gets to zero
jne div_loop
    
; Now print those digits on stack, one at a time
    
mov di, 3854        ; video memory offset (top left of screen)
mov ah, 0x07     ; attribute: white on black
                     
print_loop:          
pop bx           ; get the digit
mov al, bl       ; copy the digit to AL (being < 10 it fits in one byte)
add al, 0x30     ; convert digit to char   
mov [es:di], ax  ; print it
add di, 2        ; advance offset
dec cl           ; counter--
jnz print_loop

pop di
jmp play3
;---------------------------------------------------------;
printing2:
;this is for printing the splash screen
;opening
mov ah,3dh
mov al,0
mov dx,fname2
int 21h
;jc error
mov word[fhandle2],ax

;reading 
mov ah,3fh
mov bx,[fhandle2]
mov cx,1360
mov dx,buffer2
mov si,buffer2
int 21h

mov ax,0xb800
mov es,ax
mov dx,0
mov bx,0

mov dx,0
mov di,640

sscheck:
cmp bx,1360
je exitsscheck1
;call sleep
mov dl,[bx+si]
cmp dl,' '
je spacey1
cmp dl,'-'
je upperdash
cmp dl,'_'
je lowerdash
cmp dl,'|'
je str8line
cmp dl,'['
je leftbrack
cmp dl,']'
je rightbrack
cmp dl,'\'
je leftslant
cmp dl,'/'
je ri8slant
cmp dl,'('
je rightround1
cmp dl,')'
je leftround
cmp dl,'o'
je circle1
;-----------------------------------------------------;
upperdash:
mov word[es:di],0x082D
add bx,1
add di,2
jmp sscheck
;------------------------------------------------------;
lowerdash:
mov word[es:di],0x085F
add bx,1
add di,2
jmp sscheck
;------------------------------------------------------;
str8line:
mov word[es:di],0x0F7C
add bx,1
add di,2
jmp sscheck
;-------------------------------------------------------;
spacey1:
jmp spacey
;--------------------------------------------------------;
rightround1:
jmp rightround
;--------------------------------------------------------;
circle1:
jmp circle
;-------------------------------------------------------;
exitsscheck1:
jmp exitsscheck2
;-------------------------------------------------------;
leftbrack:
mov word[es:di],0x0F5B
add bx,1
add di,2
jmp sscheck
;--------------------------------------------------------;
rightbrack:
mov word[es:di],0x0F5D
add bx,1
add di,2
jmp sscheck
;--------------------------------------------------------;
leftslant:
mov word[es:di],0x0F5C
add bx,1
add di,2
jmp sscheck
;----------------------------------------------------;
ri8slant:
mov word[es:di],0x0F2F
add bx,1
add di,2
jmp sscheck
;----------------------------------------------------;
leftround:
mov word[es:di],0x0F29
add bx,1
add di,2
jmp sscheck
;----------------------------------------------------;
rightround:
mov word[es:di],0x0F28
add bx,1
add di,2
jmp sscheck
;----------------------------------------------------;
circle:
mov word[es:di],0x0F6F
add bx,1
add di,2
jmp sscheck
;----------------------------------------------------;
spacey:
mov word[es:di],0x0720
add bx,1
add di,2
jmp sscheck
;------------------------------------------------------;
exitsscheck2:
ret

;-------------------------------------------------------;
;this func is for when rocky moves from water to castle door
baby:
mov cx,4
mov di,3916
baby2:
call sleep
mov word[es:di],0x3320
sub di,160
mov word[es:di],0x0F02
sub cx,1
cmp cx,0
jnz baby2
ret
;---------------------------------------------------------;
printlives:
push di
mov ax,0xb800
mov es,ax
mov di,398
mov cx,word[lives]
mov bx,0x0720

livesloop:
mov ax, 0x0403
mov word[es:di],ax
add di,2
mov word[es:di],bx
add di,2
sub cx,1
jnz livesloop

pop di
ret


;---------------------------------------------------------;

start:

call cls
call sun
call rect
call names
call go

mov ah,0
int 16h
call cls2
call printing2
call baby
call cls

a:
call stringy
call printing
call border
call printlvl
call printlives
call play

g1:
call cls
;call cls3
add word[lvl],1
call printlvl
mov ah,0x13
mov al,1
mov bh,0
mov bl,07
mov dx,0x0920
mov cx,24
push cs
pop es
mov bp,game1
int 0x10
cmp word[lvl],3		;check for level 3
je end2
cmp word[lvl],2		;check for level 2
je end1
jmp end

g2:		;for displaying game over msg
call cls
;call cls3
call printlvl
mov ah,0x13
mov al,1
mov bh,0
mov bl,07
mov dx,0x0920
mov cx,9
push cs
pop es
mov bp,game2
int 0x10
sub word[lives],1
cmp word[lives],0
je end
cmp word[lvl],3		;check for level 3
je end2
cmp word[lvl],2		;check for level 2
je end1
cmp word[lvl],1		;check for level 1
je a 
jmp end

end1:		;level 2
call cls
call stringy
call printing3
call border
call printlives
call printlvl
call play

end2:		;level 3
call cls
call stringy
call printing4
call border
call printlives
call printlvl
call play

term:
end:
call sound
call cls
mov ax,0x4c00
int 0x21