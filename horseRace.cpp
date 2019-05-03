
//#include "HorseRace.h"

// libraries
#include<iostream>
    using std::cin;
    using std::cout;
    using std::endl;

#include<string>
    using std::string;

#include <sstream>
    using std::ostringstream;

#include<unistd.h>

#include<cstdlib>
#include<ctime>

#include<vector>
    using std::vector;

const int T = 270000; // constant time for running
// end of libraries


/**
 * @brief       race()
 *
 * @detailed    randomly display a simulation of a horse racing
 *
 * @param[out/ref]      first       the integer of the first place horse
 * @param[out/ref]      second      the integer of the second place horse
 * @param[out/ref]      third       the integer of the third place horse
 *
 * @return      void
 */
 void race(int& first, int& second, int& third)
 {
     srand(time(0));

     vector<int> horse(8); /*= {1,2,3,4,5,6,7,8};*/
     for(int i = 0; i < 8; i++)
     {
         horse[i] = i+1;
     }
     string sHorse[] = {"\033[37;40m♞ 1\033[0m", "\033[37;41m♞ 2\033[0m", "\033[37;46m♞ 3\033[0m", "\033[37;44m♞ 4\033[0m",
     "\033[37;45m♞ 5\033[0m",   "\033[37;42m♞ 6\033[0m", "\033[37;43m♞ 7\033[0m", "\033[30;47m♞ 8\033[0m"};

     int check[] = {0,0,0,0,0,0,0,0};

     vector<string> winner;
     vector<string> lines;

     vector<int> winHorse;

     string str = "";

     for(int i = 1; i <=15; i++)
     {
         system("clear");

         cout << "\n\n\n";

         for(int n = 1; n <= i; n++) //get empty space
         {
             if(n == 1 && i > 1)
             {
                 cout << "S>\t\t\t  START HERE";
             }

             else if(n == 1)
             {
                 cout << "S>\t";
             }

             else
             {
                 cout << "•)\t";
             }

             if(n < i)
             {
                 if(n > 7)
                 {
                     cout << lines[n-1];
                 }
                 cout << endl;
             }
         }

         for(int j = 0; j < 8; j++)
         {
             if(sHorse[j] == "0")
             {
                 cout << "\t";
             }

             else
             {
                 cout << sHorse[j] << "\t";
             }
         }
         cout << endl;

         usleep(T/4);
         if(i == 1)
         {
             usleep(T*8);
         }

         str.clear();

         if(i > 7)
         {
             int index = rand() % horse.size();

             winner.push_back(sHorse[horse.at(index)-1]);
             winHorse.push_back(horse.at(index));

             for(int c = 0; c < 8; c++)
             {
                 check[c] = 0;
             }

             check[horse.at(index)-1] = 1;

             for(int c = 0; c < 8; c++)
             {
                 if(check[c] == 0)
                 {
                     str = str + "\t";
                 }
                 else
                 {
                     str = str + sHorse[horse.at(index)-1];
                 }
             }

             sHorse[horse.at(index)-1] = "0";
             horse.erase(horse.begin() + index);
         }

         else
         {
             str = "\n";
         }

         lines.push_back(str);
     }

     for(int i = 0; i < 20; i++)
     {
         system("clear");
         cout << "\n\n\n";

         for(int ii = 0; ii < i+8; ii++)
         {
             if(ii == 0 )
             {
                 cout << "S>\t\t\t  START HERE";
             }

             else if(ii > 13 && ii < 23)
             {
                 if(ii == 14)
                 {
                     cout << "\033[37mR\033[0m)\t";
                 }

                 else if(ii == 15)
                 {
                     cout << "\033[37mO\033[0m)\t";
                 }

                 else if(ii == 16)
                 {
                     cout << "\033[37mT\033[0m)\t";
                 }

                 else if(ii == 17)
                 {
                     cout << "\033[37mH\033[0m)\t";
                 }

                 else if(ii == 18)
                 {
                     cout << "•)\t";
                 }

                 else if(ii == 19)
                 {
                     cout << "\033[37mP\033[0m)\t";
                 }

                 else if(ii == 20)
                 {
                     cout << "•)\t";
                 }
                 else if(ii == 21)
                 {
                     cout << "\033[37mI\033[0m)\t";
                 }
                 else
                 {
                     cout << "\033[37mN\033[0m)\t";
                 }
             }
             else
             {
                 cout << "•)\t";
             }
             /////-----

             cout << "\n";
         }

         for(unsigned long j = 7; j < lines.size(); j++)
         {
             ///-----
             if(i == 14 && (j == lines.size() - 1))
             {
                 cout << ">F\t";
             }

             else
             {
                 cout << "•)\t";
             }

             cout << lines[j] << endl;
         }

         usleep(T/4);

         //make horse run slower as they get close to finish line
         //if(i > 14)
         //{
         //    usleep(T/3);
         //}
         //if(i > 17)
         //{
         //    usleep(T/2);
         //}

     }

     string p = "\033[37;40m  \033[0m"; //white
     string e = "\033[30;47m  \033[0m"; //black
     //print out finish line================
     cout << "       " << p << e << p << e << p << e << p << e << p << e << p
          << e << p << e << p << e << p << e << p << e << p << e << p << e << p
         << e << p << e << p << e << endl;
     usleep(T/4);
     cout << "       " << e << p << e << p << e << p << e << p << e << p << e
          << p << "FINISH  LINE" << e << p << e << p << e<< p << e << p
          << e << p << e << p <<  "\n\n";
     usleep(T*3);
     //===========================================

     //print out and pass back the winner resutl
     for(int i = 0; i < 6; i++)
     {
         if(i == 2)
         {
             cout << "1ST Place: " << winner[7];
             first = winHorse[7];
         }
         else if(i == 3)
         {
             cout << "2ND Place: "<< winner[6];
             second = winHorse[6];
         }
         else if(i == 4)
         {
             cout << "3RD Place: "<< winner[5];
             third = winHorse[5];
         }

         cout << endl;

         usleep(T);
     }
 }

 int main()
 {
     int _1, _2, _3;

     cout << "Press ENTER ";
     cin.get();

     race(_1, _2, _3);

     return 0;
 }
