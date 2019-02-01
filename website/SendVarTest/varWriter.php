<?php
$data = $_GET['DATA'];
$data2 = $_GET['DATA2'];
echo "Variables ".$data." & ".$data2." sauvegardee sur le serveur ";
$file=fopen("saveVar.txt","w");
fwrite($file,"DATA:");
fwrite($file, $data);
fwrite($file, " et ");
fwrite($file, $data2);
fclose($file);
?>
