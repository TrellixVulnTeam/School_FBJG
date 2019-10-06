<?php 
include "head.php";
?>
<link rel="stylesheet" href="main.css" type="text/css">
<title>Main Page</title>

</head>

<?php
include "body.php";
?>

<div id="main">
	<div id="text">
	
<table id="tabulka">
<tr>
<td id="left"><a href="vypis.php"><button type="submit" value="vypsat" name="vypsat" id="mb"> Výpis</button></a></td>
<td id="right"><a href="pod_vypis.php"><button type="submit" value="pod_vypsat" name="pod_vypsat" id="mb"> Vypsat s podmínkou</button></a></td>
</tr>
</table>	
	</div>	
</div>

<?php
include "bottom.php";
?>
