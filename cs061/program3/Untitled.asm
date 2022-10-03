.orig x3000

LEA R1, array
LD R2, size
AND R3, R2, #0
ADD R3, R3, #1

LOOP
    STR R3, R1, #0
    ADD R3, R3, R3
    ADD R1, R1, #1
    ADD R2, R2, #-1
    BRnp LOOP

HALT
size    .FILL #5
array   .BLKW #5

.end