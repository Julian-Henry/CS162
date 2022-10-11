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
 #include <time.h>
 #include <cstdlib>
 #include "zoo.h"
 #include "animal.h"
 #include "monkey.h"
 #include "meerkat.h"
 #include "seaotter.h"
 
using namespace std;


int main() {
  Zoo zoo;                                                  //Game phase 1: beginning
  int weekstopass = 0;
  int i = 0;
  zoo.intromessage();
  zoo.printzooinfo();
  zoo.purchaseanimals();
  
  while (zoo.getmoney() >= 0 && zoo.gamedone == false) {    //Game phase 2: gameplay loop
    i = 0;
    weekstopass = zoo.fastforward();
    while ( i < weekstopass && zoo.getmoney() >= 0 && zoo.gamedone == false) {
      zoo.ageup();                                          //animal ages incease  
      if (zoo.getmoney() > 0) {zoo.randomevent();}          //a random event takes place, messages about the effects are displayed - ie animal died, extra revinue added/subtracted, etc
      zoo.updateexhibitstats();                             //update stats
      zoo.calculaterevinue();                               //revinue from each animal is added to "money"
      zoo.calculatecosts();                                 //cost of food for each animal is subtracted from "money"
      i++;
    }
    if (zoo.getmoney() > 0 && zoo.gamedone == false) {      //only do the following if the game is still going...
      zoo.printzooinfo();                                   //shows exhibits
      zoo.purchaseanimals();                                //allow user to buy new animals
    }
  }
  zoo.endingmessage();
}
