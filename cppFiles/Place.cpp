#include "../hFiles/Place.h"
#include <vector>
#include "../hFiles/Enemy.h"
#include "../hFiles/Container.h"

//Constructor ----------------------------------------------------------------------
//
Place::Place(Game *pc_board, string pc_name, unsigned int pc_id, string pc_info, 
unsigned int pc_north, unsigned int pc_south, unsigned int pc_east, unsigned int pc_west)
 {
  name_ = pc_name;
  placeID_ = pc_id;
  info_ = pc_info;
  board_ = pc_board;
  place_to_the_north_ = pc_north;
  place_to_the_south_ = pc_south;
  place_to_the_east_ = pc_east;
  place_to_the_west_ = pc_west;
  current_enemy_IPI_ = 1;
  current_container_IPI_ = 1;
}
 
// ----------------------------------------------------------------------
//Getter ----------------------------------------------------------------------
//
string Place::getName()
{
  return name_;
}

unsigned int Place::getID()
{
  return placeID_;
}

string Place::getInfo()
{
  return info_;
}

unsigned int Place::getNorth()
{
  return place_to_the_north_;
}
unsigned int Place::getSouth()
{
  return place_to_the_south_;
}
unsigned int Place::getEast()
{
  return place_to_the_east_;
}
unsigned int Place::getWest()
{
  return place_to_the_west_;
}
vector<Enemy*> Place::getEnemys()
{
  return all_enemys_;
}
vector<Container*> Place::getContainer()
{
  return all_container_;
}

// ----------------------------------------------------------------------
//Setter ----------------------------------------------------------------------
//

// ----------------------------------------------------------------------

//Adder ------------------------------------------------------------------------
//
// could me much easier with copyconstructor for enemy.. ?
void Place::addEnemy(unsigned int enemy_id) 
{
  vector<Enemy*> all_enemy_types = board_->getAllEnemys();
  Enemy *to_be_copied = all_enemy_types[enemy_id - 1];
  
  string name = to_be_copied->getName();
  string info = to_be_copied->getInfo();
  int hp = to_be_copied->getHP();
  unsigned int maxhp = to_be_copied->getMaxHP();
  unsigned int attack = to_be_copied->getAttack();
  unsigned int diceamount = to_be_copied->getDiceAmount();
  unsigned int dicetype = to_be_copied->getDiceType();
  unsigned int ac = to_be_copied->getAC();
  unsigned int enemyid = to_be_copied->getID();
  unsigned int gold = to_be_copied->getGold();
  unsigned int exp = to_be_copied->getEXP();
  
  Enemy *new_enemy = new Enemy(name, info, hp, maxhp, attack, diceamount, 
    dicetype, ac, enemyid, placeID_, 
  current_enemy_IPI_, gold, exp, board_);

  all_enemys_.push_back(new_enemy);
  
  current_enemy_IPI_++;
}

void Place::addContainer(unsigned int container_id)
{
  // loop through all existing containers in game
  vector<Container*> all_existing_containers = board_->getAllContainers();
  for(unsigned int i = 0; i < all_existing_containers.size();i++)
  {
    if(container_id == all_existing_containers[i]->getContainerID()) // if found
    {
      // make copy
      Container *new_container = all_existing_containers[i]->copy();
      // change several values
      new_container->setPlaceID(placeID_); // maybe a pointer would be better
      new_container->setIPI(current_container_IPI_);
      current_container_IPI_++; // prepare for next container
      // Add the container to the place
      all_container_.push_back(new_container);
    }
  }
}
//------------------------------------------------------------------------------

// Other------------------------------------------------------------------------
//
void Place::deleteEnemybyIDI(unsigned int enemy_idi)
{
  //search for the enemy with the right IDI
  for(unsigned int i = 0; i < all_enemys_.size(); i++)
  {
    // if there is a enemy with given IDI
    if(all_enemys_[i]->getIDI() == enemy_idi)
    {
      // delete it from the vector
      all_enemys_.erase(all_enemys_.begin() + i);
    }
  }
}
// -----------------------------------------------------------------------------
 