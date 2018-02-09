<?php

// index.php

// includes
include("config.php");

$connection = mysqli_connect($hostname, $user, $password, $database) or die ("Unable to connect!");

?>

<html>
  <body>
    <h1>It worked!</h1>
  </body>
</html>

<?php
mysqli_close($connection);
?>
