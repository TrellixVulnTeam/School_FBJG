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
        <td>NÁZEV tabulky:</td> 
        <td><input type="text" name="jmeno" placeholder="NÁZEV"></td>
        <td rowspan="2"><a href="tabulka.php"><button type="button" value="zpět" name="zpět" id="ma">zpět</button></a></td>
        </tr> 
        <tr>  
        <td><button type="submit" value="vytvorit" name="vytvorit"> Vytvořit</button></td>
        <td><button type="reset" value="reset" name="reset"> Reset</button></td>
        </tr>             			  
 		  </table>             			  
        </form>

<?php
  if($_POST) {
          $jmeno = $_POST["jmeno"];
          
// Create connection
$spojeni = mysqli_connect("localhost","lumocompany.tk","password", "lumocompany_tk") or die("nelze připojit");
mysqli_set_charset($spojeni, "utf8");
// sql to create table
$sql = "CREATE TABLE $jmeno (
id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
jmeno VARCHAR(30) NOT NULL,
prijmeni VARCHAR(30) NOT NULL,
email VARCHAR(50) NOT NULL,
reg_datum TIMESTAMP
)";

if (mysqli_query($spojeni, $sql)) {
    echo "Úspěšně vytvořeno";
} else {
    echo "Chyba při vytváření tabulky ". mysqli_error($spojeni);

}
mysqli_close($spojeni);
}
?>
   </div>     
</div>

<?php
include "bottom.php";
?>