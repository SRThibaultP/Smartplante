<?php
$sql = "SELECT * FROM id8552472_dbvariables WHERE id = (SELECT MAX(id) FROM id8552472_dbvariables)";
include($_SERVER['DOCUMENT_ROOT'].'/Database/login.php');
$db=connexion();
$req = mysqli_query($db,$sql) or die(mysqli_error());
while($data = mysqli_fetch_assoc($req)){
  $humidite = $data["humidite"];
}

echo "<!doctype html>
<html>
  <head>
   <script src='https://www.google.com/jsapi'></script>
   <script>
  		google.charts.load('current', {packages: ['gauge']});
      google.charts.setOnLoadCallback(drawGauge);
      var gaugeOptions={width:150, height:150, minorTicks:10, min:0, max:700};
	  var gauge;

	  function drawGauge() {

        gaugeData = new google.visualization.DataTable();

		gaugeData.addColumn('number','Humidité');

		gaugeData.addRows(1);
        gaugeData.setCell(0,0,$humidite);
        gauge = new google.visualization.gauge(container);;
		gauge.draw(gaugeData,gaugeOptions);
		}
</script>

  </head>
  <body>
    <div id='$29'></div>
  </body>
</html>
";


?>
