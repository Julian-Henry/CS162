/*********************************************************************
** Program Filename: program3
** Author:  Julian Henry
** Date: 07/29/2022
** Description: This program is a small game where the player acts as 
** the owner of a zoo, which has exhibits of monkeys, sea otters, and 
** meerkats. The player must both to ensure the welfare of the animals 
** and generate as much profit as possible by investing in animals, 
** feeding them, caring for them when they are sick, and raising their 
** babies when they are born.
** Input: user inputs numbers to the console to interact with the code
** Output: information is output on the console
*********************************************************************/

/*
	This file describes the Seaotter class.
*/

#ifndef SEAOTTER_H
#define SEAOTTER_H

#include <iostream> 
#include "animal.h"

class Seaotter : public Animal {
  private:
    int cost;  
    int foodcost;
    int babiesproduced;
    int revenue;
    int type; //0 = meerkat, 1 = seaotter, 2 = monkey
    
  public:
    Seaotter();
    Seaotter(int); // int = starting age in weeks
    int gettype();
    int getcost();
};

#endif
