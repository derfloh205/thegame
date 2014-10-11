#include "Container.h"

#include <string>
#include <iostream>
#include "Game.h"
#include <vector>
#include "Weapon.h"
#include "Usable.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

Container::Container(string cc_name, unsigned int cc_placeID, unsigned int cc_containerID,
  unsigned int cc_IDI, Game *cc_game)
{
  name_ = cc_name;
  current_placeID_ = cc_placeID;
  containerID_ = cc_containerID;
  in_place_identifier_ = cc_IDI;
  game_ = cc_game;
  
  current_weapon_in_containerID_ = 1;
  current_usable_in_containerID_ = 1;
  opened_ = false;
}

// Getter ----------------------------------------------------------------------
//
string Container::getName()
{
  return name_;
}
unsigned int Container::getPlaceID()
{
  return current_placeID_;
}
unsigned int Container::getContainerID()
{
  return containerID_;
}
unsigned int Container::getIDI()
{
  return in_place_identifier_;
}
vector<Weapon*> Container::getWeapons()
{
  return all_weapons_inside_;
}

vector<Usable*> Container::getUsables()
{
  return all_usables_inside_;
}

bool Container::getOpen()
{
  return opened_;
}
// -----------------------------------------------------------------------------

// Adder and Deleter -----------------------------------------------------------
//
void Container::addWeaponByID(unsigned int weaponID_to_add)
{
  // Loop through all existing Weapons in Game
  vector<Weapon*> all_existing_weapons = game_->getAllWeapons();
  for (unsigned int i = 0; i < all_existing_weapons.size(); i++)
  {
    if(weaponID_to_add == all_existing_weapons[i]->getID()) // if found
    {
      // make a copy
      Weapon *new_weapon = all_existing_weapons[i]->copy();
 
      // Set new values which are important for a weapon in the game
      new_weapon->setinSomethingID(current_weapon_in_containerID_);
      current_weapon_in_containerID_++; // prepare for next weapon to be added
      new_weapon->setContainer(this);
      
      // Add the weapon to the container
      all_weapons_inside_.push_back(new_weapon);
      
    }
  }
}

void Container::addUsableByID(unsigned int usableID_to_add)
{
  // Loop through all existing Usables in Game
  vector<Usable*> all_existing_usables = game_->getAllUsables();
  for (unsigned int i = 0; i < all_existing_usables.size(); i++)
  {
    if(usableID_to_add == all_existing_usables[i]->getID()) // if found
    {
      // make a copy
      Usable *new_usable = all_existing_usables[i]->copy();
 
      // Set new values which are important for a weapon in the game
      new_usable->setinSomethingID(current_usable_in_containerID_);
      current_usable_in_containerID_++; // prepare for next weapon to be added
      new_usable->setContainer(this);
      
      // Add the weapon to the container
      all_usables_inside_.push_back(new_usable);
      
    }
  }
}

void Container::deleteWeaponByIDI(unsigned int weaponIDI_to_delete) // The weapon is not destroyed !! It will be moved by take command
{
  // Loop through all weapons in the container
  for(unsigned int i = 0; i < all_weapons_inside_.size(); i++)
  {
    if(weaponIDI_to_delete == all_weapons_inside_[i]->getinSomethingID()) // if found
    {
      all_weapons_inside_.erase(all_weapons_inside_.begin() + i);
    }
  }
  
}

void Container::deleteUsableByIDI(unsigned int usableIDI_to_delete) // The usable is not destroyed !! It will be moved by take command
{
  // Loop through all usables in the container
  for(unsigned int i = 0; i < all_usables_inside_.size(); i++)
  {
    if(usableIDI_to_delete == all_usables_inside_[i]->getinSomethingID()) // if found
    {
      all_usables_inside_.erase(all_usables_inside_.begin() + i);
    }
  }
  
}
// -----------------------------------------------------------------------------

// Other -----------------------------------------------------------------------
//
Container* Container::copy()
{
  Container *new_one = new Container(
  name_,
  current_placeID_,
  containerID_,
  in_place_identifier_,
  game_
  );
  
  return new_one;
}
// -----------------------------------------------------------------------------

//Setter -----------------------------------------------------------------------
//
void Container::setPlaceID(unsigned int newID)
{
  current_placeID_ = newID;
}
void Container::setIPI(unsigned int newIPI)
{
  in_place_identifier_ = newIPI;
}

void Container::setOpened(bool newbool)
{
  opened_ = newbool;
}
// -----------------------------------------------------------------------------