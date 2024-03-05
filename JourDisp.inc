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

; Make choice message
;loops till user makes a choice 
Choice_Scr MACRO
MOV SI, OFFSET Choice_Disp

; Set up the LOOP counter:
MOV CX, 4


@@AdditionLoop:
; Get the word currently pointed to by DS:SI:

; Advance to the next word in the array (1 word = 2 bytes):
ADD SI, 1

LOOP @@AdditionLoop

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
    mov ah, 01h        ; Function 01h of interrupt 21h waits for a keypress
    int 21h
    ; Exit interrupt
    MOV AH, 4Ch
    INT 21h
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






