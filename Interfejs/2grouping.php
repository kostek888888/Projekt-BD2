<?php include_once 'top.php'; ?>
 


<?php
$sql = "SELECT Nvl(To_Char(sprzedaz.id_salonu),'Wszystkie salony') AS id_salonu,
       sprzedaz.id_dnia,  Sum(sprzedaz.suma_zysku) AS zysk FROM sprzedaz
GROUP BY Grouping sets ((id_salonu,id_dnia), id_dnia ,())
ORDER BY id_salonu desc , id_dnia";

$colNames = array(
    'id_salonu',
    'id_dnia',
    'zysk',
);

$opis = 'Suma zysku danego dnia we wszystkich salonach, suma calkowitego zysku, a potem zysk dzienny dla kazdego salonu kazdego dnia';

displaySql($sql, $opis);
echo maketable($dbh->query($sql), $colNames);
?>

<?php include_once 'back.php'; ?>