LOAD DATA
INFILE 'osoby.csv'
BADFILE 'osoby.bad'
DISCARDFILE 'osoby.dsc'
REPLACE INTO TABLE Osoby 
FIELDS TERMINATED BY "," TRAILING NULLCOLS
( id_osoby, imie, nazwisko, data_ur DATE "YYYY-MM-DD", pesel, adres, telefon)
