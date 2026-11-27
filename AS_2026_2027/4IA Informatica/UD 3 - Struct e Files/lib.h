/* STRUTTURE DEFINITE CON TYPDEF */
typedef struct{
    int b;
    int h;
}Shape;
/* FUNZIONI DEFINITE NELLA LIBRERIA PERSONALE */

/**
 * Permette l'inserimento dei dati base e altezza di uno shape
 * @param Shape* Riferimento alla variabile da utilizzare.
 */
void inputShape(Shape* _x);

void printShape(Shape _x);