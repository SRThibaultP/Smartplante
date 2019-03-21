<?php
$hauteur = $_GET['hauteur'];
$ventilateur = $_GET['ventilateur'];
$humidite = $_GET['humidite'];
$temperature = $_GET['temperature'];
echo "Data ".$hauteur." et ".$humidite." et ".$ventilateur." et ".$temperature."bien acquise sur le serveur ";
$file=fopen("debugVar.txt","w");
fwrite($file,"hauteur:");
fwrite($file, $hauteur);
fwrite($file, "ventilateur:");
fwrite($file, $ventilateur);
fwrite($file, "humidite:");
fwrite($file, $humidite);
fwrite($file, "temperature:");
fwrite($file, $temperature);
fclose($file);
?>
