#include <iostream>
#include "generate_lib.h"

using namespace std;

int main()
{
    srand(time(NULL));
    for(int i=0; i<10; i++)
    cout << generate_date(1900,2000) << endl;

    for(int i=0; i<10; i++)
    cout << generate_name("kek") << endl;



   return 0;
}
