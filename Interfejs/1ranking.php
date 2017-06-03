<?php include_once 'top.php'; ?>
 


<?php
$sql = "SELECT id_sprzedawcy,
       Sum(suma_zysku) AS zysk,
       Rank() OVER (PARTITION BY NULL ORDER BY Sum(suma_zysku) desc) AS ranking
FROM sprzedaz
GROUP BY id_sprzedawcy";

$colNames = array(
    'id_sprzedawcy',
    'zysk',
    'ranking',
);

$opis = 'ranking sprzedawcow: ktory zarobil dla firmy najwiecej';

displaySql($sql, $opis);
echo maketable($dbh->query($sql), $colNames);
?>

<?php include_once 'back.php'; ?>