#include "Character.h"
#include <iostream>

using std::cout;
using std::endl;
 
Character::Character(string cc_name) : Command(cc_name)
{}
 
 Character::~Character()
{
}

int Character::execute(Game& board, std::vector<std::string>& params)
{
  cout << "-----------------------------------------" << endl;
  cout << "HP:     " << board.getHP() << "/" << board.getMaxHP();
  if(board.getHP() <= 3 && board.getHP() > 0 )
  cout << " You are near death!" << endl;
  else
  cout << endl;
  cout << "Damage: " << board.getDMG();
  if(board.getWeapon() == NULL)
  {
    cout << " (unarmed)";
  }
    cout << endl;

  cout << "Level: " << board.getLVL() << endl;
  cout << "Exp: " << board.getEXP() << "/" << board.getNextEXP() << endl; 
  cout << "Gold: " << board.getGold() << endl;
  cout << "-----------------------------------------" << endl;
  
  return 0;
}