#include "Quit.h"

Quit::Quit(string qc_name) : Command(qc_name)
{}

Quit::~Quit()
{}

int Quit::execute(Game& board, std::vector<std::string>& params)
{

  if(params.size() > 1)
  {
    std::cout << "You can't do that!" << std::endl;
  }
  else
  {  
    board.setQuitflag(true);
  }
  return 0;
}