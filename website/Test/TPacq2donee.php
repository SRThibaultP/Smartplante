<?php
$data = $_GET['DATA'];
$data2 = $_GET['DATA2'];
echo "Data ".$data." et ".$data2." bien acquise sur le serveur ";
$file=fopen("bank.txt","w");
fwrite($file,"DATA:");
fwrite($file, $data);
fwrite($file, " et ");
fwrite($file, $data2);
fclose($file);
?>