#ifndef USE_H
#define USE_H
#include "Game.h"
#include "Command.h"

class Use : public Command
{
  private:
  
  public:
    Use(string uc_name);
    virtual ~Use();
    virtual int execute(Game& board, std::vector<std::string>& params);
};
#endif