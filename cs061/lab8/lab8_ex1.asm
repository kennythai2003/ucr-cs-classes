;=================================================
; Name: Kenny Thai
; Email: kthai025
; 
; Lab: lab 8, ex 1
; Lab section: 024
; TA: Sarthak Jain
; 
;=================================================

; test harness
.orig x3000
ld r6, SYS_STACK_ADDR ; DO NOT CHANGE
	
	ld r1, SUB_LOAD_VALUE
	jsrr r1
	
	add r5, r5, #1
		
	ld r1, SUB_PRINT_DECIMAL
	jsrr r1
	
	
halt
;-----------------------------------------------------------------------------------------------
; test harness local data:

; Address of stack for backing up registers. DO NOT CHANGE!
SYS_STACK_ADDR .FILL xFE00 ; DO NOT CHANGE
SUB_LOAD_VALUE .FILL x3200
SUB_PRINT_DECIMAL .FILL x3400

;===============================================================================================
.end

; subroutines:

;------------------------------------------------------------------------------------------
; Subroutine: SUB_LOAD_VALUE (Be sure to fill details in below)
;
; Parameter (R):  R5 has the value
; Return Value:     R5 
;------------------------------------------------------------------------------------------
.orig x3200

; Don't forget to backup R7 and any other register you use
    add r6, r6, #-1
    str r7, r6, #0
				 
	ld r5, value
				 
    ldr r7, r6, #0
    add r6, r6, #1
; Don't forget to restore any registers you use and R7				 
ret
;-----------------------------------------------------------------------------------------------
; SUB_LOAD_VALUE local data

value .FILL #-1204
.end

;===============================================================================================


;------------------------------------------------------------------------------------------
; Subroutine: SUB_PRINT_DECIMAL (Be sure to fill details in below)
;
; Parameter (R): R5 has the original value plus 1
; Return Value: nothing
;------------------------------------------------------------------------------------------
.orig x3400
				 
; Don't forget to backup R7 and any other register you use				 
	add r6, r6, #-1
    str r7, r6, #0	
    add r6, r6, #-1
    str r3, r6, #0
    add r6, r6, #-1
    str r2, r6, #0
    add r6, r6, #-1
    str r1, r6, #0
    add r6, r6, #-1
    str r0, r6, #0
    add r6, r6, #-1
    str r4, r6, #0
	
	add r5, r5, #0
	brn neg_dec
	add r5, r5, #0
	brzp end_neg_dec
	
	neg_dec ;outputs a negative sign if the filled value is negative
	    not r5, r5
	    add r5, r5, #1
	    ld r0, neg_sign
	    out
	end_neg_dec
	
;first digit
    and r2, r2, #0
    add r2, r5, #0 ;add our value to r2 
    and r3, r3, #0 ;reset r3 to 0 
    ld r3, neg_10000 ;fills r3 with -10000
    and r4, r4, #0 
    add r2, r2, r3 ;checks to see if filled value is less than 10000
    brn zero_1digit
    add r2, r2, #0 
    brzp digit_loop_1
    
    digit_loop_1
        add r4, r4, #1
        add r2, r2, r3 ;adds another 10000 to see if  value is 20000, repeats for 30000
        brzp digit_loop_1
        add r2, r2, #0 ;checks for left digit of the value 
        brn first_digit
    
    first_digit
        and r0, r0, #0
        ld r0, ascii
        add r0, r0, r4 ;r4 currently holds the value of the placement of left bit
        out
        add r0, r0, #0
        brp next_digit_1 ;goes to next digit
    
    zero_1digit ;outputs a zero if number is not in five digit range
        and r0, r0, #0
        ld r0, ascii
        out
        add r0, r0, #0
        brp go_to_next_digit_1
        
   next_digit_1
    
    and r3, r3, #0
    ld r3, neg_10000
    
    update_r5_1 ;loop to subtract amount of left digit left
        add r5, r5, r3
        add r4, r4, #-1
        brp update_r5_1
        
    go_to_next_digit_1
        
    
;second digit
    and r2, r2, #0
    add r2, r5, #0
    and r3, r3, #0
    ld r3, neg_1000
    and r4, r4, #0
    add r2, r2, r3
    brn zero_2digit
    add r2, r2, #0
    brzp digit_loop_2
    
    digit_loop_2
        add r4, r4, #1
        add r2, r2, r3
        brzp digit_loop_2
        add r2, r2, #0
        brn second_digit
    
    second_digit
        and r0, r0, #0
        ld r0, ascii
        add r0, r0, r4
        out
        add r0, r0, #0
        brp next_digit_2
    
    zero_2digit  ;outputs a zero if number is not in four digit range
        and r0, r0, #0
        ld r0, ascii
        out
        add r0, r0, #0
        brp go_next_digit_2
        
    next_digit_2
    
    and r3, r3, #0
    ld r3, neg_1000
    
    update_r5_2
        add r5, r5, r3
        add r4, r4, #-1
        brp update_r5_2
        
    go_next_digit_2
        
;third digit
    and r2, r2, #0
    add r2, r5, #0
    and r3, r3, #0
    ld r3, neg_100
    and r4, r4, #0
    add r2, r2, r3
    brn zero_3digit
    add r2, r2, #0
    brzp digit_loop_3
    
    digit_loop_3
        add r4, r4, #1
        add r2, r2, r3
        brzp digit_loop_3
        ADD r2, r2, #0
        brn third_digit
    
    third_digit
        and r0, r0, #0
        ld r0, ascii
        add r0, r0, r4
        out
        add r0, r0, #0
        brp next_digit_3
    
    zero_3digit  ;outputs a zero if number is not in three digit range
        and r0, r0, #0
        ld r0, ascii
        out
        add r0, r0, #0
        brp go_next_digit_3
        
    next_digit_3
    
    and r3, r3, #0
    ld r3, neg_100
    
    update_r5_3 ;updates value for next digit
        add r5, r5, r3
        add r4, r4, #-1
        brp update_r5_3
        
    go_next_digit_3
        
    
;fourth digit
    and r2, R2, #0
    add r2, R5, #0
    and r3, R3, #0
    ld r3, neg_10
    and r4, r4, #0
    add r2, r2, r3
    brn zero_4digit
    add r2, r2, #0
    brzp digit_loop_4
    
    digit_loop_4
        ADD R4, R4, #1
        ADD R2, R2, R3
        BRzp digit_loop_4
        ADD R2, R2, #0
        BRn fourth_digit
    
    fourth_digit
        and r0, r0, #0
        ld r0, ascii
        add r0, r0, r4
        out
        add r0, r0, #0
        brp next_digit_4
    
    zero_4digit    ;outputs a zero if number is not in two digit range
        and r0, r0, #0
        ld r0, ascii
        out
        add r0, r0, #0
        brp go_next_digit_4
        
    next_digit_4
    
    and r3, r3, #0
    ld r3, neg_10
    
    update_r5_4 ;prepears for next digit
        add r5, r5, r3
        ADD r4, r4, #-1
        brp update_r5_4 
        
    go_next_digit_4
        

;fifth digit
    and r0, r0, #0 ;output last digit
    ld r0, ascii
    add r0, r0, r5
    out

;newline
    and r0, r0, #0
    ld r0, newline
    out
	
	ldr r4, r6, #0
    add r6, r6, #1
	ldr r0, r6, #0
    add r6, r6, #1
    ldr r1, r6, #0
    add r6, r6, #1
    ldr r2, r6, #0
    add r6, r6, #1
    ldr r3, r6, #0
    add r6, r6, #1
	ldr r7, r6, #0
    add r6, r6, #1
; Don't forget to restore any registers you use and R7				 
ret
;-----------------------------------------------------------------------------------------------
; SUB_PRINT_DECIMAL local data
ascii   .FILL #48
neg_10000 .FILL #-10000
;ADD_10000   .FILL #10000
neg_1000  .FILL #-1000
;ADD_1000    .FILL #1000
neg_100   .FILL #-100
;ADD_100     .FILL #100
neg_10    .FILL #-10
;ADD_10      .FILL #10
neg_sign   .FILL #45
newline     .FILL #10

.end
