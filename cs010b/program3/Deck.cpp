#include <algorithm>
#include "Deck.h"
#include <vector>
using namespace std;

// THE FOLLOWING shuffleDeck() IMPLEMENTATION IS GIVEN TO YOU. 
// DO NOT CHANGE!!

/* Places all cards back into theDeck and shuffles them into random order.
   Uses random_shuffle function from algorithm library.
*/
void Deck::shuffleDeck() {
	for (unsigned i = 0; i < dealtCards.size(); ++i) {
		theDeck.push_back(dealtCards.at(i));
	}
	dealtCards.clear();
	random_shuffle(theDeck.begin(), theDeck.end());
}

Deck::Deck() {
	Card defaultCards;
	int rankN = 0;
	char suitN = 'a';

	for (unsigned int i = 13; i >= 1; --i){
		suitN = 's';
		rankN = i;
		defaultCards = Card(suitN , rankN);
		theDeck.push_back(defaultCards);
	}
	for (unsigned int i = 13; i >= 1; --i){
		suitN = 'h';
		rankN = i;
		defaultCards = Card(suitN , rankN);
		theDeck.push_back(defaultCards);
	}
	for (unsigned int i = 13; i >= 1; --i){
		suitN = 'd';
		rankN = i;
		defaultCards = Card(suitN , rankN);
		theDeck.push_back(defaultCards);
	}
	for (unsigned int i = 13; i >= 1; --i){
		suitN = 'c';
		rankN = i;
		defaultCards = Card(suitN , rankN);
		theDeck.push_back(defaultCards);
	}
}

Card Deck::dealCard() {
	Card dealtC;
	dealtC = theDeck.back();
	dealtCards.push_back(dealtC);
	theDeck.pop_back();
	return dealtC;
}
unsigned Deck::deckSize() const {
	return theDeck.size();
}

	// for (unsigned int i = 1; i <= 13; ++i){
	// 	suitN = 'c';
	// 	rankN = i;
	// 	defaultCards = Card(suitN , rankN);
	// 	theDeck.push_back(defaultCards);
	// }
	// for (unsigned int i = 1; i <= 13; ++i){
	// 	suitN = 'd';
	// 	rankN = i;
	// 	defaultCards = Card(suitN , rankN);
	// 	theDeck.push_back(defaultCards);
	// }
	// for (unsigned int i = 1; i <= 13; ++i){
	// 	suitN = 'h';
	// 	rankN = i;
	// 	defaultCards = Card(suitN , rankN);
	// 	theDeck.push_back(defaultCards);
	// }
	// for (unsigned int i = 1; i <= 13; ++i){
	// 	suitN = 's';
	// 	rankN = i;
	// 	defaultCards = Card(suitN , rankN);
	// 	theDeck.push_back(defaultCards);
	// }