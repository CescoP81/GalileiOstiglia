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
