// This program implements the Monte Carlo Method for estimating the value of PI.
	   
#include <iostream>
#include <cstdlib>
#include <cmath>
   
using namespace std;
   
// given the coordinates of a point (x,y) computes if the point is inside or on the circle 
// centered at origin with radius r. Returns 'true' if it is inside or on the circle, 'false' otherwise.
// DO NOT use the sqrt function here. Just compare to r squared.    
bool isInside(double x, double y, double r)
{
   bool inside;
   if ( (x * x + y * y) <= (r * r) )
   {
      inside = true;
   }
   else 
   {
      inside = false;
   }
   return inside;
}

// given s, the size of the side of a square that is centered at the origin, 
// chooses a random coordinates inside the square, and calls isInside function 
// to test if the point is inside the circle or not.
bool throwDart(int s) {
   int x, y; 
   // assign x and y to two random integers between -s/2 and s/2 
   x = rand() % (s + 1) - (s / 2); // s+1 gives diameter, -s/2 allows for negative cords
   y = rand() % (s + 1) - (s / 2); // s+1 gives diameter, -s/2 allows for negative cords
   //Call the isInside function and return its output. 
   bool inside;
   if (isInside (x, y, s/2))
   {
      inside = true;
   }
   else
   {
      inside = false;
   }
   //You do not have to cast x & y to doubles, it is done automatically.
  return inside;
}

int main() {
   srand(333);
   int side; // this is the side of the square and is also our resolution. 
   int tries;  // this is the number of tries.

   //Ask the user for the size (integer) of a side of the square
   cout << "What is the size of a side of your square?" << endl;
   //Get the users input using cin
   cin >> side;
   //Ask the user for the number of tries using cout.
   cout << "How many amount of tries do you want?" << endl;
   //Get the users input using cin.
   cin >> tries;
 
 
   int inCount = 0; //counter to track number of throws that fall inside the circle

   for(int i = 0; i < tries; ++i) 
   {
      //throw a dart using throwDart method and increment the counter depending on its output.
      if (throwDart(side))
      {
      inCount = inCount +  1;
      }
   }

   //Compute and display the estimated value of PI. Make sure you are not using integer division.
   double pi;
   pi = 4.0 * (static_cast<double>(inCount) / tries);
   cout << pi << endl;

   return 0;
}