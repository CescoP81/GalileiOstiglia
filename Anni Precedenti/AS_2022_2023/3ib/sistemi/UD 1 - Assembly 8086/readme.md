### PER COMPILARE IN ASSEMBLER
- Aprire DOSBox
    - Nell'interfaccia comandi (Prompt) ci troviamo in Z:\
- Eseguire il comando "mount e: z:\tasm\bin" per montare l'unità vituale E:
    - Digitare E: (invio) per cambiare unità [ E:\ -> z:\tasm\bin].
- Salvare il proprio esercizio sul server nella cartella \tasm\bin
### Comandi in DOSBox
- DIR -> Visualizza il contenuto della directory corrente.
- DIR p*.asm -> Visualizza tutti i file che iniziano per 'p' e hanno estensione .asm
- tasm p.asm -> Compila il file scritto in assembly, se tutto ok restituisce un file con lo stesso nome ma con estensione .obj
- tlink p -> senza specificare l'estensione, viene linkato e quindi generati .map e .exe
- p.exe -> esegue il programma nel prompt dei comandi.
- td p.exe -> Apre il debugger e permette di eseguire il programma riga per riga (tasto F7).
- rescan -> se non vedi il file .asm nell'unità e:\ esegue un nuovo check della cartella.

### ISTRUZIONI DI SALTO (Pag. 137)
Devono sempre essere precedute da un'istruzione di compare (CMP) tra due registri o tra registro e valore.
CMP operando1, operando 2
- JNE -> Jump Not Equal -> !=
- JE -> Jump Equal -> ==
- JL -> Jump Less -> <
- JLE -> Jump Less Equal -> <=
- JG -> Jump Great -> >
- JGE -> Jump Great Equal -> >=



### *ELENCO ESERCITAZIONI*

**p01.asm**  
Esempi di assegnazione valori ai registri grazie al comando MOV 
- Assegnazione su 16bit e su 8bit. 
- Assegnazione tra registri.
- Assegnazioni tra parti di registri.

**p02.asm**  
Esempi di addizioni di valori a registri e tra registri. 
- addizione di un valore fisso ad un registro.
- addizione tra registri a 16bit.
- addizione tra parti di registri a 8bit.

**p03.asm**   
Esempio di IF-ELSE con i saldi condizionati e l'utilizzo delle LABEL.

**p04.asm**
Esempio di ciclo WHILE (controllo in testa) e di ciclo DO-WHILE (controllo in coda). Esempio anche di stampa a video di un carattere.

**p05.asm**  
Programma Assembly che grazie all'uso di una label ed ai salti condizionati,
realizza una iteravia (ciclo do-while) per la stampa delle prime 10 cifre naturali.

**p06.asm**  
Programma Assembly per mostrare l'utilizzo dello stack come area di memoria in cui salvare momentaneamente il valore di registri per poterli utilizzare per altre funzionalità. Uso di PUSH e POP.

**p08.asm**  
Programma di esempio per la dichiarazione di una procedura NEAR, con richiamo grazie all'uso di CALL e con passaggio di valori tramite lo stack PUSH e POP.

**p09.asm**  
Programma Assembly che grazie alla procedura stampaCar recupera dallo stack il carattere da visualizzare a video.

**p10.asm**  
Programma Assembly che grazie alla procedura stampaCar richiamata internamente ad una iterativa 'ciclo' stampa a video le lettere dalla A alla Z, alfabeto maiuscolo.

**p11.asm**  
Programma Assembly che grazie alla procedura 'sommatoria' recupera dallo stack i due addendi e a sua volta scrive nello stack il risultato calcolato. Il main con le operazioni di POP estrae i valori così calcolati. Fare attenzione alla struttura LI-FO dello stack, le operazioni di PUSH e POP come di indirizzamento [BP+??] non sono casuali.

**p12.asm**  
Scrivere una PROC NEAR Assembly che riceve dal MAIN tramite lo stack due valori, il primo valore è un numero intero maggiore di zero; il secondo valore deve essere 0 oppure 1. La funzione recuperati i due dati dallo stack procede nel seguente modo:
- se il numero è minore di 9, controlla il secondo valore se è 1 stampa a video i valori da numero a 9, se è zero invece da numero a 0.
- se il numero è superiore a 9 allora stampa a video un singolo carattere ash '#'.

**pausa01.asm**
Realizzare un programma Assembly utilizzando i salti condizionali, impostando nel registro AX il numero del giorno della settimana il programma dovrà visualizzare il nome del giorno in formato 3 lettere: lun, mar, mer, gio, ven, sab, dom dove lunedì è il giorno 1.
