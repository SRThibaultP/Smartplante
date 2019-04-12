$.get("hauteur.php",function(data){
  hauteurValue = data;
});

google.charts.load('current', {'packages':['gauge']});
google.charts.setOnLoadCallback(drawChart);

function drawChart() {

  var data = google.visualization.arrayToDataTable([
    ['Label', 'Value'],
    ['Hauteur', hauteurValue]
  ]);

  var options = {
    width: 400, height: 120,
    redFrom: 90, redTo: 100,
    yellowFrom:75, yellowTo: 90,
  };

  var chart = new google.visualization.Gauge(document.getElementById('hauteur'));

  chart.draw(data, options);
}
