#include "Help.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Help::Help(string hc_name) : Command(hc_name)
{}
 
Help::~Help()
{}

int Help::execute(Game& board, std::vector<std::string>& params)
{
  cout << "------------------------Available Commands-------------------------------" << endl;
  cout << "character:                  Shows you information about yourself         " << endl;
  cout << "inventory:                  Take a look inside your inventory            " << endl;
  cout << "inspect ([enemy] [number]): Examine the current place or                 " << endl;
  cout << "                            an enemy by his number                       " << endl;
  cout << "go [direction]:             Walk along a certain direction               " << endl;
  cout << "attack [enemy] [number]:    Attack an enemy, if there is more than one   " << endl;
  cout << "                            you can say whom by mentioning his number    " << endl;
  cout << "open [something] [number]:  open something and show the things within    " << endl;
  cout << "take [something] [number]:  put something into your inventory            " << endl;
  cout << "equip [something] [number]: equip something from your inventory          " << endl;
  cout << "help:                       Shows you all available Commands             " << endl;
  cout << "-------------------------------------------------------------------------" << endl;
  return 0;
}