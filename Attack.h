#ifndef ATTACK_H
#define ATTACK_H

#include<string>
#include<iostream>
#include "Game.h"
#include "Command.h"

class Attack : public Command
{
  private:
  
  public:
  Attack(string ac_name);
  virtual ~Attack();
  virtual int execute(Game& board, std::vector<std::string>& params);
};

#endif