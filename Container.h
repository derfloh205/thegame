#ifndef CONTAINER_H
#define CONTAINER_H

#include<string>
#include<iostream>
#include <vector>
class Weapon;
class Game;
class Usable;

using std::string;
using std::vector;

class Container
{
  private:
  string name_;
  unsigned int current_placeID_;
  unsigned int containerID_;
  unsigned int in_place_identifier_;
  unsigned int current_weapon_in_containerID_;
  unsigned int current_usable_in_containerID_;
  vector<Weapon*> all_weapons_inside_;
  vector<Usable*> all_usables_inside_;
  bool opened_;
  Game *game_;
  // Other Stuff
  
  public:
  Container(string cc_name, unsigned int cc_placeID, unsigned int cc_containerID,
  unsigned int cc_IDI, Game *cc_game);
  
  //Getter
  string getName();
  unsigned int getPlaceID();
  unsigned int getContainerID();
  unsigned int getIDI();
  vector<Weapon*> getWeapons();
  vector<Usable*> getUsables();
  bool getOpen();
  
  //Setter
  void setPlaceID(unsigned int newID);
  void setIPI(unsigned int newIPI);
  void setOpened(bool newbool);
  
  // Adder and Deleter
  void addWeaponByID(unsigned int weaponID_to_add);
  void addUsableByID(unsigned int usableID_to_add);
  void deleteWeaponByIDI(unsigned int weaponIDI_to_delete);
  void deleteUsableByIDI(unsigned int usableIDI_to_delete);
  
  // Other
  Container* copy();
};

#endif