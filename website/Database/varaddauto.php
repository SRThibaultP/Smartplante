<?php
 include("login.php");
 $hauteur = $_GET['hauteur']; //ben (val num sans virgule)
 $ventilateur = $_GET['ventilateur']; //romain (valeur en 0/1?)
 $humidité = $_GET['humidité']; //flo
 $QO = $_GET['QO']; //flo
 echo nl2br("hauteur=$hauteur \n ventilateur=$ventilateur \n humidité=$humidité \n QO=$QO");
  {
    $db=connexion();
	  $sql = "INSERT INTO id8552472_dbvariables (hauteur,ventilateur,humidité,QO)
    VALUES ('$hauteur', '$ventilateur', '$humidité', '$QO')";
	  mysqli_query($db,$sql) or die(mysqli_error());
	}
?>
