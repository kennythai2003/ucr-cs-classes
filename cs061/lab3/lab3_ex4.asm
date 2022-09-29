;=================================================
; Name: Kenny Thai
; Email: kthai025@ucr.edu
; 
; Lab: lab 3, ex 4
; Lab section: 024
; TA: Sarthak Jain
; 
;=================================================
.ORIG x3000

;LD R1, LOCATIONS10 ;hold the counter for the 10 inputs
LD R2, ARRAY_PTR ; load the address of ARRAY into R2
AND R3, R3, #0
DO_WHILE_LOOP
    GETC ;receive userinput
    OUT ;disply userinput to avoid ghost
    ;ST R0, ARRAY
    STR R0, R2, #0 ; the value of R0 is stored in the memory location of R2 + 0
    ADD R3, R3, #1
    ADD R2, R2, #1 ;move the index of the array up
    
    ADD R0, R0, #-10
    BRnp DO_WHILE_LOOP
END_DO_WHILE_LOOP
;BRz
ADD R3, R3, #-1
LD R2, ARRAY_PTR
DO_WHILE_LOOP_1
    LDR R0, R2, #0; load the value from the memory location found at R2 by adding the value found with 0;
    OUT ;disply userinput to avoid ghost
    ;ST R0, ARRAY
    ;LD R0, newline
    ;OUT
    ADD R2, R2, #1 ;move the index of the array up
    ADD R3, R3, #-1 ;decrement counter
    BRp DO_WHILE_LOOP_1
END_DO_WHILE_LOOP_1

LD R0, newline
OUT

HALT
;LOCAL DATA
;    ARRAY .BLKW #100
    ARRAY_PTR .FILL x4000
    DEC_ENTER .FILL #10
;LOCATIONS10 .FILL #10
    newline .FILL x0A
.END
    
.ORIG x4000
    ARRAY .BLKW #100
.END