/*
	This file describes the Hand class.
*/
#ifndef HAND_H
#define HAND_H

#include <iostream>
#include "card.h"
#include "deck.h"
 
class Hand {
  private:
    Card* cards;
    int numCards;  // Number of cards in the hand.

  public:
    void display();
    void displayPlayableCards(Card);    // points to cards that can be played
    bool canPlay(Card);
    Card returncard(int); //returns card at index
    int cardsInHand(); //returns number of cards left in hand
    void addcard();
    void removecard();
    void drawcard(Card);
    Card playcard(int); //shift cards and such, return played card
    Hand();
    ~Hand(); 
    void deal(Deck&);
  	Hand(const Hand&); // copy constructor
  	Hand& operator=(const Hand&); // assignment operator overload
};



#endif
