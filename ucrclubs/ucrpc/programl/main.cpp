#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
 
  long long trainCars;
  cin >> trainCars;
  cin.ignore();
 
  vector<long long> trains (100001);
  vector<bool> real (100001, false);
  
  long long trainDefense;
  long long trainPosition;
  
  for (int i = 0; i < trainCars; i++)
    {
        cin >> trainPosition;
        //trainPosition -= 1;
        cin.ignore();
 
        cin >> trainDefense;
        cin.ignore();
      
        trains.at(trainPosition) = trainDefense;
        real.at(trainPosition) = true;
    }   
 
  long long attacks;
  cin >> attacks;
  cin.ignore();
  
  long long attackValue;
  long long centralPosition;
  long long range;
  long long trainsDestroyed;
  vector<long long> trainsDestroyV;
 
  long long modded1;
  long long modded2;
  
  for (int i = 0; i < attacks; i++)
    {
        cin >> attackValue;
        cin.ignore();
        cin >> range;
        cin.ignore();
        cin >> centralPosition;
        cin.ignore();
        modded1 = range;
        modded2 = range;
        trainsDestroyed = 0;
        if (centralPosition - range < 0) {
          modded1 = range - ((centralPosition - range) * -1);
        //  cout << modded1;
        }   
        if (centralPosition + range > 10) {
          modded2 = 10 - centralPosition;
        }  
        for (int i = centralPosition - modded1; i <= centralPosition + modded2; i++)
          {
           //  cout << "before "<< i << " train: " << trains.at(i) << endl;
             trains.at(i) -= attackValue;
             if (trains.at(i) > 0 && real.at(i) == true){
                trains.at(i) += attackValue;
             }
           //  cout << "after "<< i << " train: " << trains.at(i) << endl;
 
            if(trains.at(i) <= 0 && real.at(i) == true)
            {
                 trainsDestroyed += 1;
                 real.at(i) = false;
            }
          }
       // cout << "this attack round " << i << ": " << trainsDestroyed << endl;
        trainsDestroyV.push_back(trainsDestroyed);
    }
  //case 1
        
        for (int i = 0; i < trainsDestroyV.size(); i++)
        {
           // cout << trainsDestroyV.at(i) << " ";
            printf("%d\n", trainsDestroyV.at(i));
        }
  //case 2
 
    return 0;
}