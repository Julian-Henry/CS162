/*
	This file describes the Chimera class. 
*/

#ifndef CHIMERA_H
#define CHIMERA_H

#include <iostream>
#include "event.h"

class Chimera : public Event {
  public:
    void showsymbol();
    void percept();
    int eventhappens();
    char getsymbol();
};

#endif
