<?php include_once 'top.php'; ?>
 


<?php
$sql = "SELECT id_salonu, id_sprzedawcy, id_pisma AS id_pisma,
Count(id_pisma) OVER(
                    PARTITION BY id_salonu
                    ORDER BY id_dnia, id_pisma asc
                    RANGE BETWEEN unbounded preceding  AND CURRENT ROW
                    ) AS liczba_sprzedanych_pism
FROM sprzedaz
WHERE id_dnia <29";

$colNames = array(
    'id_salonu',
    'id_sprzedawcy',
    'id_pisma', 
    'liczba_sprzedanych_pism'
);

$opis = 'ile pism sprzedal sprzedawca w danym dniu i jakie to byly pisma';

displaySql($sql, $opis);
echo maketable($dbh->query($sql), $colNames);
?>

<?php include_once 'back.php'; ?>