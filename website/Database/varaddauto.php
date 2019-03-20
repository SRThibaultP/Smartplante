<?php
 include("login.php");
 $hauteur = $_GET['hauteur'];
 $ventilateur = $_GET['ventilateur'];
 $humidite = $_GET['humidite'];
 $eau = $_GET['eau'];
 echo "Data ".$hauteur." et ".$humidite." et ".$ventilateur." et ".$eau."bien acquise sur le serveur ";
  {
    $db=connexion();
	  $sql = "INSERT INTO id8552472_dbvariables (hauteur,ventilateur,humidite,eau)
    VALUES ('$hauteur', '$ventilateur', '$humidite', '$eau')";
	  mysqli_query($db,$sql) or die(mysqli_error());
	}
?>
