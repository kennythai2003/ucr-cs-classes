#include <iostream>
#include <string>

using namespace std;
//resubmitted for legibility(: )
class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;
 public:
   Date(); //DONE
   Date(unsigned m, unsigned d, unsigned y); 
   Date(const string &mn, unsigned d, unsigned y);
   void printNumeric() const;
   void printAlpha() const;

 private:
   bool isLeap(unsigned y) const;
   unsigned daysPerMonth(unsigned m, unsigned y) const;
   string name(unsigned m) const;
   unsigned number(const string &mn) const;

};

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}

Date::Date() {
   day = 1;
   month = 1;
   monthName = "January";
   year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y){
   year = y;
   bool invalid = false;
  
   if (m > 12) {
      m = 12;
      month = m;
      invalid = true;
   }
   else if (m < 1) {
      m = 1;
      month = m;
      invalid = true;
   }
   else {
      month = m;
   }
   
   if (d < 1) {
      d = 1;
      day = d;
      invalid = true;
   }
   else if (d > daysPerMonth(m, y)) {
      d = daysPerMonth(m, y);
      day = d;
      invalid = true;
   }
   else {
      day = d;
   }

   if (invalid) {
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }

}

Date::Date(const string &mn, unsigned d, unsigned y){
   year = y;
   bool invalid = false;
   if(mn == "january" ){
      monthName = "January";
   }
   else if(mn == "february"){
      monthName = "February";
   }
   else if(mn == "march"){
      monthName = "March";
   }
   else if(mn == "april"){
      monthName = "April";
   }
   else if(mn == "may"){
      monthName = "May";
   }
   else if(mn == "june"){
      monthName = "June";
   }
   else if(mn == "july"){
      monthName = "July";
   }
   else if(mn == "august"){
      monthName = "August";
   }
   else if(mn == "september"){
      monthName = "September";
   }
   else if(mn == "october"){
      monthName = "October";
   }
   else if(mn == "november"){
      monthName = "November";
   }
   else if(mn == "december"){
      monthName = "December";
   }
   else if (mn == "January" || mn == "February" || mn == "March" || mn == "April" || mn == "May" || mn == "June" || mn == "July" || mn == "August" || mn == "September" || mn == "October" || mn == "November" || mn == "December") {
      monthName = mn;
   }
   else {
      invalid = true;
   }

   bool invalid1 = false; // error message for day value
   month = number(monthName);

   if (d < 1) {
      d = 1;
      day = d;
      invalid1 = true;
   }
   else if (d > daysPerMonth(month, y)) {
      d = daysPerMonth(month, y);
      day = d;
      invalid1 = true;
   }
   else {
      day = d;
   }
   if (invalid) {
      day = 1;
      month = 1;
      monthName = "January";
      year = 2000;
      cout << "Invalid month name: the Date was set to " << month << "/" << day << "/" << year << "." << endl;
   }
   else if (invalid1){
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }

}

void Date::printAlpha() const {
   string mName = name(month);
   cout << mName << " " << day << ", " << year;
}

void Date::printNumeric() const{
   cout << month << "/" << day << "/" << year;
}

bool Date::isLeap(unsigned y) const {
   bool leapYear = false;
   if (y % 4 == 0 && y % 100 != 0) {
      leapYear = true;
   }
   else if (y % 400 == 0) {
      leapYear = true;
   }

   return leapYear;
}


unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
   unsigned int days;
   if (m == 2) {
      if (isLeap(y)) {
         days = 29;
      }
      else {
         days = 28;
      }
   }
   if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
      days = 31;
   }
   if (m == 4 || m == 6 || m == 9 || m == 11) {
      days = 30;
   }

   return days;
}

string Date::name(unsigned m) const {
   string monthString;
  
   if (m == 1) {
      monthString = "January";
   }
   if (m == 2) {
      monthString = "February";
   }
   if (m == 3) {
      monthString = "March";
   }
   if (m == 4) {
      monthString = "April";
   }
   if (m == 5) {
      monthString = "May";
   }
   if (m == 6) {
      monthString = "June";
   }
   if (m == 7) {
      monthString = "July";
   }
   if (m == 8) {
      monthString = "August";  
   }
   if (m == 9) {
      monthString = "September";
   }
   if (m == 10) {
      monthString = "October";      
   }
   if (m == 11) {
      monthString = "November";
   }
   if (m == 12) {
       monthString = "December";    
   }

   return monthString;
}

unsigned Date::number(const string &mn) const {
   unsigned monthNum;

   if (mn == "January") {
      monthNum = 1;
   }
   if (mn == "February") {
      monthNum = 2;
   }
   if (mn == "March") {
      monthNum = 3;
   }
   if (mn == "April") {
      monthNum = 4;
   }
   if (mn == "May") {
      monthNum = 5;
   }
   if (mn == "June") {
      monthNum = 6;
   }
   if (mn == "July") {
      monthNum = 7;
   }
   if (mn == "August") {
      monthNum = 8;
   }
   if (mn == "September") {
      monthNum = 9;
   }
   if (mn == "October") {
      monthNum = 10;
   }
   if (mn == "November") {
      monthNum = 11;
   }
   if (mn == "December") {
      monthNum = 12;
   }
      
   return monthNum;
} 
