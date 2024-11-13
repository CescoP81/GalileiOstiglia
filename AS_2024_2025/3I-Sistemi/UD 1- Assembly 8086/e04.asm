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
    
    ; il registro AX se usato totalmente è un registro a 16bit
    ; da cui si ricavano la parta AL i primi 8bit da destra, e la parte AH il secondo
    ; gruppo di 8 bit
    
    mov cx, ax      ; questa assegnazione la posso fare perchè muovo 16bit in 16bit
    mov cl, ax      ; NON POSSIBILE perchè tento di muovere 16bit (ax) in 8bit
                    ; (cl -> parte bassa di CX)
    
    mov cl, al      ; muovo 8bit bassi in 8bit bassi
    mov ch, al      ; muovo 8bit bassi in 8bit alti

    mov cx, al      ; muovo (AL o AH) 8bit in un registro da 16
                    ; gli 8bit vanno sempre nella parte BASSA del registro
                    ; la parte ALTA viene azzerata.
    
    
    ; righe di chiusura
    mov ah, 4ch
    int 21h
    .exit
END