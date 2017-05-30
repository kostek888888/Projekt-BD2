LOAD DATA
INFILE 'miesiac.csv'
BADFILE 'miesiac.bad'
DISCARDFILE 'miesiac.dsc'
REPLACE INTO TABLE Miesiac 
FIELDS TERMINATED BY "," TRAILING NULLCOLS
( id_miesiaca, id_roku, miesiac )