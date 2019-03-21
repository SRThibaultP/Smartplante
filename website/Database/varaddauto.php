<?php
 include("login.php");
 $hauteur = $_GET['hauteur'];
 $ventilateur = $_GET['ventilateur'];
 $humidite = $_GET['humidite'];
 $temperature = $_GET['temperature'];
 echo "Data ".$hauteur." et ".$humidite." et ".$ventilateur." et ".$temperature."bien acquise sur le serveur ";
  {
    $db=connexion();
	  $sql = "INSERT INTO id8552472_dbvariables (hauteur,ventilateur,humidite,temperature)
    VALUES ('$hauteur', '$ventilateur', '$humidite', '$temperature')";
	  mysqli_query($db,$sql) or die(mysqli_error());
	}
?>
