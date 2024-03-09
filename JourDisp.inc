;Display file for Displaying messages for the user


.DATA
    
    Welc_msg db            '      Welcome to Journal Time. What is on your mind ?', '$'
    bye_msg db 13, 10, 'Thank you for journaling. See you in the next one', '$'  ; Define the message
    ; Choice screen messages START
    Choice1_Msg db 13, 10, '      A:              Jot a thought (Create new Entry)', '$'
    Choice2_Msg db 13, 10, '      B:              Reflect (Edit an existingEntry)', '$'
    Choice3_Msg db 13, 10, '      C:              Clean clutter (Delete an Entry)', '$'
    Choice4_Msg db 13, 10, '      0:              Save and Exit Journal TIme Application', '$'
    UserChoice_Msg db 13, 10, 'User Choice:        ', '$'
    ;Choice_Disp DW Choice1_Msg
    arraySize DW 5                 ; Number of elements in the array
    Choice_Disp DB 'Choice', 'B', 'C', 'D', 'E'

    ;;input buffer section
    buffer DB ? ; Define a buffer to store user input

    
    
.Code
; Main home screen welcome message screen



; Welcome message macro
Welc_Scr MACRO
    mov ax, SEG Welc_msg
    mov ds, ax
    mov dx, OFFSET Welc_msg
    mov ah, 09h      ; DOS function to display a string
    int 21h 
    mov ah, 01h        ; Function 01h of interrupt 21h waits for a keypress
    int 21h
ENDM



;;Macro to display welcome screen
PrintChoice_Scr MACRO Choice_Msg
MOV AX, SEG Choice_Msg
MOV DS, AX
mov dx, OFFSET Choice_Msg
Mov ah, 09h
Int 21h
ENDM

Choice_Screen MACRO
    PrintChoice_Scr Welc_msg
    PrintChoice_Scr Choice1_Msg    
    PrintChoice_Scr Choice2_Msg
    PrintChoice_Scr Choice3_Msg
    PrintChoice_Scr Choice4_Msg
    PrintChoice_Scr UserChoice_Msg
    ; Exit interrupt
    ;MOV AH, 4Ch
    ;INT 21h
ENDM

GrabInput_Scr MACRO
    ; grabs the input from the user 
    mov ah, 01h        ; Function 01h of interrupt 21h waits for a single key NOT a string
    int 21h
    MOV buffer, al ; DX points to the buffer where the input will be stored
    mov ah,0
    push ax
    CALL UserCh_Val
    ADD SP, 2
    Exit_Scr 
ENDM



; exit/interrupt screen
Exit_Scr MACRO 
    ; goodbye message that is loaded for display
    mov ax, SEG bye_msg
    mov ds, ax
    mov dx, OFFSET bye_msg
    mov ah, 09h      ; DOS function to display a string
    int 21h         ; Call DOS interrupt to display the message

    ; Exit interrupt
    MOV AH, 4Ch
    INT 21h
    RET
ENDM


;User choice validationf

UserCh_Val PROC  UsrInput:Byte; validates the user choice to see if it was a valid input
mov BL, UsrInput
;0
cmp BL, 30h
je Exit:

;A
cmp BL, 41h
je NewEntry
NewEntry:
    Choice_Screen
    jmp RetState

;a
cmp BL, 61h
je NewEntry
NewEntry:
    Choice_Screen
    jmp RetState



Exit:
    Exit_Scr

RetState:
    ret


;;jmp to exit





; if the Usr_Choice is not the value of Aa or Bb or Cc or 0
; then loop
; else jmp to the appropriate macro for the system call

;may want to add an extra help macro like an evaluator to break this up a little more

    
UserCh_Val ENDP 








