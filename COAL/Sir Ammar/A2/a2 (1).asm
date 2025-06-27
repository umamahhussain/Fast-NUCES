[org 0x0100]
jmp start 

; place final outputs in these variables
topAvg:    dw 0   
bottomAvg: dw 0
topsum: dw 0
bottomsum: dw 0

; the data array and its size
; change these two to ensure your program works correctly all the time
marks:     dw 15,10,25,40,35,30,20,50,45,55
sizee:      dw 10

;------------------------------------------------------------------ 
; bubblesort subroutine 
;------------------------------------------------------------------
bubblesort:   push bp                 ; save old value of bp 
              mov  bp, sp             ; make bp our reference point 
              sub sp, 2               ; make two byte space on stack
              push ax                 ; save old values of registers
              push bx 
              push cx 
              push si 
 
              mov  bx, [bp+6]         ; load start of array in bx 
              mov  cx, [bp+4]         ; load count of elements in cx 
              dec  cx                 ; last element not compared 
              shl  cx, 1              ; turn into byte count 
 
mainloop:     mov  si, 0              ; initialize array index to zero 
              mov  word [bp-2], 0     ; reset swap flag to no swaps 
 
innerloop:    mov  ax, [bx+si]        ; load number in ax 
              cmp  ax, [bx+si+2]      ; compare with next number 
              jbe  noswap             ; no swap if already in order 
 
              xchg ax, [bx+si+2]      ; exchange ax with second number 
              mov  [bx+si], ax        ; store second number in first 
              mov  word [bp-2], 1     ; flag that a swap has been done 
 
noswap:       add  si, 2              ; advance si to next index 
              cmp  si, cx             ; are we at last index 
              jne  innerloop          ; if not compare next two 
              cmp word [bp-2], 1      ; check if a swap has been done 
              je   mainloop           ; if yes make another pass  
 
              pop  si                 ; restore old value of registers 
              pop  cx
              pop  bx
              pop  ax
              mov  sp, bp             ; remove space created on stack
              pop  bp                 ; restore old value of bp 
              ret  4                  ; go back and remove two params
;------------------------------------------------------------------
; list_avg subroutine
; Required parameters (on stack): array start address, array size
; Returns (again, on stack): the average value
;------------------------------------------------------------------
list_avg:     
mov si,0
mov dx,0
push bp
mov bp,sp

mov ax,[bp+6]	;accessing the array starting index
mov cx,[bp+4]	;accessing the array size which is 3

listav2:
add dx,[bx+si]		;storing the sum in the dx register
add si,2
sub cx,1		;acting as a counter for the loop
jnz listav2

mov [bp+8],dx		;transferring the sum onto the stack

mov  sp, bp             ; remove space created on stack
pop  bp 
ret  4


;------------------------------------------------------------------  
; divide subroutine
; Required parameters (on stack): dividend, divisor
; Returns (on stack): the integer quotient
;------------------------------------------------------------------
divide:       

mov si,0
mov dx,0
push bp
mov bp,sp
mov ax,[bp+6]	;accessing the bottom/top sum
mov cx,[bp+4]	;accessing the size

loopi:
sub ax,cx		;subtracting divisor from the dividend
add dx,1		;counting how many times subtraction takes place
cmp ax,cx
jge loopi		;if ax(dividend) is greater than repeat otherwise end loop

mov [bp+8],dx		;moving the count on the stack

mov  sp, bp             ; remove space created on stack
pop  bp                 ; restore old value of bp 
ret  4


;------------------------------------------------------------------ 
; Main program
; Sorts the marks array using bubblesort subroutine, then 
; calls list_avg subroutine on a sublist of first 3 elements
; and then on a sublist of last 3 elements
;------------------------------------------------------------------
start:        

mov bx,marks		;pointer to the array
mov cx, word[sizee]		;cx has the size of the array
push bx		
push cx		
call bubblesort		


push bx		;again push bx onto the stack, pointer to the sorted array
mov cx,3	;first 3 elements so count is 3
push cx
call list_avg
pop cx		;pops top of the stack which has the required sum
mov word[bottomsum],cx		;stores the sum into memory


mov cx,word[sizee]		;transfer the size in to cx
mov ax,2		
mul cx		;multiply the size with 2 cuz of 'dw'
mov si,ax		;si now contains double the size
;have to calc sum of last 3 num so 3*2=6, sub 6 from the total size and add the resulting value
;into the bx pointer so now it points to the 3rd last number
sub si,6		
mov bx,marks	;points to the array
add bx,si		;incrementing the pointer to the 3rd last number
push bx
mov cx,3		;calc sum of last 3 num so counter/size is 3
push cx
call list_avg
pop cx		;pops top of the stack which has the required sum
mov word[topsum],cx		;stores the sum into memory

           
mov bx,word[bottomsum]
mov cx,word[sizee]
push bx		;the bottom sum is stored in bx
push cx		;the count of the elements
call divide
pop dx		;stores the bottom average in dx
mov word[bottomAvg],dx
		   
mov bx,word[topsum]
mov cx,word[sizee]
push bx		;the bottom sum is stored in bx
push cx		;the count of the elements
call divide	
pop dx		;stores the top average in dx
mov word[topAvg],dx	   
		   
end:       
mov ax, 0x4c00
int 21h