#ifndef __DECK_H__
#define __DECK_H__

#include <vector>
using namespace std;

#include "Card.h"

class Deck {
 private:
    vector<Card> theDeck;
    vector<Card> dealtCards;
 public:
    /* Constructs a Deck of 52 cards:
       Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
       Cards should start off in this order with the order of suits being:
       Clubs, Diamonds, Hearts, Spades.
       In other words, the above is the order the Cards would be dealt
       if the Deck is not shuffled. 
       So, the first Card dealt would be the Ace of Clubs.
       For best efficiency, the top of the Deck (next Card to be dealt) should be 
       stored at the back end of the vector.
    */
    Deck();

    /* Deals (returns) the top card on the deck. 
       Removes this card from theDeck and places it in the dealtCards.
       As mentioned in comments for constructor, for best efficiency,
       top card should be at back end of vector.
    */
    Card dealCard();


    /* Places all cards back into theDeck and shuffles them into random order.
       Use random_shuffle function from algorithm library.
       This function goes forward through dealtCards pushing each Card 
       onto back end of theDeck, then clears dealtCards.
    */
    void shuffleDeck();


    /* returns the size of the Deck (how many cards have not yet been dealt).
    */
    unsigned deckSize() const;
};

#endif
