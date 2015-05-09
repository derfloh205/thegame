#ifndef INVENTORY_H
#define INVENTORY_H

#include<string>
#include<iostream>
#include "Game.h"
#include "Command.h"
using std::string;

class Inventory : public Command
{
  private:
  
  
  
  public:
  Inventory(string ic_name);
  virtual ~Inventory();
  virtual int execute(Game& board, std::vector<std::string>& params);
  
};

#endif