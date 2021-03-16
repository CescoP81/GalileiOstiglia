/* Inizializza i vettori delle temperature
@param int[] Vettore delle temperature minime.
@param int[] Vettore delle temperature massime.
@param int Dimensione dei vettori.
@return void*/
void initTemperature(int _tmin[], int _tmax[], int _length);

/* Stampa un vettore di temperature.
@param int[] Vettore delle temperature da stampare
@param int Dimensione del vettore.
@return void*/
void stampaTemperature(int _temp[], int length);

/* Calcola e restituisce la temperatura media del vettore passato.
@param int[] Vettore delle temperature da stampare
@param int Dimensione del vettore.
@return float Temperatura media calcolata.*/
float tmp_media(int _tmp[], int _length);

/* Determina l'indice delle temperature massima e minima con differenza minore.
@param int[] Vettore delle temperature minime.
@param int[] Vettore delle temperature massime.
@param int Dimensione dei vettori.
@return int Indice delle celle _tmin e _tmax che danno differenza minore.*/
int deltaMinore(int _tmin[], int _tmax[], int _length);