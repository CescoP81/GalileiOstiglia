.model small
.stack 200h
.data

.code
MAIN:
    .startup
    mov ax,@data
    mov ds, ax

    mov bx, 0Ah         ; imposto bx con un valore iniziale
    push bx             ; salvo BX nello stack con l'operazione di push

    mov bx, 20d         ; alcune operazioni per "sporcare" bx
    add bx, 10d
    inc bx
    sub bx, 05d

    pop bx              ; ripristino il valore di BX prendendolo dallo stack

    mov ah,4ch
    int 21h
    .exit
END