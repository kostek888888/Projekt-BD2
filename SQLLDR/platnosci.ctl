LOAD DATA
INFILE 'platnosci.csv'
BADFILE 'platnosci.bad'
DISCARDFILE 'platnosci.dsc'
REPLACE INTO TABLE Platnosci 
FIELDS TERMINATED BY "," TRAILING NULLCOLS
( id_platnosci, nazwa )