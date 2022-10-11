/*
	This file describes the Game class.
*/
#ifndef GAME_H
#define GAME_H

#include <iostream>
 #include "bats.h"
 #include "chimera.h"
 #include "gold.h"
 #include "room.h"
 #include "lava.h"
 #include "event.h"
 #include "escape.h" 
 #include <vector>
 using namespace std;
 
class Game {
  private:
    vector<vector<Room>> cave;
    int dungeonsize;
    bool showmap;
    int playerR;
    int playerC;
    int escapeR;
    int escapeC;
    int  arrowR;
    int  arrowC;
    
    void getsizeandmode(int, string);
    void setevents();
    void assigneventnewroom(Event*);
    Bats bats;
    Lava lava;
    Chimera chimera;
    Gold gold;
    Escape escape;
    void setplayer();
    bool processmove(string);
    void displaypercepts();
    void eventhappens();
    bool goldcollected = false;
    bool chimeradead = false;
    int numarrows = 3;
    void shootarrow(int);
    void removeeventfromroom(char);
    void chimshot();
    void chimNOTshot();
    void shotup();
    void shotdown();
    void shotleft();
    void shotright();

  public:
    void initialize(int, string);
    int checkvalidstart(int, string);
    void taketurn();
    void showdungeon();
    bool gameover = false;
    bool playagain();

};

#endif
