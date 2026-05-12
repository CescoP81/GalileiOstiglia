#include <stdio.h>
/**
 * Converte un numero decimale in cifre esadecimali, attenzione che utilizzando
 * un ciclo e in assenza di un vettore le cifre esadecimali risulteranno invertite rispetto
 * alla visualizzazione classica.
 * 
 * @param int Numero decimale da convertire.
 */
void baseSedici(int _n){
    int resto;

    while(_n > 0){
        resto = _n % 16;
        if(resto < 10) printf("%d", resto);
        if(resto == 10) printf("A");
        if(resto == 11) printf("B");
        if(resto == 12) printf("C");
        if(resto == 13) printf("D");
        if(resto == 14) printf("E");
        if(resto == 15) printf("F");
        _n = _n / 16;
    }
}

/**
 * Funzione RICORSIVA che converte un numero decimale in esadecimale. L'utilizzo di una ricorsiva
 * permette di avere la visualizzazione delle cifre esadecimali nell'ordine giusto.
 * Attenzione: il richiamo della funzione alla riga 37 DEVE stare sopra alle stampe,
 * se posizionata sotto alle printf il numero esadecimale risulta stampato come con il ciclo di cui sopra.
 * 
 * @param int Valore decimale da convertire
 */
void baseSediciRecursive(int _n){
    int resto;

    if(_n > 0){
        resto = _n % 16;
        baseSediciRecursive(_n / 16);
        if(resto < 10) printf("%d", resto);
        if(resto == 10) printf("A");
        if(resto == 11) printf("B");
        if(resto == 12) printf("C");
        if(resto == 13) printf("D");
        if(resto == 14) printf("E");
        if(resto == 15) printf("F");
    }
}

int main(){
    int decimale;
    char junk;

    printf("Inserisci un valore: ");
    scanf("%d", &decimale);
    junk = getchar();

    // conversione con funzione tradizionale e con ciclo
    printf("Il numero in decimale e': ");
    baseSedici(decimale);

    // conversione con funzione ricorsiva, le cifre esadecimali risultano visualizzate correttamente secondo i pesi 16^(n-1), 16^(n-2)...16^(0)
    printf("\n\n");
    printf("Numero in base 16 con ricorsiva: ");
    baseSediciRecursive(decimale);
}