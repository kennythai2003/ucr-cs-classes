#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main(int argc, char *argv[]) {

    //get command line the name of file that containis the wind tunnel data
    string tunnel;
    tunnel = argv[1];

    //user angle, vector for data
    double flightPathAngle; 
    vector <double> VflightAngles;
    vector <double> VliftCoefficients;

    //sets up the vectors
    readData (tunnel, VflightAngles, VliftCoefficients); 
    if (!isOrdered(VflightAngles)) {
        reorder (VflightAngles, VliftCoefficients);
    }

    //finds minimum and maximum bounds of data
    double min = VflightAngles.at(0);
    double max = VflightAngles.at(0);
    for (unsigned int i = 0; i < VflightAngles.size(); i++) {
        if (max < VflightAngles.at(i)) {
            max = VflightAngles.at(i);
        }
    }
        for (unsigned int i = 0; i < VflightAngles.size(); i++) {
        if (min > VflightAngles.at(i)) {
            min = VflightAngles.at(i);
        }
    }
    
    string repeatProgram; // for after program runs
    
    cout << "What is your desired flight path angle? ";
    cin >> flightPathAngle;
    
    if (flightPathAngle >= min && flightPathAngle <= max){  
    cout << interpolation(flightPathAngle, VflightAngles , VliftCoefficients);
    }

    cout << "Do you want to enter another angle? ";
    cin >> repeatProgram;

   while (repeatProgram != "No") {
    cout << "What is your desired flight path angle? ";
    cin >> flightPathAngle;
    cout << interpolation(flightPathAngle, VflightAngles , VliftCoefficients);

    cout << "Do you want to enter another angle? Enter Yes or No.";
    cin >> repeatProgram;
   }

    return 0;
}

void readData(const string &fileName, vector<double> &flightPathAngles, vector<double> &liftCoefficients) {
    ifstream fin;
    fin.open(fileName);

    if (!fin.is_open()){
        cout << "Error opening " << fileName << endl;
        exit (1);
    }
    
    double angles;
    double lifecoe;

    
    while (fin >> angles) {
        flightPathAngles.push_back(angles);
        fin >> lifecoe;
        liftCoefficients.push_back(lifecoe);
    }

    fin.close();
}

double interpolation(double angle, const vector<double> &flightPathAngles, const vector<double> &lifeCoefficients){
    double coef;

    //checker to see if angle alrdy exists in data
    bool existing = false;
    for (unsigned int i = 0; i < flightPathAngles.size(); ++i) {
        if (angle == flightPathAngles.at(i))
        {
            existing = true;
            coef = lifeCoefficients.at(i);
        }
    }

    if (existing) {
        return coef;
    }
    else {
    for (unsigned int i = 0; i < flightPathAngles.size(); ++i) {
        if (flightPathAngles.at(i) < angle && flightPathAngles.at(i + 1) > angle) {
            coef = lifeCoefficients.at(i) + (angle - flightPathAngles.at(i)) * ( (lifeCoefficients.at(i + 1) - lifeCoefficients.at(i)) / (flightPathAngles.at(i + 1) - flightPathAngles.at(i))); 
        
        }
        
     } 
    return coef;
    }
}

        
bool isOrdered(const vector<double> &flightPathAngles){
    bool ordered = true;
    if (flightPathAngles.size() > 0) {
    for (unsigned int i = 0 ; i < flightPathAngles.size() - 1; ++i) {
        if (flightPathAngles.at(i) > (flightPathAngles.at(i + 1))) {
            ordered = false;
        }
    }
    }
    return ordered;
}

 void reorder(vector<double> &flightPathAngles, vector<double> &lifeCoeffiecents) {

    // this code is used from chapter 10!!!
    if (flightPathAngles.size() > 0) {
        if (flightPathAngles.at(0) > flightPathAngles.at(1)) {
        double x;
        x = flightPathAngles.at(1);
        flightPathAngles.at(1) = flightPathAngles.at(0);
        flightPathAngles.at(0) = x;   

        double y;
        y = lifeCoeffiecents.at(1);
        lifeCoeffiecents.at(1) = lifeCoeffiecents.at(0);
        lifeCoeffiecents.at(0) = y;       
    }
        for (unsigned int i = 0; i < flightPathAngles.size() - 1; ++i) {
        int smallestIndex = i;
            for (unsigned int j = i + 1; j < flightPathAngles.size(); ++j) {
           
             if (flightPathAngles.at(j) < flightPathAngles.at(smallestIndex)) {
                smallestIndex  = j;
             } 

            }

            double temp; // swaps flightPathAngles
            temp = flightPathAngles.at(i);
            flightPathAngles.at(i) = flightPathAngles.at(smallestIndex);
            flightPathAngles.at(smallestIndex) = temp;
    
            double temp1; //swaps lifecoefficients
            temp1 = lifeCoeffiecents.at(i); 
            lifeCoeffiecents.at(i) = lifeCoeffiecents.at(smallestIndex);
            lifeCoeffiecents.at(smallestIndex) = temp1;
        }
    }
 }

/*
Read the file name of the tsv file from the user.
Open the tsv file and read the student information.
Compute the average exam score of each student.
Assign a letter grade to each student based on the average exam score in the following scale:
A: 90 =< x
B: 80 =< x < 90
C: 70 =< x < 80
D: 60 =< x < 70
F: x < 60
Compute the average of each exam.
Output the last names, first names, exam scores, and letter grades of the students into a text file named report.txt. Output one student per row and separate the values with a tab character.
Output the average of each exam, with two digits after the decimal point, at the end of report.txt. Hint: Use the setprecision manipulator to format the output.

int main() {
    ifstream fin;
    ofstream fout;

    string 

    fin.open(fileName);

    if (!fin.is_open()){
        cout << "Error opening " << fileName << endl;
        exit (1);
    }
    
    double angles;
    double lifecoe;
    
    while (fin >> angles) {
        flightPathAngles.push_back(angles);
        fin >> lifecoe;
        liftCoefficients.push_back(lifecoe);
    }

    fin.close();
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
 #include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int main() {

   /* TODO: Declare any necessary variables here. */
      
      
   /* TODO: Read a file name from the user and read the tsv file here. */
   
   
   /* TODO: Compute student grades and exam averages, then output results to a text file here. */

//    return 0;
// }

// */
