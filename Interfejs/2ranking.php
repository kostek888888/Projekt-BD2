<?php include_once 'top.php'; ?>
 


<?php
$sql = "SELECT id_pisma,
       Count(id_pisma) AS liczba_sprzedanych,
       Rank() OVER (PARTITION BY NULL ORDER BY  Count(id_pisma) desc) AS ranking
FROM sprzedaz
GROUP BY id_pisma";

$colNames = array(
    'id_pisma',
    'liczba_sprzedanych',
    'ranking',
);

$opis = 'ranking liczby sprzedanych pism';

displaySql($sql, $opis);
echo maketable($dbh->query($sql), $colNames);
?>

<?php include_once 'back.php'; ?>