//include any standard libraries needed
#include <iostream>
#include <fstream>
using namespace std;
//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);

// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);
//lol
//sad
const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line
   ifstream inFS;
   string arrayValues;
   arrayValues = argv[1];

   // open file and verify it opened
   inFS.open(arrayValues);
   if(!inFS.is_open()) {
      cout << "Error Opening " << arrayValues << endl;
      exit(1);
   }

   // Declare an array of doubles of size ARR_CAP.
   double array1[ARR_CAP];
   double fileVals;

    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   int arraySize = 0;
   while (inFS >> fileVals) {
      array1[arraySize] = fileVals;
      arraySize = arraySize + 1;
   }

   inFS.close();
    
   // Call the mean function passing it this array and output the 
   // value returned.
   double arrayMean;
   arrayMean = mean(array1, arraySize);
   cout << "Mean: " << arrayMean << endl;
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   int index;
   cout << "Enter index of value to be removed (0 to " << arraySize - 1 << "):" << endl;
   cin >> index;
   cout << endl; 
	
   // Call the display function to output the array.
   cout << "Before removing value: ";
   display (array1, arraySize);
   cout << endl;

   // Call the remove function to remove the value at the index
   // provided by the user.
   remove (array1, arraySize, index); 
    
   // Call the display function again to output the array
   // with the value removed.
   cout << "After removing value: ";
   display (array1, arraySize);
   cout << endl; 
   
   // Call the mean function again to get the new mean
   arrayMean =  mean(array1, arraySize);
   cout << "Mean: " << arrayMean << endl;

	return 0;
}

double mean(const double array[], int arraySize) {
   double avg;
   double sum = 0;
   for (int i = 0; i < arraySize; ++i) {
      sum = sum + array[i]; 
   }
   avg = sum / arraySize;
   return avg;
}

void remove(double array[], int &arraySize, int index){
   for (int i = index; i < arraySize - 1; ++i) {
      array[i] = array[i + 1];
   }
   arraySize = arraySize - 1;
}
 
void display(const double array[], int arraySize) {
   for (int i = 0; i < arraySize; ++i) {
      if (i != arraySize - 1) {
      cout << array[i] << ", ";
      }
      else {
      cout << array[i];   
      } 
   }
   cout << endl;
}