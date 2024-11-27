; Inizializzare i registri AX e BX con due valori a tua scelta compresi tra 0 e 255, quindi:
; se AX è uguale a BX incrementare AX di 1 unità e decrementare BX di 1 unità.

.model small
.stack 200h
.data
.code
MAIN:
    .startup
    mov ax, @data
    mov ds, ax
    
    mov ax, 0Ah
    mov bx, 0Ah
    
    cmp ax, bx 
    je VERO
    jmp fine
    VERO:
        add ax, 01h
        sub bx, 01h
        ;oppure poteete usare le istruzioni di INC e DEC
        ;inc ax
        ;dec bx
    fine:
        mov ah, 4ch
        int 21h
    .exit
END