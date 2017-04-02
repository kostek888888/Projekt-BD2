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
        tream << "C:\\Users\\koste\\OneDrive\\Informatyka\\Semestr 4\\Bazy Danych 2\\Projekt\\Projekt-BD2\\SQLLDR";
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


void sprawdzenie_czy_pliki_zamkniete()
{
    fstream fplik;
    string sciezka = pobierz_sciezke() + "czas.csv";
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


    sciezka = pobierz_sciezke() + "kierownik.csv";
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


    sciezka = pobierz_sciezke() + "miasto.csv";
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


    sciezka = pobierz_sciezke() + "osoby.csv";
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


    sciezka = pobierz_sciezke() + "salon.csv";
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


    sciezka = pobierz_sciezke() + "sprzedawca.csv";
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

int main()
{
    sprawdzenie_czy_pliki_zamkniete();
    srand(time(NULL));

    cout << "dane beda zapisywane w " << pobierz_sciezke() << endl;


    unsigned int ile;
    cout << endl << "ile wpisow do tabeli Osoby chcesz wygenerowac: ";
    cin >> ile;
    unsigned int ile_osob = generuj_osoby(ile);

    int ile_zw_kier = ile_osob/16;
    unsigned int ile_kierownikow = generuj_kierownikow(ile_osob/4,ile_zw_kier);


    unsigned int ile_sprzedawcow = ile_osob-ile_kierownikow;
    int ile_zw_sprz = ile_sprzedawcow/10;
    generuj_sprzedawcow(ile_sprzedawcow,ile_kierownikow,ile_zw_sprz,ile_zw_kier);

    cout << endl << "ile wpisow do tabeli Czas chcesz wygenerowac: ";
    cin >> ile;

    cout << "Od ktorego roku: ";
    int od_roku;
    cin >> od_roku;
    generuj_czas(ile,2005);

    cout << endl << "ile wpisow do tabeli Miasta chcesz wygenerowac: ";
    int l_miast;
    cin >> l_miast;
    generuj_miasto(l_miast);


    cout << endl << "ile wpisow do tabeli Salon chcesz wygenerowac: ";
    unsigned int l_salonow;
    cin >> l_salonow;
    generuj_salony(l_salonow,l_miast);




   return 0;
}
