; Incrementare un registro AX per un numero di volte pari al valore di BX
.model small
.stack 200h
.data
.code
MAIN:
    .startup
    mov ax, @data
    mov ds,ax

    mov ax, 0000h
    mov bx, 0005h

    ciclo:              ; realizzazione ciclo con controllo in TESTA -> al pari di un WHILE();
        cmp bx, 0000h   ; controllo il registro con il valore di stop
        jle fine        ; se il contenuto del registro è inferiore o uguale a 0 salto a fine
        inc ax          ; se non salto eseguo queste due operazioni.
        dec bx          ; IMPORTANTE: Modificare il registro (variabile) su cui si basa il ciclo altrimenti possibile loop!
        jmp ciclo       ; salto alla testa del ciclo per un nuovo controllo.
    
    fine:
        mov ah, 4ch
        int 21h    
    .exit
END