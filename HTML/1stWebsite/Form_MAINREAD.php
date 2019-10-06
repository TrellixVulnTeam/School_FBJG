<!DOCTYPE html>
<html>
<head>
<title>Form Main READ</title>
	<meta name="generator" content="Bluefish 2.2.5" >
	<meta http-equiv="content-type" content="text/html; charset=UTF-8">
	
	<link href="Main_css.css" rel="stylesheet">
</head>

<body>

<div id="Selectdiv">
<form name="Select">

		<select name="Language" id="Language">
			<option value="nothing">ENG</option>
			<option value="Main_menu_CZ.html">CZ</option>
		</select>
	</form>
</div>

<img id="icon" src="Images/Icon_32x32.png" alt="icon">

<div id="head">
<a href="Main_menu_ENG.html"><h1 id="logo">LUMO company</h1></a> 
</div>

<div id="navigation"> 


<div id="dn" ><p><a href="Main_menu_ENG.html">Home</a></p>
	<p><a href="Form_ENG.html">Form</a></p>
	<p><a href="Photos_ENG.html">Images</a></p>
	<p><a href="Table_ENG.html">Table</a></p>
</div>

</div>
<div id="main">
<form name="form" action="" method="POST">
<select name="MLG">
<option value="Czech">Czech Republic</option>
<option value="Slovakia">Slovakia</option>
</select>
</form>
<table id="tab" border="0px">
<tr>
<th>First name</th>
<th>Last name</th>
<th>E-mail</th>
<th>E-mail confirmed</th>
<th>Product</th>
<th>Quantity</th>
<th>City</th>
<th>Country</th>

</tr>
<?php
$file = fopen("POST.dat", "r");
$find = "Czech";

$pos = strpos($file, $find);

$a = $_POST["form"];

if($a = "Czech") 
	{
		
	}
	

/*
if ($pos === false) {
    echo "The string '$find' was not found in the string '$file'";
} else {
    echo "The string '$find' was found in the string '$file'";
    echo " and exists at position $pos";
}
*/

/*
while($row = fgets($file))
 {
 	echo "<tr>";

 	$fuck = explode(";", $row);
 	foreach($fuck as $you) 
 	 {
 	 	echo "<td>";
 		echo $you;
 	 	echo "</td>";
 	 }
 	echo "</tr>";
 }
*/



fclose($file);
?>
</table>
</div>

<div id="bottom">
 	<p>&copy; Lukáš Moravec</p>
</div>
 
<script src="Main_script.js" type="text/javascript"></script>

</body>
</html>