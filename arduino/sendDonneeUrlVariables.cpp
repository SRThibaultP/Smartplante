#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0x90, 0xA2, 0xDA, 0x0F, 0xCD, 0xE9}; //adresse mac shield ethernet
IPAddress server(178,32,28,116); //adresse ip arduino
EthernetClient client;
float distance,humidite;

void setup() {

  Serial.begin(9600);
  humidite = 39.7456;
  distance = 27;

  if (Ethernet.begin(mac) == 0) { //detecter en cas de probleme d'ip (DHCP = IP dynamique)
    Serial.println("Failed to configure Ethernet using DHCP");
    for(;;);
  }

  delay(1000);
  Serial.println("connecting...");

  if (client.connect("proxy-eple.in.ac-nantes.fr",3128)) { //proxy lycée
    Serial.println("connection OK");
    client.print("GET http://thibaultpech.000webhostapp.com/acq2donee.php?DATA="); //url envoyé par le client arduino | viens du vieux tp 2018
    client.print(humidite,10); //10 pour 10 chiffres après la virgule
    client.print("&DATA2=");
    client.print(distance,0); //0 pour 0 chiffre après la virgule
    client.println(" HTTP/1.1"); //NE FAIT PAS PARTIE DE L'URL
    client.println();
  }
  else {

      Serial.println("connection failed");
  }
}
 void loop()
 {
  if (client.available()) {
    char c = client.read();
    Serial.print(c); //ecrire dans le moniteur série les données du site web
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    for(;;);
 }
}
