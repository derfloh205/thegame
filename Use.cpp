#include "Use.h"
#include "Usable.h"
#include <iostream>

using std::cout;
using std::endl;
 
Use::Use(string uc_name) : Command(uc_name)
{}
 
 Use::~Use()
{
}

int Use::execute(Game& board, std::vector<std::string>& params)
{
  vector<Usable*> all_usables_here = board.getAllUsablesInventory();

  if(!board.dead())
  {
    if(!board.getinFight())
    {
      if(params.size() == 3)
      {
        // search usables
        unsigned int IDI_to_use = atoi(params[2].c_str());
        for(unsigned int i = 0; i < all_usables_here.size();i++)
        {
        
        
          if(all_usables_here[i]->getName() == params[1] && 
          all_usables_here[i]->getinSomethingID() == IDI_to_use) // if found
          {
            board.useUsableByIDI(IDI_to_use);
            cout << "You use " << all_usables_here[i]->getName() << endl;
            return 0;
          }
          
          
          
        }
           
        // if nothing found
        cout << "There is no \"" << params[1] << "\" to use." << endl;
        
        
        
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