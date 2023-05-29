; Programma assembly che stampa a video le prime 10 cifre naturali 0->9
.model small
.stack 200h
.data
.code
MAIN:
    .startup
    mov AX, @data
    mov DS, AX

    mov DL, 48d             ;oppure 30h oppure '0'
    ciclo_numeri:
        mov AH, 02h
        int 21h

        inc DL              ; add dl, 1d
        cmp DL, '9'
        jle ciclo_numeri

    mov dl,00h              ; azzero DL altrimenti stampa a video un carattere non voluto.
    mov AH, 02h
    int 21H
    .exit
END