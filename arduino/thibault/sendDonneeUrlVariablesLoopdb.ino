#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x0F, 0xCD, 0xE9}; //adresse mac shield ethernet
EthernetClient client;

void setup() {
Serial.begin(9600);  //Initialisation Moniteur Serie
}

void loop() {
connexion();
requete(ae);
}

void connexion () {
if (Ethernet.begin(mac) == 0) { //detecter en cas de probleme d'ip (DHCP = IP dynamique)
  Serial.println("Failed to configure Ethernet using DHCP");
  for(;;);
  delay(1000);
  Serial.println("*Connexion");
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
