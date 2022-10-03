;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Kenny Thai
; Email: kthai025@ucr.edu
;
; Assignment name: Assignment 4
; Lab section: 024
; TA: Sarthak Jain
;
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=================================================================================
;THE BINARY REPRESENTATION OF THE USER-ENTERED DECIMAL NUMBER MUST BE STORED IN R4
;=================================================================================
.ORIG x3000
;-------------
;Instructions
;-------------
LD R3, DEC_5 ;max = 5 digits
AND R4, R4, #0

BEGIN_LOOP
; output intro prompt
	LD R0, introPromptPtr
	PUTS

    AND R4, R4, #0

	GETC
    OUT
; Set up flags, counters, accumulators as needed
    LD R3, DEC_5 ;max = 5 digits

; Get first character, test for '\n', '+', '-', digit/non-digit
; is very first character = '\n'? if so, just quit (no message)!
	AND R1, R1, #0
	ADD R1, R1, R0 ;first input stored in R0
	ADD R1, R1, #-10 ;checks newline input
	BRz ERROR_STOP

; is it = '+'? if so, ignore it, go get digits
	ADD R1, R1, #-16
	ADD R1, R1, #-16
	ADD R1, R1, #-1 ;decrement until we get ASCII represnetation of + (43) in decimal
	BRz POS_SIGN
	BRp NEG_CHECK

; is it = '-'? if so, set neg flag, go get digits
	NEG_CHECK
	    ADD R1, R1, #-2 ;get 45 aka the representation of -
	    BRz NEG_SIGN
	    BRp CHECKFORDIGIT
; is it < '0'? if so, it is not a digit	- o/p error message, start over
; is it > '9'? if so, it is not a digit	- o/p error message, start over
    CHECKFORDIGIT
        AND R1, R1, #0
        ADD R1, R1, R0 ;reload inputted value
        ADD R1, R1, #-16
        ADD R1, R1, #-16
        ADD R1, R1, #-16 ;gets R5 to check if ASCII representation falls within 0-9
        BRn ERROR ;nondigit <9 (<48)
        ADD R1, R1, #-9
        BRp ERROR ;nondigit >9	(>57)
        ADD R3, R3, #-1
        BR NO_SIGN

; if none of the above, first character is first numeric digit - convert it to number & store in target register!
	POS_SIGN
	    GETC ;get digit after +
	    OUT
	    ADD R0, R0, #-10
	    BRz ERROR_STOP ;terminate
	    ADD R0, R0, #-16
	    ADD R0, R0, #-16
	    ADD R0, R0, #-6 ;checks for nondigit (<48)
	    BRn ERROR
	    ADD R5, R0, #0
	    ADD R5, R5, #-9 ;checks for nondigit (>57)
	    BRp ERROR
	    ADD R6, R4, R4
	    ADD R4, R4, R4
	    ADD R4, R4, R4
	    ADD R4, R4, R4
	    ADD R4, R6, R4
	    ADD R4, R4, R0
	    ADD R3, R3, #-1
	    BRp POS_SIGN
	    BR ERROR_STOP

	NEG_SIGN
	    GETC
	    OUT
	    ADD R0, R0, #-10
	    BRz TWOCOMPLEMENT
	    ADD R0, R0, #-16
	    ADD R0, R0, #-16
	    ADD R0, R0, #-6
	    BRn ERROR
	    ADD R5, R0, #0
	    ADD R5, R5, #-9 ;checks for nondigit (>57)
	    BRp ERROR
	    ADD R6, R4, R4
	    ADD R4, R4, R4
	    ADD R4, R4, R4
	    ADD R4, R4, R4
	    ADD R4, R6, R4
	    ADD R4, R4, R0
	    ADD R3, R3, #-1
	    BRp NEG_SIGN
	    BR TWOCOMPLEMENT

	NO_SIGN
	    ADD R0, R0, #-10
	    BRz ERROR_STOP
	    ADD R0, R0, #-16
	    ADD R0, R0, #-16
	    ADD R0, R0, #-6
	    BRn ERROR
	    ADD R5, R0, #0
	    ADD R5, R5, #-9 ;checks for nondigit (>57)
	    BRp ERROR
	    ADD R6, R4, R4
	    ADD R4, R4, R4
	    ADD R4, R4, R4
	    ADD R4, R4, R4
	    ADD R4, R6, R4
	    ADD R4, R4, R0
	    BR POS_SIGN

	TWOCOMPLEMENT
	    NOT R4, R4
	    ADD R4, R4, #1
	    BR ERROR_STOP

	ERROR
	    LD R0, newline
	    OUT
	    LD R0, errorMessagePtr
	    PUTS
	    BR BEGIN_LOOP

	ERROR_STOP
	    LD R0, newline
	    OUT


; Now get remaining digits from user in a loop (max 5), testing each to see if it is a digit, and build up number in accumulator

; remember to end with a newline!

HALT

;---------------
; Program Data
;---------------
newline .FILL x0A
DEC_5   .FILL #5
introPromptPtr  .FILL xB000
errorMessagePtr .FILL xB200

.END

;------------
; Remote data
;------------
.ORIG xB000	 ; intro prompt
.STRINGZ	 "Input a positive or negative decimal number (max 5 digits), followed by ENTER\n"

.END

.ORIG xB200	 ; error message
.STRINGZ	 "ERROR: invalid input\n"

;---------------
; END of PROGRAM
;---------------
.END

;-------------------
; PURPOSE of PROGRAM
;-------------------
; Convert a sequence of up to 5 user-entered ascii numeric digits into a 16-bit two's complement binary representation of the number.
; if the input sequence is less than 5 digits, it will be user-terminated with a newline (ENTER).
; Otherwise, the program will emit its own newline after 5 input digits.
; The program must end with a *single* newline, entered either by the user (< 5 digits), or by the program (5 digits)
; Input validation is performed on the individual characters as they are input, but not on the magnitude of the number.
