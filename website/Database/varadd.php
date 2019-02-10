<?php
 include("login.php");
 if ($_POST['hauteur'] != '' AND $_POST['ventilateur'] != '' AND $_POST['humidité'] != '' AND $_POST['QO'] != '')
  {
    $db=connexion();
	  $sql = "INSERT INTO id8552472_dbvariables(id,hauteur,ventilateur,humidité,QO) ";
 	  $sql .= "VALUES('','".$_POST['hauteur']."','".$_POST['ventilateur']."','".$_POST['humidité']."','".$_POST['QO']."')";
	  mysqli_query($db,$sql) or die(mysqli_error($db));
	}

  else
  {
     echo 'Erreur ! Vous devez remplir tous les champs !';
  }
?>
