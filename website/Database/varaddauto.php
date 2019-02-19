<?php
 include("login.php");
 $hauteur = $_GET['hauteur']; //ben (val num sans virgule)
 $ventilateur = $_GET['ventilateur']; //romain (valeur en 0/1?)
 $humidité = $_GET['humidité']; //flo
 $QO = $_GET['QO']; //flo
 
  {
    $db=connexion();
	  $sql = "INSERT INTO id8552472_dbvariables (hauteur,ventilateur,humidité,QO)
    VALUES ('$hauteur', '$ventilateur', '$humidité', '$QO')";
	  mysqli_query($db,$sql) or die(mysqli_error());
	}
?>
