// lib.c contiene tutte le definizioni delle funzioni.
// include tutte le librerie necessarie alle funzioni.
// include il file header lib.h con i prototipi.
#include <stdio.h>
#include "lib.h"

// -- realizzate per p02bis.c --
void initStringa(char _s[], int _dim){
    int i;
    for(i=0; i<_dim; i++)
        _s[i] = '\0';
}
void inputStringa(char _s[]){
    printf("Inserisci una parola: ");
    scanf("%s", _s);
}
int lunghezzaStringa(char _s[]){
    int i=0;
    while(_s[i] != '\0')
        i = i + 1;
    return(i);
}
int contaLetteraStringa(char _s[], char _c){
    int i;
    int cnt;

    i=0; 
    cnt=0;

    while(_s[i]!='\0'){
        if(_s[i] == _c){
            cnt = cnt + 1;
        }
        i = i + 1;
    }
    return(cnt);
}
int contaVocaliStringa(char _s[]){
    int i;
    int cnt;

    i = 0;
    cnt = 0;
    while(_s[i] != '\0'){
        if(_s[i]=='a' || _s[i]=='e' || _s[i]=='i' || _s[i]=='o' || _s[i]=='u'){
            cnt = cnt + 1;
        }
        i = i + 1;
    } 
    return(cnt);
}
void sostituisciCarattereStringa(char _s[], char _src, char _dst){
    int i;

    i = 0;
    while(_s[i] != '\0'){
        if(_s[i] == _src)
            _s[i] = _dst;
        i = i + 1;
    }
}
void stampaContrarioStringa(char _s[]){
    int i;
    for(i=lunghezzaStringa(_s)-1; i>=0; i--)
        printf("%c", _s[i]);
}
int verificaPalindroma(char _s[]){
    int i;
    int lung = lunghezzaStringa(_s);
    for(i=0; i<lung; i++){
        if(_s[i] != _s[lung-i-1]){
            return(0);
        }
    }
    return(1);
}
// -- realizzate per p03.c --
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
		lungStringa = lunghezzaStringa(_str);
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