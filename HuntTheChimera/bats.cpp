#include <iostream>
#include "bats.h"

using namespace std;


/*********************************************************************
** Function: showsymbol
** Description: prints symbol to console
** Parameters: n/a
** Pre-Conditions: dont try to "cout" this function
** Post-Conditions: n/a
*********************************************************************/
void Bats::showsymbol() {
  cout << "B";
}


/*********************************************************************
** Function: percept
** Description: prints percept message to console
** Parameters: n/a
** Pre-Conditions: dont try to "cout" this function
** Post-Conditions: n/a
*********************************************************************/
void Bats::percept() {
  cout << "You hear wings flapping." << endl;
}


/*********************************************************************
** Function: eventhappens
** Description: prints message about event and returns int for game.cpp to use
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: you can now use the returned int to identify what event occurred
*********************************************************************/
int Bats::eventhappens() {
  cout << "\n\nOops, you walked into the bat room and got moved to a random location\n" << endl;
  return 3;
}


/*********************************************************************
** Function: getsymbol
** Description: returns event's symbol as char
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: you can now use the symbol publicly
*********************************************************************/
char Bats::getsymbol() {
  return 'B';
}
