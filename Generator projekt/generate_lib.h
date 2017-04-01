/*
################################################################################
#                                                                              #
#    Library to generation values for databases                                #
#                                                                              #
#    Author: https://github.com/wojtek9502/                                    #
#    Email: wojtek.klusek2@gmail.com                                           #
#    Year: 2017                                                                #
#                                                                              #
################################################################################
*/


#include <cstdlib>
#include <sstream>
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

    string data = streamData.str();
    return data;
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

    string data = streamData.str();
    return data;
}

string generate_name(string male_name_end, string female_name_end)
{

    char letter = 0;
    stringstream streamData;
    int gender = rand()%2;

                    if(gender==0) ///M
                      {
                          letter = (rand() % 25) +65;
                          streamData << letter << male_name_end;
                      }
                      else   ///F
                      {
                          letter = (rand() % 25) +65;
                          streamData<< letter << female_name_end;
                      }

    string data = streamData.str();
    return data;
}


