<?php 
include "head.php";
?>
<link rel="stylesheet" href="main.css" type="text/css">
<title>Main Page</title>

</head>

<?php
include "body.php";
?>
 <div id="main" >
 	<div id="text">
 <form action="" method="post" enctype="multipart/form-data">
        <table>
        <tr>
        <td>název tabulky:</td> 
        <td><?php
		  include "connect.php"; 
		  $prikaz1="SHOW TABLES";
        $vysl1 = mysqli_query($spojeni, $prikaz1);
		   
		   echo "<select name=\"nazev\">";
			while($oneradek = mysqli_fetch_array($vysl1)) 
			{
				echo "<option>";
				echo $oneradek[0];
				echo "</option>";	
			}
			echo "</select>";
			 ?></td>
        </tr>
        <tr>
        <td>id:</td> 
        <td><input type="text" name="id" placeholder="Id"></td>
        </tr>
        <tr>
        <td>Změnit na:</td> 
        </tr>
        <tr>
        <td>jméno:</td> 
        <td><input type="text" name="jmeno" placeholder="Jméno"></td>
        </tr> 
        <tr>
        <td>příjmení:</td> 
        <td><input type="text" name="prijmeni" placeholder="Příjmení"></td>
        </tr>
        <tr>
        <td>e-mail:</td> 
        <td><input type="text" name="email" placeholder="E-mail"></td>
        <td rowspan="2"><a href="upravy.php"><button type="button" value="zpět" name="zpět" id="ma">zpět</button></a></td>
        </tr>
        <tr>  
        <td><button type="submit" value="vytvorit" name="vytvorit">Upravit</button></td>
        <td><button type="reset" value="reset" name="reset">Reset</button></td>
        </tr>             			  
 		  </table>             			  
        </form>


<?php
  if($_POST) 
{
$nazev = $_POST["nazev"];  	
$id = $_POST["id"]; 
$jmeno = $_POST["jmeno"];
$prijmeni = $_POST["prijmeni"];
$email = $_POST["email"];
if($id == NULL or $jmeno == NULL or $prijmeni == NULL or $email == NULL) 
{
	echo "Nebyly vyplňeny všechny údaje.";
}
else {
include "connect.php";

$prikaz="UPDATE $nazev SET jmeno='$jmeno', prijmeni='$prijmeni', email='$email' WHERE id =$id";
       $vysl=mysqli_query($spojeni, $prikaz);
            if ($vysl)
            {
             echo "Úprava byla zaznamenána: $id";
            }
            else
            {
             echo "Chyba při ukládání do tabulky";
            }
         
          
          mysqli_close($spojeni); 
}
}
?>
   </div>     
</div>
<?php
include "bottom.php";
?>