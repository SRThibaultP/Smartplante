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
    <link rel="icon" href="/Images/favicon-32x32.png">
    <link rel="stylesheet" href="../serre.css">
  </head>
  <body>
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
      <div class="hauteur"><iframe src="https://sitetsti2dsin.000webhostapp.com/gauge.php?nam=Hauteur&cot=150&min=0&max=100&val='.$hauteur.'"></iframe></div>
      <div class="humidite"><iframe src="https://sitetsti2dsin.000webhostapp.com/gauge.php?nam=Humidite&cot=150&min=0&max=100&val='.$humidite.'"></iframe></div>
    </div>
  </body>
  <footer>
    <script src="../alerte.js"></script>
  </footer>
</html>'
?>
