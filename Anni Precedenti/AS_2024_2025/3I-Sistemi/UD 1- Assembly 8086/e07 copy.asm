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
    
    ciclo:              ; realizzazione con ciclo DO-WHILE
        inc ax          ; incremento del registro AX
        dec bx          ; decremento di BX, registro su cui si basa il ciclo.
        cmp bx, 0000h   ; controllo valore di BX
        jg ciclo        ; eventuale salto condizionato alla testa del ciclo.
        
    fine:
        mov ah, 4ch
        int 21h    
    .exit
END