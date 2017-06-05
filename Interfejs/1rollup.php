<?php include_once 'top.php'; ?>
 


<?php
$sql = "SELECT Nvl(To_Char(id_salonu),'Wszystkie salony') AS id_salonu,
       Nvl(To_Char(id_pisma),'Ogolem pism') AS id_pisma,
       Count(id_pisma) AS liczba_sprzedanych
FROM sprzedaz
GROUP BY rollup (id_salonu, id_pisma)";

$colNames = array(
    'id_salonu',
    'id_pisma',
    'liczba_sprzedanych'
);

$opis = 'ROLLUP ile kazdego z pism zostalo sprzedanych w danym salonie, ile ogolem pismy bylo sprzedanych w danym salonie, ile pism zostalo sprzedanych we wszystkich salonach';

displaySql($sql, $opis);
echo maketable($dbh->query($sql), $colNames);
?>

<?php include_once 'back.php'; ?>