#ifndef OPEN_H
#define OPEN_H

#include<string>
#include<iostream>
#include "Game.h"
#include "Command.h"
using std::string;

class Open : public Command
{
  private:
  
  
  
  public:
  Open(string oc_name);
  virtual ~Open();
  virtual int execute(Game& board, std::vector<std::string>& params);
  
};

#endif