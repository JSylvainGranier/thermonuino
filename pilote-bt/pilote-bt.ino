#include "Arduino.h"
#include "Zone.h"
#define LED_PIN_ZONE1 6
#define LED_PIN_ZONE2 7
#define LED_PIN_ZONE3 8
#define LED_PIN_ZONE4 9
#define LED_PIN_STATUT 10

#define OPTO_PIN_ZONE1 A0
#define OPTO_PIN_ZONE2 A4
#define OPTO_PIN_ZONE3 A1
#define OPTO_PIN_ZONE4 A5

#define TELEINFO A2

#define BTN_PIN 3


Zone z1;
Zone z2;
Zone z3;
Zone z4;


void setup() {
  pinMode(LED_PIN_ZONE1, OUTPUT);
  pinMode(LED_PIN_ZONE2, OUTPUT);
  pinMode(LED_PIN_ZONE3, OUTPUT);
  pinMode(LED_PIN_ZONE4, OUTPUT);
  pinMode(LED_PIN_STATUT, OUTPUT);

  pinMode(OPTO_PIN_ZONE1, OUTPUT);
  pinMode(OPTO_PIN_ZONE2, OUTPUT);
  pinMode(OPTO_PIN_ZONE3, OUTPUT);
  pinMode(OPTO_PIN_ZONE4, OUTPUT);

  pinMode(BTN_PIN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BTN_PIN), btn_handler, RISING);

  z1.Setup(OPTO_PIN_ZONE1, LED_PIN_ZONE1);
  z2.Setup(OPTO_PIN_ZONE2, LED_PIN_ZONE2);
  z3.Setup(OPTO_PIN_ZONE3, LED_PIN_ZONE3);
  z4.Setup(OPTO_PIN_ZONE4, LED_PIN_ZONE4);

}

volatile boolean btnToConsumes = false;
void btn_handler() {
  btnToConsumes = true;
}

void loop() {

  if(btnToConsumes){
    delay(3000);

    btnToConsumes = false;
  }

  if(digitalRead(BTN_PIN) == LOW){
    delay(5000);
  }

  digitalWrite(LED_PIN_ZONE1, LOW);
  digitalWrite(LED_PIN_ZONE2, LOW);
  digitalWrite(LED_PIN_ZONE3, LOW);
  digitalWrite(LED_PIN_ZONE4, LOW);
  digitalWrite(LED_PIN_STATUT, LOW);

  digitalWrite(OPTO_PIN_ZONE1, LOW);
  digitalWrite(OPTO_PIN_ZONE2, LOW);
  digitalWrite(OPTO_PIN_ZONE3, LOW);
  digitalWrite(OPTO_PIN_ZONE4, LOW);

  delay(500);

  digitalWrite(LED_PIN_ZONE1, HIGH);
  digitalWrite(LED_PIN_ZONE2, HIGH);
  digitalWrite(LED_PIN_ZONE3, HIGH);
  digitalWrite(LED_PIN_ZONE4, HIGH);
  digitalWrite(LED_PIN_STATUT, HIGH);

  digitalWrite(OPTO_PIN_ZONE1, HIGH);
  digitalWrite(OPTO_PIN_ZONE2, HIGH);
  digitalWrite(OPTO_PIN_ZONE3, HIGH);
  digitalWrite(OPTO_PIN_ZONE4, HIGH);

  delay(500);

}



//Stocker en EPROM la charge MAX de chaque zone. 
//Recevoir en ordre la quantité de watt/h à dispenser
//Ordonner la mise en fonction de ces zones en fonction de la puissance connue de ces zones. 
//Si la lecture du linky fonctionne, déduire la puissance de chaque zone en les allumants successivement à plusieurs reprises. 
//Un protocole pour parler entre deux arduino sur les ports RX et TX ? 
//Envoyer l'heure obtenue du Linky à la console. 
//Coordonner la conduite des zone, rappel : sur le fil pilote, la 1/2 alternance négative = OFF, rien = Confort. 
//Détecter une bonne communcation sur RX / TX. 
//  --réception OK : Statut OK
//  --réception KO : Statut en alerte. 
//  --Pas de réception depuis plus de 5 minutes = KO. 


// Pour ma phase de dev, faire en sorte que la centrale soit autonome, et que je puisse faire des bascules entre on / off sur pression du bouton. 



//https://github.com/meirm/SerialGSM