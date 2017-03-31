DROP TABLE Sprzedaz CASCADE CONSTRAINTS;
DROP TABLE Pismo CASCADE CONSTRAINTS;
DROP TABLE Tematyka CASCADE CONSTRAINTS;
DROP TABLE Dodatek CASCADE CONSTRAINTS;
DROP TABLE Salon CASCADE CONSTRAINTS;
DROP TABLE Miasto CASCADE CONSTRAINTS;
DROP TABLE Czas CASCADE CONSTRAINTS;
DROP TABLE Sprzedawca CASCADE CONSTRAINTS;
DROP TABLE Kierownik CASCADE CONSTRAINTS;
DROP TABLE Osoby CASCADE CONSTRAINTS;

CREATE TABLE Osoby (
id_osoby NUMBER CONSTRAINT osoby_pk PRIMARY KEY,
imie VARCHAR2(25) NOT NULL,
nazwisko VARCHAR(50) NOT NULL,
data_ur DATE NOT NULL,
pesel VARCHAR2(11) NULL CONSTRAINT os_pesel_uni UNIQUE,
adres VARCHAR2(60) NOT NULL,
telefon VARCHAR2(20) NOT NULL
);

CREATE TABLE Kierownik (
id_kierownika NUMBER CONSTRAINT kierownik_pk PRIMARY KEY,
id_osoby NUMBER NOT NULL,
data_zatrudnienia DATE NOT NULL,
data_zwolnienia DATE,
pensja NUMBER(6) NOT NULL,

CONSTRAINT kier_os_fk FOREIGN KEY(id_osoby) REFERENCES Osoby(id_osoby)
);

CREATE TABLE Sprzedawca (
id_sprzedawcy NUMBER CONSTRAINT Sprzedawca PRIMARY KEY,
id_osoby NUMBER NOT NULL,
id_kierownika NUMBER NOT NULL,
data_zatrudnienia DATE NOT NULL,
data_zwolnienia DATE,
pensja NUMBER(6) NOT NULL,
ocena NUMBER(1),                   ---------od 1 do 5

CONSTRAINT sprzed_os_fk FOREIGN KEY(id_osoby) REFERENCES osoby(id_osoby),
CONSTRAINT sprzed_kier_fk FOREIGN KEY(id_kierownika) REFERENCES Kierownik(id_kierownika)
);

CREATE TABLE Czas (
id_czasu NUMBER NOT NULL CONSTRAINT czas_pk PRIMARY KEY,
data DATE NOT NULL,
kwartal NUMBER(1) NOT NULL
);

CREATE TABLE Miasto (
id_miasta NUMBER NOT NULL CONSTRAINT miasto_pk PRIMARY KEY,
nazwa VARCHAR2(50) NOT NULL,
wojewodztwo VARCHAR2(40) NOT NULL,
liczba_mieszkancow NUMBER(7)
);

CREATE TABLE Salon(
id_salonu NUMBER NOT NULL CONSTRAINT salon_pk PRIMARY KEY,
id_miasta NUMBER NOT NULL,
adres VARCHAR2(30) NOT NULL,
powierzchnia NUMBER(4) NOT NULL,
obrot_miesieczny NUMBER(7) NOT NULL,

CONSTRAINT salon_miasto_fk FOREIGN KEY(id_miasta) REFERENCES miasto(id_miasta)
);


CREATE TABLE Dodatek (
id_dodatku NUMBER NOT NULL CONSTRAINT dodatek_pk PRIMARY KEY,
nazwa VARCHAR2(50) NOT NULL,
naklad NUMBER(7) NOT NULL
);

CREATE TABLE Tematyka (
id_tematyki NUMBER NOT NULL CONSTRAINT tematyka_pk PRIMARY KEY,
nazwa VARCHAR2(50) NOT NULL,
dziedzina VARCHAR2(50) NOT NULL,
opis varchar2(200)
);

CREATE TABLE Pismo (
id_pisma NUMBER NOT NULL CONSTRAINT pismo_pk PRIMARY KEY,
id_dodatku NUMBER NOT NULL,
id_tematyki number NOT NULL,
okres_wydawania VARCHAR2(30) NOT NULL,  --np tygodnik itp
nazwa VARCHAR(40) NOT null,
naklad NUMBER(7) NOT NULL,
cena NUMBER(2,2) NOT NULL,

CONSTRAINT pismo_dodatek_fk FOREIGN KEY(id_dodatku) REFERENCES dodatek(id_dodatku),
CONSTRAINT pismo_tematyka_fk FOREIGN KEY(id_tematyki) REFERENCES tematyka(id_tematyki)
);

CREATE TABLE Sprzedaz (
id_sprzedazy NUMBER NOT NULL CONSTRAINT sprzedarz_pk PRIMARY KEY,
id_pisma NUMBER NOT NULL,
id_salonu NUMBER NOT NULL,
id_czasu NUMBER NOT NULL,
ilosc_sprzedanych NUMBER NOT NULL,
suma_zysku NUMBER NOT NULL,

CONSTRAINT sprzedarz_pismo_fk FOREIGN KEY(id_pisma) REFERENCES Pismo(id_pisma),
CONSTRAINT sprzedarz_salon_fk FOREIGN KEY(id_salonu) REFERENCES Salon(id_salonu),
CONSTRAINT sprzedarz_czas_fk FOREIGN KEY(id_czasu) REFERENCES Czas(id_czasu)
);


