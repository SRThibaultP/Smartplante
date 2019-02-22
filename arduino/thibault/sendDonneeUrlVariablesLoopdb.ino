#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x0F, 0xCD, 0xE9}; //adresse mac shield ethernet
IPAddress server(178,32,28,116); //adresse ip arduino
EthernetClient client;

//A SUPPRIMER LORS DU CODE FINAL
float ae,humidite,QO = 42.24;
int ventilateur = 0; //db limit
//A SUPPRIMER LORS DU CODE FINAL

void setup() {
Serial.begin(9600);  //Initialisation Moniteur Serie
}

void loop() {
connexion();
requete(ae,humidite,QO,ventilateur);
}

void connexion () {
if (Ethernet.begin(mac) == 0) { //detecter en cas de probleme d'ip (DHCP = IP dynamique)
  Serial.println("Failed to configure Ethernet using DHCP");
  for(;;);
  delay(1000);
  Serial.println("*Connexion");
  }
}

void requete(int hauteur, int ventilateur, int humidite, int QO) {
if (client.connect("proxy-eple.in.ac-nantes.fr",3128)) { //proxy lycée
  Serial.println("*Connectée");
  client.print("GET http://projetsmartplante.000webhostapp.com/Database/varaddauto.php?hauteur="); //url envoyé par le client arduino
  client.print(hauteur);       //var 1
  client.print("&ventilateur");
  client.print(ventilateur); //var 2 | add 2nd valeur here
  client.print("&humidité"); //changer nom var? (start base sheets var)
  client.print(humidite); //var 3 | add 3nd valeur here | changer nom var? (start base sheets var)
  client.print("&QO");
  client.print(QO); //var 4 | add 4nd valeur here
  client.println(" HTTP/1.1"); //NE FAIT PAS PARTIE DE L'URL
  client.println();
  Serial.println("**Valeurs envoyées");
  client.stop();
  }

else {
  Serial.println("**Connexion impossible");
  }
}
