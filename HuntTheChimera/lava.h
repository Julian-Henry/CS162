/*
	This file describes the Lava class. 
*/

#ifndef LAVA_H
#define LAVA_H

#include <iostream>
#include "event.h"

class Lava : public Event {
  public:
    void showsymbol();
    void percept();
    int eventhappens();
    char getsymbol();
};

#endif
