#include <array>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
   

using namespace std;



int main() {

  // create and array of size n
  int numNames;
  // cout << "Enter how many names you want: " << endl;
  cin >> numNames;


  // Initialize house vectors
    vector<string> skull1;
    vector<string> skull2;
    vector<string> skull3;

  string dummyClear;
  getline(cin, dummyClear);
  int place = 0;
  int highestpts = 0;
  string skullwin;
  string numskull;
  for (int i = 0; i < numNames; i++) {
    
    string schoolAndpnts;
    getline(cin, schoolAndpnts);

    // Parse tokens
    int indexOfSpace = schoolAndpnts.find(" ");
    numskull = schoolAndpnts.substr(0, indexOfSpace);
    string pts = schoolAndpnts.substr(indexOfSpace + 1,    schoolAndpnts.size());
    int ptscompare = stoi(pts);


    if ( highestpts < ptscompare)
    {
      highestpts = ptscompare;
      place = i+1; 
      skullwin = numskull;
    }
    // Assign skulls
    if (numskull.compare("1") == 0) {
      skull1.push_back(numskull);
    } 
    else if (numskull.compare("2") == 0) {
      skull2.push_back(numskull);
    }
    else if (numskull.compare("3") == 0) {
      skull3.push_back(numskull);
    }

  }

  // Print results
  cout << numNames<<endl;
  cout << place << endl;
    if (skullwin.compare("1") == 0) {
      cout<< skull1.size();
    } 
    else if (skullwin.compare("2") == 0) {
      cout<< skull2.size();
    }
    else if (skullwin.compare("3") == 0) {
      cout<< skull3.size();
    }
  
  
  return 0;

}