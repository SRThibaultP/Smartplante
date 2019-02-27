<?php
$hauteur = $_GET['hauteur'];
$ventilateur = $_GET['ventilateur'];
$humidité = $_GET['humidité'];
$QO = $_GET['QO'];
echo "hauteur=".$hauteur." ventilateur=".$ventilateur." humidité=".$humidité." QO=".$QO."";
$file=fopen("debugVar.txt","w");
fwrite($file,"hauteur=");
fwrite($file, $hauteur);
fwrite($file,"ventilateur=");
fwrite($file, $ventilateur);
fwrite($file,"humidité=");
fwrite($file, $humidité);
fwrite($file,"QO=");
fwrite($file, $QO);
fclose($file);
?>
