; Inizializzare i registri AX e BX con due valori a tua scelta compresi tra 0 e 255, quindi:
; 2. se AX è minore o uguale di BX sommare i due valori in CX

.model small
.stack 200h
.data
.code
MAIN:
    .startup
    mov ax, @data
    mov ds, ax
    
    mov ax, 06h
    mov bx, 0Fh
    
    cmp ax, bx
    jle SOMMA
    jmp fine
    SOMMA:
        mov cx, ax
        add cx, bx
    FINE:
        mov ah, 4ch
        int 21h
    .exit
END
