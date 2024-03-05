;This program is example on how to use include keyword in TASM 16 bit program to refenrce an external procedure, struct, obj, macro, etc
;All it does is call a system interrupt from the respective .inc file. In this case it is main2.inc

.MODEL small
.STACK 100h
.DATA
    ; Data section here

.CODE
        Include main2.inc
        Include JourDisp.inc
        MOV AX, @data            ; Required at the start of every program (inside your main procedure, from what I've seen)
        MOV DS, AX
Start:  
        Choice_Screen
        GrabInput_Scr
        ;;Grab choice
        ;;evaluate choice

END Start


