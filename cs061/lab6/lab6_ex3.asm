;=================================================
; Name:
; Email:
;
; Lab: lab 6, ex 3
; Lab section:
; TA:
;
;=================================================

; test harness
.orig x3000
LD R6, sys_stack_addr ; R6 is used to backup and restore registers in subroutines		 
; put your code here
    LD R3, base_stack_addr
    LD R4, max_stack_addr
    LD R5, base_stack_addr
;prompt for integer
    LEA R0, intro1
    PUTS

    GETC
    OUT

    LD R2, ascii
    ADD R0, R0, R2
    LD R1, SUB_STACK_PUSH
    JSRR R1

    LD R0, newline
    OUT

    LEA R0, intro2
    PUTS

    GETC
    OUT

    ADD R0, R0, R2
    JSRR R1

    LD R0, newline
    OUT

    LEA R0 intro3
    PUTS

    GETC
    OUT

    LD R0, newline
    OUT

    LD R1, SUB_RPN_ADD
    JSRR R1

    AND R0, R0, #0
    LEA R0, stop1
    PUTS

    LDR R0, R5, #0
    LD R2, ascii_add
    ADD R0, R0, R2
    OUT

    LD R0, newline
    OUT

halt
;-----------------------------------------------------------------------------------------------
; test harness local data:
base_stack_addr    .fill xA000
max_stack_addr  .fill xA005
sys_stack_addr     .fill xFE00 ; do not use, or change
SUB_STACK_PUSH  .FILL x3200
SUB_STACK_POP   .FILL x3400
SUB_RPN_ADD .FILL x3600
newline .fill x0a
ascii   .fill   #-48
ascii_add   .fill #48
intro1  .STRINGZ "Enter first number: "
intro2  .STRINGZ "Enter second number: "
intro3  .STRINGZ "Enter operator(+):"
stop1 .STRINGZ    "Sum: "

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
   STR R7, R6, #0
   ADD R6, R6, #-1
   STR R1, R6, #0

   ADD R5, R5, #1 ;update tos
   LDR R1, R5, #0
   ADD R1, R0, #0 ;input into R1
   STR R1, R5, #0 ;put value to return

; restore registers here
   LDR R1, R6, #0
   ADD R6, R6, #1
   LDR R7, R6, #0
   ADD R6, R6, #1
ret
;-----------------------------------------------------------------------------------------------
; SUB_STACK_PUSH local data
OVERFLOW_ERROR .STRINGZ "Overflow"
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
	STR R7, R6, #0
	ADD R6, R6, #-1
	STR R1, R6, #0

	LDR R1, R5, #0
	AND R0, R0, #0
	ADD R0, R1, #0
	ADD R5, R5, #-1

	LDR R1, R6, #0
	ADD R6, R6, #1
	LDR R7, R6, #0
	ADD R6, R6, #1

ret

;-----------------------------------------------------------------------------------------------
; SUB_STACK_POP local data



;===============================================================================================
.end
;------------------------------------------------------------------------------------------
; Subroutine: SUB_RPN_ADD
; Parameter (R3): BASE: A pointer to the base (one less than the lowest available
;                       address) of the stack
; Parameter (R4): MAX: The "highest" available address in the stack
; Parameter (R5): TOS (Top of Stack): A pointer to the current top of the stack
; Postcondition: The subroutine has popped off the top two values of the stack,
;		    added them together, and pushed the resulting value back
;		    onto the stack.
; Return Value: R5 ← updated TOS address
;------------------------------------------------------------------------------------------
.orig x3600
; backup registers here
	ADD R6, R6, #-1
	STR R1, R6, #0
	ADD R6, R6, #-1
	STR R2, R6, #0
	ADD R6, R6, #-1
	STR R7, R6, #0

	LD R2, SUB_STACK_POP_1
	JSRR R2

	AND R1, R1, #0
	ADD R1, R0, #0

	JSRR R2

	ADD R0, R0, R1
	LD R2, SUB_STACK_PUSH_1
	JSRR R2

	LDR R7, R6, #0
	ADD R6, R6, #1
	LDR R2, R6, #0
	ADD R6, R6, #1
	LDR R1, R6, #0
	ADD R6, R6, #1



; restore registers here
ret
;-----------------------------------------------------------------------------------------------
; SUB_RPN_MULTIPLY local data
SUB_STACK_POP_1 .fill x3400
SUB_STACK_PUSH_1    .fill x3200


;===============================================================================================
.end


; SUB_ADDED

; SUB_GET_NUM

; SUB_PRINT_DIGIT		Only needs to be able to print 1 digit numbers.
