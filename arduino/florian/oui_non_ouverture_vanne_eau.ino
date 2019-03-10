int vanPin = 13;                 // LED connectée à la broche numérique n° 13

void setup()
{
  pinMode(vanPin, OUTPUT);      // met la broche utilisée avec la LED en SORTIE
}

void loop()
{
  digitalWrite(vanPin, HIGH);   // allume la LED
  delay(1000);                  // pause 1 seconde
  digitalWrite(vanPin, LOW);    // éteint la LED
  delay(1000);                  // pause 1 seconde
}

