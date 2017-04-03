LOAD DATA
INFILE 'pismo.csv'
BADFILE 'pismo.bad'
DISCARDFILE 'pismo.dsc'
REPLACE INTO TABLE Pismo
FIELDS TERMINATED BY "," TRAILING NULLCOLS
( id_pisma, id_dodatku, id_tematyki, okres_wydawania, nazwa, naklad, cena)
