<?php
$hauteur = $_GET['hauteur'];
$ventilateur = $_GET['ventilateur'];
$humidite = $_GET['humidite'];
$eau = $_GET['eau'];
echo "Data ".$hauteur." et ".$humidite." et ".$ventilateur." et ".$eau."bien acquise sur le serveur ";
$file=fopen("bank.txt","w");
fwrite($file,"hauteur:");
fwrite($file, $hauteur);
fwrite($file, " ventilateur:");
fwrite($file, $ventilateur);
fwrite($file, " humidite:");
fwrite($file, $humidite);
fwrite($file, " eau:");
fwrite($file, $eau);
fclose($file);
?>
