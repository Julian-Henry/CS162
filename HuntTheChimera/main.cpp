/*********************************************************************
** Program Filename: program4
** Author:  Julian Henry
** Date: 08/11/2022
** Description: Hunt the Chimera is set in a dungeon. The player's must guide 
                an adventurer through the dungeon (using wasd), avoiding hazards 
                to kill the Chimera, find its hidden gold, and escape alive. To
                reiterate, the player must kill the monster AND take the gold to win.
** Input: user inputs numbers and strings to the console to interact with the code
**       Also, the initial input is through the command line.
** Output: information is output on the console
*********************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
 #include <time.h>
 #include "bats.h"
 #include "chimera.h"
 #include "gold.h"
 #include "lava.h"
 #include "event.h"
 #include "game.h"


using namespace std;


int main(int argc, char* argv[]) {
  bool firsttime = true;
  if (argc != 3) {
    cout << "You are supposed to provide a command line argument with the dungeon size (>=4) and true or false (true = debug(map) mode)." << endl;
		return 1;
	}
  Game game;
  do {
    cout << "\n\n\n\nWelcome to Hunt the Chimera.\nYour goal is to take the gold, kill the Chimera and get back to the exit.\nGood luck!\n\n\n" << endl;
    if (firsttime) {
      firsttime = false;
      game.initialize(atoi(argv[1]), argv[2]);
    } else {
      game.initialize(0, "doesntmatter");
    } 
    while (!(game.gameover)) {
      game.taketurn();
    }
  } while (game.playagain());
}
