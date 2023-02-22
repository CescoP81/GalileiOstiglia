;creare un programma che utilizzando le funzioni stampa a video un quadrato di asterischi
;la cui misura del lato ,cioè il numero di asterischi è impostato nel main nel registro ax a tuo piacimento
.model small
.stack 200h
.data
.code
quadrato proc near
    push BP
    mov BP,SP
    mov cx,[BP+4]
    CICLOrighe:
        push cx
        mov cx,[BP+4]
        ciclocolonne:
            mov dl,'*'
            mov ah,02H
            int 21H
            loop ciclocolonne
        pop cx
        mov dl,10d
        mov ah,02H
        int 21H
        mov dl,13d
        mov ah,02H
        int 21H
        loop CICLOrighe
    pop BP
    ret
endp
MAIN:
    .startup
    mov AX,@data
    mov DS,Ax
    
    ;imposto ax a un valore
    mov AX,5d
    
    ;preparo il valorenello stack,chiamo la procedura,svuoto lo stack
    push AX
    call quadrato 
    pop AX
    
    ;ultima istruzione di chiusura del programma
    mov AH, 4Ch
    int 21h
    .exit
END
    
