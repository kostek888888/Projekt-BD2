LOAD DATA
INFILE 'sprzedaz.csv'
BADFILE 'sprzedaz.bad'
DISCARDFILE 'sprzedaz.dsc'
REPLACE INTO TABLE Sprzedaz 
FIELDS TERMINATED BY "," TRAILING NULLCOLS
( id_sprzedazy, id_pisma, id_salonu, id_czasu, id_sprzedawcy, ilosc_sprzedanych, suma_zysku )