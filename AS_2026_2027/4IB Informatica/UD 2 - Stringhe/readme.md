## ULTIMA ESERCITAZIONE PROPOSTA

Crea un programma che richieda l'inserimento di una stringa, calcola e comunica quali lettere e in che numero compongono la parola.
Es. RESSA
A = 1
E = 1
R = 1
S = 2

Sulla base del programma e04 che conta le lettere di una parola, sviluppare un algoritmo
che richieste due parole, verifica e comunica se sono due ANAGRAMMI.
Anagramma: due parole si dicono anagrammi se sono composte dalle stesse lettere ma in posizioni diverse!
p1: 'CACO'
p2: 'COCA'

---

:gear: *main programs*  
- **e01.c**  
Codice di esempio sulla dichiarazione di una stringa, visualizzazione char by char.  

- **e02.c**  
Come esercizio precedente ma sviluppando le funzioni e in aggiunta conta quante vocali sono presenti nella parola.

- **e03.c**   
Verifica se una parola inserita in input è palindroma. La proprietà **palindroma** prevede che una parola risulti uguali anche letta al contrario.

- **e04.c**  
Esercitazione che mostra il numero di occorrenze per ogni lettera dell'alfabeto in una determinata parola.

- **e05.c**  
Esercitazione che richiede in input due parole e verifica se sono una l'anagramma dell'altra.

---

### :notebook: **File:** lib_stringhe.h
- void initStringa(int _dim, char _str[]): Inizializza un vettore di caratteri con '\0' in tutte le celle.
- void strCharByChar(int _dim, char _str[]): Stampa una stringa char-by-char.
- int lunghezzaStringa(char _str[]): Calcola e restituisce la lunghezza di una stringa.
- int contaVocali(int _dim, char _str[]): Calcola e restituisce il numero di VOCALI presenti nella stringa.
- int isPalindroma(char _str[]): Verifica proprietà PALINDROMA: Una parola si dice palindroma se è possibile leggerla al contrario.
- int isPalindroma(char _str[]): Verifica se una parola è palindroma oppure no.
- void contaLettere(int _dim, char _str[]): Conta per ogni singola lettere quante volte compare nella parola passata.
- int isAnagramma(char _str1[], char _str2[]): Verifica se due stringhe sono l'una l'anagramma dell'altra.