;=================================================
; Name: Kenny Thai 
; Email: kthai025@ucr.edu
; 
; Lab: lab 5, ex 1
; Lab section: 024
; TA: Sarthak Jain
; 
;=================================================
.orig x3000
; Initialize the stack. Don't worry about what that means for now.
    ld r6, top_stack_addr ; DO NOT MODIFY, AND DON'T USE R6, OTHER THAN FOR BACKUP/RESTORE
    
; your code goes here
;=================================================
    LEA R1, ARRAY_1 ;load array
    LD R4, SUB_GET_STRING 
    JSRR R4 ;invoke the subroutine located at the memory location of r4
    
    LEA R0, ARRAY_1
    TRAP x22
    
halt
    
;your local data goes here
    SUB_GET_STRING  .FILL x3200
    ARRAY_1 .BLKW   #100
    top_stack_addr  .fill xFE00
.end

;SUB_GET_STRING
.orig x3200
    ;back up registers that are important and modified
    ADD R6, R6, #-1
    STR R2, R6, #0
    ADD R6, R6, #-1
    STR R7, R6, #0
    ADD R6, R6, #-1
    STR R0, R6, #0
    ADD R6, R6, #-1
    STR R1, R6, #0
    
    LD R5, ZERO ;counter
    
    CHECK_ENTER ;f ill array until enter character is detected
        GETC
        OUT
        STR R0, R1, #0
        ADD R0, R0, #-10
        BRz END_CHECK_ENTER
        ADD R1, R1, #1
        ADD R5, R5, #1
        BR CHECK_ENTER
    END_CHECK_ENTER
    
    LD R0, ZERO 
    STR R0, R1, #0 ;0 after the string to mark the end
    
    LDR R1, R6, #0
    ADD R6, R6, #1
    LDR R0, R6, #0
    ADD R6, R6, #1
    LDR R7, R6, #0
    ADD R6, R6, #1
    LDR R2, R6, #0
    ADD R6, R6, #1

RET
    ZERO    .FILL #0
.end