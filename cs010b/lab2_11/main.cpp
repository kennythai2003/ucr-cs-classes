#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt (string file, char x);

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt (string file, char x) {
   int count = 0;
   char a; //letters from the file, x is the one we are looking for
   ifstream inFS;  
   inFS.open(file);
   if (!inFS.is_open()) {
      cout << "Error opening " << file << endl;
      exit(1);
   }
   while (inFS.get(a)) {
      if (a == x) {
         count = count + 1;
      }
   }
   inFS.close();
   return count;
}
