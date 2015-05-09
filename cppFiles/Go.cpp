#include "../hFiles/Go.h"
#include <iostream>
#include <string>
#include "../hFiles/Place.h"
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

Go::Go(string gc_name) : Command(gc_name)
{}
 
Go::~Go()
{}

int Go::execute(Game& board, std::vector<std::string>& params)
{
  vector<Place*> all_places = board.getAllPlaces();
  Place *current_place = all_places[board.getPlace() - 1];
  if(!board.dead())
  {
    if(!board.getinFight())
    {
  
      if(params.size() == 1)
      {
        cout << "going.. where?" << endl;
        
      }
      else if(params.size() == 2)
      {
        board.tolowerCase(params[1]);
      
        if(params[1] == NORTH && current_place->getNorth())
        {
          cout << "You are going to "
          << all_places[current_place->getNorth() - 1]->getName() << "." << endl;
          board.setNewPlace(current_place->getNorth());
        }
        else if(params[1] == SOUTH && current_place->getSouth())
        {
          cout << "You are going to "
          << all_places[current_place->getSouth() - 1]->getName() << "." << endl;
          board.setNewPlace(current_place->getSouth());
        }
        else if(params[1] == EAST && current_place->getEast())
        {
          cout << "You are going to "
          << all_places[current_place->getEast() - 1]->getName() << "." << endl;
          board.setNewPlace(current_place->getEast());
        }
        else if(params[1] == WEST && current_place->getWest())
        {
          cout << "You are going to "
          << all_places[current_place->getWest() - 1]->getName() << "." << endl;
          board.setNewPlace(current_place->getWest());
        }
        else
        {
          cout << "You can't go there." << endl;
        }
      } // params 2
    } // infight  
    else
    {
      cout << "You can't do that during combat!" << endl;
    }
  } // dead
  else
  {
    cout << "You are dead, please start a new game." << endl;
  }
  return 0;
}