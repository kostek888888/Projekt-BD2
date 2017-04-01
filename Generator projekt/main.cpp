#include <iostream>
#include "generate_lib.h"

using namespace std;

int main()
{
    srand(time(NULL));
    ///rok randomowo
    for(int i=0; i<10; i++)
    cout << generate_date() << endl;

    cout << endl;

    ///rok od podanego do podanego
    for(int i=0; i<10; i++)
    cout << generate_date(1900,2000) << endl;

    cout << endl;

    ///imie lub nazwisko. Jako parametr koncowka nazwiska w wersji dla mezczyzn i dla kobiet potem juz generuje automatycznie
    for(int i=0; i<10; i++)
    cout << generate_name("ski","ska") << endl;



   return 0;
}
