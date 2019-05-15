#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x0F, 0xCD, 0xE9}; //adresse mac shield ethernet
EthernetClient client;

int sensorPin = A1;                     //initialisation variable SensorPin (capteur humidité) sur entree analogique AO
int sensorValue = 0;                    //initialisation variable du capteur sur O
int vanPin = 8;

void setup() {
Serial.begin(9600);  //Initialisation Moniteur Serie
pinMode(vanPin, OUTPUT);
}

void loop() {
connexion();
humidite();
requete(sensorValue);
}

void connexion () {
if (Ethernet.begin(mac) == 0) { //detecter en cas de probleme d'ip (DHCP = IP dynamique)
  Serial.println("Failed to configure Ethernet using DHCP");
  for(;;);
  delay(1000);
  Serial.println("*Connexion");
  }
}

void requete(int humidite) {
if (client.connect("proxy-eple.in.ac-nantes.fr",3128)) { //proxy lycée
  Serial.println("*Connectée");
  client.print("GET http://projetsmartplante.000webhostapp.com/Database/varaddauto.php?hauteur="); //url send arduino
  client.print("9"); //var 1
  client.print("&ventilateur=");
  client.print("1"); //var 2
  client.print("&humidite=");
  client.print(humidite); //var 3
  client.print("&temperature=");
  client.print("9"); //var 4
  client.println(" HTTP/1.1"); //NOT IN URL
  client.println();
  Serial.println("**Valeurs envoyées");
  client.stop();
  delay(10000);
}

else {
  Serial.println("**Connexion impossible");
  }
}

void humidite (){
sensorValue = analogRead(sensorPin); //lecture de la valeur analogique par le capteur et stockage dans variable sensorValue
Serial.print("humidite = " );        //écriture sur le moniteur série de humidité
Serial.println(sensorValue);         //écriture sur le moniteur série de la valeur numerique de SensorValue
delay(1000);                         //attente durant 1 Seconde

if (sensorValue<732) {               // Si la valeur numérique est inférieur à 732
  digitalWrite(vanPin,HIGH);         // ouvre la vanne (commande le relais qui met en marche la pompe)
  delay(1000);                       // pause 1 seconde
  }

if (sensorValue>732) {               // Si la valeur numérique est supérieur à 732
  digitalWrite(vanPin,LOW);          // ferme la vanne (commande le relais qui met en marche la pompe)
  delay(1000);                       // pause 1 seconde
  }
}
