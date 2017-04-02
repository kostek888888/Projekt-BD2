LOAD DATA
INFILE 'sprzedawca.csv'
BADFILE 'sprzedawca.bad'
DISCARDFILE 'sprzedawca.dsc'
REPLACE INTO TABLE Sprzedawca 
FIELDS TERMINATED BY "," TRAILING NULLCOLS
( id_sprzedawcy, id_osoby, id_kierownika,  data_zatrudnienia DATE "YYYY-MM-DD", data_zwolnienia DATE "YYYY-MM-DD", pensja, ocena )