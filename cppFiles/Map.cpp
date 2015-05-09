#include "../hFiles/Map.h"
#include <iostream>
#include <string>
#include "../hFiles/Place.h"
#include <vector>

using std::cout;
using std::endl;
using std::string;

Map::Map(string mc_name) : Command(mc_name)
{}
 
Map::~Map()
{}

int Map::execute(Game& board, std::vector<std::string>& params)
{
  // Get the current place

  Place *current_place = board.getAllPlaces()[board.getPlace() - 1];

    cout << "---------- map ----------" << endl;

  if(current_place->getNorth())
  {
    cout << "        | North |        " << endl;
  }
  else
  {
    cout << "                         " << endl;
  }

  if(current_place->getWest() && current_place->getEast())
  {
    cout << "| West |          | East |" << endl;
  }
  else if(current_place->getWest())
  {
    cout << "| West |                  " << endl;
  }
  else if(current_place->getEast())
  {
    cout << "                  | East |" << endl;
  }
  else
  {
    cout << "                          " << endl;
  }

  if(current_place->getSouth())
  {
    cout << "        | South |         " << endl;
  }
  else
  {
    cout << "                          " << endl;
  }

    cout << "--------------------------" << endl;

    cout << "      ~" << current_place->getName() << "~" << endl;
  return 0;
}