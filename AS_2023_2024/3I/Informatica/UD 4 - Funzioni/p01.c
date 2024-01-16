/*
	Esercizio di esempio sulla dichiarazione, definizione e chiamata
	di una funzione.
	Funzione pu� essere indicata, per esempio sul libro di testo, anche
	come come procedura.
	In generale una funzione � un blocco di codice richiamabile quantevolte si vuole
	evitando di riscriverlo per intero.
*/
#include <stdio.h>

/* Dichiarazione del prototipo della funzione
	void -> Indica che la funzione non restituisce nulla al MAIN.
	calcoliRettangolo -> il nome della funzione, non possono esserci due nomi uguali.
	int _b -> parametro di tipo intero
	int _h -> parametro di tipo intero
	
	tutta la riga void.... viene chiamata FIRMA della funzione.
*/
void calcoliRettangolo(int _b, int _h);

int main(){
	int base, altezza;
	
	//int area, perimetro;
	
	base = 5;
	altezza = 4;
	calcoliRettangolo(base, altezza); // chiamata della funzione passando base e altezza.
	/*area = base * altezza;
	perimetro = (base + altezza) * 2;
	printf("Il rettangolo %d x %d ha:\n", base, altezza);
	printf("- perimetro %d\n", perimetro);
	printf("- area %d\n\n", area);
	*/
	
	base = 2;
	altezza = 7;
	calcoliRettangolo(base, altezza); // chiamata della funzione passando base e altezza.
	/*area = base * altezza;
	perimetro = (base + altezza) * 2;
	printf("Il rettangolo %d x %d ha:\n", base, altezza);
	printf("- perimetro %d\n", perimetro);
	printf("- area %d\n\n", area);*/
	
	base = 8;
	altezza = 2;
	calcoliRettangolo(base, altezza); // chiamata della funzione passando base e altezza.
	/*area = base * altezza;
	perimetro = (base + altezza) * 2;
	printf("Il rettangolo %d x %d ha:\n", base, altezza);
	printf("- perimetro %d\n", perimetro);
	printf("- area %d\n\n", area);*/
	
	base = 5;
	altezza = 5;
	calcoliRettangolo(base, altezza); // chiamata della funzione passando base e altezza.
	/*area = base * altezza;
	perimetro = (base + altezza) * 2;
	printf("Il rettangolo %d x %d ha:\n", base, altezza);
	printf("- perimetro %d\n", perimetro);
	printf("- area %d\n\n", area);*/
	
	return(0);
}

/*
int main(){
	int base, altezza;
	
	base = 5;
	altezza = 4;
	calcoliRettangolo(base, altezza); // chiamata della funzione passando base e altezza.
		
	base = 2;
	altezza = 7;
	calcoliRettangolo(base, altezza); // chiamata della funzione passando base e altezza.
		
	base = 8;
	altezza = 2;
	calcoliRettangolo(base, altezza); // chiamata della funzione passando base e altezza.
		
	base = 5;
	altezza = 5;
	calcoliRettangolo(base, altezza); // chiamata della funzione passando base e altezza.
	return(0);
}
*/

// definizione della funzione -> si inseriscono le righe di codice
// necessarie alle operazioni che devono essere svolte.
void calcoliRettangolo(int _b, int _h){
	int area, perimetro;
	
	area = _b * _h;
	perimetro = (_b + _ah) * 2;
	printf("Il rettangolo %d x %d ha:\n", _b, _h);
	printf("- perimetro %d\n", perimetro);
	printf("- area %d\n\n", area);
}


