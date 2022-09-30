;=================================================
; Name: 
; Email: 
; 
; Lab: lab 4, ex 3
; Lab section: 
; TA: 
; 
;=================================================
.ORIG x3000

	LD R1, DATA_PTR

	AND R2, R2, #0
	ADD R2, R2, #1
	AND R3, R3, #0

    AND R4, R4, #0
    LD R4, DEC_VAL

	WHILE_LOOP
		STR R2, R1, #0
		ADD R1, R1, #1
		ADD R2, R2, R2
		;ADD R3, R3, #1
		;ADD R0, R3, xFFF6
		;BRn WHILE_LOOP
		ADD R4, R4, #-1
		BRp WHILE_LOOP
	END_WHILE_LOOP


	HALT

	DATA_PTR 	.FILL	x4000
	DEC_VAL     .FILL #10
.END

.ORIG x4000

	.BLKW 	#10

.END