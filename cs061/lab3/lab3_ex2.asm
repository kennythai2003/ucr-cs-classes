;=================================================
; Name: Kenny Thai
; Email: kthai025@ucr.edu
; 
; Lab: lab 3, ex 2
; Lab section: 024
; TA: Sarthak Jain
; 
;=================================================
.ORIG x3000

LD R1, LOCATIONS10 ;hold the counter for the 10 inputs
LEA R2, ARRAY ; load the address of ARRAY into R2

DO_WHILE_LOOP
    GETC ;receive userinput
    OUT ;disply userinput to avoid ghost
    ;ST R0, ARRAY
    STR R0, R2, #0 ; the value of R0 is stored in the memory location of R2 + 0
    
    ADD R2, R2, #1 ;move the index of the array up
    ADD R1, R1, #-1 ;decrement counter
    BRp DO_WHILE_LOOP
END_DO_WHILE_LOOP

HALT
;LOCAL DATA
    ARRAY .BLKW #10
    LOCATIONS10 .FILL #10

.END