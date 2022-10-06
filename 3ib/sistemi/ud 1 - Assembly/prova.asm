.model small
. stack 200h
.data
.code
    .startup
    mov ax,@data
    mov ds, ax
    mov ah, 4Ch
    int 21h
    .exit
end