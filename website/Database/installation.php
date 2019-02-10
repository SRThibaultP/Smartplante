<?php
 include("login.php");

 $db=connexion();
////////////////*création de la table dans la base de données*////////////////////////////

<<<<<<< HEAD
 $sql= "CREATE TABLE IF NOT EXISTS `id8552472_dbvariables` (";
 $sql .= "`id` int(11) NOT NULL auto_increment,";
 $sql .= "`hauteur` int NOT NULL,";
 $sql .= "`ventilateur` int NOT NULL,";
 $sql .= "`humidité` int NOT NULL,";
 $sql .= "`QO` int NOT NULL,";
 $sql .= "PRIMARY KEY  (`id`),";
 $sql .= "UNIQUE KEY `id_2` (`id`),";
=======
 $sql= "CREATE TABLE IF NOT EXISTS `id8552472_variables` (";
 $sql .= "`id` int(11) NOT NULL auto_increment,";
 $sql .= "`hauteur` SMALLINT NOT NULL,";
 $sql .= "`ventilateur` TINYINT NOT NULL,";
 $sql .= "`humidité` SMALLINT(5,5) NOT NULL,";
 $sql .= "`QO` SMALLINT NOT NULL,";
>>>>>>> 7315b3babd62ecadd909075b2f56379530b7c92e
 $sql .= "KEY `id` (`id`)";
 $sql .= ") ENGINE=MyISAM;";
 echo ($sql) ;
 mysqli_query($db,$sql) or die(mysqli_connect_error());
?>
