;=================================================
; Name: Kenny Thai
; Email: kthai025@ucr.edu
; 
; Lab: lab 1, ex 0
; Lab section: 024
; TA: Sarthak Jain
; 
;=================================================
; 
; Hello world example program
; Also illustrates how to use PUTS (aka: Trap x22)
;
.ORIG x3000
;--------------
; Instructions
;--------------
    LEA R0, MSG_TO_PRINT ;R0 <-the location of the label: MSG_TO_PRINT
                            ;LEA serves to translate the label you give to a memory address in this case MSG_TO_PRINT
    PUTS    ;Prints string defined as MSG_TO_PRINT
    ;invokes the subroutine which uses R0 to locate the string
    
    HALT        
;--------------
; Local data
;--------------
    MSG_TO_PRINT .STRINGZ "Hello world!!!\n" ;store 'H' in an address labelled
                                     ;MSG_TO_PRINT and then each
                                     ;character ('e','l','l','o','',w',...) in
                                     ;its own (consecutive) memory
                                     ;address, followed by $0 at the end
                                     ;of the string to mark the end of the string
    .END