/*
	This file describes the Card class.
*/
#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
  private:
    int rank;  // Should be in the range 0-12. 11 = jack 12 = queen, 0 = king, 1 = ace
    int suit;  // Should be in the range 0-3. //0 == heart, 1 == diamond, 2 === spade, 3 == club.


  public:
    void display();
    void displayRank();
    void displaySuit();    
    int getrank();
    int getsuit();
    void setsuit(int);
    void setContent(int a, int b);

};

#endif
