<?php
 include("login.php");

 $db=connexion();
////////////////*création de la table dans la base de données*////////////////////////////

 $sql= "CREATE TABLE IF NOT EXISTS `id8552472_dbvariables` (";
 $sql .= "`id` int(11) NOT NULL auto_increment,";
 $sql .= "`hauteur` int(11) NOT NULL,";
 $sql .= "`ventilateur` int(11) NOT NULL,";
 $sql .= "`humidite` int(11) NOT NULL,";
 $sql .= "`temperature` int(11) NOT NULL,";
 $sql .= "PRIMARY KEY  (`id`),";
 $sql .= "UNIQUE KEY `id_2` (`id`),";
 $sql .= "KEY `id` (`id`)";
 $sql .= ") ENGINE=MyISAM;";
 echo ($sql) ;
 mysqli_query($db,$sql) or die(mysqli_connect_error());
?>
