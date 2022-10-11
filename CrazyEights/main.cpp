/******************************************************
** Program: Crazy Eights (program2)
** Author: Julian Henry
** Date: 07/15/2022
** Description:  Play crazy eights against the computer
**        following the rules given for the assignment
** Input: No command line inputs. Inputs while program runs are
**        the number of the card you want to play, 0 to draw, 0-3
**        for the suit when an eight is played, and 1 to play again
** Output: the number of cards in the computers hand, the card
**        in play, your hand, instructions, and which cards
**        are legal to play are output each turn.
******************************************************/

 #include <iostream>
 #include <time.h>
 #include <cstdlib>
 #include "deck.h"
 #include "card.h"
 #include "hand.h"
 #include "player.h"
 #include "game.h"
 
using namespace std;

int main() {
int playAgain;
  do {
    srand(time(NULL));
    Game game;
    game.make();
    game.setplayername();

    while (!game.isGameOver()) {
      game.menu();
      game.compTurn();
    }
    game.winning();
    playAgain = game.playAgain();
   } while(playAgain == 1);
   
  return 0;
}
