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
	This file describes the Animal class.
*/ 

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <cstdlib>

#define BASEFOODCOST 25
#define MEERKATCOST 500
#define SEAOTTERCOST 4000
#define MONKEYCOST 12000

using namespace std;
class Animal {
  protected:
    int type; //0 = meerkat, 1 = sea otter, 2 = monkey
    int cost;  
    int babiesproduced;
    int revenue;
    int age;  // in weeks
    
  public: 
    virtual ~Animal() {};
    virtual void display();
    int calculatesickcost();
    string getstage(); //baby, adolescent or adult
    virtual int gettype();
    virtual string getname();
    void ageup();
    int getage();
    virtual int getcost();
};

#endif
