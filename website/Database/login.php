 <?php
 $host = "localhost"; /* L'adresse de l'hôte MySQL */
 $login = "id8552472_smartplante"; /* Votre numéro d'utilisateur MySQL*/
 $password = "r0vskuk8HH5GRbFt"; /* Votre mot de passe */
 $base = "id8552472_variables"; /* Le nom de votre base */

 function connexion()
 {
    global $host, $login, $password, $base;
    $db = mysqli_connect($host, $login, $password, $base);
    mysqli_select_db($db,$base);
    return $db;
 }
?>
