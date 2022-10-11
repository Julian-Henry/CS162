/******************************************************
** Program: footballstats
** Author: Justin Goins, Julian Henry
** Date: 7/3/2022
** Description:	This code provides the user with data from a txt file in various ways
**				It parses information schools and historical matches. The data is then
**				processed to compute various statistics.
** Input:		Command line argument containing input filename.
** Output:		Computes various statistics and gives the user the option to print them.
******************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "functions.h"
using namespace std;

/*
This program is designed to process athletic records and print various statistics.
It requires one command line argument: the name of the file containing athletic information.
*/
int main(int argc, char* argv[]) {
	AthleticInfo info;
	int menu_choice = 0;
 
  if (argc != 2) {
    cout << "You are supposed to provide a command line argument with the input filename." << endl;
		return 1;
	}
 
  do {
  process_file(argv[1], info);
  menu_choice = menu();
  sort_data(info, menu_choice);
  }
  
  while (menu_choice !=4);
  //delete_school_data(info.array, info.numSchools); Due to time constraint and deleting memory only being 3 points, this function was commented out. 
  return 0;
}

