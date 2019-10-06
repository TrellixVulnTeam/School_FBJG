<!DOCTYPE html>
<html>
<head>
<title>Form POST</title>
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
<?php

$a = $_POST["First_name"];
$b = $_POST["Last_name"];
$c = $_POST["E-mail"];
$d = $_POST["re-E-mail"];
$e = $_POST["Product"];
$f = $_POST["Quantity"];
$g = $_POST["City"];
$h = $_POST["Country"];
$i = $_POST["Agree"];
if(isset ($_POST["Agree"])) $i ="ano"; 
else $i ==NULL;
$j = $_POST["Address"];
$k = $_POST["Postal"];



if($a==NULL or $b==NULL or $c==NULL or $d==NULL or $e==NULL or $f==NULL or $g==NULL or $h==NULL or $i ==NULL or $j ==NULL or $k ==NULL) 
	{
	 	echo "!!!Something missing!!!";
	}
else 
	{ 

	
$all = "First name: $a <br> 
		  Last name: $b <br> 
		  E-mail: $c <br> 
		  E-mail confirmed: $d <br> 
		  Product: $e <br> 
		  Quantity: $f <br> 
		  City: $g <br> 
		  Country: $h <br>
		  Address: $j <br> 
		  Postal: $k <br>  
		  Agree: $i <br>";
		  
echo $all;

$file = fopen("POST.dat","a");

if($file == NULL)
     {
      echo("soubor neexistuje");
     }
    fwrite($file, "$a;$b;$c;$d;$e;$f;$g;$h;$j;$k;\n");
    fclose($file);
   }

$l = $_POST["return"];
header("refresh:3; url=$l");

?>
</div>

<div id="bottom">
 	<p>&copy; Lukáš Moravec</p>
</div>
 
<script src="Main_script.js" type="text/javascript"></script>

</body>
</html>