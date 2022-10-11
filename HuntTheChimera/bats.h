/*
	This file describes the Bats class. 
*/

#ifndef BATS_H
#define BATS_H

#include <iostream>
#include "event.h"

class Bats : public Event {
  public:
    void percept();
    void showsymbol();
    int eventhappens();
    char getsymbol();
};

#endif
