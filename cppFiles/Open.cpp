#include "../hFiles/Open.h"
#include <iostream>
#include "../hFiles/Place.h"
#include <string>
#include "../hFiles/Enemy.h"
#include "../hFiles/Container.h"
#include "../hFiles/Weapon.h"
#include "../hFiles/Usable.h"
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

Open::Open(string oc_name) : Command(oc_name)
{}
 
Open::~Open()
{}

int Open::execute(Game& board, std::vector<std::string>& params)
{
  Place *actual_place = board.getAllPlaces()[board.getPlace() - 1];
  
  if(!board.dead()) // if you are dead
  {
    if(actual_place->getContainer().size()) // if there is a container
    {
      if(!actual_place->getEnemys().size()) // if there are still enemies
      {
        // Check for right amount of params
        if(params.size() == 3)
        {
          // Check if there is a container with the given name
          string container_name = params[1];
          unsigned int container_IPI = atoi(params[2].c_str());

          // Loop through all containers
          vector<Container*> all_container_here = actual_place->getContainer();
          for(unsigned int i = 0; i < all_container_here.size(); i++)
          {
            if(container_name == all_container_here[i]->getName() 
            && container_IPI == all_container_here[i]->getIDI()) // if found
            {
              // Make opened and give infos about the things within
              all_container_here[i]->setOpened(true);
              cout << "------------ " << all_container_here[i]->getName() << " ------------" << endl;

              // Info about Weapons
              vector<Weapon*> all_weapons_within = all_container_here[i]->getWeapons();
              for(unsigned int w = 0; w < all_weapons_within.size(); w++)
              {
                cout << "There is a " << all_weapons_within[w]->getName() << " (" << all_weapons_within[w]->getinSomethingID() << ")" << endl;

              }

              // Info about Usables
              vector<Usable*> all_usables_within = all_container_here[i]->getUsables();
              for(unsigned int u = 0; u < all_usables_within.size(); u++)
              {
                cout << "There is a " << all_usables_within[u]->getName() << " (" << all_usables_within[u]->getinSomethingID() << ")" << endl;
              }
              
              
              // if there is nothing in it (if has to contain all sizes of all items)
              if(!all_weapons_within.size() && !all_usables_within.size())
              {
                cout << "It's empty." << endl;
              }
              
              cout << "------------" ;
              for(unsigned int l = 0; l < (all_container_here[i]->getName().length() + 2); l++)
              {
                cout << "-";
              }
              cout << "------------" << endl;
              
              // close all other containers
              for(unsigned int x = 0; x < all_container_here.size(); x++)
              {
                if(container_name != all_container_here[x]->getName() 
                && container_IPI != all_container_here[x]->getIDI())
                {
                  all_container_here[x]->setOpened(false);
                }
              }
              // 
              
              
            }
          }
        }
        else
        {
          cout << "You cannot open that." << endl;
        }
        
      
        
      } // enemies
      else
      {
        cout << "There are still enemies..." << endl;
        return 0;
      }
    } // if container
    else
    {
      cout << "There is nothing to open." << endl;
    }
  } // if dead
  else
  {
    cout << "You are dead, please start a new game." << endl;
  }
  
  return 0;
}