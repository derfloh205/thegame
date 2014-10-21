#include "Character.h"
#include <iostream>
#include "Weapon.h"

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
  else if(board.getHP() == 0)
  cout << " You are Dead." << endl;
  else
  cout << endl;
  cout << "Attack: " << board.getAttack() << endl;
  cout << "Damage: ";

  // This should be with the new Damage label then
  if(board.getWeapon() == NULL)
  {
    cout << board.getDMG();
    cout << " (unarmed)";
  }
  else
  {
    cout << board.getWeapon()->getDiceAmount() << "d" << board.getWeapon()->
      getDiceType();
    cout << " (" << board.getWeapon()->getName() << ")";
  }

  cout << endl;

  cout << "Armorclass: " << board.getAC() << endl;
  cout << "Level: " << board.getLVL() << endl;
  cout << "Exp: " << board.getEXP() << "/" << board.getNextEXP() << endl; 
  cout << "Gold: " << board.getGold() << endl;
  cout << "-----------------------------------------" << endl;
  
  return 0;
}