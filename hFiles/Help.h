#ifndef HELP_H
#define HELP_H

#include<string>
#include<iostream>
#include "Game.h"
#include "Command.h"

class Help : public Command
{
  private:
  
  public:
  Help(string hc_name);
  virtual ~Help();
  virtual int execute(Game& board, std::vector<std::string>& params);
};

#endif