#include <iostream>
#include <string>

using namespace std;

void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}
//Implement the flipString function here
void flipString(string &s){
   if (s.size() == 1 || s.size() == 0) {
      return;
   }
   char x;
   char y;
   x = s.at(0);
   y = s.at(s.size() - 1);
   //using sentence; money 4 easy visualization
   // cout << "output 4 x & y" << endl;
   // cout << x << " " << y << endl;
   // expected: m y , o e

   string z = s.substr(1 , s.size() - 2); 
   //passby reference means we need to make substr a variable

   flipString(z);
   // cout<< "new string variatoin" << endl;
   // cout << z << endl;
   s = y + z + x;
   // cout << s << endl;
}

