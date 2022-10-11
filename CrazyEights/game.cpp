#include <iostream>
#include "game.h"

using namespace std;


/*********************************************************************
** Function: make
** Description: This function intializes and shuffles the deck, deals cards
**              to players, and sets the first CIP (Card In Play)
** Parameters: n/a
** Pre-Conditions: deck shouldnt already be initialized probably
** Post-Conditions: deck is initialized, players are initialized, CIP is set
*********************************************************************/
void Game::make() {
  cards.make();                          //deck created
  cards.shuffle();                       //deck shuffled
  for (int i = 0; i < 2; i++) {          //the array of players gets filled with two players. 
    players[i].deal(cards);              //each players hand gets 8 cards from the deck.
  }
  CIP = cards.drawcard();
}


/*********************************************************************
** Function: setplayername
** Description: This function tells the player to set their name
** Parameters: n/a
** Pre-Conditions: name will be overwritten if already set
** Post-Conditions: player now has a name
*********************************************************************/
void Game::setplayername() {
  players[1].setname(); 
}


/*********************************************************************
** Function: drawcard
** Description: This function removes a card from the deck and returns it
** Parameters: n/a
** Pre-Conditions: Deck must be made already
** Post-Conditions: deck has one less card
*********************************************************************/
Card Game::drawcard() {
  return cards.drawcard();
}


/*********************************************************************
** Function: display
** Description: This function displays the "game board"
** Parameters: n/a
** Pre-Conditions: players and CIP initialized
** Post-Conditions: number of cards in computers hand, CIP, players hand, 
**                and instructions are cout-ed
*********************************************************************/
void Game::display() { //display the up card, players hand, and opponents number of cards
  cout << "\n\nComputer currently has " << players[0].cardsInHand() << " cards in their hand.\n\n" << endl;
  cout << "Card in play: " << endl;
  CIP.display();
  cout << "\n\nYour Hand:" << endl;
  players[1].showhand(CIP);
  cout << "\nChoose your action.\nEnter the number of the card you would like to play or 0 to draw a card." << endl;
}


/*********************************************************************
** Function: menu
** Description: This function displays the game, then gets and executes the users input
** Parameters: n/a
** Pre-Conditions: everything is initialized properly
** Post-Conditions: user makes an action like draw or play which is completed
*********************************************************************/
void Game::menu() {
  int action;
  do {  
    display();
    action = getValidInput();
    if (action == 0) {
      drawACard(1);
    }
    if ((action == 0) && !(players[1].canPlay(CIP)) && (cards.getnumCards() < 1)) {
      return;
    }
  }
  while (action == 0);
  playACard(1, action-1);
}


/*********************************************************************
** Function: getValidInput
** Description: This function takes user input for card to play and makes
**              sure its a valid play given the current CIP, once the input
**              is valid, it returns it as an int for the index of card to play
** Parameters: n/a
** Pre-Conditions: valid CIP, user input < 10000 chars
** Post-Conditions: user is prompted for an input until they give a valid 
**                one which gets returned
*********************************************************************/
int Game::getValidInput() {
  int action;
  do {
    cin >> action;
    cin.clear();                 //infinite loop bug fixed by these two lines. They were gotten from the following URL:
    cin.ignore(10000, '\n');      //https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
    if (action > players[1].cardsInHand() || action < 0) {
     cout << "\nYour input was not valid.\nMake sure you select a valid card number, displayed below each card." << endl;
    }
  
    else if (action != 0) {
      if ((((players[1].returncard(action-1)).getsuit() != CIP.getsuit()) && ((players[1].returncard(action-1)).getrank() != CIP.getrank())) && ((players[1].returncard(action-1)).getrank() != 8)) {
        cout << "\nYour input was not valid.\nMake sure your card selection matches the rank or suit of the card in play." << endl;
        action = -1;
      }
    }
  }
  while (action > players[1].cardsInHand() || action < 0);
  return action;
}


/*********************************************************************
** Function: eightplayed
** Description: This function asks the user what suit they want their
**              8 to swap to and returns 0-3 for suit
** Parameters: n/a
** Pre-Conditions: Deck must be made already, user can input more than 10000 characters
** Post-Conditions: new suit for the 8 gets output (0-3)
*********************************************************************/
int Game::eightplayed(){ //choose what suit to make it message
  cout << "You played an eight. Choose the suit you would like it to have.\nHeart = 0,\nDiamond = 1,\nSpade = 2,\nClub = 3.\nNote: if you enter something else, the suit will default to Hearts." << endl;
  int suit;
  cin >> suit;
  cin.clear();                
  cin.ignore(10000, '\n');
  if (suit > 3 || suit < 0) {
    suit = 0;
  }
  return suit;
}


/*********************************************************************
** Function: isGameOver
** Description: This function returns true if game is over (someone ran 
**              out of cards or there are no more cards and someone cant play)
** Parameters: n/a
** Pre-Conditions: players initialized
** Post-Conditions: true if game should end, false if it should continue
*********************************************************************/
bool Game::isGameOver(){ //TRUE if either hand size = 0 or deck = o
  for (int i = 0; i < 2; i++) {
    if ( (players[i].cardsInHand() < 1) || ((cards.getnumCards() < 1) && !(players[i].canPlay(CIP))) ){
      return true;
    }
  }
  return false;
}


/*********************************************************************
** Function: winning
** Description: This function says who won after the game is over
** Parameters: n/a
** Pre-Conditions: players initialized
** Post-Conditions: one of three options is cout-ed, user win, user lose, or tie
*********************************************************************/
void Game::winning(){  //tell user who won and such
  cout << "\n\n\n\n\nGAME OVER!\n\n" << endl;
  if ((players[0].cardsInHand()) < (players[1].cardsInHand())) {
    cout << "The computer beat you this time, " << players[1].getname() <<".\n\n" << endl;
  }
  else if ((players[0].cardsInHand()) > (players[1].cardsInHand())) {
    cout << "You win, "<< players[1].getname() << ", good job.\n\n" << endl;
  }  
  else {
    cout << "You tied with the computer, " << players[1].getname() <<".\n\n" << endl;
  }
}


/*********************************************************************
** Function: playAgain
** Description: This function asks the user if they would like to play again
** Parameters: n/a
** Pre-Conditions: user cannot input more than 10000 characters
** Post-Conditions: returned value is either 0 (dont play again) or 1 (play again)
*********************************************************************/
int Game::playAgain() {
  int playAgain;
  cout << "Play again? (1 - yes, anything else - no) ";
  cin >> playAgain;
  cin.clear();                 //infinite loop bug fixed by these two lines. They were gotten from the following URL:
  cin.ignore(10000, '\n');      //https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
  if (playAgain == 1) {
    return playAgain;
  }
  return 0;
}

/*********************************************************************
** Function: drawAcard
** Description: This function removes a card from the deck and puts it in
**              the players hand (if there are enough cards in the deck)
** Parameters: int playerIndex (0 = comp, 1 = user)
** Pre-Conditions: valid player index, deck etc. initialized, player hand
**                  must not be at capacity
** Post-Conditions: one less card in deck, one more in hand
*********************************************************************/
void Game::drawACard(int playerIndex) {//0 = comp, 1 = player
  if (cards.getnumCards() >= 1) {  //if there are enough cards, draw a card
    players[playerIndex].drawcard(cards.drawcard());    //get the card from cards.drawcard() put into their hand.
  }
  else {
    cout << "Sorry, there are no more cards to draw. The game will continue until someone cannot play." << endl;
  }
}


/*********************************************************************
** Function: playAcard
** Description: This function removes a card from the hand and makes it the CIP
**              if it was an 8, either ask player the suit or set it for the computer
** Parameters: int playerIndex (0 = comp, 1 = user), int cardIndex (which card 
**             from the players hand to play)
** Pre-Conditions: valid player index, card index, and CIP
** Post-Conditions: CIP is changed, card removed from players hand and set as new CIP
*********************************************************************/
void Game::playACard(int playerIndex, int cardIndex) {

  CIP = players[playerIndex].returncard(cardIndex); //played card is set to CIP
  
    if ((playerIndex == 1) && (CIP.getrank() == 8)) { //if its an 8, make them set the suit
      CIP.setsuit(eightplayed());
    } else if ((playerIndex == 0) && (CIP.getrank() == 8)) {
          CIP.setsuit(((players[0].returncard(0)).getsuit()));
    }
    players[playerIndex].playcard(cardIndex);          //remove the card from the hand
}


/*********************************************************************
** Function: compTurn
** Description: This function deals with all aspects of the computers turn
** Parameters: n/a
** Pre-Conditions: players and CIP initialized
** Post-Conditions: messages about computers actions are cout-ed, computer 
**          draws until it can play or there are no more cards in the
**          deck, or plays a card given the CIP
*********************************************************************/
void Game::compTurn() {
  cout << "\n\nComputers turn..." <<endl;
  
  while (!(players[0].canPlay(CIP))) {                     //comp draws until it can play (or there are no more cards)
    cout << "\nComputer cannot play. Drawing a new card...\n" << endl;
    drawACard(0);
    if (cards.getnumCards() < 1) {
      return;
    }
  }
  int cardIndex;
  for (int i= 0; i < (players[0].cardsInHand()); i++) {     //if comp can play, choose last playable card and play it
    if (((players[0].returncard(i)).getsuit() == CIP.getsuit()) || ((players[0].returncard(i)).getrank() == CIP.getrank())) {
      cardIndex = i;
    }
  }
  playACard(0, cardIndex);
}
