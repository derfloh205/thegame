#ifndef CHARACTER_H
#define CHARACTER_H
#include "Game.h"
#include "Command.h"

class Character: public Command
{
  private:
  
  public:
    Character(string cc_name);
    virtual ~Character();
    virtual int execute(Game& board, std::vector<std::string>& params);
};

#endif