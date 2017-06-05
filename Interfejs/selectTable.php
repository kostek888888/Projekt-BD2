<?php include_once 'top.php'; ?>


<?php

$tableName = $_GET['table'];


$col = array(
    'Sprzedawca' => array(
        'id_sprzedawcy',
        'data_zatrudnienia',
        'data_zwolnienia',
        'pensja',
    ),
    'Rok' => array(
        'id_roku',
        'rok',
    ),
    'Miesiac' => array(
        'id_miesiaca',
        'id_roku',
        'miesiac',
    ),
    'Dzien' => array(
        'id_dnia',
        'id_miesiaca',
        'dzien',
    ),
    'Miasto' => array(
        'id_miasta',
        'nazwa',
        'kraj',
        'liczba_mieszkancow',
    ),
    'Salon' => array(
        'id_salonu',
        'id_miasta',
        'nazwa',
        'adres',
        'powierzchnia',
        'obrot_miesieczny',
    ),
    'Tematyka' => array(
        'id_tematyki',
        'nazwa',
        'opis',
    ),
    'Pismo' => array(
        'id_pisma',
        'id_tematyki',
        'okres_wydawania',
        'nazwa',
        'naklad',
        'cena',
    ),
    'Platnosci' => array(
        'id_platnosci',
        'nazwa',
    ),
    'Paragony' => array(
        'id_paragonu',
        'id_platnosci',
        'do_zaplaty',
    ),
    'Sprzedaz' => array( 
        'id_sprzedazy',
        'id_pisma',
        'id_salonu',
        'id_dnia',
        'id_sprzedawcy',
        'id_paragonu',
        'suma_zysku',
    ),
);

$colNames = $col[$tableName];

echo maketable( $dbh->query( "SELECT * FROM $tableName" ), $colNames); 

?>

<?php include_once 'back.php'; ?>