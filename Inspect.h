#ifndef INSPECT_H
#define INSPECT_H

#include<string>
#include<iostream>
#include "Game.h"
#include "Command.h"
using std::string;

class Inspect : public Command
{
  private:
  
  const string NORTH = "north";
  const string SOUTH = "south";
  const string EAST = "east";
  const string WEST = "west";
  
  
  public:
  Inspect(string ic_name);
  virtual ~Inspect();
  virtual int execute(Game& board, std::vector<std::string>& params);
  
};

#endif