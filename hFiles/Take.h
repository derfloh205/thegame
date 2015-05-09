#ifndef TAKE_H
#define TAKE_H

#include<string>
#include<iostream>
#include "Game.h"
#include "Command.h"
using std::string;

class Take : public Command
{
  private:
  
  
  
  public:
  Take(string tc_name);
  virtual ~Take();
  virtual int execute(Game& board, std::vector<std::string>& params);
  
};

#endif