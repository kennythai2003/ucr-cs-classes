;=================================================
; Name: Kaihang MA
; Email: kma023@ucr.edu
; GitHub username: KarlMa1997
; 
; Assignment name: Assignment 4
; Lab section: 028
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team.
;
;=================================================================================
;THE BINARY REPRESENTATION OF THE USER-ENTERED DECIMAL NUMBER MUST BE STORED IN R6
;=================================================================================

.ORIG x3000			; Program begins here
;-------------
;Instructions
;-------------

;-------------------------------
;INSERT CODE STARTING FROM HERE 
;--------------------------------
;Example of how to Output Intro Message
;LD R0, introMessagePtr  ; Get pointer to Intro Message
;PUTS

;Example of how to Output Error Message
;LD R0, errorMessagePtr  ; Get pointer to Error Message
;PUTS
LD R3,COUNTER
AND R6,R6,#0

START_LOOP
  AND R6,R6,#0
  LD R0,introMessagePtr
  PUTS
  
  GETC
  OUT
  
  AND R5,R5,#0		;CHECK POSITIVE SIGN
  ADD R5,R5,R0
  ADD R5,R5,#-10
  BRz ERROR1
  ADD R5,R5,#-6
  ADD R5,R5,#-16
  ADD R5,R5,#-11
  BRz LOOP_POS
  BRp CHECKNEG
  
  CHECKNEG
    ADD R5,R5,#-2	;CHECK NEGATIVE SIGN
    BRz LOOP_NEG
    BRp CHECKNUM
    
  CHECKNUM
    AND R5,R5,#0
    ADD R5,R5,R0  
    ADD R5,R5,#-16
    ADD R5,R5,#-16
    ADD R5,R5,#-16
    BRn ERROR1
    ADD R5,R5,#-9
    BRp ERROR1
    ADD R3,R3,#-1
    BR LOOP_NUM
    
  LOOP_POS
    GETC
    OUT
    ;CONVERT ASCII TO DECIMAL
    ADD R0,R0,#-10
    BRz HALTPROGRAM
    ADD R0,R0,#-6
    ADD R0,R0,#-16
    ADD R0,R0,#-16
    BRn ERROR1
    ADD R4,R0,#0
    ADD R4,R4,#-9
    BRp ERROR1
    ADD R1,R6,R6
    ADD R6,R6,R6
    ADD R6,R6,R6 
    ADD R6,R6,R6 
    ADD R6,R1,R6 
    ADD R6,R6,R0
    ADD R3,R3,#-1
   BRp LOOP_POS
   BR HALTPROGRAM
   
   LOOP_NEG
    GETC
    OUT
    ADD R0,R0,#-10
    BRz TWOCOM
    ADD R0,R0,#-6
    ADD R0,R0,#-16
    ADD R0,R0,#-16
    BRn ERROR1
    ADD R4,R0,#0
    ADD R4,R4,#-9
    BRp ERROR1
    ADD R1,R6,R6 
    ADD R6,R6,R6
    ADD R6,R6,R6 
    ADD R6,R6,R6 
    ADD R6,R1,R6 
    ADD R6,R6,R0
    ADD R3,R3,#-1
   BRp LOOP_NEG
   BR TWOCOM
    
   LOOP_NUM
    ADD R0,R0,#-10
    BRz HALTPROGRAM
    ADD R0,R0,#-6
    ADD R0,R0,#-16
    ADD R0,R0,#-16
    BRn ERROR1
    ADD R4,R0,#0
    ADD R4,R4,#-9
    BRp ERROR1
    ADD R1,R6,R6 
    ADD R6,R6,R6
    ADD R6,R6,R6 
    ADD R6,R6,R6 
    ADD R6,R1,R6 
    ADD R6,R6,R0
    BR LOOP_POS
    
   TWOCOM
    NOT R6,R6
    ADD R6,R6,#1
    BR HALTPROGRAM
  
   ERROR1
    LEA R0,NEWLINE
    PUTS
    LD R0,errorMessagePtr
    PUTS
   BR START_LOOP
   
  HALTPROGRAM
    LEA R0,NEWLINE
    PUTS
    HALT

;---------------	
;Data
;---------------
introMessagePtr		.FILL x6000
errorMessagePtr		.FILL x6100
NEWLINE .STRINGZ "\n"
COUNTER .FILL #5
.END
;------------
;Remote data
;------------
.ORIG x6000
;---------------
;messages
;---------------
intro .STRINGZ	"Input a positive or negative decimal number (max 5 digits), followed by ENTER\n"
;---------------
;error_messages
;---------------
.END

.ORIG x6100	
error_msg1	.STRINGZ	"ERROR INVALID INPUT\n"

;---------------
;END of PROGRAM
;---------------
.END
;-------------------
;PURPOSE of PROGRAM
;-------------------