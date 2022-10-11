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
	This file describes the Zoo class.
*/ 


#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <cstdlib>
#include "animal.h"

using namespace std;
class Zoo {
  private:
    int  nummeerkats; 
    int  numadultmeerkats;
    int  numbabymeerkats;
      
    int  nummonkeys;
    int  numadultmonkeys;
    int  numbabymonkeys;
      
    int  numseaotters;
    int  numadultseaotters;
    int  numbabyseaotters;
      
    int  weeks;
    int  months;
    int  years;
    
    int  numexhibits;
    int  maxexhibits; 
    int  money;
    Animal ** exhibits; 




  
  public: 
    Zoo();
    string namefromtype(int);
    bool validpurchase(int , int);
    int getint(int, int);
    void addanimalstoarray(int, int, int);
    Animal* typetoanimalptr(int, int);
    ~Zoo();
    Zoo(const Zoo& old_obj);
    Zoo& operator=(const Zoo& old_obj);
    bool  gamedone = false;
    void purchaseanimals();
    void printzooinfo();
    void timepassed();
    void calculaterevinue();
    void calculatecosts();
    void display();
    int getmoney();
    void intromessage();
    void endingmessage();
    void ageup();
    void updateexhibitstats();
    int fastforward();
    unsigned long xorshf96();
    void randomevent();
    void attendenceboom();
    void sickness() ;
    void animaldeath(int);
    void birth();
};

#endif
