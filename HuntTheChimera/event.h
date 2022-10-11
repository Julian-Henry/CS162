/*
	This file describes the Event class. 
*/

#ifndef EVENT_H
#define EVENT_H

#include <iostream>

class Event {
  public:
    virtual void showsymbol() = 0;
    virtual void percept() = 0;
    virtual int eventhappens() = 0;
    virtual char getsymbol() = 0;
    
};

#endif
