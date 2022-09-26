#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


int main() {
   /* TODO: Declare any necessary variables here. */
    string studentInfoFile; //input file

    string report; //output file
    cin >> studentInfoFile;

    string lastName;
    string firstName;
    double midterm1;
    double midterm2;
    double final;

    vector<double> midterm1Grades;
    vector<double> midterm2Grades;
    vector<double> finalGrades;   
    double studentGradeAvg;

    char grade;
    double avgMidterm1;
    double avgMidterm2;
    double avgFinal;
      
   /* TODO: Read a file name from the user and read the tsv file here. */
    cin >> studentInfoFile;
    ifstream fin;
    ofstream fout;

    fin.open(studentInfoFile);

    if (!fin.is_open()){
        cout << "Error opening " << studentInfoFile << endl;
        return 1;
    }

    fout.open("report.txt");

    if (!fout.is_open()){
        cout << "Error opening report.txt" << endl;
        return 1;
    }

    while (fin >> lastName >> firstName >> midterm1 >> midterm2 >> final) {
        midterm1Grades.push_back(midterm1);
        midterm2Grades.push_back(midterm2); 
        finalGrades.push_back(final);      
       
        studentGradeAvg = (midterm1 + midterm2 + final) / 3.0;
       
        if (studentGradeAvg >= 90) {
            grade = 'A';
        }
        if (studentGradeAvg < 90 && studentGradeAvg >= 80){
            grade = 'B';
        }
        if (studentGradeAvg < 80 && studentGradeAvg >= 70) {
            grade = 'C';
        }
        if (studentGradeAvg < 70 && studentGradeAvg >= 60) {
            grade = 'D';
        }
        if (studentGradeAvg < 60) {
            grade = 'F';
        }
        fout << lastName << '\t' << firstName << '\t' << midterm1 << '\t' << midterm2 << '\t' << final << '\t' << grade << endl;
    }

   /* TODO: Compute student grades and exam averages, then output results to a text file here. */
    for (unsigned int i = 0; i < midterm1Grades.size(); ++i) {
        //total midterms & final grade from each student
        avgMidterm1 += midterm1Grades.at(i);
        avgMidterm2 += midterm2Grades.at(i);     
        avgFinal += finalGrades.at(i);  
    }

    avgMidterm1 /= midterm1Grades.size();
    avgMidterm2 /= midterm2Grades.size();
    avgFinal /= finalGrades.size();

    fout << "\n";
    fout << fixed << setprecision(2);

    fout << "Averages: midterm1 " << avgMidterm1 << ", midterm2 " << avgMidterm2 << ", final " << avgFinal << "\n";

    fin.close();
    fout.close();

   return 0;
}
