#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
// Passes in an index of type int and a vector of type T (T could be string, double or int). 
// The function returns the index of the min value starting from "index" to the end of the "vector"
    unsigned int minIndex = index;
    T minValue = vals.at(index);
    for (unsigned int i = index + 1; i < vals.size(); ++i) {
        if (vals.at(i) <= minValue) {
            minValue = vals.at(i);
            minIndex = i;
        }
    }
    return minIndex;
}

template<typename T>
void selection_sort(vector<T> &vals) {
    for (unsigned int i = 0; i < vals.size(); ++i) {
        unsigned int minIndex = min_index(vals, i);
        
        T temp = vals.at(i);
        vals.at(i) = vals.at(minIndex);
        vals.at(minIndex) = temp;
    }
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template<typename T>
T getElement(vector<T> vals, unsigned index) {
    if (index > vals.size() - 1) {
        throw runtime_error ("Invalid index.");
    }
    return vals.at(index);
}

int main(){

    //Part B
    //  write up a try catch block in main function so that when the index is out of the range of the vector, the "std::outofrange" exception will be caught 
    //  by the catch (const std::outofrange& excpt). Once the exception is caught, it should output 
    //  "out of range exception occured" followed by a new line
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
    //  selection_sort(vals);
    //  for (unsigned int i = 0; i < vals.size(); ++i) {
    //     cout << vals.at(i) << endl;
    //  }
     while(--numOfRuns >= 0){
        try {
         cout << "Enter a number: " << endl;
         cin >> index;
         curChar = getElement(vals,index);
         cout << "Element located at " << index << ": is " << curChar << endl;
        }
        catch (runtime_error &excpt) {
            cout << excpt.what() << endl;
            cout << "Cannot retrieve element" << endl;
        }
    }

    return 0;
}
