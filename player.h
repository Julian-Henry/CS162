/*
	This file describes the Player class.
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "hand.h"
#include "deck.h"

class Player {
  private:
    Hand hand;
    std::string name;
    bool isComputer; // TRUE if player is computer
  public:
    Player();             //constructor
    void setname();       //set players name
    std::string getname();//returns players name
    Card playcard(int);   //remove card from hand, returns removed card.
    Card returncard(int); //just returns the card at the index provided.
    void drawcard(Card);  //adds the arg card to the players hand
    int cardsInHand();    //returns number of cards in hand
    bool canPlay(Card);   //true if player can play on arg card
    void showhand(Card);  //displays hand and what cards can be played
    void deal(Deck&);     //put cards from deck to hand
};

#endif
