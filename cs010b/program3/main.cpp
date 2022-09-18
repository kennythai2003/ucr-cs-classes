#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand);

// Sends to output a "hand" of Cards.
// The "hand" should be output all on one line,
//   with a comma and a single space between each Card.
//   Do not output a comma, space, or newline at the end.
// Each Card should be output as: Rank of Suit
// i.e., Ace of Spades
ostream & operator<<(ostream &, const vector<Card> &);

int main() {
	srand(2222);
	Deck deck1;
	vector<Card> cardHand;
	string userInput;
	string fileName = "";
	unsigned int cardsPerHand;
	unsigned int numOfSimulations;
	int pairCounter = 0;
	double pairChance = 0.0;

	cout << "Do you want to output all hands to a file?(Yes/No)" << endl;
	cin >> userInput; 
	
	if (userInput == "Yes"){
		cout << "Enter name of output file:" << endl;
		cin >> fileName;
		
		ofstream outFS;
		outFS.open(fileName);
		
		cout << "Enter number of cards per hand:" << endl;
		cin >> cardsPerHand; 
	
		cout << "Enter number of deals (simulations):" << endl;
		cin >> numOfSimulations;

		for (unsigned int i = 0; i < numOfSimulations; ++i) {
			deck1.shuffleDeck();
			for (unsigned int j = 0; j < cardsPerHand; ++j) {
				cardHand.push_back(deck1.dealCard());
			}
			// outFS << cardHand << endl;
			if (hasPair(cardHand)) {
				pairCounter = pairCounter + 1;
				outFS << "Found Pair!! " << cardHand << endl;
			}
			else{
				outFS << "             " << cardHand << endl;

			}
			cardHand.clear();
		}
		pairChance = (static_cast<double>(pairCounter) / (numOfSimulations)) * 100;
		cout << "Chances of receiving a pair in a hand of " << cardsPerHand << " cards is:" << pairChance << " %" << endl;
	}
	else {
		cout << "Enter number of cards per hand:" << endl;
		cin >> cardsPerHand; 
	
		cout << "Enter number of deals (simulations):" << endl;
		cin >> numOfSimulations;

		for (unsigned int i = 0; i < numOfSimulations; ++i) {
			deck1.shuffleDeck();
			for (unsigned int j = 0; j < cardsPerHand; ++j) {
				cardHand.push_back(deck1.dealCard());
			}
			if (hasPair(cardHand)) {
				pairCounter = pairCounter + 1;
			}
			cardHand.clear();
		}
		pairChance = (pairCounter / static_cast<double>(numOfSimulations)) * 100;
		cout << "Chances of receiving a pair in a hand of " << cardsPerHand << " cards is:" << pairChance << " %" << endl;
	}

	return 0;
}

bool hasPair(const vector<Card> &hand) {
	bool pairExists = false;
	int pair1 = 0;
	int pair2 = 0;
	int pair3 = 0;
	int pair4 = 0;
	int pair5 = 0;
	int pair6 = 0;
	int pair7 = 0;
	int pair8 = 0;
	int pair9 = 0;
	int pair10 = 0;
	int pair11 = 0;
	int pair12 = 0;
	int pair13 = 0;
	for (unsigned int i = 0; i < hand.size(); ++i) {
		if (hand.at(i).rank() == 1){
			pair1 = pair1 + 1;
		}
		if (hand.at(i).rank() == 2){
			pair2 = pair2 + 1;			
		}
		if (hand.at(i).rank() == 3){
			pair3 = pair3 + 1;			
		}
		if (hand.at(i).rank() == 4){
			pair4 = pair4 + 1;			
		}
		if (hand.at(i).rank() == 5){
			pair5 = pair5 + 1;			
		}
		if (hand.at(i).rank() == 6){
			pair6 = pair6 + 1;			
		}
		if (hand.at(i).rank() == 7){
			pair7 = pair7 + 1;			
		}
		if (hand.at(i).rank() == 8){
			pair8 = pair8 + 1;			
		}
		if (hand.at(i).rank() == 9){
			pair9 = pair9 + 1;			
		}
		if (hand.at(i).rank() == 10){
			pair10 = pair10 + 1;			
		}
		if (hand.at(i).rank() == 11){
			pair11 = pair11 + 1;			
		}
		if (hand.at(i).rank() == 12){
			pair12 = pair12 + 1;			
		}
		if (hand.at(i).rank() == 13){
			pair13 = pair13 + 1;			
		}
	}

	//seperates for readbility
	if (pair1 > 1 || pair2 > 1 || pair3 > 1 || pair4 > 1 || pair5 > 1 || pair6 > 1 ||pair7 > 1 || pair8 > 1 || pair9 > 1 || pair10 > 1 || pair11 > 1 || pair12 > 1 || pair13 > 1){
		pairExists = true;
	}

	return pairExists;
}

// Sends to output a "hand" of Cards.
// The "hand" should be output all on one line,
//   with a comma and a single space between each Card.
//   Do not output a comma, space, or newline at the end.
// Each Card should be output as: Rank of Suit
// i.e., Ace of Spades
// ostream & operator<<(ostream &, const vector<Card> &);
ostream & operator<<(ostream &outFS, const vector<Card> &dealtHand){
	for (unsigned int i = 0; i < dealtHand.size(); ++i) {
		if (i != dealtHand.size() - 1){
			outFS << dealtHand.at(i) << ", ";
		}
		else {
			outFS << dealtHand.at(i);
		}
	}
	return outFS;
}