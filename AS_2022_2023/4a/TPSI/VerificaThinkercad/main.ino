/**
 *  Author: Francesco Pradella
 *  Date: 23.05.2023
 *  Abstract: Creare un circuito arduino e relativo codice sorgente che gestisca due led con temporizzazione
 * di lampeggio diverse e due bottoni che attivano/disattivano il lampeggio dei rispettivi led.
 * 
 * Note:
 * - I bottoni vanno temporizzati, ho scelto 500ms in modo da avere tempo di togliere il dito dal bottone (click del mouse)
 * altrimenti avrei false letture, ricordo che arduino esegue il loop() con una frequenza di 25volte a secondo.
 * - Per la lettura dello stato dei bottoni bisogna mettere una resistenza di pulldown che va a massa in parallelo 
 * con il cavo che andrà al pin digitale di input (3 e 4) nel caso del circuito in foto. La resistenza l'ho messa da 10K Ohm,
 * ma funziona anche con una normale 220 Ohm. 
//
#define LED1 11
#define LED2 12

#define BTN1 3
#define BTN2 4

unsigned long tLedUno;
int deltaLedUno = 500;
int statoLedUno;
bool activeLedUno = true;

unsigned long tLedDue;
int deltaLedDue = 1000;
int statoLedDue;
bool activeLedDue = true;

unsigned long tBtnUno;
unsigned long tBtnDue;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  Serial.begin(9600);
  
  statoLedUno = 1;
  digitalWrite(LED1, HIGH);
  tLedUno = millis();
  
  statoLedDue = 1;
  digitalWrite(LED2, HIGH);
  tLedDue = millis();  
  
  tBtnUno = millis();
  tBtnDue = millis();
}

void loop()
{
  // controllo lo stato dei pulsanti se premuti oppure no.
  // aggiungo una temporizzazione di 500ms altrimenti non ho il tempo di alzare il dito
  // dal mouse/tasto, quindi avrei false letture ripetute.
  if((digitalRead(BTN1) == HIGH) && (millis()-tBtnUno > 500)){
  	if(activeLedUno) activeLedUno = false;
    else activeLedUno = true;
    tBtnUno = millis();
  }
  if((digitalRead(BTN2) == HIGH)  && (millis()-tBtnDue > 500)){
  	if(activeLedDue) activeLedDue = false;
    else activeLedDue = true;
    tBtnDue = millis();
  }
  
  // gestione led temporizzata per il Led 1
  if(millis()-tLedUno > deltaLedUno)
  {
    if(statoLedUno == 1){
      if(activeLedUno){
    		statoLedUno = 0;
      		digitalWrite(LED1, LOW);
      }
    }
    else{
      if(activeLedUno){
    	statoLedUno = 1;
      	digitalWrite(LED1, HIGH);
      }
    }
    tLedUno = millis();
  }
  
  // gestione led temporizzata per il Led 2
  if(millis()-tLedDue > deltaLedDue)
  {
    if(statoLedDue == 1){
      if(activeLedDue){
    		statoLedDue = 0;
      		digitalWrite(LED2, LOW);
      }
    }
    else{
      if(activeLedDue){
    	statoLedDue = 1;
      	digitalWrite(LED2, HIGH);
      }
    }
    tLedDue = millis();
  }
}