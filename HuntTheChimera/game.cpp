 #include <iostream>
 #include <stdlib.h>
 #include "bats.h"
 #include "chimera.h"
 #include "gold.h"
 #include "lava.h"
 #include "event.h"
 #include "game.h"
 #include "escape.h"

using namespace std;

#define ARROWRANGE 3


/*********************************************************************
** Function: getsizeandmode
** Description: gets user to input valid dungeon size and debug mode
** Parameters: int of size user wants to have dungeon and string of debug more t/f
** Pre-Conditions: n/a
** Post-Conditions: dungeonsize and showmap now have values
*********************************************************************/
void Game::getsizeandmode(int size, string mode) {
  dungeonsize = size;
  string debugmode = mode;
  while (checkvalidstart(dungeonsize, debugmode) == 1) {
    cout << "Enter dungeon size (int >=4): ";
    cin >> dungeonsize;
    cin.clear();
    cin.ignore(10000, '\n');    
    cout << "Enter debug mode specifier (\"true\" = map): "; 
    cin >> debugmode;
    cin.clear();
    cin.ignore(10000, '\n');    
  }
  if (debugmode == "true") {showmap = true;}
  else {showmap = false;}
}


/*********************************************************************
** Function: initialize
** Description: sets up dungeon/game with users size/ mode
** Parameters: int of dungeon size and string of game mode
** Pre-Conditions: n/a
** Post-Conditions: the dungeon is now all ready to use/ game ready to start!
*********************************************************************/
void Game::initialize(int size, string mode) {
  gameover = false;
  chimeradead = false;
  goldcollected = false;
  numarrows = 3;
  getsizeandmode(size, mode);
  cave = vector<vector<Room>>(dungeonsize, vector<Room>(dungeonsize));
  for (int i = 0; i < dungeonsize; i++) {
    for (int j = 0; j < dungeonsize; j++) {
      cave[i][j].evptr = nullptr;
     }
  }
  setevents();
  setplayer();
  cave[playerR][playerC].evptr = &escape;
  escapeR = playerR;
  escapeC = playerC;
}


/*********************************************************************
** Function: taketurn
** Description: displays game info (arrows, map, character options), and
**              gets user input. Repeats until game is over
** Parameters: n/a
** Pre-Conditions: initialized dungeon
** Post-Conditions: game is now over
*********************************************************************/
void Game::taketurn() {
  string action;
  do {
    displaypercepts();
    showdungeon();
    cout << "You have " << numarrows << " arrows left." << endl;
    do {
      cout << "\nWhat will you do (move with wasd, fire arrow with space+wasd)? ";
      getline(cin, action);
    } while (!processmove(action));
    eventhappens();
  } while (!gameover);
}


/*********************************************************************
** Function: eventhappens
** Description: determines what happens to character based on what room 
**              they are in then does it
** Parameters: n/a
** Pre-Conditions: initialized dungeon, functions work properly
** Post-Conditions: event happened, now user is ready for next turn
*********************************************************************/
void Game::eventhappens() {
  int outcome = cave[playerR][playerC].eventhappens();
  if ( outcome == 0) {      //death
    cout << "\tGAME OVER" << endl;
    gameover = true;
  } else if (outcome == 2) { //gold collected
    goldcollected = true;
    removeeventfromroom('G');
  }else if (outcome == 3) { //bats moved them
    setplayer();
  }else if (outcome == 4) { //player is at exit
    if (chimeradead && goldcollected) {
      cout << "\n\n\tYOU DID IT! CONGRATS\n\n" << endl;
      gameover = true;
    }
  }
}


/*********************************************************************
** Function: processmove
** Description: determines if user input is valid then does what said 
**              valid input should. returns true if action was valid
** Parameters: string of user action
** Pre-Conditions: initialized dungeon
** Post-Conditions: either players action is complete or they have to 
**                  input a valid prompt
*********************************************************************/
bool Game::processmove(string action) {
  if (action  == "w") {
    if (playerR > 0) {playerR--; return true;}
    else {cout << "\n\tinvalid move" << endl; return false;}
  } else if (action  == "a") {
    if (playerC > 0) {playerC--; return true;}
    else {cout << "\n\tinvalid move" << endl; return false;}  
  } else if (action  == "s") {
    if (playerR < dungeonsize - 1) {playerR++; return true;}
    else {cout << "\n\tinvalid move" << endl; return false;}
  } else if (action  == "d") {
    if (playerC < dungeonsize - 1) {playerC++; return true;}
    else {cout << "\n\tinvalid move" << endl; return false;}
  } else if (action == " w") {      //up = 0, right = 1, down = 2, left = 3
    shootarrow(0); return true;
  } else if (action == " a") {
    shootarrow(3); return true;
  } else if (action == " s") {
    shootarrow(2); return true;
  } else if (action == " d") {
    shootarrow(1); return true;
  } else {
    cout << "\n\tinvalid move" << endl;
    return false;
  }
}


/*********************************************************************
** Function: checkvalidstart
** Description: checks if the users input is valid. returns 0 if so
** Parameters: int user input size, string user input map mode
** Pre-Conditions: n/a
** Post-Conditions: you now know if user parameters are valid
*********************************************************************/
int Game::checkvalidstart(int size, string mode) {
  if (size < 4) {
    cout << "please check your dungeon size." << endl;
    return 1;
  }
  else if (mode != "true" && mode != "false") {
    cout << "please check your debug mode specifier." << endl;
    return 1;
  } else {
    return 0;
  }
}


/*********************************************************************
** Function: xorshf
** Description: this function was found at the url:https://stackoverflo
**              w.com/questions/1640258/need-a-fast-random-generator-for-c
**              it returns a random unsigned long.
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: use random number for whatever
*********************************************************************/
static unsigned long x=123456789, y=362436069, z=521288629;

unsigned long xorshf() {
  unsigned long t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

   t = x;
   x = y;
   y = z;
   z = t ^ x ^ y;

  return z;
}


/*********************************************************************
** Function: setevents
** Description: sets each event in a random room
** Parameters: n/a
** Pre-Conditions: assigneventnewroom works how it should
** Post-Conditions: the dungeon has now been populated with events
*********************************************************************/
void Game::setevents() {
  assigneventnewroom(&bats);
  assigneventnewroom(&bats);
  assigneventnewroom(&lava);
  assigneventnewroom(&lava);  
  assigneventnewroom(&chimera);  
  assigneventnewroom(&gold);
}


/*********************************************************************
** Function: assigneventnewroom
** Description: puts event specified into a random empty room
** Parameters: pointer to event that you want in the dungeon
** Pre-Conditions: initialized dungeon
** Post-Conditions: the event has been added to the dungeon
*********************************************************************/
void Game::assigneventnewroom(Event* event) {
  int ro = xorshf() % dungeonsize;
  int co = xorshf() % dungeonsize;
   while (cave[ro][co].evptr != nullptr) {
    ro = xorshf() % dungeonsize;
    co = xorshf() % dungeonsize;
  }
  cave[ro][co].evptr = event;
}


/*********************************************************************
** Function: setplayer
** Description: puts the player in a random empty room
** Parameters: n/a
** Pre-Conditions: dungeon initialized
** Post-Conditions: you are now in the dungeon... good luck
*********************************************************************/
void Game::setplayer() {
  int ro = xorshf() % dungeonsize;
  int co = xorshf() % dungeonsize;
   while (cave[ro][co].evptr != nullptr) {
    ro = xorshf() % dungeonsize;
    co = xorshf() % dungeonsize;
  }
  playerR = ro;
  playerC = co;
}


/*********************************************************************
** Function: showdungeon
** Description: prints the dungeon grid. If debug mode, shows event locations
** Parameters: n/a
** Pre-Conditions: initialized dungeon
** Post-Conditions: now user knows more about where they are etc
*********************************************************************/
void Game::showdungeon() {
  for (int i = 0; i < dungeonsize; i++) /*top of dungeon*/ {cout << " __";}
  cout << endl;
  for (int r = 0; r < dungeonsize; r++) {
    for (int c = 0; c < dungeonsize; c++) /*"in room" line*/ {
      cout << "|";
      if (r == playerR && c == playerC) {cout << "P";}
      else {cout << " ";}
      if (showmap) {
        if (cave[r][c].getsymbol() == 'G' && goldcollected) {cout << " ";}
        else if (cave[r][c].getsymbol() == 'C' && chimeradead) {cout << " ";}
        else {cave[r][c].showsymbol();}
      } else {cout << " ";}
    }
    cout << "|\n|"; // new line after row
    for (int i = 0; i < dungeonsize; i++) /*bottom of dungeon rooms*/ {cout << "__|";}
  cout << endl;
  }
}


/*********************************************************************
** Function: displaypercepts
** Description: shows user percepts of adjacent rooms
** Parameters: n/a
** Pre-Conditions: initialized dungeon/player position
** Post-Conditions: player knows more about their surroundings now
*********************************************************************/
void Game::displaypercepts() {
  if (playerR > 0) {
    cave[playerR-1][playerC].percept();
  }
  if (playerC > 0) {
    cave[playerR][playerC-1].percept();
  }
  if (playerR < dungeonsize -1) {
    cave[playerR+1][playerC].percept();
  }
  if (playerC < dungeonsize -1) {
    cave[playerR][playerC+1].percept();
  }
}


/*********************************************************************
** Function: shootarrow
** Description: shoots arrow in direction specified by parameter
** Parameters: int of direction, up = 0, right = 1, down = 2, left = 3
** Pre-Conditions: initialized dungeon etc
** Post-Conditions: arrow has been shot/done all it needs to
*********************************************************************/
void Game::shootarrow(int direction) { 
  arrowR = playerR;
  arrowC = playerC;
  if (numarrows > 0) {
    numarrows--;
    switch (direction) {
      case 0://up
        cout << "You shot an arrow up." << endl;
        shotup();
        break;
      case 1://right
        cout << "You shot an arrow right." << endl;
        shotright();
        break; 
      case 2://down
        cout << "You shot an arrow down." << endl;
        shotdown();
        break;
      case 3://left
        cout << "You shot an arrow left." << endl;
        shotleft();
        break;
    } 
    if (!chimeradead) {chimNOTshot();}
  } else {cout << "You are out of arrows." << endl;}
  cout << "You now have " << numarrows << " arrows left." << endl;
}


/*********************************************************************
** Function: shotup
** Description: shoots arrow up, kills chimera if applicable
** Parameters: n/a
** Pre-Conditions: everything initialized
** Post-Conditions: chimera dead or not, one less arrow in quiver
*********************************************************************/
void Game::shotup() {
  for (int i = 0; i < ARROWRANGE; i++) {
    if (arrowR > 0) {
      arrowR--;
      if (cave[arrowR][arrowC].getsymbol() == 'C') {
        chimshot();
      }
    } 
  }
}


/*********************************************************************
** Function: shotright
** Description: shoots arrow right, kills chimera if applicable
** Parameters: n/a
** Pre-Conditions: everything initialized
** Post-Conditions: chimera dead or not, one less arrow in quiver
*********************************************************************/
void Game::shotright() {
  for (int i = 0; i < ARROWRANGE; i++) {
    if (arrowC > dungeonsize - 1) {
      arrowC++;
      if (cave[arrowR][arrowC].getsymbol() == 'C') {
        chimshot();
      }
    }
  }
}


/*********************************************************************
** Function: shotdown
** Description: shoots arrow down, kills chimera if applicable
** Parameters: n/a
** Pre-Conditions: everything initialized
** Post-Conditions: chimera dead or not, one less arrow in quiver
*********************************************************************/
void Game::shotdown() {
  for (int i = 0; i < ARROWRANGE; i++) {
    if (arrowR < dungeonsize - 1) {
      arrowR++;
      if (cave[arrowR][arrowC].getsymbol() == 'C') {
        chimshot();
      }
    }
  }
}


/*********************************************************************
** Function: shotleft
** Description: shoots arrow left, kills chimera if applicable
** Parameters: n/a
** Pre-Conditions: everything initialized
** Post-Conditions: chimera dead or not, one less arrow in quiver
*********************************************************************/
void Game::shotleft() {
  for (int i = 0; i < ARROWRANGE; i++) {
    if (arrowC > 0) {
      arrowC--;
      if (cave[arrowR][arrowC].getsymbol() == 'C') {
        chimshot();
      }
    }
  }
}


/*********************************************************************
** Function: removeeventfromroom
** Description: gets rid of all of one type of event from dungeon
** Parameters: char of symbol of event to get rid of
** Pre-Conditions: everything initialized
** Post-Conditions: one less type of event in dungeon
*********************************************************************/
void Game::removeeventfromroom(char eventsymbol) {
  for (int i = 0; i < dungeonsize; i++) {
    for (int j = 0; j < dungeonsize; j++) {
      if (cave[i][j].getsymbol() == eventsymbol) {
        cave[i][j].evptr = nullptr;
      }
    }
  }
}



/*********************************************************************
** Function: playagain
** Description: asks user if they want to play again, returns true if they do
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: now you know if player wants another go
*********************************************************************/
bool Game::playagain() { 
  int choice;
  cout << "Would you like to play again?\nOptions:\n1 = play again\nanything else = quit" << endl;
  cin >> choice;
  cin.clear();
  cin.ignore(10000, '\n');
  if (choice == 1) {
    return true;
  } else {
    cout << "Thanks for playing." << endl;
    return false;
  }
}


/*********************************************************************
** Function: chimshot
** Description: says the chimera has been shot, removes it from the dungeon,
**              and sets chimeradead to true
** Parameters: n/a
** Pre-Conditions: initialized everything
** Post-Conditions: chimera isnt there anymore and player knows it
*********************************************************************/
void Game::chimshot() {
  cout << "You shot and killed the chimera!" << endl;
  chimeradead = true;
  removeeventfromroom('C');
}


/*********************************************************************
** Function: chimNOTshot
** Description: says the chimera hasnt been shot, and moves it to a 
**              new random room
** Parameters: n/a
** Pre-Conditions: everything initialized
** Post-Conditions: chimera has been moved and player knows it
*********************************************************************/
void Game::chimNOTshot() {
  cout << "The Chimera heard you miss and moved to a random room" << endl;
  removeeventfromroom('C');
  assigneventnewroom(&chimera);  
}
