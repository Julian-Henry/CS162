#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "functions.h"
using namespace std;


/*********************************************************************
** Function: create_school_array
** Description: This function creates an array of School structs with 
**              the specified size
** Parameters: number of schools as an int
** Pre-Conditions: int must be greater than 0
** Post-Conditions: array can be accessed outside function
*********************************************************************/
School* create_school_array(int numSchools) {
 	School* ptr = new School[numSchools];
 		return ptr;
}


/*********************************************************************
** Function: create_match_array
** Description: This function creates an array of Match structs with 
**              the specified size
** Parameters: number of matches as an int
** Pre-Conditions: int must be greater than 0
** Post-Conditions: array can be accessed outside function
*********************************************************************/
Match* create_match_array(int numMatches) {
 	Match* ptr = new Match[numMatches];
 		return ptr;
}


/*********************************************************************
** Function: create_year_array
** Description: This function creates an array of ints with 
**              the specified size
** Parameters: number of ints as an int
** Pre-Conditions: int must be greater than 0
** Post-Conditions: array can be accessed outside function
*********************************************************************/
// create an array of years with the specified size
int* create_year_array(int numMatches) {
 	int* ptr = new int[numMatches];
 		return ptr;
}


/*********************************************************************
** Function: load_school_data
** Description: This function will fill a School struct with 
**              information that is read in from the text file
** Parameters: a pointer to a school array, the number of schools, 
**              and an ifstream (input file stream)
** Pre-Conditions: number of schools > 0, ifstream data separated by ';'s
** Post-Conditions: struct can be accessed outside function
*********************************************************************/
void load_school_data(School* array, int numSchools, ifstream & fin) {
  for (int i = 0; i < numSchools; i++) {
 	  getline(fin, array[i].name, ';');
 		getline(fin, array[i].moniker, ';');
 		getline(fin, array[i].city, ';');
 		int numMatches;
 		fin >> numMatches;
    array[i].numMatches = numMatches;
 		fin.ignore();                                   //ignore newline character
    Match* match_ptr = create_match_array(numMatches);
    load_match_data(match_ptr, numMatches, fin);
    array[i].array = match_ptr;
    array[i].winRatio = find_winRatio(array[i].array, numMatches);
  }
}


/*********************************************************************
** Function: load_match_data
** Description: This function will fill a Match struct with information
**              that is read in from the text file.
** Parameters: a pointer to a match array, the number of matches,
**             and an ifstream (input file stream)
** Pre-Conditions: number of matches > 0, ifstream data separated by ';'s
** Post-Conditions: struct can be accessed outside function
*********************************************************************/
void load_match_data(Match* match_ptr, int numMatches, ifstream & fin) {
  for (int j = 0; j < numMatches; j++) {
    fin >> match_ptr[j].year;
 		fin.ignore();                                //ignore semicolons
    fin >> match_ptr[j].homeScore;
    fin.ignore();
 		getline(fin, match_ptr[j].opponentName, ';');
    fin >> match_ptr[j].opponentScore;
    fin.ignore();
  }
}


/*********************************************************************
** Function: load_year_array
** Description: This function creates an int array of the years of each
**              match a school played
** Parameters: a pointer to an int array, a pointer to a match array,
**             and the number of matches
** Pre-Conditions: number of matches > 0, filled match struct
** Post-Conditions: array can be accessed outside function
*********************************************************************/
void load_year_array(int* yeararray, Match* info, int numMatches) {
  for (int i = 0; i < numMatches; i++) {
    yeararray[i] = info[i].year;
 //   cout <<  "year #" << i+1 << ": " << yeararray[i] << endl;
  }
}


/*********************************************************************
** Function: load_year_array2
** Description: This function creates an int array of the distinct years 
**              that a school played football
** Parameters: a pointer to an int array, a pointer to a match array,
**             the number of matches, and the number of years a school
**             played football.
** Pre-Conditions: number of matches and years > 0, filled match struct
** Post-Conditions: array can be accessed outside function
*********************************************************************/
void load_year_array2(int* yeararray2, Match* info, int num_years, int numMatches) {
  int j = 0;
  for (int i = 0; i < numMatches; i++) {
    if (!(info[i].year == info[i+1].year)) {
      yeararray2[j] = info[i].year;
      j++;
    }
  }  
}


/*********************************************************************
** Function: find_winRatio
** Description: This function computes the win ratio for a given team
** Parameters: a pointer to a match array and the number of football 
**             matches a school played.
** Pre-Conditions: number of matches > 0, filled match struct
** Post-Conditions: win ratio cna be accessed outside function
*********************************************************************/
double find_winRatio(Match* match, int numMatches) {
  double ties = 0;
  double wins = 0;
  double losses = 0;
  for (int j = 0; j < numMatches; j++) {
    if (match[j].homeScore > match[j].opponentScore) { wins++;};
    if (match[j].homeScore < match[j].opponentScore) { losses++;};
    if (match[j].homeScore == match[j].opponentScore) { ties++;};
  }
  double winRatio = wins/(wins+losses+ties);
  return winRatio;
}


/*********************************************************************
** Function: process_file
** Description: This function makes sure a given file is valid, then opens it and  
**              loads school and match data.
** Parameters: a C-style string (the command line argument) and a reference
**            to an AthleticInfo struct
** Pre-Conditions: file given as command line argument
** Post-Conditions: athletic info struct can be accessed outside function
*********************************************************************/
void process_file(char* filename, AthleticInfo& ai) {																
  ifstream fin;
  fin.open(filename);

	if (!fin.is_open()) {
    cout << "I'm sorry, I couldn't open that file." << endl;
		exit(1);
	}
 																																	
	// we have a valid file!
	fin >> ai.numSchools; // load the school info into ai
	fin.ignore();            //ignore newline
  																																
	ai.array = create_school_array(ai.numSchools);
  load_school_data(ai.array, ai.numSchools, fin);
}


/*********************************************************************
** Function: menu
** Description: This function asks the user to input an int (1-4) and  
**              repeats until a valid int is provided.
** Parameters: N/A
** Pre-Conditions: user must not have more than a 10000 character response
** Post-Conditions: an int 1-4 is returned.
*********************************************************************/
int menu() {
  int choice;
  do {
  cout << "\nWhich option would you like to choose?\nDisplay each school's earliest year on file (Press 1):\nList the best year (by points acquired) for each school (Press 2):\nSort schools by overall historical performance (win ratio) (Press 3):\nQuit (Press 4):\n";
  cin >> choice;
  cin.clear();                 //infinite loop bug fixed by these two lines. They were gotten from the following URL:
  cin.ignore(10000, '\n');      //https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
  }
  while (choice < 1 || choice > 4); 
  return choice;
}


/*********************************************************************
** Function: sort_data
** Description: This chooses between 3 options of how the program should   
**              proceed. 
** Parameters: an AthleticInfo struct and an int
** Pre-Conditions: int must be 1-4, AthleticInfo struct must be filled
** Post-Conditions: functions called in sort_data must be functional
*********************************************************************/
void sort_data(AthleticInfo info, int menu_choice) {
  if (menu_choice == 1) {
    earliest_year(info.array, info.numSchools);
  }
  if (menu_choice == 2) {
    best_year(info.array, info.numSchools);
  }
  if (menu_choice == 3) {
    best_overall(info.array, info.numSchools);
  }
}

/*********************************************************************
** Function: earliest_year
** Description: This displays each schools name, moniker, first year,    
**              and city
** Parameters: a school pointer and an int for the number of schools
** Pre-Conditions: numSchools > 0, school* struct filled
** Post-Conditions: result output to terminal.
*********************************************************************/
void earliest_year(School* info, int numSchools) {
  for (int i = 0; i < numSchools; i++) {
    cout << info[i].name << ", '";
    cout << info[i].moniker;
    cout << "', Team Founded: " << info[i].array[i].year;
    cout << ", City: " << info[i].city << endl;
  }
}


/*********************************************************************
** Function: best_year
** Description: This displays each schools name, most points scored in    
**              a year, and the year the most points were scored in.
**             Additionally, for the extra credit, this displays all 
**            opposing teams from each schools best year.
** Parameters: a school pointer and an int for the number of schools
** Pre-Conditions: numSchools > 0, school* struct filled
** Post-Conditions: result output to terminal, dynamic memory deleted
*********************************************************************/
void best_year(School* info, int numSchools){
  for (int i = 0; i < numSchools; i++) {
    int* yeararray = create_year_array(info[i].numMatches);       //make array of years
    load_year_array(yeararray, info[i].array, info[i].numMatches);//load it

    int num_years = numYears(yeararray, info[i].numMatches);      //number of unique years
    int* yeararray2 = new int[num_years];                         //yeararray2 gets each unique year once
    load_year_array2(yeararray2, info[i].array, num_years, info[i].numMatches);
    int* pointsarray = new int[num_years];                        //pointsarray is array of points per year
    for (int k = 0; k < num_years; k++) {pointsarray[k] = 0;}     //prefill with 0's   
    
    points_per_year(info[i], pointsarray);
    int byi = 0;                                                  //best year index
    int mostpoints = most_points(pointsarray, byi, num_years);
    cout << info[i].name << ": " << mostpoints << " points in " << yeararray2[byi] << endl;
    find_losers(info[i], yeararray2[byi]);
  }
}


/*********************************************************************
** Function: find_losers
** Description: This displays every opponent of a school during a     
**              given year
** Parameters: a school struct and an int for the best year
** Pre-Conditions: bestyear valid, school struct filled
** Post-Conditions: result output to terminal
*********************************************************************/
void find_losers(School school, int bestyear) {
  cout << "During their best year, this team played against: " << endl;
  for (int i = 0; i < school.numMatches; i++) {
    if (int(school.array[i].year) == bestyear) {
      cout << school.array[i].opponentName << endl;
    }
  }
}


/*********************************************************************
** Function: most_points
** Description: This returns the maximum value from a given int array.
**             Additionally, it updates a value for the index that the
**            max value came from (used in another function).
** Parameters: an int array, an int for the number of items in the array,
**             and a reference to an int.
** Pre-Conditions: int array filled, num_years is the right number
** Post-Conditions: int output, reference to int updates outside function.
*********************************************************************/
int most_points(int* pointsarray, int & byi, int num_years) {
  int most_points;
  for (int l = 0; l < num_years; l++) {
    if (pointsarray[l] >= pointsarray[0]) {
      byi = l;
      pointsarray[0] = pointsarray[l];
      most_points = pointsarray[0];
    }  
  }
  return most_points;
}


/*********************************************************************
** Function: points_per_year
** Description: This function goes through a School struct and updates 
**             an integer array with the sum of all points a team earned
**            each year.
** Parameters: a school struct and an int array
** Pre-Conditions: array and struct filled
** Post-Conditions: array updated correctly
*********************************************************************/
void points_per_year(School specschool, int* pointsarray) {
  int year = 0;                                              // year used as index for pointsarray
  for (int i = 0; i < specschool.numMatches; i++) {
    if (specschool.array[i].year == specschool.array[i+1].year) {
      pointsarray[year] += specschool.array[i].homeScore;
    }
    if (specschool.array[i].year != specschool.array[i+1].year) {
      pointsarray[year] += specschool.array[i].homeScore;
      year++;
    }
  }
}  


/*********************************************************************
** Function: numYears
** Description: This function finds the number of unique values in an 
**            array of a specified size.
** Parameters: an int array and its length as an int
** Pre-Conditions: array filled, int accurate
** Post-Conditions: correct value output
*********************************************************************/
int numYears(int* years, int len) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (!(years[i] == years[i+1])) {
      count++;
    }
  }  
  return count;
}


/*********************************************************************
** Function: best_overall
** Description: This function goes through an array of School structs
**             and prints each schools name and win ratio in descending
**            order by win ratio.
** Parameters: an array of school structs and an int for the number of schools
** Pre-Conditions: struct array filled and school number accurate
** Post-Conditions: memory deleted properly
*********************************************************************/
void best_overall(School* info, int numSchools) {
  double* printorder = new double[numSchools];  
  for (int i = 0; i < numSchools; i++) {
    printorder[i] = info[i].winRatio;
  }
  array_descending(printorder, numSchools);
  for (int j = 0; j < numSchools; j++){
    for (int m = 0; m < numSchools; m++) {
      if (printorder[j] == info[m].winRatio) {
        cout << info[m].name << ": " << info[m].winRatio << endl;
      }
    }
  }
}    


/*********************************************************************
** Function: array_descending
** Description: This function rearranges an array of doubles in
**              descending order.
** Parameters: an array of doubles and an int for the number of schools
** Pre-Conditions: array filled and school number accurate
** Post-Conditions: updated array can be used outside program
*********************************************************************/
void array_descending(double* printorder, int numSchools) {
  for (int k = 0; k < numSchools; k++) {
    for (int l = 0; l < numSchools; l++) {
      if (printorder[k] > printorder[l]) {
        double temp = printorder[k];
        printorder[k] = printorder[l];
        printorder[l] = temp;
      }
    }
  }
}


/*********************************************************************
** Function: delete_school_data
** Description: This function is supposed to delete the dynamically allocated
**              arrays from an array of school structs.
** Parameters: an array of school structs and the number of array items
** Pre-Conditions: array filled, number accurate
** Post-Conditions: no memory should be left behind...
*********************************************************************/
void delete_school_data(School* school, int numSchools) {
  for (int i = 0; i < numSchools; i++) {
    delete school[i].array;
  }
  delete school;
}
