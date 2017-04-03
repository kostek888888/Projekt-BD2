#include <iostream>
#include "generate_lib.h"
#include <fstream>
#include <sstream>


using namespace std;

///pobiera sciezke do projektu z uwzglednieniem nazwy uzytkownika
string pobierz_sciezke()
{
       stringstream stream;
       string user_name = getenv("USERNAME");

       if(user_name=="Wojciech")
         stream << "C:\\Users\\" << user_name << "\\Documents\\Github\\Projekt-BD2\\SQLLDR\\";
       else if(user_name=="koste")
<<<<<<< HEAD
        stream << "C:\\Users\\koste\\OneDrive\\Informatyka\\Semestr 4\\Bazy Danych 2\\Projekt\\Projekt-BD2\\SQLLDR";
=======
        stream << "C:\\Users\\koste\\OneDrive\\Informatyka\\Semestr 4\\Bazy Danych 2\\Projekt\\Projekt-BD2\\SQLLDR\\";
>>>>>>> origin/master
        else
        stream << "C:\\";

       return stream.str();
}

unsigned int generuj_osoby(unsigned int p_ile)
{
    unsigned int ile = p_ile;
    string sciezka = pobierz_sciezke() + "osoby.csv";
    fstream fplik;
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=1; i<=ile; i++)
       {
           fplik << i << "," << generate_name("mek","ski","mka","ska") << ",";
           fplik << generate_date(1945,2000) << "," << generate_pesel() << "," << generate_address("owska") << ",";
           fplik << generate_phone_number() << endl;
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
       generuj_osoby(p_ile);
       cout << "plik jest otwarty w innym programie";
    }
    return ile;
}

int generuj_kierownikow(unsigned int n, int &p_ile_zw_kier)
{
    string sciezka = pobierz_sciezke() + "kierownik.csv";
    fstream fplik;
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=0; i<n; i++)
       {
           fplik << i+1 << "," << i+1 << ",";
           fplik << generate_date(2000,2005) << ",";

           ///czasem ma date zwolnienia czasem nie
           if (i<p_ile_zw_kier)
              fplik << generate_date(2006,2017);

           fplik << ",";
           fplik << ( (rand()%6)+5 ) * 1000;
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
    return n;
}

void generuj_sprzedawcow(unsigned int &n, unsigned int ile_kierownikow, int p_ile_zw_sprz, int p_ile_zw_kier)
{
    unsigned int id_kierownika = p_ile_zw_kier;
    unsigned int id_osoby = ile_kierownikow;

    string sciezka = pobierz_sciezke() + "sprzedawca.csv";
    fstream fplik;
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=0; i<n; i++)
       {
           id_osoby++;
           id_kierownika++;

           if(id_kierownika>ile_kierownikow)
                id_kierownika = p_ile_zw_kier++;

           fplik << i+1 << "," << id_osoby << "," << id_kierownika << ",";
           fplik << generate_date(2000,2005) << ",";

           ///czasem ma date zwolnienia czasem nie
           if (i<p_ile_zw_sprz)
              fplik << generate_date(2006,2017);

           fplik << ",";
           fplik << ( (rand()%3)+2 ) * 1000 << ","; ///pensja

           if (i<p_ile_zw_sprz)    ///ocena 1 dla tych zwolnionych
              fplik << 1;
           else
              fplik << ( rand()%4 )+2;     ///ocena dla reszty od 2 do 5


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

void generuj_czas(int ile_rekordow, int od_roku)
{
    int miesiac = 1;
    int dzien = 0;
    string sciezka = pobierz_sciezke() + "czas.csv";
    fstream fplik;
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=1; i<=ile_rekordow; i++)
       {
           dzien++;
           fplik << i << ",";


            ///data
           ///rok
           if(miesiac == 12 && dzien > 28)
           {
               miesiac = 0;
               od_roku++;
           }

           fplik << od_roku << "-";

           ///miesiac
           if(dzien > 28)
           {
                miesiac++;
                dzien=1;
           }


           if(miesiac<10)
               fplik << 0 << miesiac;
           else
            fplik << miesiac;

           fplik<< "-";


           ///dzien
           if(dzien<10)
               fplik << 0 << dzien;
           else
            fplik << dzien;


           fplik << ",";


           ///kwartal
           if(miesiac<=3)
            fplik << 1;
           if(miesiac>3 && miesiac <=6)
            fplik << 2;
           if(miesiac>6 && miesiac <=9)
            fplik << 3;
           if(miesiac>9)
            fplik << 4;

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
       cout << "plik jest otwarty w innym programie";
    }
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

unsigned int generuj_dodatki(unsigned int l_pism)
{
    unsigned int l_dodatkow= l_pism/4;
    string sciezka = pobierz_sciezke() + "dodatek.csv";
    fstream fplik;


    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=0; i<l_dodatkow; i++)
       {
           char letter = (rand() % 25) +65;
           fplik << i+1 << ","; ///id_dodatku
           fplik << "Dodatek " << letter << ",";

           ///maklad
           int naklad = ((rand()%5)+5);
           naklad *= ((rand()%50)+10);
           naklad *=100;
           fplik << naklad;

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
    return l_dodatkow;
}

void generuj_tematyke(unsigned int l_pism)
{
    string sciezka = pobierz_sciezke() + "tematyka.csv";
    fstream fplik;
    string nazwy_tematyk[] = {"Wedkarstwo","Informatyka", "Prawo", "Sport", "Motoryzacja", "Budownictwo", "Gielda", "Mlodzierzowe", "Polityka", "Wiadomosci krajowe", "Gry wideo", "Muzyka"};

    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=0; i<l_pism; i++)
       {
           fplik << i+1 << ","; ///id_tematyki

           ///tematyka
           int val = rand()%5;
           fplik << nazwy_tematyk[val] << ",";
           fplik << "Opis:" << ",";
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

void generuj_pisma(unsigned int l_pism, unsigned int l_dodatkow)
{
    string sciezka = pobierz_sciezke() + "pismo.csv";
    fstream fplik;
    string okres_wydawania[] = {"Dziennik", "Tygodnik", "Dwutygodnik", "Miesiecznik", "Kwartalnik", "Rocznik"};

    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       ///najpierw stworzy pisma z id dodatku
       for(unsigned int i=0; i<l_dodatkow; i++)
       {
           ///id pisma, id_dodatku losowane z puli id_dodatków, id_tematyki
           fplik << i+1 << "," << i+1 << "," << i+1 << ",";

           ///okres wydawania
           int val = rand()%5;
           fplik << okres_wydawania[val] << ",";

           ///nazwa
           char letter = (rand() % 25) +65;
           fplik << okres_wydawania[val] << " " << letter << ","; ///wyjdzie np Tygodnik A, Rocznik B itd.

           ///naklad
           fplik << ( (rand()%9) +1 ) * ((rand()%40)+10) * 40 << ",";

           ///cena
           if(okres_wydawania[val]=="Rocznik" || okres_wydawania[val]=="Kwartalnik")
           fplik << ((rand()%15)+30) * 1.0; ///kosztuje od 30.0 do 45.0 zl

           if(okres_wydawania[val]=="Miesiecznik" || okres_wydawania[val]=="Dwutygodnik")
           fplik << ((rand()%14)+15) * 1.0; ///kosztuje od 15.0 do 29.0 zl

           if(okres_wydawania[val]=="Tygodnik" || okres_wydawania[val]=="Dziennik")
           fplik << ((rand()%6)+9) * 1.0; ///kosztuje od 9 do 15 zl

           fplik << endl;
       }






       ///pisma bez dodatkow
        for(unsigned int i=l_dodatkow; i<l_pism; i++)
       {
            ///id pisma, id_dodatku losowane z puli id_dodatków, id_tematyki
           fplik << i+1 << "," << "," << i+1 << ",";

           ///okres wydawania
           int val = rand()%5;
           fplik << okres_wydawania[val] << ",";

           ///nazwa
           char letter = (rand() % 25) +65;
           fplik << okres_wydawania[val] << " " << letter << ","; ///wyjdzie np Tygodnik A, Rocznik B itd.

           ///naklad
           fplik << ( (rand()%9) +1 ) * ((rand()%30)+10) * 100 << ",";

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


void generuj_sprzedaz(unsigned int l_sprzedazy, unsigned int l_pism, unsigned int l_salonow, unsigned int l_czasow, unsigned int l_sprzedawcow)
{
    string sciezka = pobierz_sciezke() + "sprzedaz.csv";
    fstream fplik;
    int id=1;

    unsigned int id_sprzedazy;
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=1; i<=l_salonow; i++)
       {
           for(int j=1; j<=l_czasow; j++)
           {
               int sprzedanych_gazet = rand()%30;
               int id_pisma = (rand()%l_pism)+1;

               fplik << id++ << ","; ///id_sprzedazy
               fplik << id_pisma << ","; ///id pisma
               fplik << i << ",";   ///id_salonu
               fplik << j << ",";   ///id_czasu
               fplik << (rand()%l_sprzedawcow)+1 << ","; /// l_sprzedawcow
               fplik << sprzedanych_gazet << ",";   ///ilosc sprzedanej gazety w danym dniu w danym salonie

               ///suma zysku
               ///tu poki co jakas wartosc na lewo, ale przydaloby sie wejsc do pliku pismo.csv i odczytac cene pisma o podanym id
                if(sprzedanych_gazet==0)
                    fplik << 0;
                else
                    fplik << sprzedanych_gazet*2;


           fplik << endl;

           }
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
void sprawdzenie_czy_pliki_zamkniete()
{
    string nazwy_plikow[] = {"czas.csv","kierownik.csv","miasto.csv","osoby.csv","salon.csv","sprzedawca.csv","dodatek.csv","tematyka.csv","pismo.csv, sprzedaz.csv"};
    for(int i=0; i<8; i++)
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

    cout << "dane beda zapisywane w " << pobierz_sciezke() << endl;
    unsigned int ile_osob = generuj_osoby(40);

    int ile_zw_kier = ile_osob/16;
    unsigned int ile_kierownikow = generuj_kierownikow(ile_osob/4,ile_zw_kier);

    unsigned int ile_sprzedawcow = ile_osob-ile_kierownikow;
    int ile_zw_sprz = ile_sprzedawcow/10;
    generuj_sprzedawcow(ile_sprzedawcow,ile_kierownikow,ile_zw_sprz,ile_zw_kier);


    int l_miast = 10;
    generuj_miasto(l_miast);
    int l_salonow = 30;
    generuj_salony(l_salonow,10);

    int ile_czasow=167;
    generuj_czas(ile_czasow,2005);


    unsigned int l_pism = 10;
    unsigned int l_dodatkow = generuj_dodatki(l_pism); ///bedzie 4 razy mniej dodatkow niz pism
    generuj_tematyke(l_pism);
    generuj_pisma(l_pism,l_dodatkow);

     unsigned int l_sprzedazy= ile_czasow * l_salonow;

    generuj_sprzedaz(l_sprzedazy,l_pism,l_salonow,ile_czasow,ile_sprzedawcow);


    cout << endl << endl << "w tabeli faktow jest " << l_sprzedazy << " wpisow" << endl << "gotowe" << endl;


    ///bedzie wpisane na sztywno w razie czego mozna odkomentowac

   /*
    unsigned int ile;
    cout << endl << "ile wpisow do tabeli Osoby chcesz wygenerowac: ";
    cin >> ile;
    unsigned int ile_osob = generuj_osoby(ile);

    int ile_zw_kier = ile_osob/16;
    unsigned int ile_kierownikow = generuj_kierownikow(ile_osob/4,ile_zw_kier);


    unsigned int ile_sprzedawcow = ile_osob-ile_kierownikow;
    int ile_zw_sprz = ile_sprzedawcow/10;
    generuj_sprzedawcow(ile_sprzedawcow,ile_kierownikow,ile_zw_sprz,ile_zw_kier);

    cout << endl << "ile wpisow do tabeli Miasta chcesz wygenerowac: ";
    int l_miast;
    cin >> l_miast;
    generuj_miasto(l_miast);


    cout << endl << "ile wpisow do tabeli Salon chcesz wygenerowac: ";
    unsigned int l_salonow;
    cin >> l_salonow;
    generuj_salony(l_salonow,l_miast);


    int potrzeba = (5000/l_salonow)+1;
    cout << endl << endl << "Mamy " << l_salonow << " salonow" << endl;
    cout << "Potrzeba jeszcze co najmniej " << potrzeba << " wpisow do tabeli czas zeby miec ponad 5000 rekordow w tabeli Sprzedarz" << endl;

    cout << endl << "ile wpisow do tabeli Czas chcesz wygenerowac: ";
    unsigned int ile_czasow;
    cin >> ile_czasow;
    while(ile_czasow<potrzeba)
    {
        cout << "potrzeba co najmniej " << potrzeba << " wpisow w tabeli Czas";
        cin >> ile_czasow;
    }

    cout << "Od ktorego roku: ";
    int od_roku;
    cin >> od_roku;
    generuj_czas(ile_czasow,od_roku);




    cout << endl << "ile wpisow do tabeli Pisma chcesz wygenerowac: ";
    unsigned int l_pism;
    cin >> l_pism;
    unsigned int l_dodatkow = generuj_dodatki(l_pism); ///bedzie 4 razy mniej dodatkow niz pism
    generuj_tematyke(l_pism);
    generuj_pisma(l_pism,l_dodatkow);

    unsigned int l_sprzedazy= ile_czasow * l_salonow;

    generuj_sprzedaz(l_sprzedazy,l_pism,l_salonow,ile_czasow,ile_sprzedawcow);
    */

   return 0;
}
