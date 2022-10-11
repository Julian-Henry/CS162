#include <iostream>
#include <algorithm>
#include "deck.h"

using namespace std;


/*********************************************************************
** Function: make
** Description: This function initializes the values for a deck
** Parameters: n/a
** Pre-Conditions: setContent for card class should be made
** Post-Conditions: rank and suit should change unless rank == 8
*********************************************************************/
void Deck::make() {
  numCards = 52;
  int i = 0;
  for (int j = 0; j < 13; j++) {
    for (int k = 0; k < 4; k++) {
      cards[i].setContent(j, k);
      i++;
    }
  }
}

/*********************************************************************
** Function: shuffle
** Description: This function randomizes the contents of an array
** Parameters: n/a
** Pre-Conditions: Deck must be initialized already
** Post-Conditions: n/a
*********************************************************************/
void Deck::shuffle() {
  random_shuffle(begin(cards), end(cards)); // gotten from https://stackoverflow.com/questions/14720134/is-it-possible-to-random-shuffle-an-array-of-int-elements
}

/*********************************************************************
** Function: display
** Description: This function displays every card in a deck
** Parameters: n/a
** Pre-Conditions: display function for cards and a deck must be made
** Post-Conditions: n/a
*********************************************************************/
void Deck::display() {
  for (int i = 0; i < numCards; i++) {
    cards[i].display();
  }
}

/*********************************************************************
** Function: deal
** Description: This function puts eight cards from a deck into a hand array
**             by copying the last bit of deck contents to the hand then 
**            decrementing the number of cards in deck by 1, so that last
**            bit of data wont be accessed in the future
** Parameters: pointer to a Card array (hand)
** Pre-Conditions: Hand must be made, need 8 cards, and shouldnt have any
**            thing in it to begin with
** Post-Conditions: dont try to get the info from the old deck index...
*********************************************************************/
void Deck::deal(Card* cardsinhand) {
  for (int i = 0; i < 8; i++) { //8 is starting hand size
    cardsinhand[i] = cards[--numCards];
  }
}


/*********************************************************************
** Function: getLastElementAndDecrement
** Description: This function returns the last Card in the deck
**             and shortens the deck by one cards
** Parameters: n/a
** Pre-Conditions: Deck must be made already, numCards must be accurate
** Post-Conditions: returned card should be used for something then not 
**                get accessed in the deck again
*********************************************************************/
Card Deck::getLastElementAndDecrement() {
  numCards--;
  return cards[numCards];
}

/*********************************************************************
** Function: getdeck
** Description: This function returns the array of Cards that makes the deck
** Parameters: n/a
** Pre-Conditions: Deck must be made already
** Post-Conditions: the deck can be modified
*********************************************************************/
Card* Deck::getdeck() {
  return cards;
}

/*********************************************************************
** Function: drawcard
** Description: This function removes a card from the deck and returns it
** Parameters: n/a
** Pre-Conditions: Deck must be made already
** Post-Conditions: dont access cards[numCards+x] again
*********************************************************************/
Card Deck::drawcard() {
  return cards[--numCards];
}

/*********************************************************************
** Function: getnumCards
** Description: This function returns the number of cards left in the deck
** Parameters: n/a
** Pre-Conditions: numCards should be accurate
** Post-Conditions: please dont modify numCards
*********************************************************************/
int Deck::getnumCards(){ //return num of cards left in deck
  return numCards;
}
