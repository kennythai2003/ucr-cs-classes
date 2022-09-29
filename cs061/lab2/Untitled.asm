.ORIG x3000
    LEA R1, label1
    LD R2, label2
    LDI R3, label3
    LDR R4, R2, #0
    HALT
 
label1    .FILL x4000      ; label1 is an alias for mem. add. x3005
label2    .FILL x4100     ; label2 is an alias for mem. add. x3006
label3    .FILL x4200  
.end