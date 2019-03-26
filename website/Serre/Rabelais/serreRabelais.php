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
?>

<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>SerreRabelais - SmartPlante</title>
    <link rel="icon" href="/Images/favicon-32x32.png" type="image/png">
    <link rel="stylesheet" href="../serre.css">
  </head>
  <body>
    <div class="hauteur">
      <?php echo "$hauteur"; ?>
    </div>
    <div class="ventilateur">
      <?php echo "$ventilateur"; ?>
    </div>
    <div class="humidite">
      <h1> <?php echo "$humiditeTXT"; ?> </h1>

    </div>
    <div class="temperature">
      <?php echo "$temperature"; ?>
    </div>
  </body>
</html>
