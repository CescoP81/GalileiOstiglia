;Esempi di addizioni di valori a registri e tra registri. 
;- addizione di un valore fisso ad un registro.
;- addizione tra registri a 16bit.
;- addizione tra parti di registri a 8bit.

.model small
.stack 200h
.data
.code
MAIN:
    .startup
    mov AX, @data 
    mov DS, AX

    ;azzero il registro AX
    mov AX, 0000h
    ;aggiungo ad AX il valore 10 decimale
    ADD ax, 10d

    ;assegno a BX il valore 0002h
    mov BX, 0002h
    ;aggiungo a AX il contenuto di BX
    ADD AX, BX

    mov CX, 0005h
    add CH, CL

    MOV AH, 255d
    mov AL, 255d
    ADD AX, 0001h
    ;quanto vale il registro AX?
    ;il flag di Carry è cambiato? quali altri flag sono cambiati?

    mov AH, 4Ch
    int 21h
    .exit
END