/*
	This file describes the Gold class. 
*/

#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include "event.h"

class Gold : public Event {
  public:
    void showsymbol();
    void percept();
    int eventhappens();
    char getsymbol();
};

#endif
