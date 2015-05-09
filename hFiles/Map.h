#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "Command.h"
class Game;


class Map : public Command
{
  private:
  
  public:
  Map(string mc_name);
  virtual ~Map();
  virtual int execute(Game& board, std::vector<std::string>& params);
};
#endif