;=================================================
; Name: Kenny Thai
; Email: kthai025@ucr.edu
; 
; Lab: lab 2. ex 4
; Lab section: 024
; TA: Sarthak Jain
; 
;=================================================
.orig x3000
    ;Instructions
    
    ;load local data values into R0 and R1
    LD R0, HEX_61
    LD R1, HEX_1A
    
    DO_WHILE_LOOP
        TRAP x21
        ADD R0, R0, #1
        ADD R1, R1, #-1
        BRp DO_WHILE_LOOP
    END_DO_WHILE_LOOP
    
    HALT
    ;local data
    HEX_61  .FILL x61
    HEX_1A  .FILL x1A
    
.end