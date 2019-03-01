#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x0F, 0xCD, 0xE9}; //adresse mac shield ethernet
IPAddress server(178,32,28,116); //adresse ip arduino
EthernetClient client;

//A SUPPRIMER LORS DU CODE FINAL
float ae,humidite,QO = 48.35;
int ventilateur = 1; //db limit
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
  client.print("25.686");       //var 1
  client.print("&ventilateur");
  client.print("1"); //var 2 | add 2nd valeur here
  client.print("&humidité"); //changer nom var? (start base sheets var)
  client.print("15.12"); //var 3 | add 3nd valeur here | changer nom var? (start base sheets var)
  client.print("&QO");
  client.print("98"); //var 4 | add 4nd valeur here
  client.println(" HTTP/1.1"); //NE FAIT PAS PARTIE DE L'URL
  client.println();
  //Serial.print(client.read());
  //Serial.println("**Valeurs envoyées");
  client.stop();
  if (client.available()) {
    char c = client.read();
    Serial.print(c); //ecrire dans le moniteur série les données du site web
  }
  }

else {
  Serial.println("**Connexion impossible");
  }
}
