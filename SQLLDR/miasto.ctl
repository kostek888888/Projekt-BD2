LOAD DATA
INFILE 'miasto.csv'
BADFILE 'miasto.bad'
DISCARDFILE 'miasto.dsc'
REPLACE INTO TABLE Miasto 
FIELDS TERMINATED BY "," TRAILING NULLCOLS
( id_miasta, nazwa, kraj, liczba_mieszkancow )