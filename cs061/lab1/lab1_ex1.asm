;=================================================
; Name: Kenny Thai
; Email: kthai025@ucr.edu
; 
; Lab: lab 1, ex 1
; Lab section: 024
; TA: Sarthak Jain
; 
;=================================================
.orig x3000
    ;---------------
    ; Instrutions
    ;---------------
    ;nstruction copies the contents of a specified memory location (identified by a label) into a register.
    LD R2, DEC_0    ; R2 <- #0
    LD R3, DEC_12   ; R3 <- #12
    LD R4, DEC_6    ; R4 <- #6
    
    DO_WHILE_LOOP
        ADD R2, R2, R3 ; R2 <- R2 + R3
        ADD R4, R4, #-1 ; R$ <- R4 - #1
        BRp DO_WHILE_LOOP ;if (R$>0): goto DO_WHILE_LOOP
    END_DO_WHILE_LOOP
    
    HALT    ;halt program (like exit() in C++)s
    ;------------
    
    DEC_0   .FILL #0 ;put #0 into memory here
    DEC_12 .FILL #12 ;put #12 into memory here
    DEC_6   .FILL #6 ;put #6 into memory here
    
.end