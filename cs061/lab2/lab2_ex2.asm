;=================================================
; Name: Kenny Thai
; Email: kthai025@ucr.edu
; 
; Lab: lab 2. ex 2
; Lab section: 024
; TA: Sarthak Jain
; 
;=================================================
.orig x3000
    ;---------------
    ; Instrutions
    ;---------------
    ;Instruction copies the contents of a specified memory location (identified by a label) into a register.
    LDI R3, DEC_65_PTR
    LDI R4, HEX_41_PTR

    ;add code to increment the values in R3 and R4 by 1
    ADD R3, R3, #1
    ADD R4, R4, #1
    
    ;store the incremented values back into addresses x400 and x4001 using STI
    ;Nstoring vlaues back into R3 and R4
    STI R3, DEC_65_PTR
    STI R4, HEX_41_PTR
    
    HALT    ;halt program (like exit() in C++)
    ;------------
    
    ;DEC_65   .FILL #65 ;put #65 into memory here 
    ;HEX_41 .FILL x41 ;41 in HEX is the same as 65 in binary and is the ASCII equivalent of A
    
    DEC_65_PTR  .FILL x4000
    HEX_41_PTR  .FILL x4001

.end    
    ;---------------
    ;Remote data
    ;----------------
    .orig x4000
    NEW_DEC_65  .FILL #65
    NEW_HEX_41  .FILL x41
    .end
    
