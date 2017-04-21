LOAD DATA
INFILE 'paragony.csv'
BADFILE 'paragony.bad'
DISCARDFILE 'paragony.dsc'
REPLACE INTO TABLE Paragony 
FIELDS TERMINATED BY "," TRAILING NULLCOLS
( id_paragonu, id_platnosci, do_zaplaty )