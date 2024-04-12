// C++ code
//
#define LED1 10
#define LED2 11

unsigned long tempoLed1;
unsigned long tempoLed2;

int statoLed1;
int statoLed2;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  tempoLed1 = millis();
  statoLed1 = 1;
  digitalWrite(LED1, HIGH);
  
  tempoLed2 = millis();
  statoLed2 = 1;
  digitalWrite(LED2, HIGH);  
}

void loop()
{
  if(millis() - tempoLed1 > 2000){
    if(statoLed1 == 1){
    	statoLed1 = 0;
      	digitalWrite(LED1, LOW);
    }
    else{
    	statoLed1 = 1;
      	digitalWrite(LED1, HIGH);
    }
    tempoLed1 = millis();
  }
 
  if(millis() - tempoLed2 > 500){
    if(statoLed2 == 1){
    	statoLed2 = 0;
      	digitalWrite(LED2, LOW);
    }
    else{
    	statoLed2 = 1;
      	digitalWrite(LED2, HIGH);
    }
    tempoLed2 = millis();
  }
}