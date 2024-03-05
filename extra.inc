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