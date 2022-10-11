/*
	This file describes the Game class.
*/
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "game.h"
#include "card.h"
#include "deck.h"
#include "player.h"

class Game {
  private:
    Deck cards;
    Player players[2];
    Card CIP; // added this, its the face-up card "card in play"
  public:
    void make();
    void display(); //display the up card, players hand, and opponents number of cards
    Card drawcard();  // take a card from the deck
    void menu();
    void setplayername();
    int eightplayed(); //tells user to choose what suit to make it, returns the suit.
    bool isGameOver(); //TRUE if either hand size = 0 or deck = 0 and someone draws?
    void winning();  //tell user who won
    int playAgain(); //ask if play again
    void drawACard(int); //take card from deck to hand if possible, int = 0 for comp, int = 1 for player.
    void compTurn(); //deals with computers turn
    void playACard(int, int);
    int getValidInput();
};

#endif
