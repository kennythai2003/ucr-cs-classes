; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Kenny Thai
; Email: kthai025@ucr.edu
; 
; Assignment name: Assignment 5
; Lab section: 024
; TA: Sarthak Jain
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=================================================================================
; PUT ALL YOUR CODE AFTER THE main LABEL
;=================================================================================

;---------------------------------------------------------------------------------
;  Initialize program by setting stack pointer and calling main subroutine
;---------------------------------------------------------------------------------
.ORIG x3000

; initialize the stack
ld r6, stack_addr

; call main subroutine
lea r5, main
jsrr r5

;---------------------------------------------------------------------------------
; Main Subroutine
;---------------------------------------------------------------------------------
main
; get a string from the user
; * put your code here
    lea r0, user_prompt ;load r0 with a prompt to ask the user for a strin
    puts                ;output user_prompt
    
    lea r1, user_string ;use r1 to store user string
    ld r4, get_user_string_addr ;loads r4 with subroutine
    jsrr r4 ;calls subroutine to retrieve and store user string
    
; find size of input string
; * put your code here
    and r4, r4, #0
    ld r4, strlen_addr
    jsrr r4
    
; call palindrome method
; * put your code here
    and r4, r4, #0
    ld r4, palindrome_addr
    jsrr r4
    
; determine of stirng is a palindrome
; * put your code here
    add r4, r4, #0
    BRz is_palindrome
    
    add r4, r4, #0
    BRp not_palindrome
    
; print the result to the screen
; * put your code here
    is_palindrome
        lea r0, result_string
        puts
        lea r0, final_string
        puts
        br exit
        
; decide whether or not to print "not"
; * put your code here
    not_palindrome
        lea r0, result_string
        puts
        lea r0, not_string
        puts
        lea r0, final_string
        puts
        br exit
        
    exit

HALT

;---------------------------------------------------------------------------------
; Required labels/addresses
;---------------------------------------------------------------------------------

; Stack address ** DO NOT CHANGE **
stack_addr           .FILL    xFE00

; Addresses of subroutines, other than main
get_user_string_addr .FILL    x3200
strlen_addr          .FILL    x3300
palindrome_addr      .FILL	  x3400


; Reserve memory for strings in the progrtam
user_prompt          .STRINGZ "Enter a string: "
result_string        .STRINGZ "The string is "
not_string           .STRINGZ "not "
final_string         .STRINGZ "a palindrome\n"

; Reserve memory for user input string
user_string          .BLKW	  100

.END

;---------------------------------------------------------------------------------
; get_user_string - DO NOT FORGET TO REPLACE THIS HEADER WITH THE PROPER HEADER
;---------------------------------------------------------------------------------
.ORIG x3200
get_user_string
; Backup all used registers, R7 first, using proper stack discipline
    add r6, r6, #-1
    str r7, r6, #0
    add r6, r6, #-1
    str r0, r6, #0
    add r6, r6, #-1
    str r1, r6, #0
    
    get_string
        getc ;get input
        out  ;echo inputted character
        str r0, r1, #0 ;put chracter into user_string
        add r0, r0, #-10 ;condition to check for newline character
        BRz end_get_string
        add r1, r1, #1 ;increment user_string to next address for next character
        BR get_string ;continues to get inputed character
    end_get_string
    
    and r0, r0, #0 ;accounts for guide instructions
    STR r0, r1, #0  ;replaces newline with a 0
; Resture all used registers, R7 last, using proper stack discipline
    ldr r1, r6, #0
    add r6, r6, #1
    ldr r0, r6, #0
    add r6, r6, #1
    ldr r7, r6, #0
    add r6, r6, #1
    
    ret
    
.END


;---------------------------------------------------------------------------------
; strlen - DO NOT FORGET TO REPLACE THIS HEADER WITH THE PROPER HEADER
;---------------------------------------------------------------------------------
.ORIG x3300
strlen
; Backup all used registers, R7 first, using proper stack discipline
    add r6, r6, #-1
    str r7, r6, #0
    add r6, r6, #-1
    str r1, r6, #0
    add r6, r6, #-1
    str r3, r6, #0
    
    and r5, r5, #0 ;make r 0
    
    count_character
        and r3, r3, #0
        ldr r3, r1, #0
        add r3, r3, #0 ; finds end of string (0)
        BRz exit_count_character
        add r1, r1, #1  ;moves addy of strign
        add r5, r5, #1  ;increment counter
        br count_character
    exit_count_character
    
; Resture all used registers, R7 last, using proper stack discipline
    ldr r3, r6, #0
    add r6, r6, #1
    ldr r1, r6, #0
    add r6, r6, #1
    ldr r7, r6, #0
    add r6, r6, #1
    
    ret
.END

;---------------------------------------------------------------------------------
; palindrome - DO NOT FORGET TO REPLACE THIS HEADER WITH THE PROPER HEADER
;---------------------------------------------------------------------------------
.ORIG x3400
palindrome ; Hint, do not change this label and use for recursive alls
; Backup all used registers, R7 first, using proper stack discipline
    add r6, r6, #-1
    str r7, r6, #0
    add r6, r6, #-1
    str r0, r6, #0
    add r6, r6, #-1
    str r3, r6, #0
    add r6, r6, #-1
    str r5, r6, #0
    add r6, r6, #-1
    str r0, r6, #0
    add r6, r6, #-1
    str r2, r6, #0   

    and r2, r2, #0
    add r2, r1, r5
    add r2, r2, #-1
    
    compare
        ldr r0, r1, #0
        ldr r3, r2, #0
        not r3, r3
        add r3, r3, #1
        add r0, r0, r3
        brnp different 
        add r0, r0, #0
        brz same
    
    same
        add r1, r1, #1
        add r5, r5, #-2
        and r0, r0, #0
        and r3, r3, #0
        add r3, r2, #-1
        not r3, r3
        add r0, r1, r3
        brn recursive_call
        and r4, r4, #0
        br base
        
    different
        and r4, r4, #0
        add r4, r4, #1
        br base
        
    recursive_call
        jsr palindrome
        
    base
        
; Resture all used registers, R7 last, using proper stack discipline
    ldr r2, r6, #0
    add r6, r6, #1
    ldr r0, r6, #0
    add r6, r6, #1
    ldr r5, r6, #0
    add r6, r6, #1
    ldr r3, r6, #0
    add r6, r6, #1
    ldr r0, r6, #0
    add r6, r6, #1
    ldr r7, r6, #0
    add r6, r6, #1
    
    ret
.END
