#include "Enemy.h"
#include <iostream>
#include<string>
#include "Game.h"
#include "Place.h"

using std::string;
using std::cout;
using std::endl;

Enemy::Enemy(string ec_name, string ec_info, int ec_hp, unsigned int ec_max_hp, 
unsigned int ec_dmg, unsigned int ec_enemyid, unsigned int ec_place, 
unsigned int ec_IDI, unsigned int ec_gold, unsigned int ec_exp, Game *ec_game)
{
  name_ = ec_name;
  info_ = ec_info;
  enemyHP_ = ec_hp;
  enemy_maxHP_ = ec_max_hp;
  enemyDMG_ = ec_dmg;
  current_placeID_ = ec_place;
  board_ = ec_game;
  enemyID_ = ec_enemyid;
  in_place_identifier_ = ec_IDI;
  gold_ = ec_gold;
  exp_ = ec_exp;
}

// Getter ----------------------------------------------------------------------
//
string Enemy::getName()
{
  return name_;
}

string Enemy::getInfo()
{
  return info_;
}

int Enemy::getHP()
{
  return enemyHP_;
}

unsigned int Enemy::getMaxHP()
{
  return enemy_maxHP_;
}

unsigned int Enemy::getDMG()
{
  return enemyDMG_;
}

unsigned int Enemy::getPlace()
{
  return current_placeID_;
}
unsigned int Enemy::getID()
{
  return enemyID_;
}
unsigned int Enemy::getIDI()
{
  return in_place_identifier_;
}

unsigned int Enemy::getGold()
{
  return gold_;
}

unsigned int Enemy::getEXP()
{
  return exp_;
}
// -----------------------------------------------------------------------------

//Adder and Decreaser --------------------------------------------------------
//
void Enemy::addHP(unsigned int plusHP)
{
  enemyHP_ += plusHP;
  if(enemyHP_ > (int)enemy_maxHP_)
  {
    enemyHP_ = enemy_maxHP_;
  }
}
void Enemy::decreaseHP(unsigned int minusHP)
{
  enemyHP_ -= minusHP;
  if(enemyHP_ < 0)
  {
    enemyHP_ = 0;
  }
}
//------------------------------------------------------------------------


//Other ------------------------------------------------------------------------
//
bool Enemy::checkHP()
{
  if(enemyHP_ <= 0)
  {
    return false;
  }
  
    return true;
}
void Enemy::attack()
{
  // maybe some calculations .. armor.. weopen .. evasion.. 
  if( !(board_->dead()) )
  {
    cout << name_ << " (" << in_place_identifier_ << ") attacks you and deals " << enemyDMG_ << " damage!" << endl;
    board_->decreaseHP(enemyDMG_);
  }
}

void Enemy::die()
{
  Place *current_place = board_->getAllPlaces()[current_placeID_ - 1];
  current_place->deleteEnemybyIDI(in_place_identifier_);
  
  delete this;
}
//------------------------------------------------------------------------