#include "Arduino.h"
#include <TimeLib.h>
#include "DutyCycle.h"
//https://github.com/PaulStoffregen/Time

class Zone {
  private :
    bool on = false;
    //Watt par heure qu'il faut produire sur la zone. (info donnée en ordre par la console)
    int wattParHeures = 0;
    //Cummul de la puissance en watt de tous les radiateurs branchés sur la zone.
    int puissanceZone = 0;
    byte optoPin;
    byte ledPin;
    //Historique de toutes les période d'allumage, sur 1h. 
    //Si on part du principe qu'une phase d'allumage fait minimum 30 secondes, pour avoir 1h d'historique, il faut 120 phases On - Off; On historise que les phases On, donc 60 positions dans le tableau.
    DutyCycle loadHistory[20]; 

  public :
  void Setup(byte optoPin, byte ledPin);  // initialisation de la broche pour la led.
  void Allumer();
  void Eteindre();

};