#include <iostream>
#include "lava.h"

using namespace std;


/*********************************************************************
** Function: showsymbol
** Description: prints symbol to console
** Parameters: n/a
** Pre-Conditions: dont try to "cout" this function
** Post-Conditions: n/a
*********************************************************************/
void Lava::showsymbol() {
  cout << "L";
}


/*********************************************************************
** Function: percept
** Description: prints percept message to console
** Parameters: n/a
** Pre-Conditions: dont try to "cout" this function
** Post-Conditions: n/a
*********************************************************************/
void Lava::percept() {
  cout << "You feel an intense blast of heat." << endl;
}


/*********************************************************************
** Function: eventhappens
** Description: prints message about event and returns int for game.cpp - eventhappens() to use
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: you can now use the returned int to identify what event occurred
*********************************************************************/
int Lava::eventhappens() {
  cout << "\n\nOops, you fell into a lava pit and died.\n" << endl;
  return 0;
}


/*********************************************************************
** Function: getsymbol
** Description: returns event's symbol as char
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: you can now use the symbol publicly
*********************************************************************/
char Lava::getsymbol() {
  return 'L';
}
