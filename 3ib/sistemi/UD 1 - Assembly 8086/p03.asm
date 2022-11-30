;   Esempio di utilizzo dei salti condizionati.
;   L'istruzione cmp compara un registro con un valore o con altro registro
;   jl e jge sono i due salti possibili, in particolare jl "jump less" salta se BX < 000Ah 
;   jge "jump great equal" salta se BX >= 000Ah.
;   Le funzioni di salto JL e JGE richiedono l'uso di una LABEL alla quale saltare, nello specifico "allora" e "altrimenti"
;   LEZIONE 5 pag. 137 libro di testo.

.model small
.stack 200h
.data
.code

MAIN:
    .startup
    mov ax, @data
    mov ds, ax

    mov bx, 000Ch
    cmp bx, 000Ah
    jl allora
    jge altrimenti
    allora:
        mov cx, 0001h
        jmp fine_se
    altrimenti:
        mov dx, 0001h
    fine_se:
    mov ah,4ch
    int 21h
    .exit
END