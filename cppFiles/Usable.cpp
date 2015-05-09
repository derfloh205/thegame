#include "../hFiles/Usable.h"
#include <string>
#include "../hFiles/Game.h"
#include <iostream>
#include "../hFiles/Container.h"

using std::string;
using std::cout;
using std::endl;

  Usable::Usable(string uc_name, unsigned int uc_value, unsigned int uc_type, 
  unsigned int uc_usableID, unsigned int uc_insomethingID, Game *uc_game)
{
  name_ = uc_name;
  value_ = uc_value;
  type_ = uc_type;
  usableID_ = uc_usableID;
  in_somethingID_ = uc_insomethingID;
  game_ = uc_game;
  
}

// Getter ----------------------------------------------------------------------
//
string Usable::getName()
{
  return name_;
}
unsigned int Usable::getValue()
{
  return value_;
}
unsigned int Usable::getType()
{
  return type_;
}
Container* Usable::getContainer()
{
  return current_container_;
}
unsigned int Usable::getID()
{
  return usableID_;
}
unsigned int Usable::getinSomethingID()
{
  return in_somethingID_;
}
// -----------------------------------------------------------------------------

// Setter ----------------------------------------------------------------------
//
void Usable::setinSomethingID(unsigned int newID)
{
  in_somethingID_ = newID;
}
void Usable::setContainer(Container *newContainer)
{
  current_container_ = newContainer;
}

// -----------------------------------------------------------------------------

// Adder / Decreaser -----------------------------------------------------------
//
// -----------------------------------------------------------------------------

// Other -----------------------------------------------------------------------
//

Usable* Usable::copy()
{
  Usable* new_usable = new Usable(
  name_,
  value_,
  type_,
  usableID_,
  in_somethingID_,
  game_
  );
  return new_usable;
}
// -----------------------------------------------------------------------------
 