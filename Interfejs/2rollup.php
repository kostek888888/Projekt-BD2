<?php include_once 'top.php'; ?>
 


<?php
$sql = "SELECT  Nvl(To_Char(id_salonu),'Wszystkie salony') AS id_salonu,
			   Nvl(To_Char(id_sprzedawcy),'Sprzedawcy') AS id_sprzedawcy,
       Count(id_paragonu) AS liczba_obsluzonych_klientow
FROM sprzedaz
GROUP BY rollup (id_salonu,id_sprzedawcy)";

$colNames = array(
    'id_salonu',
    'id_sprzedawcy',
    'liczba_obsłużonych_klientów'
);

$opis = 'ile klientow bylo obsluzonych w danym salonie przez jakiego sprzedawce, ogolem w salonie, ogolem obsluzonych klientow';

displaySql($sql, $opis);
echo maketable($dbh->query($sql), $colNames);
?>

<?php include_once 'back.php'; ?>