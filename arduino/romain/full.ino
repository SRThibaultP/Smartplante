#include <math.h>
#include "Grove_I2C_Motor_Driver.h"

#define I2C_ADDRESS 0x0f

const int B = 4275;                  // B valeur du
const int R0 = 100000;               // R0 = 100k
const int pinTempSensor = A0;        // Le thermomètre se connecte à A0
const int CaptFinDeCourse = 6;
int ventilateur = 4;          // Relais connecté à la Pin 4
void setup()
{
    Serial.begin(9600);              // Initialisation du moniteur série
    pinMode(ventilateur,OUTPUT);     // Mode envoi de données
    Motor.begin(I2C_ADDRESS);        // Localisation du moteur
     while(CaptFinDeCourse == 1)
     {
        Motor.speed(MOTOR1, 50);
    }
}


void loop()
{

    int a = analogRead(pinTempSensor);

    float R = 1023.0/a-1.0;
    R = R0*R;

    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;    // Convertis en température

    Serial.print("temperature = ");                           // Affiche "temperature ="
    Serial.println(a);                                        // Affiche la température


    if (temperature >= 30){                                   // Si température > 30°C
      digitalWrite(ventilateur,HIGH);                         // Active le ventilateur
      Serial.println("Trop chaud");                           // Affiche "Trop chaud"
    }
    if (temperature < 25) {                                   // Si température < 25°C
      digitalWrite(ventilateur,LOW);                          // Désactive le ventilateur
    }
 }
