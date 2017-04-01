#include <iostream>
#include "generate_lib.h"
#include <fstream>
#include <sstream>


using namespace std;

///pobiera sciezke do projektu z uwzglednieniem nazwy uzytkownika
string pobierz_sciezke()
{
       stringstream stream;

       stream << "C:\\Users\\" << getenv("USERNAME") << "\\Documents\\Github\\Projekt-BD2\\SQLLDR\\";
       return stream.str();
}

void generuj_osoby(unsigned int ile)
{
    unsigned int p_ile = ile;
    string sciezka = pobierz_sciezke() + "osoby.csv";
    fstream fplik;
    srand(time(NULL));
    fplik.open(sciezka.c_str(),ios::in | ios::out | ios::trunc);
    if(fplik.good()==true)
    {
       for(unsigned int i=1; i<=ile; i++)
       {
           fplik << i << "," << generate_name("mek","ski","mka","ska") << ",";
           fplik << generate_date(1945,2000) << "," << generate_pesel() << "," << generate_street("owska") << ",";
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
       generuj_osoby(p_ile);
    }
}




int main()
{
    srand(time(NULL));

    cout << "dane beda zapisywane w " << pobierz_sciezke() << endl;


    unsigned int ile;
    cout << endl << "ile wpisow do tabeli Osoby chcesz wygenerowac: ";
    cin >> ile;
    generuj_osoby(ile);

   }


   return 0;
}
