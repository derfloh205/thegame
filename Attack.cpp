#include "Attack.h"
#include <iostream>
#include <string>
#include "Place.h"
#include "Enemy.h"

using std::cout;
using std::endl;
using std::string;

Attack::Attack(string ac_name) : Command(ac_name)
{}
 
Attack::~Attack()
{}

int Attack::execute(Game& board, std::vector<std::string>& params)
{
  bool already_attacked = false;
  bool found = false;
  
  if(!board.dead())
  {
  
    if(params.size() > 1)
    {
      //Check if there are enemies to attack
      Place *current_place = board.getAllPlaces()[board.getPlace() - 1];
      vector<Enemy*> all_enemys_here = current_place->getEnemys();
      
      if(all_enemys_here.size())
      {
        board.tolowerCase(params[1]);
        string to_attack = params[1];
        
        // When >>> attack name
        if(params.size() == 2)
        {
          // Search for the first enemy with this name
          for(unsigned int i = 0; i < all_enemys_here.size(); i++)
          {
            
            if((all_enemys_here[i]->getName() == to_attack) && !already_attacked) // if found
            {
              board.setFight(true); // get In Fight

              if(board.checkCRIT())
              {
               unsigned int new_damage = board.getDMG() * 2;
               cout << "You got a CRITICAL " << all_enemys_here[i]->getName()
               << " gets " << new_damage << "! damage" << endl;
               
               all_enemys_here[i]->decreaseHP(new_damage);
                
              }
              else
              {
              
                unsigned int new_damage = board.getDMG();
                 cout << "You attack " << all_enemys_here[i]->getName() << ", dealing "
                << new_damage << " damage!" << endl;
                
                all_enemys_here[i]->decreaseHP(new_damage);
              }

              string tempname = all_enemys_here[i]->getName();
              int tempmax = all_enemys_here[i]->getMaxHP();
              int temphp = all_enemys_here[i]->getHP();
              
              // Check if the enemy is dead
              if( !(all_enemys_here[i]->checkHP()) )
              {
                cout << all_enemys_here[i]->getName() << " is dead!" << endl;
                cout << "You recieve " << all_enemys_here[i]->getEXP() << " EXP and "
                << all_enemys_here[i]->getGold() << " Gold." << endl;
                
                board.addEXP(all_enemys_here[i]->getEXP());
                board.addGold(all_enemys_here[i]->getGold());
                
                all_enemys_here[i]->die();
              }
              
              // Let all left enemies in this place counterattack
              // Getting new actual pointer for enemys
              vector<Enemy*> all_enemys_to_attack = current_place->getEnemys();
              for(unsigned int x = 0; x < all_enemys_to_attack.size();x++)
              {
                 all_enemys_to_attack[x]->attack();
              }
              
              // look if there are enemys left
              if(!all_enemys_to_attack.size())
              {
                //get out of fight
                board.setFight(false);
              }
              
              already_attacked = true;    

             // Show enemies and your hp here ??
              if(all_enemys_here[i] != NULL)
              {
                cout << tempname << ": " << temphp << "/" << tempmax;
              }
              else
              {
                cout << tempname << ": dead";
              }

              cout << "    You: " << board.getHP() << "/" << board.getMaxHP() << endl;
              
                  
            }
          }
        } 
        else if(params.size() == 3)
        {
          unsigned int idi_to_attack = atoi(params[2].c_str());
          
          // Search for the exact enemy with this name and IDI
          for(unsigned int i = 0; i < all_enemys_here.size(); i++)
          {
            if(all_enemys_here[i]->getName() == to_attack) found = true;
          
            if((all_enemys_here[i]->getName() == to_attack) && !already_attacked 
            && (all_enemys_here[i]->getIDI() == idi_to_attack) ) // if there is one
            {
              board.setFight(true); // get In Fight
              if(board.checkCRIT())
              {
               unsigned int new_damage = board.getDMG() * 2;
               cout << "You got a CRITICAL " << all_enemys_here[i]->getName()
               << " gets " << new_damage << "! damage" << endl;
               
               all_enemys_here[i]->decreaseHP(new_damage);
                
              }
              else
              {
                unsigned int new_damage = board.getDMG();
                cout << "You attack " << all_enemys_here[i]->getName() << " (" << 
                all_enemys_here[i]->getIDI() << "), dealing "
                << new_damage << " damage!" << endl;
                
                all_enemys_here[i]->decreaseHP(new_damage);
              }
                       
              
              // Check if the enemy is dead
              if( !(all_enemys_here[i]->checkHP()) )
              {
                cout << all_enemys_here[i]->getName() << " (" 
                << all_enemys_here[i]->getIDI() << ") is dead!" << endl;
                cout << "You recieve " << all_enemys_here[i]->getEXP() << " EXP and "
                << all_enemys_here[i]->getGold() << " Gold." << endl;
                
                board.addEXP(all_enemys_here[i]->getEXP());
                board.addGold(all_enemys_here[i]->getGold());
                all_enemys_here[i]->die();
              }
              
              // Let all left enemies in this place counterattack
              // Getting new actual pointer for enemys
              vector<Enemy*> all_enemys_to_attack = current_place->getEnemys();
              for(unsigned int x = 0; x < all_enemys_to_attack.size();x++)
              {
                 all_enemys_to_attack[x]->attack();
              }
              
                // look if there are enemys left
                if(!all_enemys_to_attack.size())
                {
                  //get out of fight
                  board.setFight(false);
                }
               
             
              
              already_attacked = true; 
            }          
          }
          
          if(found && !already_attacked)
          {
                cout << "There is no " << params[1] << " (" << idi_to_attack << ")" << endl;
                already_attacked = true;
          }
          else if(!found)
          {
           cout << "What is a \"" << params[1] << "\"?" << endl;    
          } 
          
   
        }
        else
        {
          cout << "There is nothing to attack." << endl;
        }
      }
    }
    else
    {
      cout << "attacking.. what?" << endl;
    }
  
  }
  else
  {
    cout << "You are dead, please start a new game." << endl;
  }
  return 0;
}