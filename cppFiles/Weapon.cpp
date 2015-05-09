#include "../hFiles/Weapon.h"
#include <string>
#include "../hFiles/Game.h"
#include <iostream>
#include "../hFiles/Container.h"

using std::string;
using std::cout;
using std::endl;

Weapon::Weapon(string wc_name, unsigned int wc_type,
  unsigned int wc_dice_amount, unsigned int wc_dice_type, unsigned int wc_speed, 
  unsigned int wc_weaponID, unsigned int wc_insomethingID, Game *wc_game)
{
  name_ = wc_name;
  type_ = wc_type;
  dice_amount_ = wc_dice_amount;
  dice_type_ = wc_dice_type;
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
unsigned int Weapon::getType()
{
  return type_;
}
unsigned int Weapon::getDiceAmount()
{
  return dice_amount_;
}
unsigned int Weapon::getDiceType()
{
  return dice_type_;
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
void Weapon::setinSomethingID(unsigned int newID)
{
  in_somethingID_ = newID;
}
void Weapon::setContainer(Container *newContainer)
{
  current_container_ = newContainer;
}

// -----------------------------------------------------------------------------

// Other -----------------------------------------------------------------------
//

Weapon* Weapon::copy()
{
  Weapon* new_weapon = new Weapon(
  name_,
  type_,
  dice_amount_,
  dice_type_,
  speed_,
  weaponID_,
  in_somethingID_,
  game_
  );
  return new_weapon;
}
// -----------------------------------------------------------------------------
 