LOAD DATA
INFILE 'kierownik.csv'
BADFILE 'kierownik.bad'
DISCARDFILE 'kierownik.dsc'
REPLACE INTO TABLE Kierownik 
FIELDS TERMINATED BY "," TRAILING NULLCOLS
( id_kierownika, id_osoby, data_zatrudnienia DATE "YYYY-MM-DD", data_zwolnienia DATE "YYYY-MM-DD", pensja)