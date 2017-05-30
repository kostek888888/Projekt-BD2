LOAD DATA
INFILE 'sprzedaz.csv'
BADFILE 'sprzedaz.bad'
DISCARDFILE 'sprzedaz.dsc'
REPLACE INTO TABLE Sprzedaz 
FIELDS TERMINATED BY "," TRAILING NULLCOLS
( id_sprzedazy, id_pisma, id_salonu, id_dnia, id_sprzedawcy, id_paragonu, suma_zysku )