<?php include_once 'top.php'; ?>
 


<?php
$sql = "SELECT Nvl(To_Char(id_sprzedawcy),'Wszystkie sprzedawcy') AS id_sprzedawcy,
       Nvl(To_Char(id_pisma),'Ogolem pisma lub pism') AS id_pisma,
       Sum(suma_zysku) AS suma_zysku FROM sprzedaz
GROUP BY cube(id_sprzedawcy,id_pisma)
ORDER BY id_sprzedawcy, id_pisma desc";

$colNames = array(
    'id_sprzedawcy',
    'id_pisma',
    'suma_zysku',
);

$opis = 'ile sprzedawca zarobil dla firmy na poszczegolnym pismie, ile zarobil na wszystkich pismach, ile wszyscy sprzedawcy zarobili na danym pismie i ogolny zarobek wszystkich sprzedawcow na wszystkich pismach';

displaySql($sql, $opis);
echo maketable($dbh->query($sql), $colNames);
?>

<?php include_once 'back.php'; ?>