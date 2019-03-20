#include <SPI.h>
#include <Ethernet.h>
 // #include <Grove_I2C_Motor_Driver.h> PLUS BESOIN
#include <Ultrasonic.h>

#define I2C_ADDRESS 0x0f

byte mac[] = {0x90, 0xA2, 0xDA, 0x0F, 0xCD, 0xE9}; //shield ethernet
EthernetClient client;

Ultrasonic ultrasonic(8);
 // Initialisation des variables
int pir1 = 3; //Capteur d'arret
int pir2 = 2; //Capteur de mise en marche
int ae = 0;

void setup() {
Serial.begin(9600);  //Initialisation Moniteur Serie
//Motor.begin(I2C_ADDRESS); //Localisation du moteur PLUS BESOIN
pinMode(pir1,INPUT);  //Mode Réception des données
pinMode(pir2,INPUT);
}

void loop(){
connexion();
ae = ProgMoteur(pir2, pir1);
requete(ae);
}

int ProgMoteur(int CaptMarche, int CaptStop) {
  int ValMarche = digitalRead(CaptMarche);
  int ValStop = digitalRead(CaptStop);

  if(ValMarche == 0 && ValStop == 0) {
    Serial.println("Mise en marche du moteur");
    Motor.speed(MOTOR1, 50); //Mise en marche du moteur
    while(ValStop == 0){ //Tant que capteur 1 detecte une présence on continue la montée du moteur
      Motor.speed(MOTOR1, 50);
      Serial.println("Moteur stade Marche");
      ValStop = digitalRead(CaptStop);
    }
  }

  if(ValStop == 1) { //Si capteur 1 ne détecte rien
    Motor.stop(MOTOR1); //Arret du moteur
    Serial.println("Moteur stade Arret");
  }

  Serial.print("La distance capteur obstacle est de : ");
  long Distance = ultrasonic.MeasureInCentimeters(); // Envoie de la distance en centimétre entre le capteur Ultrason et le Sol
  Serial.print(Distance);
  Serial.println(" cm");
  delay(1000);
  return(Distance);
}

void connexion () {
if (Ethernet.begin(mac) == 0) { //detecter pb d'ip (DHCP = IP dynamique)
    Serial.println("Failed to configure Ethernet using DHCP");
    for(;;);
    delay(1000);
    Serial.println("connecting...");
    }
  }

void requete(int hauteur) {
if (client.connect("proxy-eple.in.ac-nantes.fr",3128)) { //proxy lycée
  Serial.println("*Connectée");
  client.print("GET http://projetsmartplante.000webhostapp.com/Database/varaddauto.php?hauteur="); //url send arduino
  client.print(hauteur); //var 1
  client.print("&ventilateur=");
  client.print("0"); //var 2
  client.print("&humidite=");
  client.print("99.99"); //var 3
  client.print("&eau=");
  client.print("999.999"); //var 4
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
