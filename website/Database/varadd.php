<?php
 include("login.php");
 if ($_POST['hauteur'] != '' AND $_POST['ventilateur'] != '' AND $_POST['humidite'] != '' AND $_POST['temperature'] != '')
  {
    $db=connexion();
	  $sql = "INSERT INTO id8552472_dbvariables (hauteur,ventilateur,humidité,QO)
    VALUES ('$_POST[hauteur]', '$_POST[ventilateur]', '$_POST[humidité]', '$_POST[QO]')";
	  mysqli_query($db,$sql) or die(mysqli_error());
	}

  else
  {
     echo 'Erreur ! Vous devez remplir tous les champs !';
  }
?>
