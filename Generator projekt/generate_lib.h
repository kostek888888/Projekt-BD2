/*
################################################################################
#                                                                              #
#    Author: https://github.com/wojtek9502/                                    #
#    Email: wojtek.klusek2@gmail.com                                           #
#    Year: 2017                                                                #
#                                                                              #
################################################################################
*/


#include <cstdlib>
#include <sstream>
#include <climits>
#include <ctime>
using namespace std;

time_t get_cur_year()
{
   time_t now = time(0);
   tm *ltm = localtime(&now);

   return 1900+ltm->tm_year;
}

string generate_date()
{

    stringstream streamData;

    ///year
    streamData << (rand()%get_cur_year() )+1
     << "-";

    ///if month <10 then month e.g. 02
    int month=(rand()%12)+1;
    if(month <10)
    {
        streamData << "0" << month;
    }
    else
        streamData << month;

    streamData << "-";

    ///day. From 1 to 28
    ///if day <10 then day e.g. 02
    int day=(rand()%28)+1;
    if(day<10)
    {
        streamData << "0" << day;
    }
    else
        streamData << day;

    return streamData.str();;
}


string generate_date(int from_year, int to_year)
{

    stringstream streamData;

    ///year
    streamData << (rand()%(to_year-from_year) )+from_year << "-";

    ///if month <10 then month e.g. 02
    int month=(rand()%12)+1;
    if(month <10)
    {
        streamData << "0" << month;
    }
    else
        streamData << month;

    streamData << "-";

    ///day. From 1 to 28
    ///if day <10 then day e.g. 02
    int day=(rand()%28)+1;
    if(day<10)
    {
        streamData << "0" << day;
    }
    else
        streamData << day;

    return streamData.str();
}

string generate_street(string street)
{

    char letter = 0;
    stringstream streamData;

    letter = (rand() % 25) +65;
    streamData << "Ul. " << letter << street << " ";
    streamData << (rand()%99)+1;
    string data = streamData.str();
    return data;
}

string generate_name(string male_surname_end, string male_name_end, string female_surname_end, string female_name_end)
{

    char letter = 0;
    stringstream streamData;
    int gender = rand()%2;

            if(gender==0) ///M
            {
                letter = (rand() % 25) +65;
                          streamData << letter << male_surname_end;

                streamData << ",";
                letter = (rand() % 25) +65;
                          streamData << letter << male_name_end;
            }
            else   ///F
            {
                letter = (rand() % 25) +65;
                streamData<< letter << female_surname_end;

                streamData << ",";
                letter = (rand() % 25) +65;
                          streamData << letter << female_name_end;
            }

    return streamData.str();
}

long long generate_pesel()
{
    int p1;
    long long p2,p3;

    p1 = (rand()%5)+4;
    p2 = (rand()%99999)+10000; p2*=100000;

    p3 = ((rand()%(LLONG_MAX))+10000000000);
    p3 *= p1;
    p3 += p2;

    return p3;
}

long long generate_phone_number()
{
    int n1;
    long long n2,n3;

    n1 = (rand()%9)+1;
    n2 = (rand()%900)+100; n2 *= 100000;

    n3 = ((rand()%(LLONG_MAX))+100000000);
    n3 *= n1;
    n3 += n2;


    return n3;



}
