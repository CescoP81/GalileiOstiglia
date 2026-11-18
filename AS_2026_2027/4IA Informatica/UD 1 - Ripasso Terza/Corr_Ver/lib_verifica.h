/**
 * Funzione 1 di inizializzazione matrice e vettore
 * @param int Numero righe matrice
 * @param int Numero colonne matrice
 * @param int* Riferimento alla matrice
 * @param int Numero celle del vettore
 * @param int* Riferimmento al vettore
 * @param int Minimo del range
 * @param int Massimo del range
 */
void initMatrixVector(int _rows, int _cols, int _m[_rows][_cols], int _cell, int _v[], int _min, int _max);

/**
 * Visualizza una matrice di interi
 * @param int Numero righe matrice
 * @param int Numero colonne matrice
 * @param int* Riferimento alla matrice
 */
void stampaMatrice(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Visualizza un vettore di interi
 * @param int Numero celle del vettore
 * @param int* Riferimmento al vettore
 */
void stampaVettore(int _cell, int _v[]);

/**
 * Calcola media per ogni riga e restituisce indice riga con media maggiore
 * @param int Numero righe matrice
 * @param int Numero colonne matrice
 * @param int* Riferimento alla matrice
 * @return Indice di riga con media maggiore
 */
int indiceRigaMediaMaggiore(int _rows, int _cols, int _m[_rows][_cols]);

/**
 * Confronta somma vettore con somma colonna della matrice
 * @param int Numero righe matrice
 * @param int Numero colonne matrice
 * @param int* Riferimento alla matrice
 * @param int Numero celle del vettore
 * @param int* Riferimmento al vettore
 * @return NUmero di colonne con somma valori maggiore rispetto a somma valori vettore.
 */
int sommeVettoreColonne(int _rows, int _cols, int _m[_rows][_cols], int _cell, int _v[]);

/**
 * scambia due celle della matrice
 * @param int Numero righe matrice
 * @param int Numero colonne matrice
 * @param int* Riferimento alla matrice
 * @param int Indice di riga 1
 * @param int Indice di colonna 1
 * @param int Indice di riga 2
 * @param int Indice di colonna 2
 * @return True/False conforme all'evenuto scambio
*/
int swapCelle(int _rows, int _cols, int _m[_rows][_cols], int _r1, int _c1, int _r2, int _c2);