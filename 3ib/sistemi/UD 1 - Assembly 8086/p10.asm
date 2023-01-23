.model small
.stack 200h
.data
.code

stampaCar PROC NEAR
    PUSH BP
    MOV BP, SP 

    MOV BX, [BP+4]
    MOV DL, BL
    MOV AH, 02H
    INT 21H 

    POP BP
    RET
ENDP

MAIN:
    .startup
    MOV AX, @DATA 
    MOV DS, AX 

    MOV AL, 'A'
    CICLO:
        CMP AL,'Z'
        JG FINE
        PUSH AX
        CALL stampaCar
        POP AX
        INC AX
        JMP CICLO

    FINE:
        MOV AH, 4Ch
        INT 21H
    .exit
END