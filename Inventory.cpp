#include "Inventory.h"
#include <iostream>
#include "Place.h"
#include <string>
#include "Enemy.h"
#include "Container.h"
#include "Weapon.h"
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

Inventory::Inventory(string ic_name) : Command(ic_name)
{}
 
Inventory::~Inventory()
{}

int Inventory::execute(Game& board, std::vector<std::string>& params)
{
  cout << "----------------inventory---------------" << endl;
  
  // Show all Weapons
  cout << "                ~weapons~               " << endl;
  vector<Weapon*> all_weapons_here = board.getAllWeaponsInventory();
  
  if(!all_weapons_here.size())
  {
  cout << "           You have no weapon" << endl;
  }
  
  for(unsigned int i = 0; i < all_weapons_here.size();i++)
  {
    cout << all_weapons_here[i]->getName();
    cout << " (" << all_weapons_here[i]->getinSomethingID() << ")";
    if(all_weapons_here[i] == board.getWeapon())
    {
      cout << " (equipped) :" << endl;
    }
    else
    {
      cout << " :" << endl;
    }
    cout << "Type: ";
    switch(all_weapons_here[i]->getType())
    {
      case 1:
      cout << "One Handed";
      break;
      case 2:
      cout << "Two Handed";
      break;
      default:
      cout << "Unknown";
    }
    cout << " Speed: " << all_weapons_here[i]->getSpeed();
    cout << " Damage: " << all_weapons_here[i]->getDMG();
    cout << " Condition: " << all_weapons_here[i]->getCondition() << "/" << all_weapons_here[i]->getMaxCondition();
    cout << endl;
  }
  
  
  cout << "----------------------------------------" << endl;
  return 0;
}