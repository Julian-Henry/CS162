#include <iostream>
#include <algorithm>
#include "hand.h"

using namespace std;


/*********************************************************************
** Function: default constructor
** Description: sets cards to correct starting number and ASSIGNS DYNAMIC MEMORY
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: your hand has now been initialized, wahoo
*********************************************************************/
Hand::Hand() {
  numCards = 8;
  cards = new Card[43]; //52(starting cards) -8 (from other players hand) -1 (from first card to play on) = max number of cards in hand.
}


/*********************************************************************
** Function: destructor
** Description: DELETES DYNAMIC MEMORY phew
** Parameters: n/a
** Pre-Conditions: dynamic memory cant already have been deleted
** Post-Conditions: dont try to access the memory any more, it gone
*********************************************************************/
Hand::~Hand() {
  delete [] cards;
}

/*********************************************************************
** Function: copy constructor
** Description: deep copy (this is required but not used...)
** Parameters: constant reference to Hand
** Pre-Conditions: one hand already made
** Post-Conditions: now theres another that wont access the same DYNAMIC MEMORY
*********************************************************************/
Hand::Hand(const Hand& old_obj) {

	numCards = old_obj.numCards;
 
  if (numCards > 0) {
    cards = new Card[numCards];
    for (int i = 0; i < numCards; i++) {
      cards[i] = old_obj.cards[i];
    }
  } 
  else {
    cards = NULL; 
  }
}


/*********************************************************************
** Function: assignment operator overload
** Description: deep copy one hand to another (again required but not used...)
** Parameters: constant reference to hand i guess
** Pre-Conditions: both hands are already made
** Post-Conditions: now one is like the other okay
*********************************************************************/
Hand& Hand::operator=(const Hand& old_obj) {
	delete [] cards;  // delete any existing memory allocation
	
	numCards = old_obj.numCards; 	// copy over the existing data

	if (numCards > 0) { 	// allocate new space and copy the entries
		cards = new Card[numCards];
		for (int i = 0; i < numCards; i++) {
			cards[i] = old_obj.cards[i];
		}
	} 
  else {cards = NULL;}

	return *this;
}

/*********************************************************************
** Function: deal
** Description: This function takes 8 cards from the given deck and puts them
**              into the hand.
** Parameters: reference to deck
** Pre-Conditions: Deck must be made already, and have 8+ cards
** Post-Conditions: hand now has 8 cards, deck has 8 less
*********************************************************************/
void Hand::deal(Deck & deck) {
  for (int i = 0; i < 8; i++) { //8 is starting hand size
    cards[i] = deck.getLastElementAndDecrement();
  }  
}


/*********************************************************************
** Function: playcard
** Description: This function removes a card from the hand and resises the 
**              hand and return the removed card
** Parameters: index of card to remove
** Pre-Conditions: valid index, non-NULL hand
** Post-Conditions: hand has one less card which gets returned and its 
**                  is decremented
*********************************************************************/
Card Hand::playcard(int index) {

	Card tmp = cards[index];  	// get a copy of the card

	for (int i = 0; i < (numCards - index - 1); i++) {	// scoot all the lower cards up by one position
		cards[index + i] = cards[index + i + 1];
	}
	numCards--;	// there is one less card on the cart

	return tmp;
}


/*********************************************************************
** Function: drawcard
** Description: This function adds a card to the end of the hand
** Parameters: Card that gets added to hand
** Pre-Conditions: valid card and hand, hand cant be max size.
** Post-Conditions: one more card in hand
*********************************************************************/
void Hand::drawcard(Card newcard) {
  cards[numCards] = newcard;
  numCards++;
}

/*********************************************************************
** Function: display
** Description: This function displays all the cards in the hand
** Parameters: n/a
** Pre-Conditions: cards in hand initialized
** Post-Conditions: n/a info is just cout-ed
*********************************************************************/
void Hand::display() {
  for (int i = 0; i < numCards; i++) /*top of cards*/ {cout << " ___  ";}
  cout << endl;
  for (int i = 0; i < numCards; i++) /*Rank line*/ {
    cout << "| ";
    cards[i].displayRank();
    cout << "| ";}
  
  cout << endl;
  for (int i = 0; i < numCards; i++) /*Suit line*/ {
    cout << "| ";
    cards[i].displaySuit();
    cout << " | ";}
    
  cout << endl;
  for (int i = 0; i < numCards; i++) /*bottom of cards*/ {
    cout << "|___| ";}  

  cout << endl;
  for (int i = 0; i < numCards; i++) /*number of cards*/ { 
    if ((i+1) < 10) { cout << "  " << i+1 << ".  "; }
    else cout << "  " << i+1 << ". ";
  }
  cout << endl;
}


/*********************************************************************
** Function: returncard
** Description: This function returns the card at the given index
** Parameters: index of card to return
** Pre-Conditions: valid index, hand initialized
** Post-Conditions: please dont mess with returned card
*********************************************************************/
Card Hand::returncard(int index) {
  return cards[index];
}


/*********************************************************************
** Function: cardsInHand
** Description: This function returns the number of cards left in the hand
** Parameters: n/a
** Pre-Conditions: hand must be made already
** Post-Conditions: int returned of number of cards in hand
*********************************************************************/
int Hand::cardsInHand() {
  return numCards;
}


/*********************************************************************
** Function: addcard
** Description: This function increments the number of cards in the hand
** Parameters: n/a
** Pre-Conditions: hand made already, and cant be at max hand size
** Post-Conditions: hand size is now one bigger
*********************************************************************/
void Hand::addcard() {
  numCards++;
}

/*********************************************************************
** Function: removecard
** Description: This function decrements the number of cards in the hand
** Parameters: n/a
** Pre-Conditions: hand made already, and cant be at size 0
** Post-Conditions: hand size is now one smaller
*********************************************************************/
void Hand::removecard() {
  numCards--;
}


/*********************************************************************
** Function: displayPlayableCards
** Description: This function shows which cards are playable given the CIP 
** Parameters: Card to check play ability against
** Pre-Conditions: valid arg Card, hand made
** Post-Conditions: info is cout-ed, works with display function to be readable
*********************************************************************/
void Hand::displayPlayableCards(Card CIP) {
  for (int i = 0; i < numCards; i++) {
    if ((cards[i].getsuit() == CIP.getsuit()) || (cards[i].getrank() == CIP.getrank()) || (cards[i].getrank() == 8)) {
      cout << "  ^   ";
    }
    else 
      cout << "      ";
  }
}


/*********************************************************************
** Function: canPlay
** Description: This function returns true if you can play given a Card
** Parameters: Card to check play ability against
** Pre-Conditions: valid arg card, hand initialized
** Post-Conditions: returns true if a card from the hand can be played
*********************************************************************/
bool Hand::canPlay(Card CIP) {
  for (int i = 0; i < numCards; i++) {
    if ((cards[i].getsuit() == CIP.getsuit()) || (cards[i].getrank() == CIP.getrank()) || (cards[i].getrank() == 8)) {
      return true;
    }
  }
  return false;
}
