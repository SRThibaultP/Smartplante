#include <math.h>


const int B = 4275;                  // B valeur du
const int R0 = 100000;               // R0 = 100k
const int pinTempSensor = A0;        // Le thermomètre se connecte à A0
const int CaptFinDeCourse = 6;
int pir1 = 3;
int pir2 = 2;
int relay1 = 7;
int relay2 = 8;
int ventilateur = 4;          // Relais connecté à la Pin 4
int valInit = 0;
int valStop = 1;

void setup()
{
    Serial.begin(9600);              // Initialisation du moniteur série
    pinMode(ventilateur,OUTPUT);     // Mode envoi de données
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);

    pinMode(pir1, INPUT);
    pinMode(pir2,INPUT);
    pinMode(CaptFinDeCourse, INPUT);

    valInit = digitalRead(CaptFinDeCourse);
    while (valInit == 0) {
        digitalWrite(relay1, LOW);
        digitalWrite(relay2,HIGH);

        valInit =digitalRead(CaptFinDeCourse);
    }
    digitalWrite(relay1,LOW);
    digitalWrite(relay2,LOW);

    valStop = digitalRead(pir1);
    while(valStop != 0){
      digitalWrite(relay1,HIGH);
      digitalWrite(relay2, HIGH);

      valStop = digitalRead(pir1);
    }
    digitalWrite(relay1,LOW);
    digitalWrite(relay2,LOW);


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
