#include "Inspect.h"
#include <iostream>
#include "Place.h"
#include <string>
#include "Enemy.h"
#include "Container.h"

using std::cout;
using std::endl;
using std::string;

Inspect::Inspect(string ic_name) : Command(ic_name)
{}
 
Inspect::~Inspect()
{}

int Inspect::execute(Game& board, std::vector<std::string>& params)
{
  vector<Place*> all_places = board.getAllPlaces();
  Place *current_place = all_places[board.getPlace() - 1];
  vector<Enemy*> all_enemys_here = current_place->getEnemys();
  if(!board.dead())
  {
  
    if(params.size() == 1)
    {
      // Give Infos about the Place
      
      cout << current_place->getInfo() << endl;
      
      // Give Infos about the Monsters here
      vector<Enemy*> all_enemys_here = current_place->getEnemys();
      for(unsigned int i = 0; i < all_enemys_here.size(); i++)
      {
        cout << "Be careful there is a " << all_enemys_here[i]->getName() 
        << " (" << all_enemys_here[i]->getIDI() << ")" << endl;
      }
      // Give Infos about the Containers here
      vector<Container*> all_container_here = current_place->getContainer();
      for(unsigned int i = 0; i < all_container_here.size();i++)
      {
        cout << "There is a " << all_container_here[i]->getName() << " (" <<
        all_container_here[i]->getIDI() << ")";
        
        if(all_container_here[i]->getOpen() )
        {
          cout << " (opened)";
        }
        
        if(!all_container_here[i]->getWeapons().size())
        {
          cout << " (empty)";
        }
        
          cout << endl;
        
      }
      
       
    }
    else if(params.size() == 2)
    {
      board.tolowerCase(params[1]);

    
      if(params[1] == NORTH && current_place->getNorth())
      {
        cout << "There is a way to the north, it leads to " 
        << all_places[current_place->getNorth() - 1]->getName() << "." << endl;
      }
      else if(params[1] == SOUTH && current_place->getSouth())
      {
        cout << "There is a way to the south, it leads to " 
        << all_places[current_place->getSouth() - 1]->getName() << "." << endl;
      }
      else if(params[1] == EAST && current_place->getEast())
      {
        cout << "There is a way to the east, it leads to " 
        << all_places[current_place->getEast() - 1]->getName() << "." << endl;
      }
      else if(params[1] == WEST && current_place->getWest())
      {
        cout << "There is a way to the west, it leads to " 
        << all_places[current_place->getWest() - 1]->getName() << "." << endl;
      }
      else
      {
         bool found = false;
         for(unsigned int i = 0; i < all_enemys_here.size();i++)
         {
            if(params[1] == all_enemys_here[i]->getName())
            {
              found = true;
            }
         }
         
         if(found)
         {
          cout << "What " << params[1] << " do you mean?" << endl;
         }
         else
         cout << "There is nothing to inspect." << endl;
      }

    }
    else if(params.size() == 3)
    {
      // check what enemy was ment
      board.tolowerCase(params[1]);
      unsigned int enemy_idi = atoi(params[2].c_str());
      bool found = false; 
         
      for(unsigned int i = 0; i < all_enemys_here.size(); i++)
      {
        if(params[1] == all_enemys_here[i]->getName())
        { 
          found = true;
          if(enemy_idi == all_enemys_here[i]->getIDI())
          {
            cout << all_enemys_here[i]->getInfo() << endl;
            cout << all_enemys_here[i]->getHP() << "/" << 
            all_enemys_here[i]->getMaxHP() << " HP" << endl;
            return 0;
          }
          
        }
      }
      
      if(found)
      {
        cout << "There is no " << params[1] << " (" << enemy_idi << ")" << endl;
      }
      else
      {
        cout << "What is a \"" << params[1] << "\"?" << endl;
      }
    }
  
  }
  else
  {
    cout << "You are dead, please start a new game." << endl;
  }

  return 0;
}