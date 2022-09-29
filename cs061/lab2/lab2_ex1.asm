;=================================================
; Name: Kenny Thai
; Email: kthai025@ucr.edu
; 
; Lab: lab 2. ex 1
; Lab section: 024
; TA: Sarthak Jain
; 
;=================================================

;Write a program in lab2_ex1.asm that uses .FILL pseudo-ops to load the values #65 (decimal
;65) and x41 (hexadecimal 41) into two memory locations with the labels DEC_65 and HEX_41 respectively. Check the binary values stored in the two locations - what do you notice?
;Look up an ASCII table (use the back of your text or this table) to see what these values represent when interpreted as characters rather than numbers.
;Then use the LD instruction to load these two values into registers R3 and R4 respectively. Run the program, and inspect those registers to make sure it did what you expected.
.orig x3000
    ;---------------
    ; Instrutions
    ;---------------
    ;Instruction copies the contents of a specified memory location (identified by a label) into a register.
    LD R3, DEC_65
    LD R4, HEX_41
    
    
    HALT    ;halt program (like exit() in C++) 
    ;------------
    ;.FILL TO LOAD values
    DEC_65  .FILL #65 ;put #65 into memory here
    HEX_41 .FILL x41 ;41 in HEX is the same as 65 in binary and is the ASCII equivalent of A
 
.end