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
?>

<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>SerreRabelais - SmartPlante</title>
    <link rel="icon" href="/Images/favicon-32x32.png" type="image/png">
    <link rel="stylesheet" href="../serre.css">
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
  </head>
  <body>
    <div class="hauteur">
      <?php echo "$hauteur"; ?>
    </div>
    <div class="ventilateur">
      <?php echo "$ventilateur"; ?>
    </div>
    <div class="humidite">
      <?php echo "$humidite"; ?>
      <iframe src="/gaugeHumidite.php"
    </div>
    <div class="temperature">
      <?php echo "$temperature"; ?>
    </div>
  </body>
</html>
