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
        <td>email:</td> 
        <td><select name="e-mail">
        <option value="none">Vyberte</option>
        <option value="@gmail.com">*@gmail.com</option>
        <option value="@seznam.cz">*@seznam.cz</option>
        </select></td>
        <td rowspan="2"><a href="or_vypis.php"><button type="button" value="zpět" name="zpět" id="ma">zpět</button></a></td>
        </tr>
        <tr>
        <td><button type="submit" value="zobrazit" name="zobrazit">Zobrazit</button></td>
        </tr>
        <tr>
		  <td><p></p></td>
        </tr>
        </table>             			  
        </form>
       


<?php
  if($_POST) 
{
	
$nazev = $_POST["nazev"];
$email = $_POST["e-mail"];

if($nazev == NULL or $email == "none") 
{
	echo "Nebyly vplňeny všechny údaje.";
}
else {
include "connect.php";

          $prikaz="SELECT * FROM $nazev WHERE email LIKE '%$email' order by jmeno ";
          $vysl = mysqli_query($spojeni, $prikaz);
          
          //tohle je k výpisu počtu řádků
          if($vysl)
                     echo"Počet záznamů v $nazev tabulce: ".mysqli_num_rows($vysl) ."<br>";
           else {
                  echo "Chyba při načítání z db!";
                   return;}
                   
            
            
            	echo "<table>";   
           while($oneradek= mysqli_fetch_array($vysl))
           {
           
           	echo "<tr>";
							echo "<td>" ;                      
                       echo $oneradek['id'];
                     echo "</td>";
                     echo "<td>";
                       echo $oneradek['prijmeni'];
                     echo "</td>";
                     echo "<td>";
                       echo $oneradek['jmeno'];
							echo "</td>";                     
                     echo "<td>" ; 
                       echo $oneradek['email'];
                     echo "</td>" ; 
                     echo "<td>";
                       echo $oneradek['reg_datum'];
                     echo "</td>";
            echo "</tr>";
				                       
           }
           echo "</table>";
            mysqli_close($spojeni); 
}
}
?>
</div> 
</div>
<?php
include "bottom.php";
?>