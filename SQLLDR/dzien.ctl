LOAD DATA
INFILE 'dzien.csv'
BADFILE 'dzien.bad'
DISCARDFILE 'dzien.dsc'
REPLACE INTO TABLE Dzien 
FIELDS TERMINATED BY "," TRAILING NULLCOLS
( id_dnia, id_miesiaca, dzien )