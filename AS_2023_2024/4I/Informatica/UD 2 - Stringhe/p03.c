/**
 * Creare un programma C che soddisfi le seguenti richieste:
 * - [x] input di una stringa.
 * - [x] stampa di una stringa a video con funzione ricorsiva.
 * - [x] Conteggio delle lettere maiuscole e minuscole in una stringa.
 * - [x] Verifica se esistono doppie in una stringa 'otto', 'sette'.
 * - [x] Prima lettera sempre maiuscola (se la stringa inizia con una minuscola, la trasforma in maiuscola).
 * - [x] Per ogni lettera calcola e stampa il numero di occorrenze (quante volte ogni lettera compare).
 * - [] Crea stringa inversa. (st1 è l'originale, st2 è l'inversa).
 * - [] Verifica se due stringhe sono anagrammi (st2 è anagramma di st1, anagramma: parole diverse ma formate dalle stesse lettere)
 * 
 * Utilizzare le funzioni già esistenti nel file lib.c/lib.h, le nuove funzioni prima farne un test nel main e poi spostarle nel file libreria.
*/
#include <stdio.h>
#include "lib.c"
const int DIM = 21;

void stampaStringaRicorsiva(char[], int);
void contaMaiuscoleMinuscole(char[]);
int verificaDoppie(char[]);
void primaLetteraMaiuscola(char[]);
void contaSingoleLettere(char[]);
void stringaInversa(char[], char[]);
int verificaAnagrammi(char[], char[]);
/**
* Genera un anagramma di str e lo restituisce in str_2
* @param char[] Riferimento a stringa orginale _str
* @param char[] Riferimento alla stringa anagramma _str2
*/
void generaAnagramma(char[], char[]);

int main(){
    char str[DIM];
    char str2[DIM];

    // punto 1
    initStringa(str, DIM);
    inputStringa(str);

    // punto 2
    stampaStringaRicorsiva(str, 0);
	printf("\n");
    // punto 3
    contaMaiuscoleMinuscole(str);
	printf("\n");
    // punto 4
    if(verificaDoppie(str))
        printf("\nNella stringa '%s' esistono una o piu' lettere doppie\n", str);
    else
        printf("\nNella stringa '%s' non sono presenti doppie.\n", str);
    
    // punto 5
    primaLetteraMaiuscola(str);
    printf("Stringa modificata: %s\n", str);

	// punto 6
	contaSingoleLettere(str);
	printf("\n");
	
	// punto 7
	stringaInversa(str, str2);
	printf("La stringa inversa e'': %s\n", str2);
	
	return(0);
}

void stampaStringaRicorsiva(char _str[], int _index){
    if(_str[_index] != '\0'){
        printf("%c", _str[_index]);
        stampaStringaRicorsiva(_str, _index+1);
    }
}
void contaMaiuscoleMinuscole(char _str[]){
    int i;
    int cntMaiuscole, cntMinuscole, lungStringa;

    lungStringa = lunghezzaStringa(_str);
    cntMaiuscole = 0;
    cntMinuscole = 0;
    for(i=0; i<lungStringa; i++){
        if(_str[i]>='A' && _str[i]<='Z')
            cntMaiuscole = cntMaiuscole + 1;
        if(_str[i]>='a' && _str[i]<='z')
            cntMinuscole = cntMinuscole + 1;
    }
    printf("Maiuscole: %d - Minuscole: %d\n", cntMaiuscole, cntMinuscole);
}
int verificaDoppie(char _str[]){
    int i;
    int esistonoDoppie = 0;

    for(i=0; i<lunghezzaStringa(_str)-1; i++){
        if(_str[i]==_str[i+1])
            esistonoDoppie = 1;
    }

    return(esistonoDoppie);
}
void primaLetteraMaiuscola(char _str[]){
    int offsetAlfabeto;
    if(lunghezzaStringa(_str)>0){
        if(_str[0]>='a' && _str[0]<='z'){
            offsetAlfabeto = _str[0] - 'a';
            _str[0] = 'A' + offsetAlfabeto;
        }
    }
}
void contaSingoleLettere(char _str[]){
	int lungStringa;
	int i;
	int occorrenze[26];
	int offset;
	
	// azzero il vettore dei contatori di 26 celle quante sono le lettere possibili
	for(i=0; i<26; i++)
		occorrenze[i] = 0;
	
	// scorro tutta la stringa e ad ogni lettera incremento il contatore associato.
	lungStringa = lunghezzaStringa(_str);
	for(i=0; i<lungStringa; i++){
		if(_str[i]>='a' && _str[i]<='z')
			offset = _str[i] - 'a';
		if(_str[i]>='A' && _str[i]<='Z')
			offset = _str[i] - 'A';
		occorrenze[offset]++;
	}
	
	// stampo tutti i 26 contatori, preceduti dalla lettera di riferimento.
	for(i=0; i<26; i++){
		printf("%c=%3d, ", ('a'+i), occorrenze[i]);
		if(i!=0 && i%10 == 0)
			printf("\n");
	}
}
void stringaInversa(char _str[], char _str2[]){
	int i;
	int lungStringa;
	// calcolo la lunghezza della stringa originale
	lungStringa = lunghezzaStringa(_str);
	// utilizzo le lettere della stringa originale riempendo str2 partendo dalla fine.
	for(i=0; i<lungStringa; i++){
		_str2[lungStringa-i-1] = _str[i];
	}
	// alla fine della stringa creata DEVO mettere il '\0' terminatore di stringa.
	_str2[lungStringa] = '\0';	
}

int verificaAnagrammi(char _str[], char _str2[]){
	int occorrenze[26];
	int i;
	int lungStringa;
	int verificato;
	
	if(lunghezzaStringa(_str) != lunghezzaStringa(_str2))
		return(0);
	else{
		// azzero il vettore occorrenze
		for(i=0; i<26; i++)
			occorrenze[i] = 0;
	
		// calcolo per ogni lettera di _str quante volte compare.
		lungStringa = lunghezzaStringa(str);
		for(i=0; i<lungStringa; i++){
			if(_str[i]>='a' && _str[i]<='z')
				occorrenze[_str[i]-'a']++;
			if(_str[i]>='A' && _str[i]<='Z')
				occorrenze[_str[i]-'A']++;
		}
		
		// utilizzo il ciclo fatto sopra, con _str2, ma anziche incrementare vado a decrementare
		for(i=0; i<lungStringa; i++){
			if(_str2[i]>='a' && _str2[i]<='z')
				occorrenze[_str2[i]-'a']--;
			if(_str2[i]>='A' && _str2[i]<='Z')
				occorrenze[_str2[i]-'A']--;
		}
		
		// controllo lo stato del vettore occorrenze
		verificato = 1;
		for(i=0; i<26; i++){
			if(occorrenze[i] != 0)
				verificato = 0;
		}
		
		return(verificato);
	}
}

