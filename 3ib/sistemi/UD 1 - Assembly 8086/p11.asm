;Realizza un programma che richiama la funzione 'sommatoria',
;passando due valori tramite lo stack e ricevendo sempre dallo stack
;il risultato della somma dei due valori.

.model small
.stack 200h
.data

.code
sommatoria PROC NEAR
    PUSH bp
    mov bp, sp
    mov AX, [bp+4]      ; recupero dallo stack il terzo valore (terzo push)
    mov BX, [bp+6]      ; secondo valore push nella main 
    mov CX, [bp+8]      ; primo valore, prima push nella main
    mov AX, BX
    add AX, CX
    mov [BP+4], AX 
    RET
ENDP

MAIN:
    .startup
    mov ax, @data 
    mov ds, ax

    mov ax, 10d
    PUSH ax 
    mov ax, 5d
    push ax 
    push ax 

    call sommatoria

    pop cx      ; nel TD dovrei ottenere 000F
    pop bx 
    pop ax 

    mov ah, 4ch
    int 21h
    .exit
END