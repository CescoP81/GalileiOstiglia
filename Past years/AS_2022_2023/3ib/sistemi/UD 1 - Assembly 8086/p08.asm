; Esempio di dichiarazione ed utilizzo di una procedura. 
; passaggio di valore tramite lo stack.
; recupero del valore dallo stack.
; indirizzamento nello stack.
; Rif. pag 179 libro di testo.

.model small
.stack 200h
.data
.code

; dichiarazione della funzione
fprova PROC NEAR
    push BP
    mov bp, sp 

    mov bx, 48d
    mov [BP+4], bx      ;rif pag 184

    pop bp
    ret
ENDP

; Dichiarazione del MAIN PROGRAM
MAIN:
    .startup
    mov ax, @data
    mov ds, ax

    mov ax, 0000h
    mov bx, 0000h

    push cx         ; salvo nello stack 
    call fprova
    pop cx

    mov ah,4ch
    int 21h
    .exit
END

