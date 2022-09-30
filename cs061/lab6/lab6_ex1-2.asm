;=================================================
; Name: Kenny Thai
; Email: kthai025@ucr.edu
; 
; Lab: lab 6, ex 1 & 2
; Lab section: 024
; TA: Sarthak Jain
; 
;=================================================

; test harness
.orig x3000
    LD R6, sys_stack_addr ; R6 is used to backup and restore registers in subroutines

; put your code here				 
    LD R3, base_stack_addr
    LD R4, max_stack_addr
    LD R5, base_stack_addr
    
    
    
DO_WHILE
    LD R2, SUB_STACK_PUSH
    GETC
    OUT
    ADD R0, R0, #-10
    BRz END_DO_WHILE
    JSRR R2
    BR DO_WHILE
END_DO_WHILE
    
   LD R2, SUB_STACK_POP
    JSRR R2
    JSRR R2
   JSRR R2
    JSRR R2
    JSRR R2
    JSRR R2
halt
;-----------------------------------------------------------------------------------------------
; test harness local data:
base_stack_addr    .fill xA000
max_stack_addr      .fill xA005
sys_stack_addr     .fill xFE00 ; do not use, or change
SUB_STACK_PUSH    .FILL x3200
SUB_STACK_POP    .FILL x3400
OVER_MESSAGE .STRINGZ "overflow"
;===============================================================================================
.end

; subroutines:
;------------------------------------------------------------------------------------------
; Subroutine: SUB_STACK_PUSH
; Parameter (R1): The value to push onto the stack
; Parameter (R3): BASE: A pointer to the base (one less than the lowest available
;                       address) of the stack
; Parameter (R4): MAX: The "highest" available address in the stack
; Parameter (R5): TOS (Top of Stack): A pointer to the current top of the stack
; Postcondition: The subroutine has pushed (R1) onto the stack (i.e to address TOS+1). 
;		    If the stack was already full (TOS = MAX), the subroutine has printed an
;		    overflow error message and terminated.
; Return Value: R6 ← updated TOS
;------------------------------------------------------------------------------------------
.orig x3200
; backup registers here	
    ADD R6, R6, #-1
    STR R0, R6, #0
   ADD R6, R6, #-1
   STR R7, R6, #0
   ADD R6, R6, #-1
   STR R1, R6, #0
   
    NOT R4, R4
 	ADD R4, R4, #1
	ADD R7, R5, R4			; TOS - MAX = (-)
	BRzp OVERFLOW   
    BR STOP
    
OVERFLOW
    LD R0, newline
    OUT
    LEA R0, OVERFLOW_ERROR
    PUTS
    BR RESTORE
    
STOP
   ADD R5, R5, #1 ;update tos
   ADD R1, R0, #0 ;input into R1 
   STR R1, R5, #0 ;put value to return
   
RESTORE   
    NOT R4, R4
    ADD R4, R4 #1
; restore registers here
   LDR R1, R6, #0
   ADD R6, R6, #1
   LDR R7, R6, #0
   ADD R6, R6, #1
  LDR R0, R6, #0
    ADD R6, R6, #1
ret
;-----------------------------------------------------------------------------------------------
; SUB_STACK_PUSH local data
OVERFLOW_ERROR .STRINGZ "Overflow"
newline .fill x0a
MAX .FILL xA005
;===============================================================================================
.end

;------------------------------------------------------------------------------------------
; Subroutine: SUB_STACK_POP
; Parameter (R3): BASE: A pointer to the base (one less than the lowest available                      
;                       address) of the stack
; Parameter (R4): MAX: The "highest" available address in the stack
; Parameter (R5): TOS (Top of Stack): A pointer to the current top of the stack
; Postcondition: The subroutine has popped MEM[TOS] off of the stack.
;		    If the stack was already empty (TOS = BASE), the subroutine has printed
;                an underflow error message and terminated.
; Return Value: R0 ← value popped off the stack
;		   R5 ← updated TOS
;------------------------------------------------------------------------------------------
.orig x3400
; backup registers here	
    ADD R6, R6, #-1
    STR R0, R6, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	ADD R6, R6, #-1
	STR R1, R6, #0
	
;	ADD R3, R3, #1
	
    NOT R3, R3
 	ADD R3, R3, #1
	ADD R7, R5, R3			; TOS - BASE = (-) || TOS <= BASE
	BRnz UNDERFLOW   
    BR STOP_1

UNDERFLOW
    LD R0, newline1
    OUT
    LEA R0, UNDERFLOW_ERROR
    PUTS
	ADD R5, R5, #1
    BR RESTORE_1

STOP_1
;    LDR R1, R5, #0
;	AND R0, R0, #0
;	ADD R0, R1, #0
	ADD R5, R5, #-1

RESTORE_1   
    NOT R3, R3
    ADD R3, R3, #1
    
	LDR R1, R6, #0
	ADD R6, R6, #1
	LDR R7, R6, #0
	ADD R6, R6, #1
    LDR R0, R6, #0
    ADD R6, R6, #1	
ret
				 
				 
; restore registers here				 
;-----------------------------------------------------------------------------------------------
; SUB_STACK_POP local data
UNDERFLOW_ERROR   .STRINGZ "Underflow"
newline1 .fill x0a

;===============================================================================================
.end
