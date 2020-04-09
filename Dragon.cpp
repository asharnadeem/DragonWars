#include <iostream>
#include "Dragon.h"

using namespace std;

// Postconditions - Creates a new dragon
Dragon::Dragon(string name, string type, bool isHatched, dragonSize curSize, dragonSize maxSize, int rarity){

  SetName(name);                                                                        
  SetType(type);
  if(GetIsHatched()){
    m_isHatched = false;
  }
  SetCurSize(curSize);
  SetMaxSize(maxSize);
  SetRarity(rarity);

}

// Postconditions - Returns the name of the dragon
string Dragon::GetName(){
  return m_name;
}

// Postconditions - Sets name of dragon
void Dragon::SetName(string name){
  m_name = name;
}

// Postconditions - Returns the type of the dragon
string Dragon::GetType(){
  return m_type;
}

// Postconditions - Sets type of dragon
void Dragon::SetType(string type){
  m_type = type;
}

// Postconditions - Returns if the dragon has hatched from an egg
bool Dragon::GetIsHatched(){
  return m_isHatched;
}

// Postconditions - If unhatched, changes isHatched to 1
void Dragon::HatchDragon(){
  m_isHatched = true;
}

// Postconditions - Returns current size from 1 - 5
dragonSize Dragon::GetCurSize() {
  return m_curSize;
}

// Postconditions - Sets size of dragon (1-5)
void Dragon::SetCurSize(dragonSize curSize){
  m_curSize = curSize;
}

// Postconditions - Returns maximum size from 1 - 5
dragonSize Dragon::GetMaxSize(){
  return m_maxSize;
}

// Postconditions - Sets maximum size of dragon (1-5)
void Dragon::SetMaxSize(dragonSize maxSize){
  m_maxSize = maxSize; 
}

// Postconditions - Returns rarity of dragon (1-10)
int Dragon::GetRarity(){
  return m_rarity;
}

// Postconditions - Sets rarity of dragon from (1-10)
void Dragon::SetRarity(int rarity){
  m_rarity = rarity;
}

// Postconditions - If possible, curSize increases, if increases, returns true else false
bool Dragon::AttemptGrow(){

  // Checks to see if the dragon has reached its max size
  if(GetCurSize() < GetMaxSize()){
    int grow = GetCurSize() + 1;
    SetCurSize((dragonSize)grow);
    cout << "Your dragon grows a bit larger!\n";
    return true;

  }else{ // What to do if the dragon is alrady at its max size
    cout << "Your dragon cannot grow any larger.\n";
    return false;
  }
  
}

// Postconditions - Returns if dragon lives or dies (true lives, dies false)
bool Dragon::AttackDragon(Dragon& dragon){
  
  // If your dragon used a special attack
  if(BreathAttack() == "Activated"){
    return true;}
  
  // If it did not use a special attack
  else{

    // What happens when your dragon is currently bigger than the enemy dragon
    if(GetCurSize() > dragon.GetCurSize()){
      cout << "Your " << GetName() << " attacks the " << dragon.GetName() << " dragon!\n";
      cout << "Your " << GetName() << " defeats the enemy " << dragon.GetName() << " dragon!\n";
      AttemptGrow();
      return true;
    }
    
    // What happens when your dragon is currently the same size as the enemy dragon
    else if(GetCurSize() == dragon.GetCurSize()){
      cout << "Your " << GetName() << " attacks the " << dragon.GetName() << " dragon!\n";
      cout << "The battle results in a draw\n";
      AttemptGrow();
      return true;
    }

    // What happens when your dragon is currently smaller than the enemy dragon 
    else{
      cout << "You lost the battle!\nYour dragon dies.\n";
      return false;
    }
    
  }
}

// Postconditions -  Automatically kills enemy dragon
string Dragon::BreathAttack() {
  
  // Random number generator to calculate chances of special attack
  srand(time(NULL));
  int breath = rand() % 100 + 1;

  // What to do if your dragon uses its special attack
  if(breath <= 5){
    cout << "Your dragon did a special " << GetType() << " attack!\n";
    cout << "Your " << GetName() << " kills the enemy dragon!\n"; 
    AttemptGrow();
    return "Activated";
  } 
  else{
    return ""; // If dragon does not land special attack
  }
}
