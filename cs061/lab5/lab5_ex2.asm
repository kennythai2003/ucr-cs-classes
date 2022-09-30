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
    
    LEA R1, ARRAY_1 ;reload array
    LD R3, SUB_IS_PALINDROME
    JSRR R3 ;invoke the subroutine located at the memory location of r3
    
    ADD R4, R4, #0  ;execute if below
    BRnz NO_PALINDROME  ;check whether the r4 has a memory of 0 
    ADD R4, R4, #0 ;execut if below
    BRp YES_PALINDROME  ;check whether r4 has a memory of 1 
    
    YES_PALINDROME ;prints respective parts of the sentence
        LEA R0, THE_STRING
        TRAP x22
        LEA R0, ARRAY_1
        TRAP x22
        LEA R0, IS_PALINDROME
        TRAP x22
        BR END_PALINDROME
    NO_PALINDROME  ;prints respective parts of the sentence
        LEA R0, THE_STRING
        TRAP x22
        LEA R0, ARRAY_1
        TRAP x22
        LEA R0, NOT_PALINDROME
        TRAP x22
        BR END_PALINDROME
    END_PALINDROME
    
    ;LEA R0, ARRAY_1
    ;TRAP x22
    
halt
    
;your local data goes here
    SUB_GET_STRING  .FILL x3200
    SUB_IS_PALINDROME   .FILL x3400
    ARRAY_1 .BLKW   #100
    top_stack_addr  .fill xFE00
    THE_STRING  .stringz    "The string \""
    NOT_PALINDROME  .stringz "\" IS NOT a palindrome\n"
    IS_PALINDROME   .stringz    "\" IS a palindrome\n"
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

.orig x3400
    ;back up registers that are important and modified
    ADD R6, R6, #-1
    STR R7, R6, #0
    ADD R6, R6, #-1
    STR R2, R6, #0
    ADD R6, R6, #-1
    STR R5, R6, #0
    ADD R6, R6, #-1
    STR R0, R6, #0
    ADD R6, R6, #-1
    STR R1, R6, #0
    ADD R6, R6, #-1
    STR R3, R6, #0
    
    ADD R2, R1, R5 ;goes to the end of the array where the 0 is
    ADD R2, R2, #-1 ;moves to last character in the string
    LD R3, ZERO_DEC 
    ADD R1, R1, R3  ;first index mover
    
    COMPARE_CHAR
        LDR R0, R1, #0 ;load first value of array into r0 
        LDR R5, R2, #0  ;r2 is the tracker of end 
        NOT R5, R5
        ADD R5, R5, #1  
        ADD R0, R0, R5  ;checks the characters to see if they are the same
        BRnp NOT_SAME
        ADD R0, R0, #0 ; same continue to same
        BRz SAME
        
    SAME
        ADD R3, R3, #1  ;increase index counter by 1
        ADD R1, R1, R3  ; move index, 
        ADD R2, R2, #-1 ; moves index left
        ADD R5, R2, #0  ;\
        NOT R5, R5
        ADD R5, R5, R1  ;keeps track of right
        LD R0, ZERO_DEC
        ADD R0, R1, R5  ; checks to see if the two elements are the same
        BRn COMPARE_CHAR
        LD R4, ONE_DEC ; boolean for main
        ADD R4, R4, #0
        BRp EXIT_LOOP
        
    NOT_SAME
        LD R4, ZERO_DEC
        ADD R4, R4, #0 ;boolean value for main
        BR EXIT_LOOP
        
    EXIT_LOOP
    
    LDR R3, R6, #0
    ADD R6, R6, #1
    LDR R1, R6, #0
    ADD R6, R6, #1
    LDR R0, R6, #0
    ADD R6, R6, #1
    LDR R5, R6, #0
    ADD R6, R6, #1
    LDR R2, R6, #0
    ADD R6, R6, #1
    LDR R7, R6, #0
    ADD R6, R6, #1
    
RET
    ZERO_DEC    .FILL #0
    ONE_DEC     .FILL #1
    SUB_TO_UPPER    .FILL x3600
.end