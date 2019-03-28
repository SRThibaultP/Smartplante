<?php
$sql = "SELECT * FROM id8552472_dbvariables WHERE id = (SELECT MAX(id) FROM id8552472_dbvariables)";
include($_SERVER['DOCUMENT_ROOT'].'/Database/login.php');
$db=connexion();
$req = mysqli_query($db,$sql) or die(mysqli_error());
while($data = mysqli_fetch_assoc($req)){
  $hauteur = $data["hauteur"];
  $ventilateur = $data["ventilateur"];
  $humidite = $data["humidite"];
  $temperature = $data["temperature"];
}

if ($humidite < 732) {
  $humiditeTXT = "TERRE SEC";
}
else {
  $humiditeTXT = "TERRE HUMIDE";
}

if ($ventilateur == 1) {
  $ventilateurTXT = "VENTILATEUR ON";
}
else {
  $ventilateurTXT = "VENTILATEUR OFF";
}

$humidite = (int)(($humidite / 730) * 100);



echo '<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>SerreRabelais - SmartPlante</title>
    <link rel="icon" href="/Images/favicon-32x32.png" type="image/png">
    <link rel="stylesheet" href="../serre.css">
  </head>
  <body>
    <div class="hauteur">
      <iframe src="https://sitetsti2dsin.000webhostapp.com/gauge.php?nam=Hauteur&cot=150&min=0&max=100&val='.$hauteur.'"></iframe>
    </div>
    <div class="ventilateur">
      <h1>'.$ventilateurTXT.'</h1>
    </div>
    <div class="humidite">
      <h1>'.$humiditeTXT.'</h1>
      <iframe src="https://sitetsti2dsin.000webhostapp.com/gauge.php?nam=Humidite&cot=150&min=0&max=100&val='.$humidite.'"></iframe>
    </div>
    <div class="temperature">
      <iframe src="https://sitetsti2dsin.000webhostapp.com/gauge.php?nam=Temperature&cot=150&min=0&max=100&val='.$temperature.'"></iframe>
    </div>
  </body>
</html>'
?>
