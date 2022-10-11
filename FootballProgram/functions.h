#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;

struct Match {
	unsigned int year;
	unsigned int homeScore;
	string opponentName;
	unsigned int opponentScore;
};

struct School {
	string name;
	string moniker;
	string city;
	double winRatio;
  int numMatches;
	struct Match* array; //struct?
};

struct AthleticInfo {
	School* array;
	unsigned int numSchools;
};


/*********************************************************************
** Function: create_school_array
** Description: This function creates an array of School structs with 
**              the specified size
** Parameters: number of schools as an int
** Pre-Conditions: int must be greater than 0
** Post-Conditions: array can be accessed outside function
*********************************************************************/
// create an array of School structs with the specified size
School* create_school_array(int numSchools);


/*********************************************************************
** Function: create_match_array
** Description: This function creates an array of Match structs with 
**              the specified size
** Parameters: number of matches as an int
** Pre-Conditions: int must be greater than 0
** Post-Conditions: array can be accessed outside function
*********************************************************************/
Match* create_match_array(int numMatches);


/*********************************************************************
** Function: create_year_array
** Description: This function creates an array of ints with 
**              the specified size
** Parameters: number of ints as an int
** Pre-Conditions: int must be greater than 0
** Post-Conditions: array can be accessed outside function
*********************************************************************/
int* create_year_array(int numMatches);





/*********************************************************************
** Function: load_school_data
** Description: This function will fill a School struct with 
**              information that is read in from the text file
** Parameters: a pointer to a school array, the number of schools, 
**              and an ifstream (input file stream)
** Pre-Conditions: number of schools > 0, ifstream data separated by ';'s
** Post-Conditions: struct can be accessed outside function
*********************************************************************/
// accept a pointer to a school array, the number of schools, an ifstream (input file stream)
void load_school_data(School* array, int numSchools, ifstream & fin);    


/*********************************************************************
** Function: load_match_data
** Description: This function will fill a Match struct with information
**              that is read in from the text file.
** Parameters: a pointer to a match array, the number of matches,
**             and an ifstream (input file stream)
** Pre-Conditions: number of matches > 0, ifstream data separated by ';'s
** Post-Conditions: struct can be accessed outside function
*********************************************************************/
void load_match_data(Match*, int, ifstream &); 


/*********************************************************************
** Function: load_year_array
** Description: This function creates an int array of the years of each
**              match a school played
** Parameters: a pointer to an int array, a pointer to a match array,
**             and the number of matches
** Pre-Conditions: number of matches > 0, filled match struct
** Post-Conditions: array can be accessed outside function
*********************************************************************/
void load_year_array(int* yeararray, Match *info, int numMatches);


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
void load_year_array2(int* yeararray2, Match* info, int num_years, int numMatches);


/*********************************************************************
** Function: find_winRatio
** Description: This function computes the win ratio for a given team
** Parameters: a pointer to a match array and the number of football 
**             matches a school played.
** Pre-Conditions: number of matches > 0, filled match struct
** Post-Conditions: win ratio cna be accessed outside function
*********************************************************************/
double find_winRatio(Match* match, int numMatches);


/*********************************************************************
** Function: process_file
** Description: This function makes sure a given file is valid, then opens it and  
**              loads school and match data.
** Parameters: a C-style string (the command line argument) and a reference
**            to an AthleticInfo struct
** Pre-Conditions: file given as command line argument
** Post-Conditions: athletic info struct can be accessed outside function
*********************************************************************/
// accepts a C-style string (the command line argument)
void process_file(char* filename, AthleticInfo& ai);


/*********************************************************************
** Function: menu
** Description: This function asks the user to input an int (1-4) and  
**              repeats until a valid int is provided.
** Parameters: N/A
** Pre-Conditions: user must not have more than a 10000 character response
** Post-Conditions: an int 1-4 is returned.
*********************************************************************/
int menu();


/*********************************************************************
** Function: sort_data
** Description: This chooses between 3 options of how the program should   
**              proceed. 
** Parameters: an AthleticInfo struct and an int
** Pre-Conditions: int must be 1-4, AthleticInfo struct must be filled
** Post-Conditions: functions called in sort_data must be functional
*********************************************************************/
void sort_data(AthleticInfo info, int menu_choice);


/*********************************************************************
** Function: earliest_year
** Description: This displays each schools name, moniker, first year,    
**              and city
** Parameters: a school pointer and an int for the number of schools
** Pre-Conditions: numSchools > 0, school* struct filled
** Post-Conditions: result output to terminal.
*********************************************************************/
void earliest_year(School* info, int numSchools);


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
void best_year(School* info, int numSchools);


/*********************************************************************
** Function: find_losers
** Description: This displays every opponent of a school during a     
**              given year
** Parameters: a school struct and an int for the best year
** Pre-Conditions: bestyear valid, school struct filled
** Post-Conditions: result output to terminal
*********************************************************************/
void find_losers(School school, int bestyear);


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
int most_points(int* pointsarray, int & byi, int num_years);




/*********************************************************************
** Function: points_per_year
** Description: This function goes through a School struct and updates 
**             an integer array with the sum of all points a team earned
**            each year.
** Parameters: a school struct and an int array
** Pre-Conditions: array and struct filled
** Post-Conditions: array updated correctly
*********************************************************************/
void points_per_year(School specschool, int* pointsarray);


/*********************************************************************
** Function: numYears
** Description: This function finds the number of unique values in an 
**            array of a specified size.
** Parameters: an int array and its length as an int
** Pre-Conditions: array filled, int accurate
** Post-Conditions: correct value output
*********************************************************************/
int numYears(int years[], int numMatches);


/*********************************************************************
** Function: best_overall
** Description: This function goes through an array of School structs
**             and prints each schools name and win ratio in descending
**            order by win ratio.
** Parameters: an array of school structs and an int for the number of schools
** Pre-Conditions: struct array filled and school number accurate
** Post-Conditions: memory deleted properly
*********************************************************************/
void best_overall(School* info, int numSchools);



/*********************************************************************
** Function: array_descending
** Description: This function rearranges an array of doubles in
**              descending order.
** Parameters: an array of doubles and an int for the number of schools
** Pre-Conditions: array filled and school number accurate
** Post-Conditions: updated array can be used outside program
*********************************************************************/
void array_descending(double* printorder, int numSchools);



/*********************************************************************
** Function: delete_school_data
** Description: This function is supposed to delete the dynamically allocated
**              arrays from an array of school structs.
** Parameters: an array of school structs and the number of array items
** Pre-Conditions: array filled, number accurate
** Post-Conditions: no memory should be left behind...
*********************************************************************/
void delete_school_data(School* school, int numSchools);


