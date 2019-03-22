int sensorPin = A1;                     //initialisation variable SensorPin (capteur humidité) sur entree analogique AO
int sensorValue = 0;                    //initialisation variable du capteur sur O
int vanPin = 8;                        // vanne connectée à la broche numérique n° 13

void setup() {
    Serial.begin(9600);                 //débit du moniteur de 9 600 bits par seconde.
     pinMode(vanPin, OUTPUT);           // met la broche utilisée avec la vanne en SORTIE
}
void loop() {

  sensorValue = analogRead(sensorPin); //lecture de la valeur analogique par le capteur et stockage dans variable sensorValue
  Serial.print("humidite = " );        //écriture sur le moniteur série de humidité
  Serial.println(sensorValue);         //écriture sur le moniteur série de la valeur numerique de SensorValue
  delay(1000);                         //attente durant 1 Seconde
  if (sensorValue<732)                 // Si la valeur numérique est inférieur à 732
    {

      digitalWrite(vanPin,HIGH);       // ouvre la vanne (commande le relais qui met en marche la pompe)
      delay(1000);                     // pause 1 seconde

      }
  if (sensorValue>732)                 // Si la valeur numérique est supérieur à 732
    {
        digitalWrite(vanPin,LOW);    // ferme la vanne (commande le relais qui met en marche la pompe)
        delay(1000);                    // pause 1 seconde

      }
    }
