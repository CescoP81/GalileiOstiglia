; crea un programma assembly che grazie ad una procedura NEAR chiamata stampaCar
; preleva dallo stack il carattere da stampare a video, ne esegue la stampa e ritorna
; al main program.

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
    mov AX, @data
    mov DS, AX

    mov AX, 'S'
    PUSH AX
    call stampaCar
    POP AX

    mov AH, 4Ch
    int 21h
    .exit
END