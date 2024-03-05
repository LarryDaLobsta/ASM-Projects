;.inc file that will contain the system interrupt procedure 
.DATA
    myVariable db 42  ; Define a byte variable

.Code
    PUBLIC myProcedure ; interface declaration that allows assembler to know that the procedure can be used publicly in the respective file
    myProcedure PROC NEAR
        ; Procedure code here
        MOV AH, 4Ch
        INT 21h
        RET
    myProcedure ENDP
    
    
    
    
 ;;;code to debuf at the bottom with problem with pointers and the loop
     lea si, Choice4_Msg
    mov cx, arraySize
printLoop:
    mov al, [si]
    ;mov si, offset Choice4_Msg
; move display messages into array
    ;mov Choice_Disp[0], SEG Choice1_Msg
    ;mov dx, si
    mov dl, al
    mov ah, 09h
    int 21h
        ; Move to the next element in the array
    inc si

    ; Decrement loop counter and check for loop termination
    loop printLoop
    ;inc si
    ;cmp byte ptr[si], 0
    ;jne Disp_Loop