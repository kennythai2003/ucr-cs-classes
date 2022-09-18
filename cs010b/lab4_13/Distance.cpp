#include <iostream>
using namespace std;

#include "Distance.h"

Distance::Distance() {
   feet = 0;
   inches = 0.0;
}

Distance::Distance(unsigned ft, double in){
   feet = ft;
   inches = in;
   init();
}

Distance::Distance(double in){
   feet = 0;
   inches = in;
   init();
}

unsigned Distance::getFeet() const {
   return feet;
}

double Distance::getInches() const{
   return inches;
}

double Distance::distanceInInches() const{
   double distanceInches;
   distanceInches = (feet * 12) + inches;
   return distanceInches;
}

double Distance::distanceInFeet() const{
   double distanceFeet;
   distanceFeet = feet + (inches / 12);
   return distanceFeet;
}

double Distance::distanceInMeters() const{
   double distanceMeters;
   distanceMeters = ((feet * 12) + inches) * 0.0254;
   return distanceMeters;
}

Distance Distance::operator+(const Distance &rhs) const{
   return Distance(distanceInInches() + rhs.distanceInInches());
}

Distance Distance::operator-(const Distance &rhs) const{
   return Distance(distanceInInches() - rhs.distanceInInches());
}

void Distance::init() {
   if (inches < 0) {
      inches = inches * -1;
   }
   int addedFeet;
   addedFeet = inches / 12;
   feet = feet + addedFeet;
   inches = inches - (12 * addedFeet);
}

ostream & operator<<(ostream &out, const Distance &rhs){
   out << rhs.feet << "' " << rhs.inches << '"';
   return out;
}