<?php include_once 'top.php'; ?>
 


<?php
$sql = "SELECT id_salonu, id_dnia, suma_zysku AS zysk_dzienny,
Sum(suma_zysku) OVER(
                    PARTITION BY id_salonu
                    ORDER BY id_dnia
                    RANGE BETWEEN unbounded preceding  AND CURRENT ROW
                    ) AS zarobek
FROM sprzedaz
WHERE id_dnia <29";

$colNames = array(
    'id_salonu',
    'id_dnia',
    'zysk_dzienny',
    'zarobek'
);

$opis = 'partycje i ruchome okno obliczeniowe
--jak wyglada sumaryczna sprzedaz w danym salonie w ostatnim miesiacu';

displaySql($sql, $opis);
echo maketable($dbh->query($sql), $colNames);
?>

<?php include_once 'back.php'; ?>