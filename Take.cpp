#include "Take.h"
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

Take::Take(string tc_name) : Command(tc_name)
{}
 
Take::~Take()
{}

int Take::execute(Game& board, std::vector<std::string>& params) // need take all !!!
{
  Place *actual_place = board.getAllPlaces()[board.getPlace() - 1];
  vector<Container*> all_container_in_place = actual_place->getContainer();
  if(!board.dead())
  {
    if(params.size() == 3)
    {
      if(all_container_in_place.size())
      {
          if(!actual_place->getEnemys().size())
          {
            // search for an opened container with given name and do stuff and return 0 when found
            for (unsigned int i = 0; i < all_container_in_place.size();i++)
            {
              
              if(all_container_in_place[i]->getOpen()) // the opened container
              {
                // loop through all stuff to find the searched item
                vector<Weapon*> all_weapons_in_container = all_container_in_place[i]->getWeapons();
                vector<Usable*> all_usables_in_container = all_container_in_place[i]->getUsables();
                
                // Check if there is anything it it
                if(!all_weapons_in_container.size() && !all_usables_in_container.size())
                {
                  cout << all_container_in_place[i]->getName() << " is empty." << endl;
                  return 0;
                }
                
                unsigned int given_inSomethingID = atoi(params[2].c_str());
                
                // loop through weapons
                for(unsigned int x = 0; x < all_weapons_in_container.size(); x++)
                {
                  if(all_weapons_in_container[x]->getName() == params[1] &&  
                  all_weapons_in_container[x]->getinSomethingID() == given_inSomethingID) // if found
                  {
                    // Delete Weapon out of container
                    all_container_in_place[i]->deleteWeaponByIDI(given_inSomethingID);
                    
                    // Put in inventory
                    board.takeWeapon(all_weapons_in_container[x]);
                    return 0;
                  }
                }

                // loop through usables
                for(unsigned int u = 0; u < all_usables_in_container.size(); u++)
                {
                  if(all_usables_in_container[u]->getName() == params[1] &&  
                  all_usables_in_container[u]->getinSomethingID() == given_inSomethingID) // if found
                  {

                    // Delete Usable out of container
                    all_container_in_place[i]->deleteUsableByIDI(given_inSomethingID);
                    
                    // Put in inventory
                    board.takeUsable(all_usables_in_container[u]);
                    return 0;
                  }
                }
              } 
            }
            // if not found
            
            cout << "You have to open something." << endl;
            
          } // if enemies
          else
          {
            cout << "There are still enemies..." << endl;
          } 
      } // if container
      else
      {
        cout << "There is nothing that you can loot." << endl;
      }
      
    } // if params
    else
    {
      cout << "You can't do that." << endl;
    }
    
  } // if dead
  else
  {
    cout << "You are dead, please start a new game." << endl;
  }
  return 0;
}