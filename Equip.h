#ifndef EQUIP_H
#define EQUIP_H
#include "Game.h"
#include "Command.h"

class Equip: public Command
{
  private:
  
  public:
    Equip(string ec_name);
    virtual ~Equip();
    virtual int execute(Game& board, std::vector<std::string>& params);
};

#endif