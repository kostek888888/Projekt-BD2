#include <iostream>
#include "generate_lib.h"
#include <fstream>

using namespace std;


string pobierz_sciezke()
{
///pobiera z pliku sciezka.txt w glownym folderze projektu sciezke do ktorej zapisywane beda pliki z danymi bo juz mi sie tego nie chce kopiowac
///Kazdy niech sobie zmieni na np C:\Users\x\Documents\GitHub\Projekt-BD2\SQLLDR\. Pliki z danymi maja isc do folderu SQLLDR

    fstream plik;
    string sciezka_dla_danych;
    plik.open("sciezka.txt", std::ios::in | std::ios::out);
    if( plik.good() == true )
    {
        getline(plik,sciezka_dla_danych);
        plik.close();
        return sciezka_dla_danych;
    }
    else
    {
        ///gdyby nie bylo pliku to utworzy
       ofstream utworz_plik;
       utworz_plik.open("sciezka.txt");
       utworz_plik.close();
       fstream plik;
       plik.open("sciezka.txt", std::ios::in | std::ios::out);
       plik << "C:\\";
       plik.close();
       sciezka_dla_danych = pobierz_sciezke();
       return sciezka_dla_danych;
    }

}

void generuj_osoby(unsigned int ile)
{
    unsigned int p_ile = ile;
    string sciezka = pobierz_sciezke() + "\\osoby.csv";
    fstream fplik;
    srand(time(NULL));
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=1; i<=ile; i++)
       {
           fplik << i << "," << generate_name("mek","mka") << "," << generate_name("ski", "ska") << ",";
           fplik << generate_date(1945,2000) << "," << generate_pesel() << "," << "Ul. " << generate_name("owska","owa") << (rand()%99)+1 << ",";
           fplik << generate_phone_number() << endl;
       }
       fplik << endl << endl;
       cout << "Dane wygenerowane do pliku " << sciezka.c_str() << endl;
       fplik.close();
    }
    else
    {
       ///gdyby nie bylo pliku to utworzy
       ofstream utworz_plik;
       utworz_plik.open(sciezka.c_str());
       utworz_plik.close();
       fstream plik;
       plik.open(sciezka.c_str(), std::ios::in | std::ios::out);
       plik.close();
       generuj_osoby(p_ile);
    }
}


int main()
{
    srand(time(NULL));
    cout << "dane beda zapisywane w " << pobierz_sciezke() << endl << "Jesli odpalasz ten program po raz pierwszy zmien zawartosc pliku sciezka.txt" << endl;


    unsigned int ile;
    cout << endl << "ile wpisow do tabeli Osoby chcesz wygenerowac: ";
    cin >> ile;
    generuj_osoby(ile);

   return 0;
}
