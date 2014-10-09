#ifndef USABLE_H
#define USABLE_H

#include <string>
#include <iostream>
class Game;
class Container;

using std::string;

class Usable
{
  private:
  string name_;
  unsigned int value_;
  // The type defines the kind of usable
  // 0 -> quest item, specific
  // 1 -> Healing Usables
  unsigned int type_;
  Game *game_;
  unsigned int usableID_;
  unsigned int in_somethingID_; // when 0 it is nowhere, can be in container or inventory
  Container *current_container_; // when 0 it is not in a container
  
  
  public:
  Usable(string uc_name, unsigned int uc_value, unsigned int uc_type, 
  unsigned int uc_usableID, unsigned int uc_insomethingID, Game *uc_game);
  
  // Getter
  string getName();
  unsigned int getValue();
  unsigned int getType();
  Container *getContainer();
  unsigned int getID();
  unsigned int getinSomethingID();
  
  // Setter
  void setinSomethingID(unsigned int newID);
  void setContainer(Container *newContainer);
  
  // Other
  Usable* copy();
};

#endif