#include <iostream>

using namespace std;
// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here
// a constructor with two parameters (numerator and denominator)
// a constructor with one parameter (denominator set to 1)
// a constructor with no parameters (0/1)
Rational::Rational(int num, int denom){
    numerator = num;
    denominator = denom;
}
Rational::Rational(int num){
    numerator = num;
    denominator = 1;
}
Rational::Rational(){
   numerator = 0;
   denominator = 1;
}
// Accessor Functions
// add
// subtract
// multiply
// divide
// display
Rational Rational::add(const Rational &fractionB) const{
   Rational sum;
   
   sum.numerator = (fractionB.numerator * this->denominator + fractionB.denominator * this->numerator);
   sum.denominator = (fractionB.denominator * this->denominator);
   
   return sum;
}

Rational Rational::subtract(const Rational &fractionB) const{
   Rational difference;

   difference.numerator = (this->numerator * fractionB.denominator - fractionB.numerator * this->denominator);
   difference.denominator = (fractionB.denominator * this->denominator);
   
   return difference;
} 

Rational Rational::multiply(const Rational &fractionB) const{
   Rational product;

   product.numerator = (fractionB.numerator * this->numerator);
   product.denominator = (fractionB.denominator * this-> denominator);

   return product;
}
Rational Rational::divide(const Rational &fractionB) const{
   Rational quotient;

   quotient.numerator = (this->numerator * fractionB.denominator);
   quotient.denominator = (this->denominator * fractionB.numerator);

   return quotient;
}

//GCD function (copied)
int Rational::gcd(int den1,int den2) const{
    int x;
  while ((den1 % den2) > 0)  {
    x = den1 % den2;
    den1 = den2;
    den2 = x;
  }
  return den2;
}
// simplify
void Rational::simplify(){
    int d = gcd(numerator,denominator);
    numerator = numerator / d;
    denominator = denominator / d;
}

//display
void Rational::display() const {
    cout << numerator << " / " << denominator;
}
// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}
void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

