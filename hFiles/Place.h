#ifndef PLACE_H
#define PLACE_H

#include "Game.h"
#include<string>
#include<vector>
class Enemy;
class Container;

using std::string;

class Place
{
  private:
  string name_;
  unsigned int placeID_;
  unsigned int place_to_the_north_;
  unsigned int place_to_the_south_;
  unsigned int place_to_the_east_;
  unsigned int place_to_the_west_;
  unsigned int current_enemy_IPI_;
  unsigned int current_container_IPI_;
  string info_;
  Game *board_;
  vector<Enemy*> all_enemys_;
  vector<Container*> all_container_;
  
  
  public:
  //Constructors
  Place(Game *pc_board, string pc_name, unsigned int pc_id, string pc_info, 
unsigned int pc_north, unsigned int pc_south, unsigned int pc_east, unsigned int pc_west);
  
  //Getter
  string getName();
  unsigned int getID();
  string getInfo();
  unsigned int getNorth();
  unsigned int getSouth();
  unsigned int getEast();
  unsigned int getWest();
  vector<Enemy*> getEnemys();
  vector<Container*> getContainer();
  
  //Adder
  void addEnemy(unsigned int enemy_id);
  void addContainer(unsigned int container_id);
  
  //Other
  void deleteEnemybyIDI(unsigned int enemy_idi);
  
};

#endif