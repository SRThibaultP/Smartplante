int sensorPin = A0;                     //initialisation variable SensorPin (capteur humidité) sur entree analogique AO
int sensorValue = 0;                    //initialisation variable du capteur sur O

void setup() {
    Serial.begin(9600);                 //débit du moniteur de 9 600 bits par seconde.
}
void loop() {
    
    sensorValue = analogRead(sensorPin); //lecture de la valeur analogique par le capteur et stockage dans variable sensorValue
    Serial.print("humidite = " );        //écriture sur le moniteur série de humidité
    Serial.println(sensorValue);         //écriture sur le moniteur série de la valeur numerique de SensorValue
    delay(1000);                         //attente durant 1 Seconde
    if (sensorValue<307)                 // Si la valeur numérique est inférieur à 307
      {
        Serial.print("humidite = terrain sec " );        //écriture sur le moniteur série de humidité = terrain sec
        
        }
    else
     if (sensorValue>700)                 // Si la valeur numérique est supérieur à 700
      {
        Serial.print("humidite = terrain très humide " );        //écriture sur le moniteur série de humidité = terrain très humide
        
        }
    else
     if (sensorValue<700)                 // Si la valeur numérique est inférieur à 700
      {
        Serial.print("humidite = terrain humide " );        //écriture sur le moniteur série de humidité = terrain humide
        
        }    
}
