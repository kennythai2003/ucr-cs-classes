;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Kenny Thai
; Email: kthai025@ucr.edu
;
; Assignment name: Assignment 2
; Lab section: 024
; TA: Sarthak Jain
;
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=========================================================================
.ORIG x3000			; Program begins here
;-------------
;Instructions
;-------------
;R0:OUT
;R1: first input
;R2: first output
;R3: answer
;R4: dec 4 for iteraetions
;
;
;
;
;----------------------------------------------
;output prompt
;----------------------------------------------
LEA R0, intro			; get starting address of prompt string
PUTS			    	; Invokes BIOS routine to output string

;-------------------------------
GETC ;gets first input
OUT

AND R1, R1, #0
ADD R1, R1, R0 ;stores the user value into R1

LD R0, NEWLINE ;newline for next input
OUT

GETC  ;gets second value
OUT

AND R2, R2, #0
ADD R2, R2, R0 ;stores the user value into r2

LD R0, NEWLINE ;newline for next output
OUT

AND R0, R0, #0
ADD R0, R0, R1;storing first value into R0 to output
OUT

LEA R0, subtract ;outputting subtact sign
PUTS

AND R0, R0, #0
ADD R0, R0, R2;storing second value into R0 to output
OUT

LEA R0, equals ;outtpuing equal sign
PUTS

LD R4, DEC_04
DO_WHILE_LOOP
    ADD R1, R1, #-12
    ADD R2, R2, #-12
    ADD R4, R4, #-1
    BRp DO_WHILE_LOOP
END_DO_WHILE_LOOP

AND R3, R3, #0

NOT R2, R2
ADD R2, R2, #1

IF_STATEMENT
    ADD R3, R1, R2
    BRn TRUE_CONDITION
FALSE_CONDITION
    BR END_IF
TRUE_CONDITION
    NOT R3, R3
    ADD R3, R3, #1
    LD R0, subsign
    OUT
END_IF

LD R4, DEC_04
DO_WHILE_LOOP_1
    ADD R3, R3, #12
    ADD R4, R4, #-1
    BRp DO_WHILE_LOOP_1
END_DO_WHILE_LOOP_1

ADD R0, R3, #0
OUT
LD R0, newline
OUT

;---------------------------

HALT				; Stop execution of program
;------
;Data
;------
; String to prompt user. Note: already includes terminating newline!
intro 	.STRINGZ	"ENTER two numbers (i.e '0'....'9')\n" 		; prompt string - use with LEA, followed by PUTS.
newline .FILL x0A	; newline character - use with LD followed by OUT
subtract .STRINGZ " - " ;subtract character
equals .STRINGZ " = " ;equals character
DEC_04 .FILL #4
subsign .FILL x2D
;---------------
;END of PROGRAM
;---------------
.END
