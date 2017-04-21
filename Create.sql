DROP TABLE Sprzedaz CASCADE CONSTRAINTS;
DROP TABLE Paragon CASCADE CONSTRAINTS;
DROP TABLE Platnosci CASCADE CONSTRAINTS;
DROP TABLE Pismo CASCADE CONSTRAINTS;
DROP TABLE Tematyka CASCADE CONSTRAINTS;
DROP TABLE Salon CASCADE CONSTRAINTS;
DROP TABLE Miasto CASCADE CONSTRAINTS;
DROP TABLE Dzien CASCADE CONSTRAINTS;
DROP TABLE Miesiac CASCADE CONSTRAINTS;
DROP TABLE Rok CASCADE CONSTRAINTS;
DROP TABLE Sprzedawca CASCADE CONSTRAINTS;


CREATE TABLE Sprzedawca (
id_sprzedawcy NUMBER CONSTRAINT Sprzedawca PRIMARY KEY,
data_zatrudnienia DATE NOT NULL,
data_zwolnienia DATE,
pensja NUMBER(6) NOT NULL
);


CREATE TABLE Rok (
id_roku NUMBER NOT NULL CONSTRAINT rok_pk PRIMARY KEY,
rok NUMBER NOT NULL
);



CREATE TABLE Miesiac (
id_miesiaca NUMBER NOT NULL CONSTRAINT miesiac_pk PRIMARY KEY,
id_roku NUMBER NOT NULL,
miesiac NUMBER NOT NULL,

CONSTRAINT dzien_rok_fk FOREIGN KEY(id_roku) REFERENCES rok(id_roku)
);


CREATE TABLE Dzien (
id_dnia NUMBER NOT NULL CONSTRAINT dzien_pk PRIMARY KEY,
id_miesiaca NUMBER NOT NULL,
dzien NUMBER,

CONSTRAINT dzien_miesiac_fk FOREIGN KEY(id_miesiaca) REFERENCES miesiac(id_miesiaca)
);


CREATE TABLE Miasto (
id_miasta NUMBER NOT NULL CONSTRAINT miasto_pk PRIMARY KEY,
nazwa VARCHAR2(50) NOT NULL,
kraj VARCHAR2(40) NOT NULL,
liczba_mieszkancow NUMBER(7)
);


CREATE TABLE Salon(
id_salonu NUMBER NOT NULL CONSTRAINT salon_pk PRIMARY KEY,
id_miasta NUMBER NOT NULL,
nazwa VARCHAR2(60) NOT NULL,
adres VARCHAR2(30) NOT NULL,
powierzchnia NUMBER(4) NOT NULL,
obrot_miesieczny NUMBER(7) NOT NULL,

CONSTRAINT salon_miasto_fk FOREIGN KEY(id_miasta) REFERENCES miasto(id_miasta)
);


CREATE TABLE Tematyka (
id_tematyki NUMBER NOT NULL CONSTRAINT tematyka_pk PRIMARY KEY,
nazwa VARCHAR2(50) NOT NULL,
opis varchar2(200)
);

CREATE TABLE Pismo (
id_pisma NUMBER NOT NULL CONSTRAINT pismo_pk PRIMARY KEY,
id_tematyki number NOT NULL,
okres_wydawania VARCHAR2(30) NOT NULL,  --np tygodnik itp
nazwa VARCHAR(40) NOT null,
naklad NUMBER(7) NOT NULL,
cena NUMBER(3) NOT NULL,

CONSTRAINT pismo_tematyka_fk FOREIGN KEY(id_tematyki) REFERENCES tematyka(id_tematyki)
);

CREATE TABLE Platnosci (
id_platnosci NUMBER NOT NULL CONSTRAINT platnosci_pk PRIMARY KEY,
nazwa VARCHAR2(50)
);

CREATE TABLE Paragon (
id_paragonu NUMBER NOT NULL CONSTRAINT paragon_pk PRIMARY KEY,
id_platnosci NUMBER NOT NULL,
do_zaplaty NUMBER,

CONSTRAINT paragon_PLATNOSCI_fk FOREIGN KEY(id_platnosci) REFERENCES Platnosci(id_platnosci) 
);

CREATE TABLE Sprzedaz (
id_sprzedazy NUMBER NOT NULL CONSTRAINT sprzedarz_pk PRIMARY KEY,
id_pisma NUMBER NOT NULL,
id_salonu NUMBER NOT NULL,
id_dnia NUMBER NOT NULL,
id_sprzedawcy NUMBER NOT NULL,
id_paragonu NUMBER NOT NULL,
suma_zysku NUMBER NOT NULL,

CONSTRAINT sprzedaz_pismo_fk FOREIGN KEY(id_pisma) REFERENCES Pismo(id_pisma),
CONSTRAINT sprzedaz_salon_fk FOREIGN KEY(id_salonu) REFERENCES Salon(id_salonu),
CONSTRAINT sprzedaz_dzien_fk FOREIGN KEY(id_dnia) REFERENCES Dzien(id_dnia),
CONSTRAINT sprzedaz_sprzedawca_fk FOREIGN KEY(id_sprzedawcy) REFERENCES Sprzedawca(id_sprzedawcy),
CONSTRAINT sprzedaz_paragon_fk FOREIGN KEY(id_paragonu) REFERENCES Paragon(id_paragonu)

);

