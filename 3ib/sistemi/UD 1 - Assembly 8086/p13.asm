;Ralizzare un programma che impostato un registro cx con un valore a scelta
;intero visualizza un numero uguale di *.
.model small
.stack 200h
.data
.code

MAIN:
    .startup
    mov ax, @data
    mov ds, ax
    
    mov cx, 10d
    
    ;ciclo: 
    ;    dec cx   
    ;    MOV DL, '*'
    ;    MOV AH, 02H
    ;    INT 21H
    ;    cmp cx, 0d
    ;    jg ciclo
    
    ciclo:
        MOV DL, '*'
        MOV AH, 02H
        INT 21H
        loop ciclo
        
    mov dl, 10d
    int 21h
    mov dl, 10d
    int 21h
    mov dl, 13d
    int 21h
    
    mov cx, 5d                  ;inizializzo cx con il numero di righe
    ciclorighe: 
        push cx                 ;salvo nello stack il valore di cx(numero di righe da fare)
        mov cx, 10d             ;inizializzo cx con il numero di colonne
        ciclocolonne:
            MOV DL, '*'         ;imposto * per la visualizzazione
            MOV AH, 02H         ;42 e 43 messa a video
            INT 21H
            loop ciclocolonne   ;1. decrementa cx 2. controlla cx con 0 3. se maggiore di 0 salta alla label
        pop cx                  ;ripristino il valore salvato alla riga 38
        mov dl, 10d             ;46 47 48 49 messa a video di un'andata a capo (\n)
        int 21h
        mov dl, 13d
        int 21h
        loop ciclorighe         ;come riga 44
    
    
    mov ah, 4ch
    int 21h
    .exit
END