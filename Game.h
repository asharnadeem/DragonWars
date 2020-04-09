#ifndef GAME_H //Header Guard
#define GAME_H //Header Guard

#include "Dragon.h"
#include <fstream>
#include <string>
const string PROJ2_DRAGONS = "dragons.txt"; //File constant

class Game{
public:
  Game(); //Default Constructor
  void LoadDragons();
  void SearchEgg();
  void HatchEgg();
  void StartGame();
  void DisplayMyDragons();
  int MainMenu();
  void Attack();
  void DisplayAllDragons();
private:
  vector <Dragon> m_dragons; // All dragons in game
  vector <Dragon> m_myDragons; // Player's dragons
  int m_countHatchedDragons; // Current number of hatched dragons the player has (for attack)
  string m_name; // Player's name
};

#endif //Exit Header Guard
