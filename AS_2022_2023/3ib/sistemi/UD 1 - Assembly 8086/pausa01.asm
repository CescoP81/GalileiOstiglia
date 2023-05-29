.model small
.stack 200h
.data
.code
MAIN:
    .startup
    mov ax, @data
    mov ds, ax

    ; codice del mio programma
    mov ax, 15d  ; 5 -> Ven

    ; Confronti di AX con i diversi valori possibili (da 1 a 7)
    cmp ax, 1d
    je lun
    cmp ax, 2d  
    je mar
    cmp ax, 3d
    je mer
    cmp ax, 4d
    je gio
    cmp ax, 5d
    je ven
    cmp ax, 6d
    je sab
    cmp ax, 7d
    je dom
    ; se nessun salto viene eseguito, stamp un '#' e vado alla terminazione del programma.
    mov dl, '#'
    mov ah, 02h
    int 21h
    jmp fine
    ; creo le diverse label per i giorni della settimana
    lun:
        mov dl, 'L'
        mov ah, 02h
        int 21h
        mov dl, 'u'
        int 21h
        mov dl, 'n'
        int 21h
        jmp fine
    
    mar:
        mov dl, 'M'
        mov ah, 02h
        int 21h
        mov dl, 'a'
        int 21h
        mov dl, 'r'
        int 21h
        jmp fine

    mer:
        mov dl, 'M'
        mov ah, 02h
        int 21h
        mov dl, 'e'
        int 21h
        mov dl, 'r'
        int 21h
        jmp fine

    gio:
        mov dl, 'G'
        mov ah, 02h
        int 21h
        mov dl, 'i'
        int 21h
        mov dl, 'o'
        int 21h
        jmp fine

    ven:
        mov dl, 'V'
        mov ah, 02h
        int 21h
        mov dl, 'e'
        int 21h
        mov dl, 'n'
        int 21h
        jmp fine

    sab:
        mov dl, 'S'
        mov ah, 02h
        int 21h
        mov dl, 'a'
        int 21h
        mov dl, 'b'
        int 21h
        jmp fine

    dom:
        mov dl, 'D'
        mov ah, 02h
        int 21h
        mov dl, 'o'
        int 21h
        mov dl, 'm'
        int 21h
           
    fine:
        mov ah, 4ch
        int 21h
    .exit
END