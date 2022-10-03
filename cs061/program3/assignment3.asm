;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Kenny Thai
; Email: kthai025@ucr.edu
; 
; Assignment name: Assignment 3
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
LD R6, Value_ptr		; R6 <-- pointer to value to be displayed as binary
LDR R1, R6, #0			; R1 <-- value to be displayed as binary 
;-------------------------------
;INSERT CODE STARTING FROM HERE
;--------------------------------
LD R4, spacecnt
LD R2, numouts

BIT
    ADD R1, R1, #0 ;sees if it is a 0 at current bit
    BRzp POSITIVE_BINARY
    
    ADD R1, R1, #0 ;sees if it is a 1 at current bit
    BRn NEGATIVE_BINARY

NEGATIVE_BINARY
    LD R0, bin1 ;output 1
    OUT
   
    ADD R1, R1, R1 ;adding it to itself shifts the MSB over 1
    
    ;if 16 bits are printed DO DONE
    ADD R2, R2, #-1 ;decremenets amount of bits left to output
    BRnz DONE  
    
    ;if four bits are printed then DO OUTPUT_SPACE
    ADD R4, R4, #-1
    BRnz SPACE_CHARACTER    ;DO OUTPUT_NEWLINE IF R3 is neg or zero
   
    ;if statement to see if all 16 bits have been outputted
    IF_STATEMENT
        ADD R2, R2, #0
        BRp TRUE_CONDITION
    FALSE_CONDITION
        BR END_IF
    TRUE_CONDITION
        BR BIT
    END_IF
    
POSITIVE_BINARY
    LD R0, bin0 ;output 0
    OUT
    
    ADD R1, R1, R1 ;increment to new MSB
    
    ;if 16 bits are printed DO OUTPUT_NEWLINE
    ADD R2, R2, #-1 ;decremenets amount of bits left to output
    BRnz DONE
    
    ;if four bits are printed then DO OUTPUT_SPACE
    ADD R4, R4, #-1
    BRnz SPACE_CHARACTER
    
    ;if statement to see if all 16 bits have been outputted, if not continute
    IF_STATEMENT_1
        ADD R2, R2, #0
        BRp TRUE_CONDITION_1
    FALSE_CONDITION_1
        BR END_IF_1
    TRUE_CONDITION_1
        BR BIT
    END_IF_1

SPACE_CHARACTER
    LD R0, space
    OUT
    LD R4, spacecnt
    ;if statement to see if all 16 bits have been outputted, if not cotinue
    IF_STATEMENT_2
        ADD R2, R2, #0
        BRp TRUE_CONDITION_2
    FALSE_CONDITION_2
        BR END_IF_2
    TRUE_CONDITION_2
        BR BIT
    END_IF_2
    
DONE
    LD R0, newline
    OUT

HALT

;---------------	
;Data
;---------------
Value_ptr	.FILL xCA01	; The address where value to be displayed is stored
space       .FILL x20   ; space chracter
newline     .FILL x0A
bin0        .FILL x30 ;ASCII FOR 0
bin1        .FILL x31 ;ASCII FOR 1
spacecnt    .FILL #4  ;SPACE B/W EACH 4 BITS
numouts     .FILL #16 ;16 outputs

.END

.ORIG xCA01					; Remote data
Value .FILL xABCD			; <----!!!NUMBER TO BE DISPLAYED AS BINARY!!! Note: label is redundant.
;---------------	
;END of PROGRAM
;---------------	
.END
