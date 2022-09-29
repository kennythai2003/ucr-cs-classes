#include <bits/stdc++.h>

// #include <vector>
// #include <iostream>

using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);    
 
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
 
    //
    //array for timeline of game
    //int timeframe[gameDuration] = {0};
    vector<long long int> timeframe(gameDuration, 0);
    //test
    // for (int i = 0; i < gameDuration; ++i)
    // 
    //     printf("%d", time[i]);
    // }
    int timeA = 0;
    int timeB = 0;
    int rainbow = 0; 
 
    for (long long int i = 0; i < upIntervals; ++i)
    {
        cin >> timeA;
        cin.ignore();
        cin >> timeB;
        cin.ignore();
        cin >> rainbow;
        cin.ignore();
 
        if (rainbow == 0)
        {
            for (timeA; timeA <= timeB; ++timeA)
            {
                timeframe.at(timeA) = 1;
            }
        }
        if (rainbow == 1)
        {
            for (timeA; timeA <= timeB; ++timeA)
            {
                timeframe.at(timeA) = 3;
            }
        }
    }
    
//use two pointers to see overlap and replace scores if needed


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
            for (timeA; timeA <= timeB; ++timeA)
            {
                if (timeframe.at(timeA) != 3)
                {
                    timeframe.at(timeA) = 1;
                }
            }
        }
        if (rainbow == 1)
        {
            for (timeA; timeA <= timeB; ++timeA)
            {
                timeframe.at(timeA) = 3;
            }
        }
    //    cout << timeA << " " << timeB << " " << rainbow << endl;     
    }
        long long int sum = 0;
        for (int i = 0; i < timeframe.size(); ++i)
        {
        //    cout << i << ": " << timeframe[i] << endl;
            sum += timeframe.at(i);
        }   
        printf("%d\n", sum);
}
