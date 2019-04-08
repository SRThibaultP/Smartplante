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
  $humiditeTXT = "La terre est sec";
}
else {
  $humiditeTXT = "La terre est humide";
}

if ($ventilateur == 1) {
  $ventilateurTXT = "Le ventilateur est en marche";
}
else {
  $ventilateurTXT = "Le ventilateur est à l'arrêt";
}

$humidite = (int)(($humidite / 730) * 100);

echo '<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>SerreRabelais - SmartPlante</title>
    <link rel="icon" href="/Images/favicon-32x32.png" type="image/png">
    <link rel="stylesheet" href="../serre.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    <script type="text/javascript" src="hauteur.js"></script>
    <script type="text/javascript" src="../alerte.js"></script>
  </head>
  <body>
  <div id="hauteur" style="width: 400px; height: 120px;"></div>
    <div class="alerte ventilateurTXT">
      <span class="closebtn">&times;</span>
      <strong>Ventilateur: </strong> '.$ventilateurTXT.'
    </div>
    <div class="alerte humiditeTXT">
      <span class="closebtn">&times;</span>
      <strong>Terre: </strong> '.$humiditeTXT.'
    </div>
    <div class="temperature">
      <iframe src="https://sitetsti2dsin.000webhostapp.com/gauge.php?nam=Temperature&cot=150&min=0&max=100&val='.$temperature.'"></iframe>
    </div>
    <div id="serre">

      <div class="humidite"><iframe src="https://sitetsti2dsin.000webhostapp.com/gauge.php?nam=Humidite&cot=150&min=0&max=100&val='.$humidite.'"></iframe></div>
    </div>
  </body>
</html>
'
?>
