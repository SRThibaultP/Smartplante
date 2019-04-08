var hauteurValue;
$.get("php.php", function(data){
  hauteurValue = data;
  alert("Data: " + data);
});

google.charts.load('current', {'packages':['gauge']});
google.charts.setOnLoadCallback(drawChart);

function drawChart() {

  var data = google.visualization.arrayToDataTable([
    ['Label', 'Value'],
    ['Memory', hauteurValue]
  ]);

  var options = {
    width: 400, height: 120,
    redFrom: 90, redTo: 100,
    yellowFrom:75, yellowTo: 90,
  };

  var chart = new google.visualization.Gauge(document.getElementById('hauteur'));

  chart.draw(data, options);
}
