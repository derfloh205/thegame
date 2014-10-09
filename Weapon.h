#ifndef WEAPON_H
#define WEAPON_H

#include<string>
#include<iostream>
#include "Game.h"
class Container;

using std::string;

class Weapon
{
  private:
  string name_;
  unsigned int damage_;
  unsigned int type_;
  /* Types:
  1 .. One Handed
  2 .. Two Handed
  */
  int condition_;
  unsigned int max_condition_;
  unsigned int speed_;
  Game *game_;
  unsigned int weaponID_;
  unsigned int in_somethingID_; // when 0 it is nowhere, can be in container or inventory
  Container *current_container_; // when 0 it is not in a container
  
  
  public:
  Weapon(string wc_name, unsigned int wc_damage, unsigned int wc_type,
  unsigned int wc_condition, unsigned int wc_max_condition, unsigned int wc_speed, 
  unsigned int wc_weaponID, unsigned int wc_insomethingID, Game *wc_game);
  
  // Getter
  string getName();
  unsigned int getDMG();
  unsigned int getType();
  int getCondition();
  unsigned int getMaxCondition();
  unsigned int getSpeed();
  Container *getContainer();
  unsigned int getID();
  unsigned int getinSomethingID();
  
  // Setter
  void resetCondition();
  void setinSomethingID(unsigned int newID);
  void setContainer(Container *newContainer);
  
  // Adder/Decreaser
  void decreaseCondition(unsigned int minus_by);
  
  // Other
  Weapon* copy();
};

#endif