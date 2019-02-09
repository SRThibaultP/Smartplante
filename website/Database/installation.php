<?php
 include("login.php");

 $db=connexion();
////////////////*création de la table dans la base de données*////////////////////////////

 $sql= "CREATE TABLE IF NOT EXISTS `id8552472_variables` (";
 $sql .= "`id` int(11) NOT NULL auto_increment,";
 $sql .= "`hauteur` SMALLINT NOT NULL,";
 $sql .= "`ventilateur` TINYINT NOT NULL,";
 $sql .= "`humidité` SMALLINT(5,5) NOT NULL,";
 $sql .= "`QO` SMALLINT NOT NULL,";
 $sql .= "KEY `id` (`id`)";
 $sql .= ") ENGINE=MyISAM;";
 echo ($sql) ;
 mysqli_query($db,$sql) or die(mysqli_connect_error());
?>
