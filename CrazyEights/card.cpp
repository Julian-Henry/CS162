#include <iostream>
#include "card.h"

using namespace std;


/*********************************************************************
** Function: setContent
** Description: This function sets the contents for the card class 
** Parameters: rank(a) and suit(b) as ints
** Pre-Conditions: a must be 0-12, b must be 0-3
** Post-Conditions: rank must not change. suit can only change if rank
**                 is 8
*********************************************************************/
void Card::setContent(int a, int b) {
  rank = a;
  suit = b;
}

/*********************************************************************
** Function: getrank
** Description: This function returns the rank of a Card
** Parameters: n/a
** Pre-Conditions: Card must be made already
** Post-Conditions: rank can be used for whatever
*********************************************************************/
int Card::getrank() {
  return rank;
}

/*********************************************************************
** Function: getsuit
** Description: This function returns the suit of a Card
** Parameters: n/a
** Pre-Conditions: Card must be made already
** Post-Conditions: suit can be used for whatever
*********************************************************************/
int Card::getsuit() {
  return suit;
}

/*********************************************************************
** Function: displayRank
** Description: This function works with display and displaySuit to 
**              display every part of a card. 
** Parameters: n/a
** Pre-Conditions: Card must be made already
** Post-Conditions: n/a
*********************************************************************/
void Card::displayRank() {
  switch(rank) { //11 = jack 12 = queen, 0 = king, 1 = ace
    case 10:
      cout << rank;
      break;
    case 11:
      cout << "J ";
      break;
    case 12:
      cout << "Q ";
      break;
    case 0:
      cout << "K ";
      break;
    case 1:
      cout << "A ";
      break;    
    default:
      cout << rank << " ";
  }  
}

/*********************************************************************
** Function: displaySuit
** Description: This function works with display and displayRank to 
**              display every part of a card. 
** Parameters: n/a
** Pre-Conditions: Card must be made already
** Post-Conditions: n/a
*********************************************************************/
void Card::displaySuit() {
  switch(suit) { //0 == heart, 1 == diamond, 2 === spade, 3 == club.
    case 0:
      cout << "H";
      break;
    case 1:
      cout << "D";
      break;
    case 2:
      cout << "S";
      break;
    default:
      cout << "C";
  }
}

/*********************************************************************
** Function: display
** Description: This function displays a Card
** Parameters: n/a
** Pre-Conditions: Card must be made already
** Post-Conditions: rank can be used for whatever
*********************************************************************/
void Card::display() {
  cout << "  ___\n | ";
  displayRank();
  cout <<  "|\n | ";  
  displaySuit();   
  cout << " |\n |___| " << endl;
}

/*********************************************************************
** Function: setsuit
** Description: This function changes a cards suit. Used for 8's 
** Parameters: int
** Pre-Conditions: newsuit 0-3
** Post-Conditions: n/a
*********************************************************************/
void Card::setsuit(int newsuit) {
  suit = newsuit;
}
