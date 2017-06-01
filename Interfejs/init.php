<?php

include_once 'maketable.php';

$dbh = null;
        
        
try {
    $server = "127.0.0.1";
    $db_username = "SYSTEM";
    $db_password = "qwerty";
    $service_name = "";
    $sid = "";
    $port = 1521;
    $dbtns = "(DESCRIPTION = (ADDRESS = (PROTOCOL = TCP)(HOST = $server)(PORT = $port)) (CONNECT_DATA = (SERVICE_NAME = $service_name) (SID = $sid)))";

    $dbh = new PDO("oci:dbname=" . $dbtns . ";charset=utf8", $db_username, $db_password, array(
        PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
        PDO::ATTR_EMULATE_PREPARES => false,
        PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC));
} catch (PDOException $e) {
    echo $e->getMessage();
}