#ifndef GO_H
#define GO_H

#include<string>
#include<iostream>
#include "Game.h"
#include "Command.h"
using std::string;

class Go : public Command
{
  private:
  
  const string NORTH = "north";
  const string SOUTH = "south";
  const string EAST = "east";
  const string WEST = "west";
  
  public:
  Go(string gc_name);
  virtual ~Go();
  virtual int execute(Game& board, std::vector<std::string>& params);
  
};

#endif