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

#include <iostream>
#include "meerkat.h"

using namespace std; 


/*********************************************************************
** Function: Constructor
** Description: sets cost, type, then sets age to argument
** Parameters: int age to make animal in weeks
** Pre-Conditions: a >= 0
** Post-Conditions: meerkat has now been initialized
*********************************************************************/
Meerkat::Meerkat(int a) {
  cost = MEERKATCOST;
  type = 0; //0 = meerkat, 1 = sea otter, 2 = monkey
  age = a; 
}


/*********************************************************************
** Function: default constructor
** Description: sets cost, type, and age
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: meerkat has now been initialized
*********************************************************************/
Meerkat::Meerkat() {
  cost = MEERKATCOST;
  type = 0; //0 = meerkat, 1 = sea otter, 2 = monkey
  age = 0; 
}


/*********************************************************************
** Function: gettype
** Description: returns the type of the meerkat as an int (0)
** Parameters: n/a
** Pre-Conditions: initialized animal
** Post-Conditions: you can now use type publicly
*********************************************************************/
int Meerkat::gettype() {
  return type;
}


/*********************************************************************
** Function: getcost
** Description: returns cost
** Parameters: n/a
** Pre-Conditions: initialized animal
** Post-Conditions: you can now use cost publicly
*********************************************************************/
int Meerkat::getcost() {
  return cost;
}
