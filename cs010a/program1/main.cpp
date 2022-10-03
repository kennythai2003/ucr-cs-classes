#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int simVal;
  int roll;
  int sum = 0;
  
  //counter for everytime outcome of 0, 20-25 is hit
  int sum0 = 0;
  int sum20 = 0;
  int sum21 = 0;
  int sum22 = 0;
  int sum23 = 0;
  int sum24 = 0;
  int sum25 = 0;
   
  srand(1000); //sets the rng
   
  cin >> simVal; 
  
  //for loop i goes through a full game for simVal times
  for (int i = 0; i < simVal; ++i){ 

    //for loop j goes through a singular game until a loss
    for (int j = 0; j < 10000; ++j) {  
      //10000 assumes  that the game will end in less than 10000 turns
      if ( j < 10000 ) {
        roll = (rand() % 6) + 1;
        sum = sum + roll; 
        
        if (roll == 1) {
          j = j + 10000000; //exits program
          sum0 = sum0 + 1; 
          sum = 0;
        }
        
        if (sum == 20){
          sum20 = sum20 + 1; 
          sum = 0;
          j = j + 10000000;
        }
        
        if (sum == 21) {
          sum21 = sum21 + 1;
          sum = 0;
          j = j + 10000000;
        }
        
        if (sum == 22) {
          sum22 = sum22 + 1;
          sum = 0;
          j = j + 10000000;
        }
        
        if (sum == 23) {
          sum23 = sum23 + 1;
          sum = 0;
          j = j + 10000000;
        }
        
        if (sum == 24) {
          sum24 = sum24 + 1;
          sum = 0;
          j = j + 10000000;
        }
        
        if (sum == 25) {
          sum25 = sum25 + 1;
          sum = 0;
          j = j + 10000000;
        }  

      }
    }
  }
  
  //headers
  cout << "Hold-at-20 turn simlulations?" << endl;
  cout << "Score\t Estimated Probability" << endl;
  
   //outputting for sum 0
   cout << "0\t";
   cout << static_cast<double>(sum0) / simVal << endl;
  

   //outputting for sum 20
   cout << "20\t";
   cout << static_cast<double>(sum20) / simVal << endl;


   //outputting for sum 21
   cout << "21\t";
   cout << static_cast<double>(sum21) / simVal << endl;


   //outputting for sum 22
   cout << "22\t";
   cout << static_cast<double>(sum22) / simVal << endl;
   

   //outputting for sum 23
   cout << "23\t";
   cout << static_cast<double>(sum23) / simVal << endl;
   

   //outputting for sum 24
   cout << "24\t";
   cout << static_cast<double>(sum24) / simVal << endl;


   //outputting for sum 25
   cout << "25\t";
   cout << static_cast<double>(sum25) / simVal << endl;

 
return 0;
} 