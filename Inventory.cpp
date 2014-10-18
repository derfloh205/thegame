#include "Inventory.h"
#include <iostream>
#include "Place.h"
#include <string>
#include "Enemy.h"
#include "Container.h"
#include "Weapon.h"
#include "Usable.h"
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
  
  unsigned int weopen_count = 0;
  for(weopen_count = 0; weopen_count < all_weapons_here.size(); weopen_count++)
  {
    cout << all_weapons_here[weopen_count]->getName();
    cout << " (" << all_weapons_here[weopen_count]->getinSomethingID() << ")";
    if(all_weapons_here[weopen_count] == board.getWeapon())
    {
      cout << " (equipped) :" << endl;
    }
    else
    {
      cout << " :" << endl;
    }

    cout << "Type: ";

    switch(all_weapons_here[weopen_count]->getType())
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

    cout << " Speed: " << all_weapons_here[weopen_count]->getSpeed();
    cout << " Damage: " << all_weapons_here[weopen_count]->getDMG();
    cout << " Condition: " << all_weapons_here[weopen_count]->getCondition() << "/" << all_weapons_here[weopen_count]->getMaxCondition();
    cout << endl;

  }

  // Show all Usables (by type)

  cout << "                ~potions~               " << endl;
  vector<Usable*> all_usables_here = board.getAllUsablesInventory();

  // Loop through Usables and look for potions (type 1)
  unsigned int usable_count = 0;
  for(usable_count = 0; usable_count < all_usables_here.size(); usable_count++)
  {
    if(all_usables_here[usable_count]->getType() == 1) // Check if its a Health Potion (by type 1)
    {
      cout << all_usables_here[usable_count]->getName();
      cout << " (" << all_usables_here[usable_count]->getinSomethingID() << ")";

      cout << " :" << endl;

      cout << "Heals you for " << all_usables_here[usable_count]->getValue() << 
     " HP" << endl;
    }
  }

  if(usable_count == 0)
  {
    cout << "           You have no potions" << endl;
  }
  
  
  cout << "----------------------------------------" << endl; 
  return 0;
}