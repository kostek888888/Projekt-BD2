<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="pl">

    <head>
        <!-- Latest compiled and minified CSS -->
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">

            <!-- Optional theme -->
            <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css" integrity="sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp" crossorigin="anonymous">
                <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
                <!-- Latest compiled and minified JavaScript -->
                <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
                <style>
                    .auto-generated td, th {
                        padding-left: 8px;
                        padding-right: 8px;
                        border: 1px solid #999;
                    }
                    th.headerSortUp { 
                        background-image: url(img/small_asc.gif) !important; 
                        background-color: #3399FF;                    
                    } 
                    th.headerSortDown { 
                        background-image: url(img/small_desc.gif) !important; 
                        background-color: #3399FF; 
                    } 
                    th.header { 
                        background-image: url(img/small_bg.gif);
                        cursor: pointer; 
                        font-weight: bold; 
                        background-repeat: no-repeat; 
                        background-position: center right; 
                        padding-right: 20px; 
                        border-right: 1px solid #dad9c7; 
                        margin-left: -1px; 
                    } 
                </style>
                
                
                </head>
    <body>


    <div class="container-fluid">
      <div class="row">
        <div class="col-sm-3 col-md-2 sidebar">
          <ul class="nav nav-sidebar">
            <li><a href="selectTable.php?table=Sprzedaz">Tabela Sprzedaz</a></li>
            <li><a href="selectTable.php?table=Paragony">Tabela Paragony</a></li> 
            <li><a href="selectTable.php?table=Platnosci">Tabela Platnosci</a></li>
            <li><a href="selectTable.php?table=Pismo">Tabela Pismo</a></li>
            <li><a href="selectTable.php?table=Tematyka">Tabela Tematyka</a></li>
            <li><a href="selectTable.php?table=Salon">Tabela Salon</a></li>
            <li><a href="selectTable.php?table=Miasto">Tabela Miasto</a></li>
            <li><a href="selectTable.php?table=Dzien">Tabela Dzien</a></li>
            <li><a href="selectTable.php?table=Miesiac">Tabela Miesiac</a></li>
            <li><a href="selectTable.php?table=Rok">Tabela Rok</a></li>
            <li><a href="selectTable.php?table=Sprzedawca">Tabela Sprzedawca</a></li>
            <li><a href="1rollup.php">rollup1</a></li>
            <li><a href="2rollup.php">rollup2</a></li>
            <li><a href="1cube.php">cube1</a></li>
            <li><a href="2cube.php">cube2</a></li>
            <li><a href="1grouping.php">1grouping</a></li>
            <li><a href="2grouping.php">2grouping</a></li>
            <li><a href="1partycje.php">1partycje</a></li>
            <li><a href="2partycje.php">2partycje</a></li>
            <li><a href="1ranking.php">1ranking</a></li>
            <li><a href="2ranking.php">2ranking</a></li>
          </ul>
        </div>
        <div class="col-sm-9 main">

<?php include_once 'init.php'; ?>