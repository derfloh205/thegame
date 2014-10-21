#ifndef GAME_H
#define GAME_H

#include <map>
#include <string>
#include <vector>
#include "Command.h"
class Enemy;
class Place;
class Weapon;
class Container;
class Usable;

using std::string;
using std::vector;


class Game
{
  private:
  //System
  bool quitflag_;
  unsigned int current_placeID_;
  unsigned int placeID_toSave_;
  unsigned int enemyID_toSave_;
  unsigned int weaponID_toSave_;
  unsigned int usableID_toSave_;
  unsigned int containerID_toSave_;
  unsigned int weaponID_inventory_toSave_;
  unsigned int usableID_inventory_toSave_;
  vector<Place*> all_places_;
  vector<Enemy*> all_enemy_types_;
  vector<Weapon*> all_weapon_types_;
  vector<Usable*> all_usable_types_;
  vector<Container*> all_container_types_;
  
  //Player
  int playerHP_;
  unsigned int player_maxHP_;
  unsigned int playerAttack_;
  unsigned int playerAC_;
  unsigned int playerCRIT_;
  unsigned int playerEXP_;
  unsigned int playerNextEXP_;
  unsigned int playerLVL_;
  unsigned int playerGold_;
  bool is_dead_;
  bool in_fight_;
  Weapon *current_equipped_weapon_;
  
  // Inventory
  vector<Weapon*> all_weapons_inventory_;
  vector<Usable*> all_usables_inventory_;
  
  
  
  //Defines
  const string PROMPT = ">>> ";
  static const char space = ' ';
  static const int lowercase = 97;
  const string QUIT = "quit";
  const string CHARACTER = "character";
  const string INSPECT = "inspect";
  const string GO = "go";
  const string ATTACK = "attack";
  const string HELP = "help";
  const string OPEN = "open";
  const string TAKE = "take";
  const string INVENTORY = "inventory";
  const string EQUIP = "equip";
  const string USE = "use";
  const string MAP = "map";
  const string START_WEAPON = "rusty_dagger";
  
  public: 
  //Constructors
  Game();
  
  //Commands
  void makeCommands(std::map<string, Command*> &command_map);
  void tolowerCase(string &str);
  
  //Deleter
  void deleteCommands(std::map<string, Command*> &commands_to_delete);
  
  //Setter
   void setQuitflag(bool newflag);
   void setHP(unsigned int newHP);
   void setNewPlace(unsigned int new_placeID);
   void setAttack(unsigned int newAttack);
   void setAC(unsigned int newAC);
   void setDead(bool newbool);
   void setFight(bool newbool);
   void setCRIT(unsigned int newcrit);
   void setEXP(unsigned int newexp);
   void setLVL(unsigned int newlvl);
   void setNextEXP(unsigned int newnextexp);
   
   //Getter
   int getHP();
   unsigned int getMaxHP();
   unsigned int getPlace();
   vector<Place*> getAllPlaces();
   vector<Enemy*> getAllEnemys();
   vector<Usable*> getAllUsables();
   vector<Weapon*> getAllWeapons();
   unsigned int getAttack();
   unsigned int getDMG();
   unsigned int getAC();
   bool dead();
   bool getinFight();
   unsigned int getRandom(unsigned int botrange, unsigned int toprange);
   unsigned int getCRIT();
   unsigned int getHIT();
   unsigned int getLVL();
   unsigned int getEXP();
   unsigned int getNextEXP();
   unsigned int getGold();
   vector<Weapon*> getAllWeaponsInventory();
   vector<Usable*> getAllUsablesInventory();


   Weapon* getWeapon();
   vector<Container*> getAllContainers();
   
   // Adder and Decreaser
   void decreaseHP(unsigned int decrease_by);

   void addHP(unsigned int add_by);
   void addPlace(Place *new_place);
   void addEnemy(Enemy *new_enemy);
   void addAttack(unsigned int plusAttack);
   void addAC(unsigned int plusAC);
   void addEXP(unsigned int plusEXP);
   void addGold(unsigned int plusGold);

   void takeWeapon(Weapon *new_weapon); // from container into inventory
   void takeUsable(Usable *new_usable);

   void addWeapon(Weapon *new_weapon); // completely new weapontype to the game
   void addUsable(Usable *new_usable);
   void addContainer(Container *new_container); // new type of container
   

   
   //Other
   int run();
   vector<string> get_arguments(string input);
   void READ();
   bool checkHP();
   bool checkCRIT();
   void levelUP();
   void checkLevelUP();
   void resetHP();
   void equipWeaponByIDI(unsigned int IDI_to_equip);
   void useUsableByIDI(unsigned int IDI_to_use);
   void deleteWeaponInventoryByIDI(unsigned int IDI_to_delete);
   void deleteUsableInventoryByIDI(unsigned int IDI_to_delete);
};
#endif