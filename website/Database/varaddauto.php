<?php
 include("login.php");
 $hauteur = $_GET['hauteur']; //ben (val num sans virgule)
 $ventilateur = $_GET['ventilateur']; //romain (valeur en 0/1?)
 $humidite = $_GET['humidite']; //flo
 $eau = $_GET['eau']; //flo
 echo "Data ".$hauteur." et ".$humidite." et ".$ventilateur." et ".$eau."bien acquise sur le serveur ";
  {
    $db=connexion();
	  $sql = "INSERT INTO id8552472_dbvariables (hauteur,ventilateur,humidite,eau)
    VALUES ('$hauteur', '$ventilateur', '$humidite', '$eau')";
	  mysqli_query($db,$sql) or die(mysqli_error());
	}
?>
