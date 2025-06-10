;Esempio iniziale di Assembler 8086

.model small
.stack 200h
.data
.code

MAIN:
	;istruzioni di inizio codice
	.startup
	mov AX, @data
	mov DS, AX
	
	mov AX, 0Ah
	mov BX, 0Bh
	
	;istruzione di chiusura codice
	mov AH, 4CH
	int 21h
	.exit
END