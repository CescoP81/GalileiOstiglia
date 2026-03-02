/*
    Esempio di scrittura codice con funzioni o sottoprogrammi.
    Data: 02.03.2026
*/
#include <stdio.h>
/* sezione dei prototipi -> E' la sezione dove si specifica:
    1. Il tipo di ritorno del dato della funzione [INT/FLOAT/BOOLEAN/ etc.] oppure nessuno VOID.
    2. Il nome della funzione, se composto da più parole allora si utilizza la camel notation, cioè
        prima lettera minuscola, tutte le altre iniziali in maiuscolo, senza spazi o trattini(alti o bassi)
    3. Il numero ed il tipo dei parametri che richiede la funzione.
    Il tutto prende il nome di FIRMA.
*/

/**
 * Calcola l'area di un quadrato conoscendo la misura del lato.
 * @param int Misura del lato.
 * @return Area calcola del quadrato.
 */
int calcolaArea(int _l);

/**
 * Visualizza tutti i divisori di un numero n passato come parametro.
 * @param int Numero iniziale di cui vedere i divisori.
 */
void vediDivisori(int _n);

/**
 * Calcola il perimetro della figura con lato L
 * @param int Misura del lato.
 * @return Perimetro calcolato.
 */
int calcolaPerimetro(int _l);

// sezione del MAIN PROGRAM
int main(){
    int lato;
    char junk;
    int area, perimetro;

    // acquisco il lato della figura 1
    printf("Inserisci un lato: ");
    scanf("%d", &lato);
    junk = getchar();

    area = calcolaArea(lato);
    printf("Area 1 calcola: %d\n", area);

    // acquisisco il lato figura 2
    printf("Inserisci un lato: ");
    scanf("%d", &lato);
    junk = getchar();

    area = calcolaArea(lato);
    printf("Area 2 calcola: %d\n", area);

    // acquisisco il lato figura 3
    printf("Inserisci un lato: ");
    scanf("%d", &lato);
    junk = getchar();

    area = calcolaArea(lato);
    printf("Area 3 calcola: %d\n", area);

    printf("\n");
    vediDivisori(54);

    printf("\n\n");
    perimetro = calcolaPerimetro(13);
    printf("Perimetro calcolato: %d\n", perimetro);
    return(0);
}
// sezione di DEFINIZIONE delle funzioni (cioè scrivo effettivamente il codice delle funzioni)
int calcolaArea(int _l){
    // dichiaro una variabile per il risultato
    int _area;
    // calcolo l'area utilizzando come lato il parametro _l
    _area = _l * _l;
    // restituisco il valore calcola alla MAIN
    return(_area);
}
int calcolaPerimetro(int _l){
    int perim;

    perim = (_l + _l) * 2;
    return(perim);
}
void vediDivisori(int _n){
    int div;
    div = 1;
    while(div <= _n){
        if(_n%div == 0)
            printf("%d ", div);
        div = div + 1;
    }
}