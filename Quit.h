#ifndef QUIT_H
#define QUIT_H

#include<string>
#include<iostream>
#include "Game.h"
#include "Command.h"

class Quit : public Command
{
  private:
  
  public:
  Quit(string qc_name);
  virtual ~Quit();
  virtual int execute(Game& board, std::vector<std::string>& params);
  
};

#endif