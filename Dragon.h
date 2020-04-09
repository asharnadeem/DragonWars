#ifndef DRAGON_H //Include/Header Guard
#define DRAGON_H //Include/Header Guard

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
using namespace std;

enum dragonSize { tiny, small, medium, large, huge};

class Dragon{
 
 public:
  Dragon(string name, string type, bool isHatched, dragonSize curSize, dragonSize maxSize, int rarity);
  string GetName();
  void SetName(string name);
  string GetType();
  void SetType(string Type);
  bool GetIsHatched();
  void HatchDragon();
  dragonSize GetCurSize();
  void SetCurSize(dragonSize curSize);
  dragonSize GetMaxSize();
  void SetMaxSize(dragonSize maxSize);
  int GetRarity();
  void SetRarity(int rarity);
  bool AttemptGrow();
  bool AttackDragon(Dragon&);
  string BreathAttack();

 private:
  string m_name;
  string m_type;
  bool m_isHatched;
  dragonSize m_curSize;
  dragonSize m_maxSize;
  int m_rarity;
};

#endif //Exit Header Guard
