#include <iostream>
#include "room.h"
#include "lava.h"

using namespace std;


/*********************************************************************
** Function: showsymbol
** Description: prints event's symbol
** Parameters: n/a
** Pre-Conditions: dont try to "cout" it, evptr shouldnt point to garbage
** Post-Conditions: n/a
*********************************************************************/
void Room::showsymbol() {
  if (evptr != nullptr)
    evptr->showsymbol();
  else
    cout << " ";
}


/*********************************************************************
** Function: percept
** Description: prints event in rooms percept message
** Parameters: n/a
** Pre-Conditions: evptr must not point to garbage
** Post-Conditions: n/a
*********************************************************************/
void Room::percept() {
  if (evptr != nullptr)
    evptr->percept();
}


/*********************************************************************
** Function: eventhappens
** Description: prints info about the event and returns an int identifying
**              what happened to game.cpp - eventhappens()
** Parameters: n/a
** Pre-Conditions: evptr must not point to garbage
** Post-Conditions: you can now use the int for whatever
*********************************************************************/
int Room::eventhappens() {
  if (evptr != nullptr)
    return evptr->eventhappens();
  else
    return 1;
}


/*********************************************************************
** Function: getsymbol
** Description: returns the event in the room's symbol as char if applicable
** Parameters: n/a
** Pre-Conditions: evptr must not point to garbage
** Post-Conditions: you can now use the symbol publicly
*********************************************************************/
char Room::getsymbol() {
  if (evptr != nullptr)
    return evptr->getsymbol();
  else
    return ' ';
}
