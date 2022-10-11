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
#include "seaotter.h"
 
using namespace std;


/*********************************************************************
** Function: Constructor
** Description: sets cost, type, then sets age to argument
** Parameters: int age to make animal in weeks
** Pre-Conditions: a >= 0
** Post-Conditions: sea otter has now been initialized
*********************************************************************/
Seaotter::Seaotter(int a) {
  age = a;
  cost = 4000;
  type = 1; //0 = meerkat, 1 = sea otter, 2 = monkey
//  cout << " Age: " << getage() << " sea otter constructed"<< endl;
}


/*********************************************************************
** Function: default constructor
** Description: sets cost, type, and age
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: sea otter has now been initialized
*********************************************************************/
Seaotter::Seaotter() {
//  cout << "baby (default) sea otter constructed"<< endl;
  type = 1; //0 = meerkat, 1 = sea otter, 2 = monkey
  age = 0; 
  cost = 4000;
}


/*********************************************************************
** Function: gettype
** Description: returns type as int (1)
** Parameters: n/a
** Pre-Conditions: initialized animal
** Post-Conditions: you can now use type publicly
*********************************************************************/
int Seaotter::gettype() {
  return type;
}


/*********************************************************************
** Function: getcost
** Description: returns cost
** Parameters: n/a
** Pre-Conditions: initialized animal
** Post-Conditions: you can now use cost publicly
*********************************************************************/
int Seaotter::getcost() {
  return cost;
}
