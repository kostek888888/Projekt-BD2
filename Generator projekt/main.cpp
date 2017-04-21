#include <iostream>
#include "generate_lib.h"
#include <fstream>
#include <sstream>


/*
DO ZROBIENIA
wygenerowac tabele paragon i platnosci
powiazac tabele paragon z tabela sprzedaz

*/

using namespace std;

///pobiera sciezke do projektu z uwzglednieniem nazwy uzytkownika
string pobierz_sciezke()
{
       stringstream stream;
       string user_name = getenv("USERNAME");

       if(user_name=="Wojciech")
         stream << "C:\\Users\\" << user_name << "\\Documents\\Github\\Projekt-BD2\\SQLLDR\\";
       else if(user_name=="koste")
        stream << "C:\\Users\\koste\\OneDrive\\Informatyka\\Semestr 4\\Bazy Danych 2\\Projekt\\Projekt-BD2\\SQLLDR\\";
        else
        stream << "C:\\";

       return stream.str();
}

void generuj_sprzedawcow(int p_ile_sprz, int p_ile_zw_sprz)
{
    string sciezka = pobierz_sciezke() + "sprzedawca.csv";
    fstream fplik;
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=0; i<p_ile_sprz; i++)
       {
           fplik << i+1 << ",";
           fplik << generate_date(2000,2005) << ",";

           ///czasem ma date zwolnienia czasem nie
           if (i<p_ile_zw_sprz)
              fplik << generate_date(2006,2017);

           fplik << ",";
           fplik << ( (rand()%3)+2 ) * 1000 << ","; ///pensja

           fplik << endl; ///koniec rekordu
       }
       cout << "Dane wygenerowane do pliku " << sciezka.c_str() << endl;
       fplik.close();
    }
    else
    {
       ///gdyby nie bylo pliku to utworzy
       ofstream utworz_plik;
       utworz_plik.open(sciezka.c_str());
       utworz_plik.close();
       cout << "Nie ma pliku lub jest otwarty w innym programie";
    }
}

int generuj_lata(int rok, int ile_lat)
{
    string sciezka = pobierz_sciezke() + "rok.csv";
    fstream fplik;
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=0; i<ile_lat; i++)
       {
           fplik << i+1 << ",";
           fplik << rok;

           fplik << endl; ///koniec rekordu
           rok++;
       }
       cout << "Dane wygenerowane do pliku " << sciezka.c_str() << endl;
       fplik.close();
    }
    return ile_lat;
}

int generuj_miesiace(int ile_lat)
{
    string sciezka = pobierz_sciezke() + "miesiac.csv";
    fstream fplik;
    int id_roku=1;
    int nr_miesiaca=1;
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=0; i<ile_lat*12; i++)
       {
           fplik << i+1 << ",";

           if(nr_miesiaca>12)
           {
              nr_miesiaca=1;
              id_roku++;
           }

           fplik << id_roku << ",";
           fplik << nr_miesiaca;
           nr_miesiaca++;

           fplik << endl; ///koniec rekordu
       }
       cout << "Dane wygenerowane do pliku " << sciezka.c_str() << endl;
       fplik.close();
    }
    return ile_lat*12;
}


unsigned int generuj_dni(int ile_miesiecy)
{
    string sciezka = pobierz_sciezke() + "dzien.csv";
    fstream fplik;
    int id_miesiaca=1;
    int nr_dnia=1;
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=0; i<ile_miesiecy*28; i++)
       {
           fplik << i+1 << ",";

           if(nr_dnia>28)
           {
              nr_dnia=1;
              id_miesiaca++;
           }

           fplik << id_miesiaca << ",";
           fplik << nr_dnia;
           nr_dnia++;

           fplik << endl; ///koniec rekordu
       }
       cout << "Dane wygenerowane do pliku " << sciezka.c_str() << endl;
       fplik.close();
    }
    return ile_miesiecy*28;
}

void generuj_miasto(int n)
{
    string sciezka = pobierz_sciezke() + "miasto.csv";
    fstream fplik;

    string kraje[] = {"Polska","Anglia","USA","Niemcy","Francja"};
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(int i=0; i<n; i++)
       {
           fplik << i+1 << "," << generate_city_name("awa") << ",";

           int val = rand()%5;
           fplik << kraje[val] << ",";

           int l_mieszkancow = (rand()%9)+1 * 1000;  /// od 1000 do 9000
           l_mieszkancow *= (rand()%60)+1;
           fplik << l_mieszkancow;

           fplik << endl;
       }
       cout << "Dane wygenerowane do pliku " << sciezka.c_str() << endl;
       fplik.close();
    }
    else
    {
       ///gdyby nie bylo pliku to utworzy
       ofstream utworz_plik;
       utworz_plik.open(sciezka.c_str());
       utworz_plik.close();
       cout << "Nie ma pliku lub jest otwarty w innym programie";
    }
}


void generuj_salony(unsigned int n, int l_miast )
{
    string sciezka = pobierz_sciezke() + "salon.csv";
    fstream fplik;


    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(int i=0; i<n; i++)
       {
           fplik << i+1 << "," << (rand()%l_miast)+1 << ",";
           fplik << generate_salon_name("ra") << ",";
           fplik << generate_address("owska") << ",";
           fplik << ( (rand()%5) +3 ) *50 << ","; ///powierzchnia
           fplik << ( (rand()%16)+4 ) * 1000; ///obrot miesieczny

           fplik << endl;
       }
       cout << "Dane wygenerowane do pliku " << sciezka.c_str() << endl;
       fplik.close();
    }
    else
    {
       ///gdyby nie bylo pliku to utworzy
       ofstream utworz_plik;
       utworz_plik.open(sciezka.c_str());
       utworz_plik.close();
       cout << "Nie ma pliku lub jest otwarty w innym programie";
    }
}


int generuj_tematyke()
{
    string sciezka = pobierz_sciezke() + "tematyka.csv";
    fstream fplik;
    string nazwy_tematyk[] = {"Wedkarstwo","Informatyka", "Prawo", "Sport", "Motoryzacja", "Budownictwo", "Gielda", "Mlodzierzowe", "Polityka", "Wiadomosci krajowe", "Gry wideo", "Muzyka"};

    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=0; i<11; i++)
       {
           fplik << i+1 << ","; ///id_tematyki

           ///tematyka
           fplik << nazwy_tematyk[i] << ",";
           fplik << "Opis:" << ",";
           fplik << endl;
       }
       cout << "Dane wygenerowane do pliku " << sciezka.c_str() << endl;
       fplik.close();
    }
    return 11; ///bo tyle jest tematyk
}

void generuj_pisma(unsigned int l_pism, int l_tematyk)
{
    string sciezka = pobierz_sciezke() + "pismo.csv";
    fstream fplik;
    string okres_wydawania[] = {"Dziennik", "Tygodnik", "Dwutygodnik", "Miesiecznik", "Kwartalnik", "Rocznik"};

    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       ///pisma bez dodatkow
        for(unsigned int i=0; i<=l_pism; i++)
       {
            ///id pisma, id_dodatku losowane z puli id_dodatków, id_tematyki
           fplik << i+1 << "," << (rand()%l_tematyk)+1 << ",";

           ///okres wydawania
           int val = rand()%5;
           fplik << okres_wydawania[val] << ",";

           ///nazwa
           char letter = (rand() % 25) +65;
           fplik << okres_wydawania[val] << " " << letter << ","; ///wyjdzie np Tygodnik A, Rocznik B itd.

           ///naklad
           fplik << ( (rand()%9) +1 ) * ((rand()%30)+10) * 70 << ",";

           ///cena
           if(okres_wydawania[val]=="Rocznik" || okres_wydawania[val]=="Kwartalnik")
           fplik << ((rand()%15)+30) * 1.0; ///kosztuje od 30.0 do 45.0 zl

           if(okres_wydawania[val]=="Miesiecznik" || okres_wydawania[val]=="Dwutygodnik")
           fplik << ((rand()%14)+15) * 1.0; ///kosztuje od 15.0 do 29.0 zl

           if(okres_wydawania[val]=="Tygodnik" || okres_wydawania[val]=="Dziennik")
           fplik << ((rand()%6)+9) * 1.0; ///kosztuje od 9 do 15 zl

           fplik << endl;
       }
       cout << "Dane wygenerowane do pliku " << sciezka.c_str() << endl;
       fplik.close();
    }
    else
    {
       ///gdyby nie bylo pliku to utworzy
       ofstream utworz_plik;
       utworz_plik.open(sciezka.c_str());
       utworz_plik.close();
       cout << "Nie ma pliku lub jest otwarty w innym programie";
    }
}


int generuj_platnosci()
{
    int l_rodzajow_platnosci=2;   ///gotowką, kartą
    string sciezka = pobierz_sciezke() + "platnosci.csv";
    fstream fplik;
    string rodzaje_platnosci[] = {"Platnosc karta","Platnosc gotowka"};
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=0; i<l_rodzajow_platnosci; i++)
       {
           fplik << i+1 << ",";
           fplik << rodzaje_platnosci[i];

           fplik << endl; ///koniec rekordu
       }
       cout << "Dane wygenerowane do pliku " << sciezka.c_str() << endl;
       fplik.close();
    }
    return l_rodzajow_platnosci;
}

int generuj_paragony(int ile_paragonow, int l_platnosci)
{
    string sciezka = pobierz_sciezke() + "paragony.csv";
    fstream fplik;
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=0; i<ile_paragonow; i++)
       {
           fplik << i+1 << ",";    ///id_paragonu
           fplik << (rand()&l_platnosci-1)+1 << ",";   ///id_platnosci
           fplik << ( (rand()%10)+1 )*8;  ///do zaplaty


           fplik << endl; ///koniec rekordu
       }
       cout << "Dane wygenerowane do pliku " << sciezka.c_str() << endl;
       fplik.close();
    }
    return ile_paragonow;
}

unsigned int generuj_sprzedaz(unsigned int l_pism, unsigned int l_salonow, unsigned int l_dni, int l_paragonow, unsigned int l_sprzedawcow)
{
    string sciezka = pobierz_sciezke() + "sprzedaz.csv";
    fstream fplik;
    int id=1;
    unsigned int i=1;
    int j=1;

    unsigned int id_sprzedazy;
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(i=1; i<=l_salonow; i++)
       {
           for(j=1; j<=l_dni; j++)
           {
               int id_pisma = (rand()%l_pism)+1;

               fplik << id++ << ","; ///id_sprzedazy
               fplik << id_pisma << ","; ///id pisma
               fplik << i << ",";   ///id_salonu
               fplik << j << ",";   ///id_czasu
               fplik << (rand()%l_sprzedawcow)+1 << ","; /// id_sprzedawcy
               fplik << (rand()%l_paragonow)+1 << ","; /// id_paragonu

               ///suma zysku
               ///tu poki co jakas wartosc na lewo, ale przydaloby sie wejsc do pliku pismo.csv i odczytac cene pisma o podanym id
               fplik << ((rand()%36)+9) << ","; /// suma_zysku



           fplik << endl;

           }
        }
       cout << "Dane wygenerowane do pliku " << sciezka.c_str() << endl;
       fplik.close();
    }
    return i*j;
}

void sprawdzenie_czy_pliki_zamkniete()
{
    string nazwy_plikow[] = {"platnosci.csv","paragony.csv","rok.csv","miesiac.csv","dzien.csv","miasto.csv","salon.csv","sprzedawca.csv","tematyka.csv","pismo.csv", "sprzedaz.csv"};
    for(int i=0; i<11; i++)
    {
            fstream fplik;
            string sciezka = pobierz_sciezke() + nazwy_plikow[i];
            fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
            if(fplik.good()==true)
            {
            }
            else
            {
                cout << "UWAGA: Zamknij wszystkie pliki z danymi" << endl;
                exit(-1);
            }
            fplik.close();
    }
}

int main()
{
    sprawdzenie_czy_pliki_zamkniete();
    srand(time(NULL));

    cout << "dane beda zapisywane w " << pobierz_sciezke() << endl << endl;

    int ile_sprzedawcow = 50;
    int ile_zwolnionych_sprz = ile_sprzedawcow/4;
    generuj_sprzedawcow(ile_sprzedawcow,ile_zwolnionych_sprz);

    int ile_lat = generuj_lata(2012,1);
    int ile_miesiecy = generuj_miesiace(ile_lat);
    unsigned int ile_dni = generuj_dni(ile_miesiecy);


    int l_miast = 10;
    generuj_miasto(l_miast);
    int l_salonow = 30;
    generuj_salony(l_salonow,10);

    unsigned int l_pism = 20;
    int l_tematyk = generuj_tematyke();
    generuj_pisma(l_pism,l_tematyk);

    int l_platnosci = generuj_platnosci();
    int l_paragonow = generuj_paragony(2000,l_platnosci);


    unsigned int ile = generuj_sprzedaz(l_pism,l_salonow,ile_dni,l_paragonow,ile_sprzedawcow);

    cout << endl << endl << "w tabeli faktow jest " <<  ile << " wpisow" << endl << "gotowe" << endl;

   return 0;
}
