#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

    
int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
  
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   
   // Create input stream and open input csv file.
   ifstream inFS;
   inFS.open(inputFile);

   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!inFS.is_open()) {
      cout << "Error opening " << argv[1] << endl;
      return 1;
   }
   
   // Read in integers from input file to vector.
   // integers from input file
   int x; 
   char comma;

   vector<int> inputFileInts;
   while (!inFS.eof()) {
       inFS >> x;
       inputFileInts.push_back(x);
       inFS >> comma;
   }
   
   // Close input stream.
   inFS.close();
   
   // Get integer average of all values read in.
   int average;
   int sum = 0;
   
   for (unsigned int i = 0; i < inputFileInts.size(); ++i) { 
       sum = sum + inputFileInts.at(i);
   }
   average = sum / inputFileInts.size();
   // Convert each value within vector to be the difference between the original value and the average.   
    for (unsigned int i = 0; i < inputFileInts.size(); ++i) { 
        inputFileInts.at(i) = inputFileInts.at(i) - average;
   }

   
   // Create output stream and open/create output csv file.
    ofstream outFS;
    outFS.open(outputFile);

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!outFS.is_open()) {
      cout << "Error opening " << argv[2] << endl;
      return 1;
   } 

   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (unsigned int i = 0; i < inputFileInts.size(); ++i) {

       if ( i == inputFileInts.size() - 1) {
           outFS << inputFileInts.at(i);
       }
      else {
          outFS << inputFileInts.at(i) << ",";
       }
   }

   // Close output stream.  
   outFS.close();
   return 0;
}