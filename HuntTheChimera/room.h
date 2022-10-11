/*
	This file describes the Room class. 
*/

#ifndef ROOM_H
#define ROOM_H
#include "event.h"

#include <iostream>

class Room {
  public:
    Event* evptr;
    void showsymbol();
    void percept();
    int eventhappens();
    char getsymbol();
};

#endif
