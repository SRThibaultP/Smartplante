#include <SPI.h>
#include <Ethernet.h>
#include <Ultrasonic.h>

#define I2C_ADDRESS 0x0f

byte mac[] = {0x90, 0xA2, 0xDA, 0x0F, 0xCD, 0xE9}; //shield ethernet
EthernetClient client;

Ultrasonic ultrasonic(9);
 /*VARIABLES UTILES À BENJAMIN */
int pir1 = 3; //Capteur d'arret
int pir2 = 2; //Capteur de mise en marche
int relay1 = 7; //Interrupteur commande moteur
int relay2 = 8;
int ae = 0;


/* VARIABLES UTILES À ROMAIN */
const int B = 4275;                  // B valeur du
const int R0 = 100000;               // R0 = 100k
const int pinTempSensor = A0;        // Le thermomètre se connecte à A0
const int CaptFinDeCourse = 6;
int ventilateur = 4;          // Relais connecté à la Pin 4
int ValInit = 0;

int sensorPin = A1;                     //initialisation variable SensorPin (capteur humidité) sur entree analogique AO
int sensorValue = 0;                    //initialisation variable du capteur sur O
int vanPin = 8;

void setup() {
Serial.begin(9600);  //Initialisation Moniteur Serie

pinMode(pir1,INPUT);  //Mode Réception des données
pinMode(pir2,INPUT);
pinMode(CaptFinDeCourse, INPUT);

pinMode(relay1, OUTPUT); //Mode Sortie d'Arduino
pinMode(relay2,OUTPUT);
pinMode(vanPin, OUTPUT);

Initialisation(); //Appel du sous-programme d'initialisation
}

void loop(){
connexion(); //Appel du sous-programme de connexion
ae = ProgMoteur(pir2, pir1); //Appel du sous-programme gestion moteur + réception de la hauteur
humidite(); //Appel du sous-programme gestion motopompe
requete(ae,vanPin); //Appel du sous-programme envoie de données sur le site
}

  /*SOUS PROGRAMME INITIALISATION*/
void Initialisation(){
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);

  valInit = digitalRead(CaptFinDeCourse);

  while (valInit == 0){
    digitalWrite(relay1, LOW);
    digitalWrite(relay2,HIGH);

    valInit = digitalRead(CaptFinDeCourse);
  }

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);

  valStop = digitalRead(pir1);

  while(valStop != 0){
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);

    valStop = digitalRead(pir1);
  }

  digitalWrite(relay1,LOW);
  digitalWrite(relay2,LOW);
}
  /*SOUS PROGRAMME GESTION MOTEUR/LAMPE*/
int ProgMoteur(int CaptMarche, int CaptStop) {
  int ValMarche = digitalRead(CaptMarche);
  int ValStop = digitalRead(CaptStop);

  digitalWrite(relay1,LOW);
  digitalWrite(relay2,LOW);

  if(ValMarche == 0 && ValStop == 0) {
    Serial.println("Mise en marche du moteur");

    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);

    while(ValStop == 0){ //Tant que capteur 1 detecte une présence on continue la montée du moteur

      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, LOW);

      Serial.println("Moteur stade Marche");
      ValStop = digitalRead(CaptStop);
    }
  }

  if(ValStop == 1) { //Si capteur 1 ne détecte rien

    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);

    Serial.println("Moteur stade Arret");
  }

  Serial.print("La distance capteur obstacle est de : ");
  long Distance = ultrasonic.MeasureInCentimeters(); // Envoie de la distance en centimétre entre le capteur Ultrason et le Sol
  Serial.print(Distance);
  Serial.println(" cm");
  delay(1000);
  return(Distance);
}
  /*SOUS PROGRAMME CONNEXION*/
void connexion () {
if (Ethernet.begin(mac) == 0) { //detecter pb d'ip (DHCP = IP dynamique)
    Serial.println("Failed to configure Ethernet using DHCP");
    for(;;);
    delay(1000);
    Serial.println("connecting...");
    }
  }
  /*SOUS PROGRAMME ENVOIs DE DONNEES*/
void requete(int hauteur, int humidite) {
if (client.connect("proxy-eple.in.ac-nantes.fr",3128)) { //proxy lycée
  Serial.println("*Connectée");
  client.print("GET http://projetsmartplante.000webhostapp.com/Database/varaddauto.php?hauteur="); //url send arduino
  client.print(hauteur); //var 1
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
  /*SOUS PROGRAMME GESTION MOTOPOMPE*/
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
