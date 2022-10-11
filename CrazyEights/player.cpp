#include <iostream>
#include "player.h"

using namespace std;

/*********************************************************************
** Function: constructor 
** Description: This is a constructor that also constructs hands
** Parameters: hand constructor?
** Pre-Conditions: n/a
** Post-Conditions: player and their hand are now made
*********************************************************************/
Player::Player():hand() {};

/*********************************************************************
** Function: setname
** Description: This function asks the user to enter their name then sets it
** Parameters: n/a
** Pre-Conditions: player class made 
** Post-Conditions: player class can now use name member variable
*********************************************************************/
void Player::setname() {
  cout << "Enter your name: ";
  cin >> name;
}

/*********************************************************************
** Function: getname
** Description: This function returns the players name
** Parameters: n/a
** Pre-Conditions: name already initialized
** Post-Conditions: name can be used for whatever, dont change it tho
*********************************************************************/
string Player::getname(){
  return name;
}

/*********************************************************************
** Function: deal
** Description: This function calls the hand deal member function
** Parameters: reference to the deck
** Pre-Conditions: Deck must be made already
** Post-Conditions: deck gets decremented for each card taken out, hand filled
*********************************************************************/
void Player::deal(Deck & deck) {
  hand.deal(deck);
}

/*********************************************************************
** Function: cardsInHand
** Description: This function returns the number of cards in the players hand
** Parameters: n/a
** Pre-Conditions: hand already initialized
** Post-Conditions: dont change number of cards in hand
*********************************************************************/
int Player::cardsInHand() {
  return hand.cardsInHand();
}


/*********************************************************************
** Function: showcard
** Description: This function displays the players hand along with 
**              which cards are playable given the parameter card
** Parameters: Card to determine playable-ness against
** Pre-Conditions: hand made, Card In Play (CIP) valid
** Post-Conditions: n/a info is just output
*********************************************************************/
void Player::showhand(Card CIP) {
  hand.display();
  hand.displayPlayableCards(CIP);
}


/*********************************************************************
** Function: drawcard
** Description: This function removes a card from the deck and 
**               puts it in the players hand
** Parameters: Card to draw
** Pre-Conditions: everything initialized, valid card to draw
** Post-Conditions: hand now has another card
*********************************************************************/
void Player::drawcard(Card newcard) {
  hand.drawcard(newcard);
}

/*********************************************************************
** Function: playcard
** Description: This function removes a card from the hand given its index
** Parameters: int index of card to remove from hand array
** Pre-Conditions: hand initialized, index valid
** Post-Conditions: players hand has one less card now
*********************************************************************/
Card Player::playcard(int index) { //return the removed card
  return hand.playcard(index);
}


/*********************************************************************
** Function: returncard
** Description: This function returns a card from the hand given its index
** Parameters: cards index in hand as int
** Pre-Conditions: hand initialized
** Post-Conditions: dont change card unless needed please
*********************************************************************/
Card Player::returncard(int index) {
  return hand.returncard(index);
}


/*********************************************************************
** Function: canPlay
** Description: This function returns true if the player can play given a card (CIP)
** Parameters: Card to check play ability against
** Pre-Conditions: CIP initialized, hand initialized
** Post-Conditions: returns true if the player can play
*********************************************************************/
bool Player::canPlay(Card CIP) {
  return hand.canPlay(CIP);
}
