#include <iostream>
#include <string>
#include <vector>

using namespace std;


void DisplayMenu();
void DisplayAllSeatsStatus(const vector<string> &vAS, const vector<bool> &vAva);
void DisplayAvailableSeats(const vector<string> &vAS, const vector<bool> &vAva);
int TotalNumberOfAvailableSeats(const vector<bool> &vAva);
void BookSeat(string &wS, const vector<string> & vAS, vector<bool> &vAva);
void CancelSeat (const string &cS, const vector<string> &vAS, vector<bool> &vAva);
void ChangeSeat(const string &wS, const string &cS, const vector<string> &vAS, vector<bool> &vAva);

int main() {
   /* Type your code here. */
   vector <string> vAirplaneSeats (20);
   vAirplaneSeats.at(0) = "1A";
   vAirplaneSeats.at(1) = "1B";
   vAirplaneSeats.at(2) = "1C";
   vAirplaneSeats.at(3) = "1D";
   vAirplaneSeats.at(4) = "2A";
   vAirplaneSeats.at(5) = "2B";
   vAirplaneSeats.at(6) = "2C";
   vAirplaneSeats.at(7) = "2D";
   vAirplaneSeats.at(8) = "3A";
   vAirplaneSeats.at(9) = "3B";
   vAirplaneSeats.at(10) = "3C";
   vAirplaneSeats.at(11) = "3D";
   vAirplaneSeats.at(12) = "4A";
   vAirplaneSeats.at(13) = "4B";
   vAirplaneSeats.at(14) = "4C";
   vAirplaneSeats.at(15) = "4D";
   vAirplaneSeats.at(16) = "5A";
   vAirplaneSeats.at(17) = "5B";
   vAirplaneSeats.at(18) = "5C";
   vAirplaneSeats.at(19) = "5D";
   
   vector <bool> vAirplaneSeatsStatus (20); 
   for (unsigned int i = 0; i < vAirplaneSeatsStatus.size(); ++i)
   {
      vAirplaneSeatsStatus.at(i) = 0;
      // 0 is default for unbooked seats
   }
  
   string wantedSeat; // for options 4 and 6 
   string canceledSeat; // for options 5 and 6
   
   DisplayMenu();
   int option;
   cin >> option;
   while (option != 7)
   {
   if (option == 1)
   {
      DisplayAllSeatsStatus (vAirplaneSeats, vAirplaneSeatsStatus);
      cout << endl;
      void DisplayMenu();
   }
   else if (option == 2)
   {
      cout << TotalNumberOfAvailableSeats (vAirplaneSeatsStatus) << endl;
      cout << endl;
      void DisplayMenu();
   }
   else if (option == 3)
   {
      DisplayAvailableSeats (vAirplaneSeats, vAirplaneSeatsStatus);
      cout << endl;
      void DisplayMenu();
   }
  else if (option == 4)
  {
    cout << "Enter seat to book: ";
    cin >> wantedSeat; 
    cout << endl;

    BookSeat (wantedSeat, vAirplaneSeats,vAirplaneSeatsStatus);
    cout << endl;
    void DisplayMenu();
  }
   else if (option == 5)
  {
    cout << "Enter seat to cancel: ";
    cin >> canceledSeat;
    cout << endl;

    CancelSeat (canceledSeat, vAirplaneSeats,vAirplaneSeatsStatus);
    cout << endl;
    void DisplayMenu();
  }
  else if (option == 6)
  {
    cout << "Enter seat to cancel: ";
    cin >> canceledSeat;
    cout << endl;
    cout << "Enter seat to book: ";
    cin >> wantedSeat; 
    cout << endl;

    ChangeSeat (wantedSeat, canceledSeat, vAirplaneSeats, vAirplaneSeatsStatus);
    cout << endl;
    void DisplayMenu();
  }
   cin >> option;  
}
   return 0;
}

void DisplayMenu()
// function displays menu options
{
   cout << "Menu options:" << endl;
   cout << "1. Display All Seats Status:" << endl;
   cout << "2. Total Number of Available Seats:" << endl;
   cout << "3. Display Available Seats: " << endl;
   cout << "4. Book Seat:" << endl;
   cout << "5. Cancel Seat:" << endl;
   cout << "6. Change Seat:" << endl;
   cout << "7. Quit:" << endl;
   cout << endl;
   cout << "Please select an option: " << endl;
   cout << endl;
}

void DisplayAllSeatsStatus (const vector<string> &vAS, const vector<bool> &vAva)
{
   //vAS is airplane seat
   //vAv is seat availablity
   cout << "Seat\tStatus" << endl;
   for (unsigned int i = 0; i < vAS.size(); ++i)
   {
      cout << vAS.at(i) << "\t" << vAva.at(i) << endl; 
   }
}

void DisplayAvailableSeats (const vector<string> &vAS, const vector<bool> &vAva)
{
   cout << "Available seats:" << endl;
   for (unsigned int i = 0; i < vAS.size(); ++i)
   {
      if (!vAva.at(i)) //bc vAva is defaulted to false, ! makes it so 1 is true
      {
         cout << vAS.at(i) << endl; //outputs available seat
      }
   }
}

int TotalNumberOfAvailableSeats (const vector<bool> &vAva)
{
   int availableSeats = 0; 
   //loops through the vector to find untaken seats
   for (unsigned int i = 0; i < vAva.size(); ++i)
   {
      if (!vAva.at(i))
      {
         availableSeats += 1;
      }
   }
   return availableSeats;
}

void BookSeat(string &wS, const vector<string> & vAS, vector<bool> &vAva)
// changed const string to string just in case seat is booked and string needs to be changed
{
    for (unsigned int i = 0; i < vAS.size(); ++i)
    {
      while ((vAS.at(i) == wS) && (vAva.at(i)==1)) //keeps getting input until an unbooked seat is entered
      {
        cout << "That seat is already taken." << endl;
        cout << "Enter seat to book : ";
        cin >> wS;
      }
      if (vAS.at(i) == wS)
      {
        vAva.at(i) = 1; //changes seat to taken
      }
    }
    cout << endl;
// shows seats and its availablility
    cout << "Seat\tStatus" << endl;
    for (unsigned int i = 0; i < vAS.size(); ++i)
    {
      cout << vAS.at(i) << "\t" << vAva.at(i) << endl;
    }
}

void CancelSeat (const string &cS, const vector<string> &vAS, vector<bool> &vAva)
{
    for (unsigned int i = 0; i < vAS.size(); ++i)
    {
      if (vAS.at(i) == cS)
      {
        vAva.at(i) = 0; //changes seat back to unbooked
      }
    }
    cout << endl;
   //outputs seats and availbiliyt
    cout << "Seat\tStatus" << endl;
    for (unsigned int i = 0; i < vAS.size(); ++i)
    {
      cout << vAS.at(i) << "\t" << vAva.at(i) << endl;
    }
}

void ChangeSeat (const string &wS, const string &cS, const vector<string> &vAS, vector<bool> &vAva)
{
   for (unsigned int i = 0; i < vAS.size(); ++i)
   {
      if (wS == vAS.at(i))
      {
         vAva.at(i) = 1; //gives user their desired seat
      }
      if (cS == vAS.at(i))
      {
         vAva.at(i) = 0; //removes old booked seat
      }
   }
   
    cout << endl;
   cout << "Seat\tStatus" << endl;
    for (unsigned int i = 0; i < vAS.size(); ++i)
    {
      cout << vAS.at(i) << "\t" << vAva.at(i) << endl;
    }
}


