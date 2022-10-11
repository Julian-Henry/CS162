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
#include <algorithm>
#include "animal.h" 

using namespace std;


/*********************************************************************
** Function: display
** Description: displays animals stage and name (type)
** Parameters: n/a
** Pre-Conditions: initialized animal
** Post-Conditions: user knows more about the animal now
*********************************************************************/
void Animal::display() {
  cout << getstage() << " " << getname();
}


/*********************************************************************
** Function: getname
** Description: returns the name of the animal using its type (0-2)
** Parameters: n/a
** Pre-Conditions: initialized animal
** Post-Conditions: you can now use animal name publicly
*********************************************************************/
string Animal::getname() {
  switch (gettype()) {
    case 0: return "meerkat"; break;
    case 1: return "sea otter"; break;
    case 2: return "monkey"; break;
    default: return "uh oh... check animal:: display..."; break;
  }
}

/*********************************************************************
** Function: ageup
** Description: increments an animal's age
** Parameters: n/a
** Pre-Conditions: initialized animal
** Post-Conditions: animal is one week older
*********************************************************************/
void Animal::ageup() {
  age++;
}


/*********************************************************************
** Function: getage
** Description: returns age of animal
** Parameters: n/a
** Pre-Conditions: initialized animal
** Post-Conditions: can now use age for whatever
*********************************************************************/
int Animal::getage() {
  return age;
}


/*********************************************************************
** Function: gettype
** Description: returns the type of the animal
** Parameters: n/a
** Pre-Conditions: initialized animal
** Post-Conditions: you can now use type for whatever
*********************************************************************/
int Animal::gettype() {
  return type;
}


/*********************************************************************
** Function: getstage
** Description: returns the stage of life of the animal as string
** Parameters: n/a
** Pre-Conditions: initialized animal
** Post-Conditions: you can now use the age for whatever
*********************************************************************/
string Animal::getstage() { //0 = baby, 1 = adolescent or 2 = adult
  if (age < 7) {          //seven weeks in weeks
    return "baby";
  } else if (age > 104) { //two years in weeks
    return "adult";
  }
  else {
    return "adolescent";
  }
}


/*********************************************************************
** Function: getcost
** Description: returns the cost to buy an animal given its type
** Parameters: n/a
** Pre-Conditions: initialized animal
** Post-Conditions: you can now use the cost for whatever
*********************************************************************/
int Animal::getcost() { //0 = meerkat, 1 = sea otter, 2 = monkey
  switch (type) {
    case 0: 
      return MEERKATCOST;
      break;
    case 1: 
      return SEAOTTERCOST;
      break;
    default: 
      return MONKEYCOST;
      break;
  }
}


/*********************************************************************
** Function: calculatesickcost
** Description: returns the cost of medicine for an animal
** Parameters: n/a
** Pre-Conditions: initialized animal
** Post-Conditions: you can now use the sick cost for whatever
*********************************************************************/
int Animal::calculatesickcost() {
  int SC = getcost()*.2;    //20%of initial cost unless its a baby
  if (getstage() == "baby") {
    SC *= 2;
  }
  return SC;
}
