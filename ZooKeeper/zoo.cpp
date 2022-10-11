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
#include "seaotter.h"
#include "meerkat.h"
#include "monkey.h"
#include "zoo.h"

using namespace std;

#define MEERKATREVENUE 25
#define MONKEYREVENUE 360
#define SEAOTTERREVENUE 200

/*********************************************************************
** Function: default constructor
** Description: sets all variables as they should be
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: your zoo has now been initialized
*********************************************************************/
Zoo::Zoo() {
  nummeerkats = 0; 
  numadultmeerkats = 0;
  numbabymeerkats = 0;
  
  nummonkeys = 0;
  numadultmonkeys = 0;
  numbabymonkeys = 0;
  
  numseaotters = 0;
  numadultseaotters = 0;
  numbabyseaotters = 0;
  
  weeks = 1;
  months = 1;
  years = 1;

  numexhibits = 0;
  maxexhibits = 5; //space for 5 exhibits, arbitrarily
  money = 100000;
  exhibits = new Animal*[maxexhibits]; 
  gamedone = false;
}


/*********************************************************************
** Function: destructor
** Description: DELETES DYNAMIC MEMORY phew
** Parameters: n/a
** Pre-Conditions: dynamic memory cant already have been deleted
** Post-Conditions: dont try to access the memory any more, its gone
*********************************************************************/
Zoo::~Zoo() {
  for (int i = 0; i < numexhibits; i++) {
    delete exhibits[i];
  }
  delete [] exhibits;
}


/*********************************************************************
** Function: copy constructor
** Description: deep copy (this is required but not used...)
** Parameters: constant reference to Zoo
** Pre-Conditions: one zoo already made
** Post-Conditions: now theres another that wont access the same DYNAMIC MEMORY
*********************************************************************/
Zoo::Zoo(const Zoo& old_obj) {
	maxexhibits = old_obj.maxexhibits;
	numexhibits = old_obj.numexhibits;
	nummeerkats = old_obj.nummeerkats;
	numseaotters = old_obj.numseaotters;
	nummonkeys = old_obj.nummonkeys; 
  if (numexhibits > 0) {
    exhibits = new Animal*[maxexhibits];
    for (int i = 0; i < numexhibits; i++) {
      exhibits[i] = old_obj.exhibits[i];
    }
  } 
  else {
    exhibits = NULL; 
  }
}


/*********************************************************************
** Function: assignment operator overload
** Description: deep copy one zoo to another (again required but not used...)
** Parameters: constant reference to zoo i guess
** Pre-Conditions: both zoos are already made
** Post-Conditions: now one is like the other okay
*********************************************************************/
Zoo& Zoo::operator=(const Zoo& old_obj) {
	delete [] exhibits;  // delete any existing memory allocation
	
	numexhibits = old_obj.numexhibits; 	  // copy over the existing data
	maxexhibits = old_obj.maxexhibits;
	nummeerkats = old_obj.nummeerkats;
	numseaotters = old_obj.numseaotters;
	nummonkeys = old_obj.nummonkeys; 

	if (numexhibits > 0) { 	              // allocate new space and copy the entries
		exhibits = new Animal*[maxexhibits];
		for (int i = 0; i < numexhibits; i++) {
			exhibits[i] = old_obj.exhibits[i];
		}
	} 
  else {exhibits = NULL;}

	return *this;
}


/*********************************************************************
** Function: purchaseanimals
** Description: provides user with options to buy animals and completes
**              the purchase if possible NOTE: this could probably be  
**              reduced into a few smaller functions but this is easier to
**              understand for me and isnt too big. please dont mark me down :)
** Parameters: n/a
** Pre-Conditions: n/a?
** Post-Conditions: new animal in zoo and less money in bank, or skipped
**                  the purchase phase, also allows user to end game...
*********************************************************************/
void Zoo::purchaseanimals() {
  int choice, numbertobuy;
  string animal;
  bool done;
  do {
    cout << "You can now purchase animals. Use numbers as shown below\n1 = Purchase meerkats ($500)\n2 = Purchase sea otters ($4000)\n3 = Purchase monkeys ($12000)\n4 = skip purchasing phase\n5 = quit game" << endl;
    choice = getint(1,5);//1 = meerkat, 2 = sea otter, 3 = monkey
    if (choice == 4) {
      return;
    } else if (choice == 5) {
      gamedone = true;
      return;
    }
    animal = namefromtype(choice-1);
    cout << "How many " << animal << " would you like to purchase? (limit 100)" << endl;
    numbertobuy = getint(0,100);
    done = validpurchase(choice-1, numbertobuy);
    
    if (done) {
      addanimalstoarray(choice-1, numbertobuy, 104);  //104 weeks is 2 years
    } else {
      cout << "\nInvalid purchase. Try again.\n" << endl;
    }
  } while (!done);
}

/*********************************************************************
** Function: namefromtype
** Description: returns the name of the animal using its type (0-2)
** Parameters: int representing type
** Pre-Conditions: "type" should be 0-2
** Post-Conditions: you can now use animal name
*********************************************************************/
string Zoo::namefromtype(int type) {
  switch (type) {
    case 0: return "meerkats";
    case 1: return "sea otters";
    case 2: return "monkeys";
    default: return "uh oh... check zoo:: namefromtype...";
  }
}


/*********************************************************************
** Function: validpurchase
** Description: if the player can make the attempted purchase, remove the
**              cost and return true, else return false.
** Parameters: int for animal type (0=meerkat,1=seaotter,2=monkey) and 
**             int for number to buy
** Pre-Conditions: animal int between 0 and 2, numbertobuy >= 0
** Post-Conditions: use the t/f returned for whatever, also money may be reduced
*********************************************************************/
bool Zoo::validpurchase(int animal, int numbertobuy) { //0meerkat, 1seaotter, 2monkey
  switch (animal) {
  case 0: //meerkat
    if ((numbertobuy*MEERKATCOST) <= money) {
      money -= numbertobuy*MEERKATCOST;
      return true;
    }
    return false;
  case 1: //seaotter
    if ((numbertobuy*SEAOTTERCOST) <= money) {
      money -= numbertobuy*SEAOTTERCOST;
      return true;
    }
    return false;
  case 2: //monkey
    if ((numbertobuy*MONKEYCOST) <= money) {
      money -= numbertobuy*MONKEYCOST;
      return true;
    }
    return false;
  default:
    cout <<"oh boy somethings really wrong with validpurchase....." << endl;
    return false;
  }
}


/*********************************************************************
** Function: getint
** Description: returns an int from the user thats in the provided range
** Parameters: ints for low and high limits, limits are included in range
** Pre-Conditions: low <= high
** Post-Conditions: you now have an int between a specified range
*********************************************************************/
int Zoo::getint(int low, int high) {
  int ans;
  do {
    cin >> ans;
    cin.clear();
    cin.ignore(10000, '\n');    
    if ((ans > high) || (ans < low)) {
      cout << "Please enter an integer between " << low << " and " << high << endl;
    }
  } while ((ans > high) || (ans < low));
  return ans;
}


/*********************************************************************
** Function: addanimalstoarray
** Description: adds a provided animal to the exhibits array
** Parameters: int for animal type (0=meerkat,1=seaotter,2=monkey), int
**             for how many to add, and int for the age of the animals
** Pre-Conditions: type is 0-2, others are positive
** Post-Conditions: exhibits array is updated, may have more room
*********************************************************************/
void Zoo::addanimalstoarray(int type, int numanimals, int age) {    //for type: 0 = meerkat, 1 = sea otter, 2 = monkey
  if (maxexhibits <= (numanimals + numexhibits)) {                  //if tyheres not enough room, increase max size of exhibit array
    while (maxexhibits <= (numanimals + numexhibits)) {  
      maxexhibits = maxexhibits*2;
    }
    Animal** tmp = new Animal*[maxexhibits];                        // temporary array to copy values to
    for (int i = 0; i < numexhibits; i++) {                         //set each value to old array
      tmp[i] = exhibits[i];
    }
    delete [] exhibits;                                              //get rid of old array
    exhibits = tmp;                                                  //now we should have an array with all the same elements as before but larger
  }
  for (int i = numexhibits; i < (numexhibits + numanimals); i++) {   //add new animals to array after the spots that are already taken
    exhibits[i] = typetoanimalptr(type, age);
  }
  numexhibits += numanimals;                                         //update size
}


/*********************************************************************
** Function: typetoanimalptr
** Description: returns a pointer to an animal  on the heap, The type 
**              of animal is determined by inputs, as well as age
** Parameters: int type (0-2 same as others), int age in weeks
** Pre-Conditions: type 0-2, age >= 0
** Post-Conditions: now theres another animal pointer you can do as you
**                  wish with
*********************************************************************/
Animal* Zoo::typetoanimalptr(int type, int age) {//0 = meerkat, 1 = sea otter, 2 = monkey
  Animal * animaltomake;
  switch(type) {
    case 0:
      animaltomake = new Meerkat(age);
      return animaltomake;                        //return a new animal pointer on heap
      break;
    case 1:
      animaltomake = new Seaotter(age);
      return animaltomake;
      break;
    case 2:
      animaltomake = new Monkey(age);
      return animaltomake;
      break;
    default:
      cout <<"UH OH, check typetoanimalptr again..." << endl;
      return nullptr;
      break;
  }
}


/*********************************************************************
** Function: printzooinfo
** Description: displays calendar, funds, and exhibit summary
** Parameters: n/a
** Pre-Conditions: variables initialized
** Post-Conditions: player now knows whats going on
*********************************************************************/
void Zoo::printzooinfo() {
  cout << "\n\n\nYear " << years << ", month " << months << ", week " << weeks << ".\n"<< endl;
  cout << "It is a new week!\n\nCurrent funds: $" << money << endl;
  cout << "\nCurrent exhibits:\n\n\tMeerkats:   " << nummeerkats << " (" << numbabymeerkats << " baby, " << nummeerkats - numbabymeerkats - numadultmeerkats << " adolescent, and " << numadultmeerkats << " adults)\n\tSea otters: " << numseaotters << " (" << numbabyseaotters << " baby, " << numseaotters - numbabyseaotters - numadultseaotters << " adolescent, and " << numadultseaotters << " adults)\n\tMonkeys:    " << nummonkeys << " (" << numbabymonkeys << " baby, " << nummonkeys - numbabymonkeys - numadultmonkeys << " adolescent, and " << numadultmonkeys << " adults)\n\n" << endl;
  for (int i = 0; i < numexhibits; i++) {
    
  }
}


/*********************************************************************
** Function: timepassed
** Description: updates years weeks and months variables to loosely mirror
**              a calendar. In this, months are all 5 weeks and years are 
**              all exactly 12 months
** Parameters: n/a
** Pre-Conditions: weeks >= 0
** Post-Conditions: calendar updated
*********************************************************************/
void Zoo::timepassed() { //this is very simplified because it is not required but i thought it would be a nice feature.
  weeks++;
  if (weeks > 5) {
    weeks -= 5;
    months++;
  }
  if (months > 12) {
    months -= 12;
    years++;
  }
  
}


/*********************************************************************
** Function: calculaterevinue
** Description: adds revinue from all animals to players money and prints 
**              info about it
** Parameters: n/a
** Pre-Conditions: valid variables
** Post-Conditions: money is a bigger number assuming there were animals 
**                  in the zoo
*********************************************************************/
void Zoo::calculaterevinue() {
  int babymeerkatrevinue = 2*MEERKATREVENUE*numbabymeerkats;
  int adolescentmeerkatrevinue = MEERKATREVENUE*(nummeerkats - numbabymeerkats - numadultmeerkats);
  int adultmeerkatrevinue = MEERKATREVENUE*numadultmeerkats;
  int meerkatrevinue = babymeerkatrevinue + adolescentmeerkatrevinue + adultmeerkatrevinue;
  
  int babyseaotterrevinue = 2*SEAOTTERREVENUE*numbabyseaotters;
  int adolescentseaotterrevinue = SEAOTTERREVENUE*(numseaotters - numbabyseaotters - numadultseaotters);
  int adultseaotterrevinue = SEAOTTERREVENUE*numadultseaotters;
  int seaotterrevinue = babyseaotterrevinue + adolescentseaotterrevinue + adultseaotterrevinue;
  
  int babymonkeyrevinue = 2*MONKEYREVENUE*numbabymonkeys;
  int adolescentmonkeyrevinue = MONKEYREVENUE*(nummonkeys - numbabymonkeys - numadultmonkeys);
  int adultmonkeyrevinue = MONKEYREVENUE*numadultmonkeys;
  int monkeyrevinue = babymonkeyrevinue + adolescentmonkeyrevinue + adultmonkeyrevinue;
  
  int totalrevinue = meerkatrevinue + seaotterrevinue + monkeyrevinue;
  money += totalrevinue;
  
  cout << "Revinue Summary:\n";
  cout << "\n\tMeerkats:   $" << meerkatrevinue << " ($" << babymeerkatrevinue << " from babies, $" << adolescentmeerkatrevinue << " from adolescents, and $" << adultmeerkatrevinue << " from adults)";
  cout << "\n\tSea otters: $" << seaotterrevinue << " ($" << babyseaotterrevinue << " from babies, $" << adolescentseaotterrevinue << " from adolescents, and $" << adultseaotterrevinue << " from adults)";
  cout<<"\n\tMonkeys:    $" << monkeyrevinue << " ($" << babymonkeyrevinue << " from babies, $" << adolescentmonkeyrevinue << " from adolescents, and $" << adultmonkeyrevinue << " from adults)\n";
  cout << "\nTotal revinue: $" << totalrevinue << endl;
}


/*********************************************************************
** Function: calculatecosts
** Description: removes the cost of all animals in zoo for a week from
**              players money and prints what was taken
** Parameters: n/a
** Pre-Conditions: valid num of animals and BASEFOODCOST
** Post-Conditions: money is now a lower number (assuming animals in zoo)
*********************************************************************/
void Zoo::calculatecosts() {
  int meerkatcost  = 1*BASEFOODCOST*nummeerkats;
  int seaottercost = 2*BASEFOODCOST*numseaotters;
  int monkeycost   = 4*BASEFOODCOST*nummonkeys;
  int totalcost = meerkatcost + seaottercost + monkeycost;
  cout << "\nCost Summary:\n\n\tMeerkats:   $" << meerkatcost << "\n\tSea otters: $" << seaottercost << "\n\tMonkeys:    $" << monkeycost << "\n\nTotal costs: $" << totalcost << endl;
  money -= totalcost;
}


/*********************************************************************
** Function: display
** Description: displays each animal in zoo, this was just used for debugging
** Parameters: n/a
** Pre-Conditions: exhibits initialized
** Post-Conditions: user/programmer now knows the type and number of 
**                  animals in their zoo
*********************************************************************/
void Zoo::display() {
  for (int i = 0; i < numexhibits; i++) {
    cout << i + 1 << ". ";
    exhibits[i]->display();
  }
}


/*********************************************************************
** Function: getmoney
** Description: returns the amount of money the player has as int
** Parameters: n/a
** Pre-Conditions: money valid
** Post-Conditions: you can now use money value
*********************************************************************/
int Zoo::getmoney() {
  return money;
}


/*********************************************************************
** Function: intromessage
** Description: displays a simple introduction message for the game
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: user now knows a bit more about the game
*********************************************************************/
void Zoo::intromessage() {
  cout << "\n\n\n\n\n\n\nWELCOME TO ZOO TYCOON!\n\nYour job is both to ensure the welfare of the animals and to generate as much profit as possible.\nAccomplish these goals by investing in animals, feeding them, caring for them when they are sick,\nand raising their babies when they are born.\nGood luck!" << endl;
}


/*********************************************************************
** Function: endingmessage
** Description: displays a simple game over message
** Parameters: n/a
** Pre-Conditions: years months and weeks >= 0
** Post-Conditions: user now knows game is over
*********************************************************************/
void Zoo::endingmessage() {
  cout << "\n\n\n\n\n\nGAME OVER\nYou made it to year " << years << ", month " << months << ", week " << weeks << ".\n\n\n\n\n\n" << endl;
}


/*********************************************************************
** Function: ageup
** Description: increments the age of each animal in exhibits array,
**              as well as my primitive calendar
** Parameters: n/a
** Pre-Conditions: timepassed() works
** Post-Conditions: animals are a week older and calendar is updated
*********************************************************************/
void Zoo::ageup() {
  timepassed();
  for (int i = 0; i < numexhibits; i++) {
    exhibits[i]->ageup();
  }
}


/*********************************************************************
** Function: updateexhibitstats
** Description: resets and updates info about exhibits
** Parameters: n/a
** Pre-Conditions: n/a?
** Post-Conditions: exhibit stats are updated, phew
*********************************************************************/
void Zoo::updateexhibitstats() {
  nummeerkats = 0;
  numadultmeerkats = 0;
  numbabymeerkats = 0;
  
  nummonkeys = 0;
  numadultmonkeys = 0;
  numbabymonkeys = 0;
  
  numseaotters = 0;
  numadultseaotters = 0;
  numbabyseaotters = 0;
  
  for (int i = 0; i < numexhibits; i++) {
    
    if (exhibits[i]->gettype() == 0) {  //0 = meerkat, 1 = seaotter, 2 = monkey
      nummeerkats++;
      if (exhibits[i]->getstage() == "baby") {
        numbabymeerkats++;
      } else if (exhibits[i]->getstage() == "adult") {
        numadultmeerkats++;
      } 
      
    } else if (exhibits[i]->gettype() == 1) {
      numseaotters++;
      if (exhibits[i]->getstage() == "baby") {
        numbabyseaotters++;
      } else if (exhibits[i]->getstage() == "adult") {
        numadultseaotters++;
      } 
      
    } else if (exhibits[i]->gettype() == 2) {
      nummonkeys++;
      if (exhibits[i]->getstage() == "baby") {
        numbabymonkeys++;
      } else if (exhibits[i]->getstage() == "adult") {
        numadultmonkeys++;
      }
    }
  }
}


/*********************************************************************
** Function: fastforward
** Description: returns an int for the number of weeks to skip before
**              player can make another action (given users response)
** Parameters: n/a
** Pre-Conditions: getint(int,int) valid
** Post-Conditions: you now have int for how many weeks to skip
*********************************************************************/
int Zoo::fastforward() {
  int weekstoskip;
  cout << "\n\tHow many weeks would you like to skip?" << endl;
  cout << "\t";
  weekstoskip = getint(1,100000);
  return weekstoskip;
}


/*********************************************************************
** Function: xorshf96
** Description: this function was found at the url:https://stackoverflo
**              w.com/questions/1640258/need-a-fast-random-generator-for-c
**              it returns a random unsigned long.
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: use random number for whatever
*********************************************************************/
static unsigned long x=123456789, y=362436069, z=521288629;

unsigned long Zoo::xorshf96() {
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
** Function: randomevent
** Description: chooses a random event to happen, the event is executed
** Parameters: n/a
** Pre-Conditions: all functions used in it are valid
** Post-Conditions: some event has happened
*********************************************************************/
void Zoo::randomevent() {
  int event = xorshf96() % 4; //0-3
  switch (event) {
    case 3:
      sickness();
      break;
    case 2:
      birth();
      break;
    case 1:
      attendenceboom();
      break;
    default:
      cout << "\n\n\t\tNo special event transpired this week." << endl;
      break;
  }
}


/*********************************************************************
** Function: attendenceboom
** Description: adds a random amount of money to user per monkey in the zoo
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: "money" is increased
*********************************************************************/
void Zoo::attendenceboom() {
  int bonusrevinue = 0;
  int totalbonus = 0;
  cout << "\n\n\t\tThere was an increase in attendence this week." << endl;
  for (int i = 0; i < nummonkeys; i++) {
    bonusrevinue = (xorshf96() % 700) + 500;
    totalbonus += bonusrevinue;
  }
  money += totalbonus;
  cout << "\t\tYou earned an additional $" << totalbonus << " from the monkeys." << endl;
}


/*********************************************************************
** Function: sickness
** Description: chooses an animal to get sick. if theres enough money,
**              the cost is automatically deducted from the users money
                else the animal dies
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: either money is deducted, or exhibit array is reduced
*********************************************************************/
void Zoo::sickness() {
  if (numexhibits > 0) {
    int sickindex = xorshf96() % numexhibits;
    int cost = exhibits[sickindex]->calculatesickcost();
    
    cout << "\n\n\t\tOh, no! a "; 
    exhibits[sickindex]->display();
    cout << " got sick." << endl;
    
    if (cost >= money) {
      cout << "You didn't have enough money to pay for medicine ($" << cost << ") so the animal died." << endl;
      animaldeath(sickindex);
    } else {
      cout << "\t\tMedicine cost you $" << cost << endl;
      money -= cost;
    }
  } else {
    cout << "\n\n\t\tYou avoided animal sickness by having the worst zoo possible." << endl;
  }
}


/*********************************************************************
** Function: animaldeath
** Description: removes the animal from index provided by scooting all 
**              higher animals down one
** Parameters: int for index to remove
** Pre-Conditions: valid index
** Post-Conditions: one less exhibit
*********************************************************************/
void Zoo::animaldeath(int index) {
	for (int i = 0; i < (numexhibits - index - 1); i++) {	// scoot all the higher animals down by one position
		exhibits[index + i] = exhibits[index + i + 1];
	}
	numexhibits--;	// there is one less exhibit

}


/*********************************************************************
** Function: birth
** Description: chooses a species that has more than one adult to give birth
** Parameters: n/a
** Pre-Conditions: zoo initialized?
** Post-Conditions: either nothing happened or there is now some amount
**                  of babies added to the exhibits array
*********************************************************************/
void Zoo::birth() {//0 = meerkat, 1 = sea otter, 2 = monkey
  bool done = false;
  if (numadultmeerkats > 1 || numadultseaotters > 1 || numadultmonkeys > 1) {
    while (!done) {
      int type = xorshf96() % 3;
      switch (type) {
        case 0:
          if (numadultmeerkats > 1) {
            addanimalstoarray(0, 3, 0); //0=meer, 3 babies, age 0
            cout << "\n\n\t\tOne of your meerkats gave birth to three lovely babies." << endl;
            done = true;
          } break;
        case 1:
          if (numadultseaotters > 1) {
            addanimalstoarray(1, 1, 0); //0=sea, 1 baby, age 0
            cout << "\n\n\t\tOne of your sea otters gave birth to a bouncing baby otter." << endl;
            done = true;
          } break;
        case 2:
          if (numadultmonkeys > 1) {
            addanimalstoarray(2, 1, 0); //0=monk, 1 baby, age 0
            cout << "\n\n\t\tOne of your monkeys gave birth to a gross little baby monkey." << endl;
            done = true;
          } break;
       }
    } 
  } else {
    cout << "\n\n\t\tThere weren't enough adults to mate, so nothing happened." << endl;
  }
}
