#include <iostream>

using namespace std;

int main() {

  int k;
  cin >> k;
  
  int gal = 0;
  int sic = 0;
  int knut = 0;
//There were 29 Knuts in one silver Sickle, and there were 17 Sickles to a Galleon.
  while( k > 492)
  {
    gal = gal+1;
    k = k - 493;
    
  }
  while( k > 28)
  {
    sic = sic + 1;
    k = k - 29;
  }

  if (k < 29)
  {
    knut = k;
  }


  cout << gal << " " << sic << " "<< knut << endl;
  
}