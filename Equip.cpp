#include "Equip.h"
#include "Weapon.h"
#include <iostream>

using std::cout;
using std::endl;
 
Equip::Equip(string ec_name) : Command(ec_name)
{}
 
 Equip::~Equip()
{
}

int Equip::execute(Game& board, std::vector<std::string>& params)
{
  vector<Weapon*> all_weapons_here = board.getAllWeaponsInventory();

  if(!board.dead())
  {
    if(!board.getinFight())
    {
      if(params.size() == 3)
      {
        // search weapons
        unsigned int IDI_to_equip = atoi(params[2].c_str());
        for(unsigned int i = 0; i < all_weapons_here.size();i++)
        {
        
        
          if(all_weapons_here[i]->getName() == params[1] && 
          all_weapons_here[i]->getinSomethingID() == IDI_to_equip) // if found
          {
            board.equipWeaponByIDI(IDI_to_equip);
            cout << "You equip " << all_weapons_here[i]->getName() << endl;
            return 0;
          }
          
          
          
        }
        
        
        
        // if nothing found
        cout << "There is no \"" << params[1] << "\" to equip." << endl;
        
        
        
      } // if params
      else
      {
        cout << "You can't do that." << endl;
      }
      
    } // if infight
    else
    {
      cout << "You can't do that during combat!" << endl;
    }
    
  } // if dead
  else
  {
    cout << "You are dead, please start a new game." << endl;
  }
  
  return 0;
}