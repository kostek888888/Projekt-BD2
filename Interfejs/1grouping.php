<?php include_once 'top.php'; ?>
 


<?php
$sql = "SELECT  Nvl(To_Char(sprzedaz.id_salonu),'Wszystkie salony') AS id_salonu,
       sprzedaz.id_dnia,  Count(sprzedaz.id_sprzedazy) AS liczba_sprzedanych_gazet FROM sprzedaz
GROUP BY Grouping sets ((id_salonu,id_dnia), id_dnia ,())
ORDER BY id_salonu desc, id_dnia";

$colNames = array(
    'id_salonu',
    'id_dnia',
    'liczba_sprzedanych_gazet',
);

$opis = 'grouping sets: liczba sprzedanych gazet we wszystkich salonach danego dnia, ogolem sprzedanych gazet, a potem sprzedanych gazet danego dnia w danym salonie';

displaySql($sql, $opis);
echo maketable($dbh->query($sql), $colNames);
?>

<?php include_once 'back.php'; ?>