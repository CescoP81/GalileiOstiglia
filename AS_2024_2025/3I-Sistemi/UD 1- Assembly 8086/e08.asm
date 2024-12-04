; Realizza un programma Assembly che imposta il registro AX con valore 0005h, il registro BX
; con valore 0004h e calcola in CX il prodotto di AX*BX con somme successive.
; Good Luck.
.model small
.stack 200h
.data
.code

MAIN:
    .startup
    mov ax, @data
    mov ds, ax

    mov ah, 4ch
    int 21h
    .exit
END
    