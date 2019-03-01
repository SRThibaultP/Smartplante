#include <math.h>

const int B = 4275;               // B valeur du
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Le thermomètre se connecte à A0
int ventilateur = 4;                    // Relais connecté à la Pin 4
void setup()
{
    Serial.begin(9600);
    pinMode(ventilateur,OUTPUT);
}

void loop()
{

    int a = analogRead(pinTempSensor);

    float R = 1023.0/a-1.0;
    R = R0*R;

    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet

    Serial.print("temperature = ");
    Serial.println(temperature);


    if (temperature >= 30){
      digitalWrite(ventilateur,HIGH);
      Serial.println("Trop chaud");
    }
    if (temperature < 25) {
      digitalWrite(ventilateur,LOW);;
    }
 }
