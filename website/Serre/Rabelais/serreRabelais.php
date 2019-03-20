<?php
$QuantiteEau = 57;
$sql = "SELECT * FROM id8552472_dbvariables WHERE id = (SELECT MAX(id) FROM id8552472_dbvariables)";
include($_SERVER['DOCUMENT_ROOT'].'/Database/login.php');
$db=connexion();
$req = mysqli_query($db,$sql) or die(mysqli_error());
while($data = mysqli_fetch_assoc($req)){
  $hauteur = $data["hauteur"];
  $ventilateur = $data["ventilateur"];
  $humidite = $data["humidite"];
  $eauBrut = $data["eau"];
  $eau = ($eauBrut/$QuantiteEau)*100;
}
?>

<!DOCTYPE html>
<html lang="fr" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>SerreRabelais - SmartPlante</title>
    <link rel="icon" href="../Images/favicon-32x32.png" type="image/png">
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
      <?php echo "$humidite"; ?>
    </div>
    <div class="eau">
      <div class="water" style="height:<?php echo "$eau"; ?>%;"
      <?php echo "$eau"; ?>
    </div>
  </body>
</html>
