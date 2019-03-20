#include <Arduino.h>
//#include "Grove_I2C_Motor_Driver.h"
#include "Ultrasonic.h"

#define I2C_ADDRESS 0x0f

Ultrasonic ultrasonic(8);
 // Initialisation des variables
int pir1 = 3; //Capteur d'arret
int pir2 = 2; //Capteur de mise en marche
int relay1 = x;
int relay2 = x;
long hauteur = 0;

void setup() {
    Serial.begin(9600);  //Initialisation Moniteur Serie
    Motor.begin(I2C_ADDRESS); //Localisation du moteur
    pinMode(pir1,INPUT);  //Mode Réception des données
    pinMode(pir2,INPUT);
    pinMode(relay1,OUTPUT);
    pinMode(relay2,OUTPUT);
}

void loop() {
    //ProgMoteur(pir2 , pir1);
    hauteur = ProgMoteur(pir2, pir1);
}
    int ProgMoteur(int CaptMarche, int CaptStop){
    int ValMarche = digitalRead(CaptMarche);
    int ValStop = digitalRead(CaptStop);

    if(ValMarche == 0 && ValStop == 0){
        Serial.println("Mise en marche du moteur");
      //  Motor.speed(MOTOR1, 50); //Mise en marche du moteur
      digitalWrite(relay1, HIGH);
    while(ValStop == 0){  //Tant que capteur 1 detecte une présence on continue la montée du moteur
        digitalWrite(relay1, HIGH);
        Serial.println("Moteur stade Marche");
        ValStop = digitalRead(CaptStop);
      }
    }

    if(ValStop == 1){  //Si capteur 1 ne détecte rien
      digitalWrite(relay1, LOW);
      Serial.println("Moteur stade Arret");
    }

    Serial.println("La distance capteur obstacle est de  : ");
    long Distance = ultrasonic.MeasureInCentimeters(); // Envoie de la distance en centimétre entre le capteur Ultrason et le Sol
    Serial.print(Distance);
    Serial.println(" cm");

    delay(1000);

    return(Distance);
}
