; Esempio di assegnazione e somma tra due registri.

.model small
.stack 200h
.data
.code

MAIN:
	;istruzioni di inizio codice
	.startup
	mov AX, @data
	mov DS, AX
	
    ; your code start here...
	mov AX, 02h     ;AX[0002]
    mov BX, 0Ah     ;BX[000A]

    add BX, AX      ;Add addizione matematica -> BX[000C]    
	
	;istruzione di chiusura codice
	mov AH, 4CH
	int 21h
	.exit
END