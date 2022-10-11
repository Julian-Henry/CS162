/*
	This file describes the Deck class.
*/

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "card.h"

class Deck {
  private:
    Card cards[52];
    int numCards;                    // Number of cards remaining in the deck.
  public:
  void make();                       // numCards = 52, initialize all cards
  void shuffle();                    // randomize cards in deck
  void display();                    // display all cards, will not use
  void deal(Card*);                  // give 8 cards to specified array
  Card drawcard();                   // take next card from the deck
  int getnumCards();                 // return num of cards left in deck
  Card* getdeck();                   // return deck array
  Card getLastElementAndDecrement(); // title says it all...
};


#endif
