LOAD DATA
INFILE 'dodatek.csv'
BADFILE 'dodatek.bad'
DISCARDFILE 'dodatek.dsc'
REPLACE INTO TABLE Dodatek 
FIELDS TERMINATED BY "," TRAILING NULLCOLS
( id_dodatku, nazwa, naklad)