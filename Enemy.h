#ifndef ENEMY_H
#define ENEMY_H

#include "Game.h"
#include "Place.h"
#include<string>
using std::string;
 
class Enemy
{
  private:
  string name_;
  string info_;
  int enemyHP_;
  unsigned int enemy_maxHP_;
  unsigned int enemyDMG_;
  unsigned int current_placeID_;
  unsigned int in_place_identifier_;
  unsigned int enemyID_;
  unsigned int gold_;
  unsigned int exp_;
  Game *board_;
  
  
  
  public:
  //Constructor
  Enemy(string ec_name, string ec_info, int ec_hp, unsigned int ec_max_hp, 
  unsigned int ec_dmg, unsigned int ec_enemyid, unsigned int ec_place, 
  unsigned int ec_IDI, unsigned int ec_gold, unsigned int ec_exp, Game *ec_game);
  
  //Getter
  string getName();
  string getInfo();
  int getHP();
  unsigned int getMaxHP();
  unsigned int getDMG();
  unsigned int getPlace();
  unsigned int getID();
  unsigned int getIDI();
  unsigned int getGold();
  unsigned int getEXP();
  
  //Setter
  
  //Adder and Decreaser
  void addHP(unsigned int plusHP);
  void decreaseHP(unsigned int minusHP);
  
  //Other
  bool checkHP();
  void attack();
  void die();
  
};

#endif