// definisco due costanti letterali associati ai pin 6 e 13 digitali
#define LED1 6
#define LED2 13

/* definisco la struttura del led definita da
  - oldTime -> ultimo tempo letto con millis in cui è cambiato lo stato
  - interval -> intervallo in ms per il cambio stato.
  - status -> 0/1 acceso/spento
  - portOut -> intero che indica il pin associato al led.
*/
struct led{
  unsigned long oldTime;  // il tempo in cui è avvenuto il cambio di stato
  int interval;           // l'intervallo in ms tra uno scatto ed il successivo.
  int status;             // lo stato attuale 1/0
  int portOut;            // il numero del pin digiale associato
};

led l1; // dichiaro l1 e l2 strutturati e globali.
led l2;

/* Funzione che inizializza una struttura led con i relativi parametri
  @param led* riferimento alla struttura led
  @param int Intervallo di cambio stato
  @param int pin output associato
*/
void initLed(led *x, int _i, int _po){
  (*x).oldTime = millis();
  (*x).interval = _i;
  (*x).status = 0;
  (*x).portOut = _po;
}

/* Funzione per il check di una struttura led passata per riferimento
  @param led* Riferimento alla struttura led da utilizzare
*/
void checkStat(led *x){
  if(millis() - (*x).oldTime > (*x).interval){
    //Serial.print("Check...");
    if((*x).status == 1){
      digitalWrite((*x).portOut, LOW);
      (*x).status = 0;
      (*x).oldTime = millis();
    }
    else{
      digitalWrite((*x).portOut, HIGH);
      (*x).status = 1;
      (*x).oldTime = millis();
    }
  }
}

// SETUP INIZIALE
void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);  // definisco il modo operativo dei due PIN DIGITALI riservati ai led.
  pinMode(LED2, OUTPUT);
  
  initLed(&l1, 500, LED1);  // inizializzo le due strutture led con valore di intervallo e pin associato.
  initLed(&l2, 2000, LED2);
}

// LOOP PROGRAM
void loop() {
  checkStat(&l1);   // ad ogni loop richiama la funzione check sui led e in base all'intervallo impostato cambia lo stato del led.
  checkStat(&l2);
}
