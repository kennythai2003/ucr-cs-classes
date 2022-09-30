#include <bits/stdc++.h>
using namespace std;

int main ()
{
    //getting T
    long long int gameDuration;
    cin >> gameDuration;
    cin.ignore();

   //getting n
   long long int upIntervals;
   cin >> upIntervals;
   cin.ignore();
   
   //getting m
   long long int downIntervals;
   cin >> downIntervals;
   cin.ignore();   
   
   long long int timeA = 0;
   long long int timeB = 1;
   long long int points = 0;
   int rainbow = 0;

   vector< pair <long long int, long long int> > timeframes;
   vector<int> rainbows;
   timeframes.push_back(make_pair(timeA, timeB));
   
    for (long long int i = 0; i < upIntervals; ++i)
    {
        cin >> timeA;
        cin.ignore();
        cin >> timeB;
        cin.ignore();
        cin >> rainbow;
        cin.ignore();

        timeframes.push_back(make_pair(timeA, timeB));
        rainbows.push_back(rainbow);

        if (rainbow == 0)
        {
          points += (timeB - timeA) + 1;  
        }
        if (rainbow == 1)
        {
          points += 3 * (timeB - timeA + 1);   
        }
    }

    for (long long int i = 0; i < downIntervals; ++i)
    {
        cin >> timeA;
        cin.ignore();
        cin >> timeB;
        cin.ignore();
        cin >> rainbow;
        cin.ignore();
            
        if (rainbow == 0)
        {
          for (int i = 0; i < timeframes.size(); ++i)
          {
            if(timeframes[i].first() <= timeA && timeB <= timeframes[i].second())
            {
                
            }
          }          
        }
        if (rainbow == 1)
        {
          for (int i = 0; i < timeframes.size(); ++i)
          {
            if(timeframes[i].first() <= timeA && timeB <= timeframes[i].second())
            {
                
            }
          } 
        }
    }
}