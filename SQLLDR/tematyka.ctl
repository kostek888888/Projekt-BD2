LOAD DATA
INFILE 'tematyka.csv'
BADFILE 'tematyka.bad'
DISCARDFILE 'tematyka.dsc'
REPLACE INTO TABLE Tematyka 
FIELDS TERMINATED BY "," TRAILING NULLCOLS
( id_tematyki, nazwa, opis )