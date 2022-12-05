.model small
.stack 200h
.data
.code
MAIN:
    .startup
    MOV AX, @data
    MOV DS, AX

    MOV CX, 0000H       ; imposto CX a 0
    MOV DX, 0000H       ; imposto DX a 0
    ; ciclo DO-WHILE -> controllo in coda
    MOV BX, 0001H       ; imposto il registro BX a 1 e lo uso nel ciclo iterativo
    CICLO:
        INC CX          ; incremento il valore di CX
        ;DEC DX         ; decremento DX
        MOV DL, '*'     ; imposto il registro DL con il carattere * 
        MOV AH, 02h     ; imposto il registro AH con il codice operativo 02H (messa a video)
        INT 21h         ; richieamo l'interrupt 21 per eseguire il codice 02H in AH.
        INC BX          ; incremento/"sposto" la variabile del ciclo.
        CMP BX, 0005h   ; confronto il registro BX con il valore 5
        JL CICLO
    
    ; ciclo WHILE -> controllo in testa
    MOV BX, 0001H
    CICLO_2:
        CMP BX, 0005
        JGE FINE
        INC CX
        MOV DL, '*'     ; imposto il registro DL con il carattere * 
        MOV AH, 02h     ; imposto il registro AH con il codice operativo 02H (messa a video)
        INT 21h         ; richieamo l'interrupt 21 per eseguire il codice 02H in AH.
        INC BX
        JMP CICLO_2
    
    FINE:
        MOV AH, 4CH
        INT 21H
    .exit
END