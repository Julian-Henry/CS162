/*
	This file describes the Escape class. 
*/

#ifndef ESCAPE_H
#define ESCAPE_H

#include <iostream>
#include "event.h"

class Escape : public Event {
  public:
    void percept();
    void showsymbol();
    int eventhappens();
    char getsymbol();
};

#endif
