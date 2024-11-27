;Inizializzare i registri AX e BX con due valori a tua scelta compresi tra 0 e 255, quindi:
;1. se ax è maggiore di bx scambiare i due valori tra loro.

.model small
-stack 200h
.data
.code

MAIN:
    .startup
    mov ax, @data
    mov ds, ax
    
    mov ax, 0Ch
    mov bx, 06h
    
    cmp ax, bx          ; comparo i due registri op1=ax, op2=bx
    jg SCAMBIA          ; salte se op1 è maggiore di op2
    jmp fine            ; salta sempre a fine se non viene fatto il salto alla riga 18
    SCAMBIA:
        mov cx, ax      ; istruzioni di scambio tra due registri.
        mov ax, bx 
        mov bx, cx
    FINE:
        mov ah, 4ch     ; istruzioni finali di chiusura programma.
        int 21h
    .exit
END