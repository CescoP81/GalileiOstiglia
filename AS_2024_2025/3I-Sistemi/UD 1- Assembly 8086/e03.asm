; Codice di esempio per lo scambio di valore tra due registri.

.model small
.stack 200h
.data
.code

MAIN:
    .startup
    mov ax, @data
    mov ds, ax
    
    mov ax, 0Fh     ; imposto AX con un valore esadecimale 0F
    mov bx, 0Ah     ; imposto BX con il valore esadecimale 0A
    
    ; come scambio i due valori tra i registri?
    mov cx, ax      ; salvo il valore di AX in CX
    mov ax, bx      ; assegno ad AX il valore contenuto in BX
    mov bx, cx      ; assegno a BX il valore contenuto in CX (ex valore di AX)
    
    ; righe di chiusura
    mov ah, 4ch
    int 21h
    .exit
END
