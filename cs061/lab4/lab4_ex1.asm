;=================================================
; Name: Kenny Thai
; Email: kthai025@ucr.edu
; 
; Lab: lab 4, ex 1
; Lab section: 24
; TA: Sarthak Jain
; 
;=================================================
.ORIG x3000

	LD R1, DATA_PTR
    LD R3, DEC_VAL
	AND R2, R2, #0
    
	WHILE_LOOP
		STR R2, R1, #0
		;R2 into the R1 array 
		ADD R1, R1, #1
		;move index of array
		ADD R2, R2, #1
		;increment value
		;ADD R3, R2, xFFF6
		ADD R3, R3, #-1
	;	BRn WHILE_LOOP
		BRp WHILE_LOOP
	END_WHILE_LOOP

	LD R1, DATA_PTR
	
	LDR R2, R1, #6
;Clearly, you can't access this location via a label, so you'll need its actual address.
;How will you obtain that? And how will you use that address to get the value stored there?
	
	HALT

	DATA_PTR 	.FILL	x4000
    DEC_VAL .FILL #10
.END

.ORIG x4000
	ARRAY .BLKW 	#10

.END