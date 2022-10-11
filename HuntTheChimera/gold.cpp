#include <iostream>
#include "gold.h"

using namespace std;


/*********************************************************************
** Function: showsymbol
** Description: prints symbol to console
** Parameters: n/a
** Pre-Conditions: dont try to "cout" this function
** Post-Conditions: n/a
*********************************************************************/
void Gold::showsymbol() {
  cout << "G";
}


/*********************************************************************
** Function: percept
** Description: prints percept message to console
** Parameters: n/a
** Pre-Conditions: dont try to "cout" this function
** Post-Conditions: n/a
*********************************************************************/
void Gold::percept() {
  cout << "You notice the shine of bullion in the distance." << endl;
}


/*********************************************************************
** Function: eventhappens
** Description: prints message about event and returns int for game.cpp - eventhappens() to use
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: you can now use the returned int to identify what event occurred
*********************************************************************/
int Gold::eventhappens() {
  cout << "\n\nHooray, you found the gold!\n" << endl;
  return 2;
}


/*********************************************************************
** Function: getsymbol
** Description: returns event's symbol as char
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: you can now use the symbol publicly
*********************************************************************/
char Gold::getsymbol() {
  return 'G';
}
