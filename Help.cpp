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
  cout << "character                   Shows your stats like dmg, life or level     " << endl;
  cout << "inventory                   Take a look inside your inventory            " << endl;
  cout << "use <something> <number>    Use something out of your inventory          " << endl;
  cout << "inspect                     Inspect your environment                     " << endl;
  cout << "inspect <enemy> <number>    Examine an enemy by his number               " << endl;
  cout << "inspect <direction*>         Show to where some direction leads          " << endl;
  cout << "go <direction*>              Walk along a certain direction              " << endl;
  cout << "attack <enemy> <number>     Attack an enemy, the <number> is otional     " << endl;
  cout << "open <something> <number>   Open something to loot (e.g: a chest)        " << endl;
  cout << "take <something> <number>   put something in your inventory              " << endl;
  cout << "equip <something> <number>  equip something from your inventory          " << endl;
  cout << "help:                       Shows you all available Commands             " << endl;
  cout << "-------------------------------------------------------------------------" << endl;
  cout << "*directions: you can go along and inspect directions like north, south .." << endl;
  return 0;
}