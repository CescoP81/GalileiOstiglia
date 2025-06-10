; Realizza un programma Assembly che imposta il valore di AX con 03h, il valore di BX con 07h
; quindi tramite confronto e salto condizionato, imposta CX con il valore maggiore tra i due registri.

.model small
.stack 200h
.data
.code

MAIN:
    .startup
    mov AX, @data
    mov DS, AX 
    
    mov AX, 03h     ; imposto il valore iniziale di AX
    mov BX, 07h     ; imposto il valore iniziale di BX

    cmp AX, BX      ; CMP-> compare quindi compara i valori dei due registri scelti.
    jg VERO
    jle FALSO
        VERO:
            mov cx, ax
            jmp continua
        FALSO:
            mov cx, bx
            jmp continua
    CONTINUA:
        mov ah, 4ch
        int 21h
    .exit
END.

; SALTI E LORO UTILIZZO
; CMP op1, op2
;
;   JE -> SALTA SE op1 è uguale a op2
;   JNE -> SALTA se op1 è diverso da op2
;   JG -> SALTA SE op1 greater (maggiore) di op2
;   JGE -> SALTA SE op1 greater or equal (maggiore o oguale) di op2
;   jl -> SALTA SE op1 less (minore) di op2
;   jle -> SALTA SE op1 less or equal (minore o uguale) di op2
;   jmp -> SALTA SEMPRE NON é CONDIZIONATO.
;
;   riferimento: libro di testo cap 6 par 3, pag 143
