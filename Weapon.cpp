#include "Weapon.h"
#include <string>
#include "Game.h"
#include <iostream>
#include "Container.h"

using std::string;
using std::cout;
using std::endl;

Weapon::Weapon(string wc_name, unsigned int wc_damage, unsigned int wc_type,
  unsigned int wc_condition, unsigned int wc_max_condition, unsigned int wc_speed, 
  unsigned int wc_weaponID, unsigned int wc_insomethingID, Game *wc_game)
{
  name_ = wc_name;
  damage_ = wc_damage;
  type_ = wc_type;
  condition_ = wc_condition;
  max_condition_ = wc_max_condition;
  speed_ = wc_speed;
  weaponID_ = wc_weaponID;
  in_somethingID_ = wc_insomethingID;
  game_ = wc_game;
  
}

// Getter ----------------------------------------------------------------------
//
string Weapon::getName()
{
  return name_;
}
unsigned int Weapon::getDMG()
{
  return damage_;
}
unsigned int Weapon::getType()
{
  return type_;
}
int Weapon::getCondition()
{
  return condition_;
}
unsigned int Weapon::getMaxCondition()
{
  return max_condition_;
}
unsigned int Weapon::getSpeed()
{
  return speed_;
}
Container* Weapon::getContainer()
{
  return current_container_;
}
unsigned int Weapon::getID()
{
  return weaponID_;
}
unsigned int Weapon::getinSomethingID()
{
  return in_somethingID_;
}
// -----------------------------------------------------------------------------

// Setter ----------------------------------------------------------------------
//
void Weapon::resetCondition()
{
  condition_ = max_condition_;
}
void Weapon::setinSomethingID(unsigned int newID)
{
  in_somethingID_ = newID;
}
void Weapon::setContainer(Container *newContainer)
{
  current_container_ = newContainer;
}

// -----------------------------------------------------------------------------

// Adder / Decreaser -----------------------------------------------------------
//
void Weapon::decreaseCondition(unsigned int minus_by)
{
  condition_ -= minus_by;
  
  if(condition_ < 0)
  {
    condition_ = 0;
  }
}
// -----------------------------------------------------------------------------

// Other -----------------------------------------------------------------------
//

Weapon* Weapon::copy()
{
  Weapon* new_weapon = new Weapon(
  name_,
  damage_,
  type_,
  condition_,
  max_condition_,
  speed_,
  weaponID_,
  in_somethingID_,
  game_
  );
  return new_weapon;
}
// -----------------------------------------------------------------------------
 