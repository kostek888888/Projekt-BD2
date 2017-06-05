<?php include_once 'top.php'; ?>
 


<?php
$sql = "SELECT id_salonu, 
   Nvl(To_Char(id_sprzedawcy),'Wszyscy sprzedawcy') AS id_sprzedawcy,
   Nvl(To_Char(id_pisma),'Wszystkie pisma') AS wszystkie_pisma,
   Count(id_pisma) AS ilosc_sprzedanych FROM sprzedaz
  GROUP BY cube(id_salonu,id_sprzedawcy,id_pisma)
  ORDER BY id_salonu";

$colNames = array(
    'id_salonu',
    'id_sprzedawcy',
    'id_pisma',
    'ilosc_sprzedanych'
);

$opis = 'cube ile pism sprzedal sprzedawca w danym salonie';

displaySql($sql, $opis);
echo maketable($dbh->query($sql), $colNames);
?>

<?php include_once 'back.php'; ?>