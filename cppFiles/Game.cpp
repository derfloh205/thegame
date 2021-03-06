#include "../hFiles/Game.h"
#include "../hFiles/Command.h"
#include <iostream>
#include <vector>
#include <sstream>

//Commands
#include "../hFiles/Quit.h"
#include "../hFiles/Character.h"
#include "../hFiles/Place.h"
#include "../hFiles/Inspect.h"
#include "../hFiles/Go.h"
#include "../hFiles/Attack.h"
#include "../hFiles/Help.h"
#include "../hFiles/Open.h"
#include "../hFiles/Take.h"
#include "../hFiles/Inventory.h"
#include "../hFiles/Equip.h"
#include "../hFiles/Use.h"
#include "../hFiles/Map.h"

//Other
#include "../hFiles/Enemy.h"
#include <time.h>
#include "../hFiles/Weapon.h"
#include "../hFiles/Usable.h"
#include "../hFiles/Container.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;



// CONSTRUCTORS-----------------------------------------------------
//
Game::Game()
{
  quitflag_ = false;
  // Test
  playerHP_ = 25;
  player_maxHP_ = 25;
  playerAttack_ = 2;
  playerAC_ = 12;
  playerCRIT_ = 30; // Critical Chance in % // DEBUG -> 100
  playerLVL_ = 1;
  playerEXP_ = 0;
  playerNextEXP_ = 500;
  playerGold_ = 0;
  
  current_placeID_ = 1;
  placeID_toSave_ = 1;
  enemyID_toSave_ = 1;
  weaponID_toSave_ = 1;
  usableID_toSave_ = 1;
  containerID_toSave_ = 1;
  weaponID_inventory_toSave_ = 1;
  usableID_inventory_toSave_ = 1;
  is_dead_ = false;
  current_equipped_weapon_ = NULL; // nothing equipped
  
}

//------------------------------------------------------------------

// COMMAND METHODS-------------------------------------------
//
void Game::makeCommands(std::map<string, Command*> &command_map)
{
  Quit *quit = new Quit(QUIT);
  Character *character = new Character(CHARACTER);
  Inspect *inspect = new Inspect(INSPECT);
  Go *go = new Go(GO);
  Attack *attack = new Attack(ATTACK);
  Help *help = new Help(HELP);
  Open *open = new Open(OPEN);
  Take *take = new Take(TAKE);
  Inventory *inventory = new Inventory(INVENTORY);
  Equip *equip = new Equip(EQUIP);
  Use *use = new Use(USE);
  Map *map = new Map(MAP);
  
  command_map[QUIT] = quit;
  command_map[CHARACTER] = character;
  command_map[INSPECT] = inspect;
  command_map[GO] = go;
  command_map[ATTACK] = attack;
  command_map[HELP] = help;
  command_map[OPEN] = open;
  command_map[TAKE] = take;
  command_map[INVENTORY] = inventory;
  command_map[EQUIP] = equip;
  command_map[USE] = use;
  command_map[MAP] = map;
}
// Clear Heap of Command Objects
void Game::deleteCommands(std::map<string, Command*> &commands_to_delete)
{
  delete commands_to_delete[QUIT];
  delete commands_to_delete[CHARACTER];
  delete commands_to_delete[INSPECT];
  delete commands_to_delete[GO];
  delete commands_to_delete[ATTACK];
  delete commands_to_delete[HELP];
  delete commands_to_delete[OPEN];
  delete commands_to_delete[TAKE];
  delete commands_to_delete[INVENTORY];
  delete commands_to_delete[EQUIP];
  delete commands_to_delete[USE];
  delete commands_to_delete[MAP];
}

void Game::tolowerCase(string &str)
{
  int length = str.length();
  for (int count = 0; count < length; count++)
  {
    if(str[count] != space && str[count] < lowercase)
      str[count] += 32;
  }
}

//-----------------------------------------------------------

// SETTER ------------------------------------------------------
//
void Game::setQuitflag(bool newflag)
{
  quitflag_ = newflag;
}

void Game::setHP(unsigned int newHP)
{
  playerHP_ = newHP;
}

void Game::setNewPlace(unsigned int new_placeID)
{
  current_placeID_ = new_placeID;
}

void Game::setAttack(unsigned int newAttack)
{
  playerAttack_ = newAttack;
}

void Game::setAC(unsigned int newAC)
{
  playerAC_ = newAC;
}

void Game::setDead(bool newbool)
{
  is_dead_ = newbool;
}
void Game::setFight(bool newbool)
{
  in_fight_ = newbool;
}

void Game::setCRIT(unsigned int newcrit)
{
  if(newcrit > 90)
  {
    newcrit = 90;
  }
  else if(newcrit < 5)
  {
    newcrit = 5;
  }
  playerCRIT_ = newcrit;
}

void Game::setEXP(unsigned int newexp)
{
  playerEXP_ = newexp;
}


void Game::setLVL(unsigned int newlvl)
{
  playerLVL_ = newlvl;
}

void Game::setNextEXP(unsigned int newnextexp)
{
  playerNextEXP_ = newnextexp;
}
//--------------------------------------------------------------

// ADDER AND DECREASER -----------------------------------------
//
void Game::decreaseHP(unsigned int decrease_by)
{
  playerHP_ -= decrease_by;
  checkHP();
}
void Game::addHP(unsigned int add_by)
{
  playerHP_ += add_by;

  if(playerHP_ > (int)player_maxHP_) // Change
  {
    playerHP_ = player_maxHP_;
  }
}

void Game::addPlace(Place *new_place)
{
  all_places_.push_back(new_place);
}

void Game::addEnemy(Enemy *new_enemy)
{
  all_enemy_types_.push_back(new_enemy);
}

void Game::addAttack(unsigned int plusAttack)
{
  playerAttack_ += plusAttack;
}

void Game::addAC(unsigned int plusAC)
{
  playerAC_ += plusAC;
}

void Game::addEXP(unsigned int plusEXP)
{
  playerEXP_ += plusEXP;
  checkLevelUP();
}

void Game::addGold(unsigned int plusGold)
{
  playerGold_ += plusGold;
}

void Game::addWeapon(Weapon *new_weapon)
{
  all_weapon_types_.push_back(new_weapon);
}

void Game::addUsable(Usable *new_usable)
{
  all_usable_types_.push_back(new_usable);
}

void Game::addContainer(Container *new_container)
{
  all_container_types_.push_back(new_container);
}

void Game::takeWeapon(Weapon *new_weapon)
{
  if(new_weapon->getName() != START_WEAPON)
  {
    cout << "You put the " << new_weapon->getName() 
    << " in your inventory." << endl;
  }

  new_weapon->setinSomethingID(weaponID_inventory_toSave_);
  weaponID_inventory_toSave_++;
  
  all_weapons_inventory_.push_back(new_weapon);
}

void Game::takeUsable(Usable *new_usable)
{
  cout << "You put the " << new_usable->getName() << " in your inventory." << endl;

  new_usable->setinSomethingID(usableID_inventory_toSave_);
  usableID_inventory_toSave_++;
  
  all_usables_inventory_.push_back(new_usable); 
}
//

// GETTER ----------------------------------------------------------------------
//
vector<string> Game::get_arguments(string input)
{
  vector<string> my_arguments;
  
  std::stringstream input_stream(input);
  string buffer;
  while (input_stream >> buffer) 
  {
    my_arguments.push_back(buffer);
  } 
  
  return my_arguments;
}

int Game::getHP()
{
  return playerHP_;
}

unsigned int Game::getMaxHP()
{
  return player_maxHP_;
}

unsigned int Game::getPlace()
{
  return current_placeID_;
}

vector<Place*> Game::getAllPlaces()
{
  return all_places_;
}

unsigned int Game::getAttack()
{
  return playerAttack_;
}

unsigned int Game::getDMG()
{
  // check if unarmed
  if(current_equipped_weapon_ == NULL)
  {
    return 1;
  }
  else
  {
    // calculate dmg from weapon
    unsigned int dmg = 0;

    for(unsigned int countdice = 0; countdice < 
      current_equipped_weapon_->getDiceAmount(); countdice++)
    {
      dmg += getRandom(1 , current_equipped_weapon_->getDiceType());
    }

    return dmg;
  }

  return 0;
}

unsigned int Game::getAC()
{

  // maybe return a full_AC based on equipment ?
  return playerAC_;
}

bool Game::dead()
{
  return is_dead_;
}

vector<Enemy*> Game::getAllEnemys()
{
  return all_enemy_types_;
}

bool Game::getinFight()
{
  return in_fight_;
}

unsigned int Game::getRandom(unsigned int botrange, unsigned int toprange)
{
  //srand ((unsigned)time(0));

  unsigned int random = (rand() % toprange + botrange);
  
  return random;
}

unsigned int Game::getCRIT()
{
  return playerCRIT_;
}

unsigned int Game::getHIT()
{
  unsigned int hit_value;

  hit_value = getRandom(1, 20) + playerAttack_;

  return hit_value;
}

unsigned int Game::getEXP()
{
  return playerEXP_;
}

unsigned int Game::getLVL()
{
  return playerLVL_;
}

unsigned int Game::getNextEXP()
{
  return playerNextEXP_;
}

unsigned int Game::getGold()
{
  return playerGold_;
}

vector<Weapon*> Game::getAllWeaponsInventory()
{
  return all_weapons_inventory_;
}

vector<Usable*> Game::getAllUsablesInventory()
{
  return all_usables_inventory_;
}

vector<Weapon*> Game::getAllWeapons()
{
  return all_weapon_types_;
}

vector<Usable*> Game::getAllUsables()
{
  return all_usable_types_;
}

Weapon* Game::getWeapon()
{
  return current_equipped_weapon_;
}

vector<Container*> Game::getAllContainers()
{
  return all_container_types_;
}
//------------------------------------------------------------------------------

// OTHER -----------------------------------------------------------------------
//
bool Game::checkHP()
{
  if(playerHP_ <= 0)
  {
    is_dead_ = true;
    cout << "YOU ARE DEAD" << endl;
    playerHP_ = 0;
    return false;
  }
    return true;
}

bool Game::checkCRIT()
{
  unsigned int random_value = getRandom(1,100);
  if(random_value <= playerCRIT_)
  return true;
  return false;
}

void Game::levelUP()
{
  unsigned int newexp = playerEXP_ - playerNextEXP_;
  unsigned int newnextexp = playerNextEXP_ * 2;
  
  playerNextEXP_ = newnextexp;
  playerEXP_ = newexp;

  // improvement
  playerAttack_ += 1;
  player_maxHP_ += 5;
  
  // Reseting Health
  resetHP();
  
  playerLVL_++;
  
  cout << "LEVEL UP! You are now level " << playerLVL_ << endl;
}
void Game::checkLevelUP()
{
  if(playerEXP_ >= playerNextEXP_)
  {
    levelUP();
  }
  
}

void Game::resetHP()
{
  playerHP_ = player_maxHP_;
}

void Game::equipWeaponByIDI(unsigned int IDI_to_equip)
{
  //loop through all weapons in inventory
  for(unsigned int i = 0; i < all_weapons_inventory_.size();i++)
  {
    if(all_weapons_inventory_[i]->getinSomethingID() == IDI_to_equip) // if found
    {
      // equip it
      current_equipped_weapon_ = all_weapons_inventory_[i];
    }
  }
}

void Game::useUsableByIDI(unsigned int IDI_to_use)
{
  //loop through all usables in inventory
  for(unsigned int i = 0; i < all_usables_inventory_.size(); i++)
  {
    if(all_usables_inventory_[i]->getinSomethingID() == IDI_to_use) // if found
    {
      // do something typespecific , heal or smth, then delete it
      if(playerHP_ == (int)player_maxHP_)                                       // Change
      {
        cout << "Your health is full." << endl;
      }
      else
      {
        cout << "You were healed by " << all_usables_inventory_[i]->getValue();
        cout << " HP" << endl;

        addHP(all_usables_inventory_[i]->getValue());
        deleteUsableInventoryByIDI(IDI_to_use);
      }
    }
  }
}

void Game::deleteWeaponInventoryByIDI(unsigned int IDI_to_delete)
{
  // Search through Weapons in inventory
  for(unsigned int actual = 0; actual < all_weapons_inventory_.size(); actual++)
  {
    if(all_weapons_inventory_[actual]->getinSomethingID() == IDI_to_delete)
    {
      delete all_weapons_inventory_[actual];
      all_weapons_inventory_.erase(all_weapons_inventory_.begin() + actual);
    }
  }

}
void Game::deleteUsableInventoryByIDI(unsigned int IDI_to_delete)
{
  // Search through Usables in inventory
  for(unsigned int actual = 0; actual < all_usables_inventory_.size(); actual++)
  {
    if(all_usables_inventory_[actual]->getinSomethingID() == IDI_to_delete)
    {
      delete all_usables_inventory_[actual];
      all_usables_inventory_.erase(all_usables_inventory_.begin() + actual);
    }
  }  
}
// -----------------------------------------------------------------------------

// RUN--------------------------------------------------------------------------
//
int Game::run()
{
  vector<string> arguments;
  string input;
  string actual_command;
  std::map<string, Command*> mapped_commands;
  makeCommands(mapped_commands);
  
  //Read all data for the game
  READ();
  
   // Begin to ask for commands until quit

      while (!quitflag_)
      {
        std::cout << PROMPT;
        std::getline(std::cin, input);
      
        // split the input and save to vector
        arguments = Game::get_arguments(input);
      
        if(arguments.size() == 0)
        {
          continue;
        }
        
        
          actual_command = arguments[0];
        
          // Make the first word of the input to lowercase
          // the actual vector where the whole input is stored is not changed
          tolowerCase(actual_command); 
        
          // Look if the given command is within the map, if yes then execute it
        if(mapped_commands.find(actual_command) == mapped_commands.end())
        {
           cout << "You can't do that!" << endl;
        }
        else
        {
          mapped_commands[actual_command]->execute(*this, arguments);
        }

      }

  deleteCommands(mapped_commands);
  
  return 0;
}
//------------------------------------------------------------------------------

// READ ------------------------------------------------------------------------
//
void Game::READ()  // Test for now
{
  //Create Enemy types ---------------------------------------------------------
  addEnemy(new Enemy("wolf", "It looks hungry and aggressive", 5, 5, 1, 1, 4, 9, // Enemy 1
  enemyID_toSave_, 0, 0, 3, 100, this));
  enemyID_toSave_++;
  
  addEnemy(new Enemy("bandit", 
  "Some thug who seems to be fleeing from the town", 20, 20, 3, 2, 4, 14,  // Enemy 2
  enemyID_toSave_, 0, 0, 23, 300, this));
  enemyID_toSave_++;
  
  addEnemy(new Enemy("troll", 
  "It is dirty and angry about something", 13, 16, 2, 1, 6, 12,  // Enemy 3
  enemyID_toSave_, 0, 0, 13, 220, this));
  enemyID_toSave_++;
  // ---------------------------------------------------------------------------
  
  
  // Create the Places ---------------------------------------------------------
  addPlace(new Place(this, "the forest", placeID_toSave_
  , "You are in some lonely forest. It's dark and cold.", 2, 0, 3, 0)); // Place 0
  placeID_toSave_++;
  
  addPlace(new Place(this, "the entrance of a town", placeID_toSave_
  , "There is a small Town ahead but you can't see any people.", 0, 1, 0, 0)); // Place 1
  placeID_toSave_++;
  
   addPlace(new Place(this, "a cave", placeID_toSave_
  , "You can see nearly nothing. Light is shining from the entrance", 0, 0, 0, 1)); // Place 2
  placeID_toSave_++;
  // ---------------------------------------------------------------------------
  
  // Add Container Types -------------------------------------------------------
  addContainer(new Container("bag", 0, containerID_toSave_, 0, this)); // Container 1
  containerID_toSave_++;
  
  addContainer(new Container("chest", 0, containerID_toSave_, 0, this)); // Container 2
  containerID_toSave_++;
  // ---------------------------------------------------------------------------
  
  // Add Weapon Types ----------------------------------------------------------
  addWeapon(new Weapon("common-sword", 1, 1, 6, 2, weaponID_toSave_, 0, this)); // Weapon 1
  weaponID_toSave_++;
  
  addWeapon(new Weapon("broadsword", 2, 2, 4, 1, weaponID_toSave_, 0, this)); // Weapon 2
  weaponID_toSave_++;

  // Start Weapon
  Weapon* start_weapon = new Weapon(START_WEAPON, 1, 1, 4, 3, weaponID_toSave_, 0, this);
  addWeapon(start_weapon); // Weapon 3
  weaponID_toSave_++;
  takeWeapon(start_weapon);
  // ---------------------------------------------------------------------------

  // Add Usable Types ----------------------------------------------------------
  addUsable(new Usable("small-health-potion", 8, 1, usableID_toSave_, 0, this)); // Usable 1
  usableID_toSave_++;

  addUsable(new Usable("health-potion", 15, 1, usableID_toSave_, 9, this)); // Usable 2
  usableID_toSave_++;
  // ---------------------------------------------------------------------------
  
  
  // Add the enemys to the places
  all_places_[0]->addEnemy(1);
  all_places_[0]->addEnemy(1);
  all_places_[1]->addEnemy(2);
  all_places_[2]->addEnemy(3);
  
  
  // Add Containers to the places
  all_places_[0]->addContainer(1); // 0 - 0
  all_places_[2]->addContainer(2); // 2 - 0
  
  // Add Weapons to Containers
  all_places_[0]->getContainer()[0]->addWeaponByID(1); // 0
  all_places_[2]->getContainer()[0]->addWeaponByID(2); // 0

  // Add Usables to Containers
  all_places_[0]->getContainer()[0]->addUsableByID(1); // 0
  all_places_[2]->getContainer()[0]->addUsableByID(2); // 0

  // Then Display some Introduction to the game

  cout << endl;
  cout << "Welcome to <thegame>!" << endl;
  cout << "Type <help> to view possible actions and commands." << endl << endl;
  cout << "-------------------------------------------------------------------------------" ;
  cout << endl;
  cout << "You wake up in some forest... no memories, no orientation, no idea who you are." << endl;
  cout << "On the ground you find some rude drawn map and an old rusty dagger." << endl;
  cout << "This could be useful..." << endl << endl;


}
// -----------------------------------------------------------------------------