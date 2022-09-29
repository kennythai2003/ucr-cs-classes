;=================================================
; Name: Kenny Thai
; Email: kthai025@ucr.edu
; 
; Lab: lab 2. ex 3
; Lab section: 024
; TA: Sarthak Jain
; 
;=================================================
.orig x3000
   ;---------------
    ; Instrutions
    ;---------------
   ; LDI R3, DEC_65_PTR
  ;  LDI R4, HEX_41_PTR

 ;  ADD R3, R3, #1
 ;   ADD R4, R4, #1
    
    ;storing the incremeneted values back into R3 and R4
 ;   STI R3, DEC_65_PTR
  ;  STI R4, HEX_41_PTR

    ;load the values of the pointeres into R5 and R6 respectively
    LD R5, DEC_65_PTR
    LD R6, HEX_41_PTR
    
    ;use ldr to load the remote data into R3 and R4, using R5 and R6 as base registers
    LDR R3, R5 #0
    LDR R4, R6 #0
    
    ;increment the values R3 & R4
    ADD R3, R3, #1
    ADD R4, R4, #1
    
    ;store the incremented values back into x4000 and x4001 using STR
    ;loading the remote data of r5 and r6 into r3 and r4
    STR R3, R5, #0
    STR R4, R6, #0
    
    HALT    ;halt program (like exit() in C++)
    ;------------
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