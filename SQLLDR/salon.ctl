LOAD DATA
INFILE 'salon.csv'
BADFILE 'salon.bad'
DISCARDFILE 'salon.dsc'
REPLACE INTO TABLE Salon 
FIELDS TERMINATED BY "," TRAILING NULLCOLS
( id_salonu, id_miasta, nazwa, adres, powierzchnia, obrot_miesieczny )