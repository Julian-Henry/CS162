#include <iostream>
#include "chimera.h"

using namespace std;


/*********************************************************************
** Function: showsymbol
** Description: prints symbol to console
** Parameters: n/a
** Pre-Conditions: dont try to "cout" this function
** Post-Conditions: n/a
*********************************************************************/
void Chimera::showsymbol() {
  cout << "C";
}


/*********************************************************************
** Function: percept
** Description: prints percept message to console
** Parameters: n/a
** Pre-Conditions: dont try to "cout" this function
** Post-Conditions: n/a
*********************************************************************/
void Chimera::percept() {
  cout << "You smell a terrible stench." << endl;
}


/*********************************************************************
** Function: eventhappens
** Description: prints message about event and returns int for game.cpp - eventhappens() to use
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: you can now use the returned int to identify what event occurred
*********************************************************************/
int Chimera::eventhappens() {
  cout << "\n\nOops, you disturbed the Chimera and died.\n" << endl;
  return 0;
}


/*********************************************************************
** Function: getsymbol
** Description: returns event's symbol as char
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: you can now use the symbol publicly
*********************************************************************/
char Chimera::getsymbol() {
  return 'C';
}
