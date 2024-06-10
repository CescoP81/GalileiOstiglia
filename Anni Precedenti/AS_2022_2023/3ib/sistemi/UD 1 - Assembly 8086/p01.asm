;Esempi di assegnazione valori ai registri grazie al comando MOV 
;- Assegnazione su 16bit e su 8bit. 
;- Assegnazione tra registri.
;- Assegnazioni tra parti di registri.

.model small
.stack 200h
.data
.code
MAIN:
    ;codice iniziale di ogni programma.
    .startup
    mov AX, @data
    mov DS, AX

    ;assegno al registro BX due valori, notare come cambia il contenuto.
    mov BX, 13d
    mov BX, 256d

    ;assegno al registro un valore in esadecimale
    ;poi assegno valori alle singole parti BH e BL
    mov BX, 0A0Ah
    mov BH, 1Ch
    mov BL, 04h

    ;assegno il contenuto di BX a AX 
    ;assegno le parti BH e BL a CL e CH.
    mov AX, BX
    mov CL, BH
    mov CH, BL

    ;Per le assegnazioni devo rispettare le dimensioni 16bit con 16bit, 8bit con 8bit
    
    ;codice finale di ogni programma.
    mov AH, 4Ch
    int 21h
    .exit
END