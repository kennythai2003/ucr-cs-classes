#include <iostream>
#include <cctype>

#include "Card.h"
using namespace std;

Card::Card() {
    _suit = 'c';
    _rank = 2;
}

Card::Card(char suit, int rank){
    suit = tolower(suit);
    if ((suit != 'c') && (suit != 'd') && (suit != 'h') && (suit != 's')) {
        _suit = 'c';
    }
    else {
        _suit = suit;
    }
    if (rank < 1 || rank > 13) {
        _rank = 2;
    }
    else {
        _rank = rank;
    }
}

char Card::suit() const {
    return _suit;
}

int Card::rank() const {
    return _rank;
}



/* Outputs a Card in the following format: Rank of Suit
For example, if the rank is 3 and the suit is h: 3 of Hearts
Or, if the rank is 1 and the suit is d: Ace of Diamonds
Or, if the rank is 12 and the suit is c: Queen of Clubs
etc. */	
ostream & operator<<(ostream &out, const Card &randCard) {
    string suitName;
    string specialRanks;
    if (randCard._suit == 'c'){
        suitName = "Clubs";
    }
    if (randCard._suit == 'd'){
        suitName = "Diamonds";
    }
    if (randCard._suit == 'h'){
        suitName = "Hearts";
    }
    if (randCard._suit == 's'){
        suitName = "Spades";
    }
    if (randCard._rank == 1) {
    out << "Ace of " << suitName; //<< endl;
    }
    else if (randCard._rank == 11) {
    out << "Jack of " << suitName; // << endl;
    }
    else if (randCard._rank == 12) {
    out << "Queen of " << suitName; // << endl;
    }
    else if (randCard._rank == 13) {
    out << "King of " << suitName; // << endl;
    }
    else {
    out << randCard._rank << " of " << suitName; // << endl;
    }
    return out; 
}