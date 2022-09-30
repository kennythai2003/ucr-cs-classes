;=================================================
; Name: Kenny Thai
; Email: kthai025@ucr.edu
; 
; Lab: lab 8, ex 2
; Lab section: 024
; TA: Sarthak Jain
; 
;=================================================

; test harness
.orig x3000
LD R6, SYS_STACK_ADDR ; DO NOT CHANGE
	ld r1, value ;xABCD
	
	lea r0, prompt
	puts
	getc ;gets bit
	out
	
	and r4, r4, #0
	add r4, r0, #0
	ld r3, ascii
	add r4, r4, r3
	brn exit
	add r4, r4, #-10
	brzp exit
	add r4, r4, #10
	and r2, r2, #0
	add r2, r2, r4 ;holds first inputted value in r2
	
	getc
	out ;gets second digit if there is one

	and r4, r4, #0
	add r4, r0, #0
	add r4, r4, #-10
	brz sub
	add r4, r4, #10
	ld r3, ascii
	add r4, r4, r3
	brn exit
	add r4, r4, #-10
	brzp exit
    add r4, r4, #10
    and r2, r2, #0
    add r2, r2, #10
    add r2, r2, r4 ; combines the two digits to get an index
    
 ;   getc
 ;   out
	
    sub
    ld r3, sub_read_bit
    jsrr r3
    
    exit
    
halt
;-----------------------------------------------------------------------------------------------
; test harness local data:
VALUE             .FILL xF0F0 ; Use this value to read bits from

sub_read_bit    .FILL x3200
prompt  .stringz "enter bit: "
newline .fill #10
ascii   .fill #-48
; Address of stack for backing up registers. DO NOT CHANGE!
SYS_STACK_ADDR .FILL xFE00 ; DO NOT CHANGE

;===============================================================================================
.end

; subroutines:

;------------------------------------------------------------------------------------------
; Subroutine: SUB_READ_BIT (Be sure to fill details in below)
;
; Parameters (R):  r1
; Return Value: 
;------------------------------------------------------------------------------------------
.orig x3200

; Don't forget to backup R7 and any other register you use				 
	add r6, r6, #-1
	str r7, r6, #0
	add r6, r6, #-1
	str r3, r6, #0
	
	and r3, r3, #0
	ld r3, first_bit 
	add r2, r2, #-1 
	brzp make_mask ;creates a mask 
	add r2, r2, #0
	brn execute_mask
	
	make_mask
	    add r3, r3, r3  ; shifts the bit of r3
	    add r2, r2, #-1  ;continues to shift the bit until the index at r2 is reached
	    brzp make_mask
	
	execute_mask
	    and r1, r1, r3 ;xABCD anded with mask where it is all 0s and there is a 1 where the desired bit is
	    
	 and r0, r0, #0 ; 
	 add r1, r1, #0 ;checks to  see if it is 1 or 0
	 brnp r0_one
	 add r1, r1, #0
	 brz r0_zero
	 
	 r0_one
	    lea r0, outro
	    puts
	    and r0, r0, #0
	    add r0, r0, #1
	    and r4, r4, #0
	    add r4, r4, #1
	    and r3, r3, #0
	    ld r3, ascii1
	    add r0, r0, r3
	    out
	    br end_sub
	 
	 r0_zero
	    lea r0, outro
	    puts
	    and r0, r0, #0
	    and r4, r4, #0
	    and r3, r3, #0
	    ld r3, ascii1
	    add r0, r0, r3
	    out
	    br end_sub
	
	end_sub
	    ld r0, newline1
	    out
	    
    	and r0, r0, #0
    	add r0, r4, #0
	
	ldr r3, r6, #0
	add r6, r6, #1
	ldr r7, r6, #0
	add r6, r6, #1
	    
; Don't forget to restore any registers you use and R7				 
ret
;-----------------------------------------------------------------------------------------------
; SUB_COUNT_ONES local data
first_bit .fill #1
outro .stringz "bit at index: "
newline1    .fill #10
ascii1  .fill #48
.end

