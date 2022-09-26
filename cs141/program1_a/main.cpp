#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);  
   
    long long int jigsawA = 0;
    long long int jigsawB = 0;
   
    cin >> jigsawA;
    jigsawB = jigsawA;
    cin.ignore();
 
    long long int rounds = 0;
    cin >> rounds;
    cin.ignore();
 
    bool aliveA = true;
    bool aliveB = true;
    bool deadA = true;
    bool deadB = true;
    long long int roundWonA = 0;
    long long int roundWonB = 0;
 
    int rollA1 = 0;
    int rollA2 = 0;
    int rollB1 = 0;
    int rollB2 = 0;
    int dmgA = 0;
    int dmgB = 0;
 
    for (long long int i = 1; i <= rounds; ++i)
    {
        cin >> rollA1;
        cin.ignore();        
        cin >> rollA2;
        cin.ignore();        
 
        cin >> rollB1;
        cin.ignore();        
        cin >> rollB2;
        cin.ignore();
 
        dmgA = rollA1 * rollA2;
        dmgB = rollB1 * rollB2;
        jigsawA -= dmgB;
        jigsawB -= dmgA;
 
        if (jigsawA <= 0)
        {
            aliveA = false;
            if (deadA)
            {
                roundWonB = i;
                deadA = false;
            }
        }
        if (jigsawB <= 0)
        {
            aliveB = false;
            if (deadB)
            {
                roundWonA = i;
                deadB = false;
            }
        }
    }
/*
cases
1. both teams alive
2&3. one team is alive; other dead
4&5. both alive, one team wins
6. both alive rounds won is the same
*/
    if (aliveA && aliveB)
    {
        printf("Oh no!");
    }
    else if (aliveA && aliveB == false)
    {
    //    cout << "Team 1 wins at round" << roundWonA << "!" << endl;
        printf("Team 1 wins at round %d!", roundWonA);
    }
    else if (aliveB && aliveA == false)
    {
        cout << "Team 2 wins at round" << roundWonB << "!" << endl;
        printf("Team 2 wins at round %d!", roundWonB);
    }
    else if (aliveB == false && aliveA == false)
    {
        if (roundWonA == roundWonB)
        {
        //    cout << "It's a tie at round " << roundWonA << "!" << endl;
            printf("It's a tie at round %d!", roundWonA);
        }
        else if (roundWonA < roundWonB)
        {
        //    cout << "Team 1 wins at round " << roundWonA << "!" << endl;    
            printf("Team 1 wins at round %d!", roundWonA);        
        }
        else
        {
        //    cout << "Team 2 wins at round " << roundWonB << "!" << endl;
            printf("Team 2 wins at round %d!", roundWonB);            
        }
    }
    // if (deadA && deadB)
    // {
    //     cout << "Oh no!" << endl;
    // }
    // else if (roundWonA == roundWonB && roundWonA > 0)
    // {
    //     cout << "It's a tie at round " << roundWonA << "!" << endl;
    // }
    // else if (roundWonA < roundWonB)
    // {
    //     cout << "Team 1 wins at round " << roundWonA << endl;
    // }
    // else if (roundWonB < roundWonA)
    // {
    //     cout << "Team 2 wins at round " << roundWonB << endl;
    // }
//    cout << rollA1 << " " << rollA2 << " " << rollB1 << " " << rollB2 << endl;
//    cout << dmgA << " " << dmgB << " " << jigsawA << " " << jigsawB << endl;
}
 

