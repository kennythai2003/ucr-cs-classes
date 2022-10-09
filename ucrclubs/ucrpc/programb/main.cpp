#include <bits/stdc++.h> 
using namespace std;


int main() {
      ios_base::sync_with_stdio(false);
    cin.tie(0);

  string name1;
  string name2;
  string stop = "caught";
  
  int pts1 = 0;
  int pts2 = 0;
  
  cin >> name1; 
  cin >> name2;

  string i;
  string j;
  string winhouse;

    vector<string> l;

bool done = true;

  while (done)
    {
        cin >> i;
        cin.ignore();
        l.push_back(i);

        if (i == name1)
        {
            pts1 +=  10;
      //      cout << name1 << " " << pts1 << endl;
        }

        if( i == name2)
        {
           // cout << "10 points to " << name2 << endl;
            pts2 += 10;
      //      cout << name2 << " " << pts2 << endl;
        }

        if (i != name1 && i != name2)
        {
            done = false;
        }
    }


    if (l.at(l.size()-2) == name1)
  {
    pts1 += 140;
  //  cout << name1 << " " << pts1 << endl;
  }
else {
    pts2 += 140;
   // cout << name2 << " " << pts2 << endl;
  }  

  if (pts1 == pts2)
  {
    printf("Tie\n");
    printf("%d-%d", pts1, pts2);
  }

  if (pts1 > pts2)
  {
    printf("%s wins\n", name1.c_str());
    printf("%d-%d", pts1, pts2);
  }
    
  if (pts1 < pts2)
  {
    printf("%s wins\n", name2.c_str());
    printf("%d-%d", pts2, pts1);
  }

  return 0;
}