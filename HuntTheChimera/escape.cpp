#include <iostream>
#include "escape.h"

using namespace std;


/*********************************************************************
** Function: showsymbol
** Description: prints symbol to console
** Parameters: n/a
** Pre-Conditions: dont try to "cout" this function
** Post-Conditions: n/a
*********************************************************************/
void Escape::showsymbol() {
  cout << "E";
}


/*********************************************************************
** Function: percept
** Description: prints percept message to console
** Parameters: n/a
** Pre-Conditions: dont try to "cout" this function
** Post-Conditions: n/a
*********************************************************************/
void Escape::percept() {
//  cout << "You hear nothing related to a potential exit..." << endl;
}


/*********************************************************************
** Function: eventhappens
** Description: prints message about event and returns int for game.cpp - eventhappens() to use
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: you can now use the returned int to identify what event occurred
*********************************************************************/
int Escape::eventhappens() {
  
  cout << "\n\nYou are at the exit.\n" << endl;
  return 4;
}

/*********************************************************************
** Function: getsymbol
** Description: returns event's symbol as char
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: you can now use the symbol publicly
*********************************************************************/
char Escape::getsymbol() {
  return 'E';
}
