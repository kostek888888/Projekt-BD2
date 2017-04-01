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


string generate_date(int od_rok, int do_rok)
{

    stringstream streamData;

    ///year
    streamData << (rand()%(do_rok-od_rok) )+od_rok << "-";

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

string generate_name(string name_end)
{

    char letter = 0;
    stringstream streamData;

                          ///if name_end = ek
                          ///name = letter + ek
                          letter = (rand() % 25) +65;
                          streamData << letter << name_end;


    string data = streamData.str();
    return data;
}

string generate_name(int sex_0_for_man_else_for_woman)
{

    char letter = 0;
    stringstream streamData;

                    if(sex_0_for_man_else_for_woman==0) ///M
                      {
                          letter = (rand() % 25) +65;
                          streamData << letter << "mek";
                      }
                      else   ///F
                      {
                          letter = (rand() % 25) +65;
                          streamData<< letter << "mka";
                      }

    string data = streamData.str();
    return data;
}


