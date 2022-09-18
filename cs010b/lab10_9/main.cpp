#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void rCopy (istream &, ostream &);
bool rCopy(const string &, const string &);

int main(int argc, char *argv[]){

if (argc != 3) {
      
      return 1;
   }
    string inputFile = argv[1];
    string outputFile = argv[2];

    // fstream fin;
    // fin.open(inputFile);

    // fstream out;
    // out.open(outputFile);

    // if (!fin.is_open()){
    //     return false;
    // }
    // if (!out.is_open()){
    //     return false;
    // }
    if(rCopy(inputFile, outputFile))
    {
        //cout << "file" << endl; 
        cout << "Copy completed" << endl;
   } else {
      cout << "Copy not completed" << endl;
   }
    
    return 0;
}

void rCopy(istream &inputFile, ostream &outputFile) {
    char c;

    if (inputFile.get(c)) {
        rCopy(inputFile, outputFile);
        outputFile << c;
    }

}

bool rCopy(const string &inputFile, const string &outputFile){
 
    ifstream fin;
    fin.open(inputFile);

    

    if (!fin.is_open()){
        cout << "Error opening " << inputFile << endl;
        return false;
    }

    ofstream out;
    out.open(outputFile);
    
    if (!out.is_open()){
        cout << "Error opening " << outputFile << endl;
        return false;
    }

    //rCopy(inputFile, outputFile);

    rCopy(fin, out);

    fin.close();
    out.close();

    return true;
}