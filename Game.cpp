#include "Game.h"
#include <fstream>
#include <string>
using namespace std;


// Postconditions - m_dragons is populated
Game::Game(){ 

  // Intro
  cout << "\nWelcome to Dragon Wars\n";
  cout << "What is your name?\n";
  getline(cin,m_name);

  // Loads in the dragons from the file
  LoadDragons(); 
}

// Postconditions - m_dragons is populated with Dragon objects
void Game::LoadDragons() {

  fstream dragons;

  dragonSize startingSize = small;
  bool defaultHatch = false; // All dragons start out as eggs

  // Values that the object Dragon has
  string name;
  string type;
  string maxSizeTemp;
  string rarityTemp;
  dragonSize size;

  // Open the file
  dragons.open(PROJ2_DRAGONS.c_str());

  // Read in each dragon 
  while(dragons){
    getline(dragons, name,',');
    getline(dragons, type,',');
    getline(dragons, maxSizeTemp,',');
    getline(dragons, rarityTemp);
    
    // Converting strings to ints
    int maxSize = atoi(maxSizeTemp.c_str());
    int rarity = atoi(rarityTemp.c_str());
      
    // What enum to assign to each size dragon
    switch(maxSize){
      case 1:
        size = small;
        break;
      case 2:
        size = medium;
        break;
      case 3:
        size = large;
        break;
      case 4:
        size = huge;
        break;
      case 5:
        size = huge;
        break;
    }

    // Creating the dragon object and adding it to the list of dragons
    Dragon addDragon = Dragon(name, type, defaultHatch, startingSize, size, rarity);
    m_dragons.push_back(addDragon);
  }    
}

// Postconditions - m_myDragons is populated
void Game::SearchEgg(){
  
  // Takes in what rarity the user wants to search for
  int m_rarity;
  cout << "What rarity egg would you like to search for?\n";
  cout << "Enter a rarity (1 = very common and 10 = very rare): ";
  cin >> m_rarity;
  
  // Random number generator 
  srand(time(NULL));
  int searchEgg = rand() % 100 + 1;
    
  // Making a seperate vector of all eggs with user defined rarity
  vector <Dragon> eggs;
  for(unsigned int i = 0; i < m_dragons.size() - 1; i++){
    if(m_dragons[i].GetRarity() == m_rarity){
      eggs.push_back(m_dragons[i]);
    
    }
  }

  // Random number generator for choosing a random egg the user gets
  srand(time(NULL));
  int randEgg = rand() % eggs.size();

  do{
    // What to do if user chooses rarity 1
    if(m_rarity == 1){
      if(searchEgg > 91){
	      cout << "Sorry, you did not find a dragon of that rarity.\n";
      }
      else {
        m_myDragons.push_back(eggs[randEgg]);
        cout << "You found a " << eggs[randEgg].GetName() << " dragon!\n";
      }
    }
    
    // What to do if user chooses rarity 2
    else if(m_rarity == 2){
      if(searchEgg > 82){
        cout << "Sorry, you did not find a dragon of that rarity.\n";
      }
      else{
        m_myDragons.push_back(eggs[randEgg]);
        cout << "You found a " <<eggs[randEgg].GetName()<< " dragon!\n";
      }
    }
    
    // What to do if user chooses rarity 3
    else if(m_rarity == 3){
      if(searchEgg > 73){
	      cout << "Sorry, you did not find a dragon of that rarity.\n";
      }
      else{
        m_myDragons.push_back(eggs[randEgg]);
        cout << "You found a " <<eggs[randEgg].GetName()<< " dragon!\n";
      }
    }
    
    // What to do if user chooses rarity 4
    else if(m_rarity == 4){
      if(searchEgg > 64){
	      cout << "Sorry, you did not find a dragon of that rarity.\n";
      }
      else{
        m_myDragons.push_back(eggs[randEgg]);
        cout << "You found a " <<eggs[randEgg].GetName()<< " dragon!\n";
      }
    }
    
    // What to do if user chooses rarity 5
    else if(m_rarity == 5){
      if(searchEgg > 55){
        cout << "Sorry, you did not find a dragon of that rarity.\n";
      }
      else{
        m_myDragons.push_back(eggs[randEgg]);
        cout << "You found a " <<eggs[randEgg].GetName()<< " dragon!\n";
      }
    }
    
    // What to do if user chooses rarity 6
    else if(m_rarity == 6){
      if(searchEgg > 46){
	      cout << "Sorry, you did not find a dragon of that rarity.\n";
      }
      else{
        m_myDragons.push_back(eggs[randEgg]);
        cout << "You found a " <<eggs[randEgg].GetName()<< " dragon!\n";
      }
    }  
    
    // What to do if user chooses rarity 7
    else if(m_rarity == 7){
      if(searchEgg > 37){
	      cout << "Sorry, you did not find a dragon of that rarity.\n";
      }
      else{
        m_myDragons.push_back(eggs[randEgg]);
        cout << "You found a " <<eggs[randEgg].GetName()<< " dragon!\n";
      }
    }
    
    // What to do if user chooses rarity 8
    else if(m_rarity == 8){
      if(searchEgg > 28){
	      cout << "Sorry, you did not find a dragon of that rarity.\n";
      }
      else{
        m_myDragons.push_back(eggs[randEgg]);
        cout << "You found a " <<eggs[randEgg].GetName()<< " dragon!\n";
      }
    }
    
    // What to do if user chooses rarity 9
    else if(m_rarity == 9){
      if(searchEgg > 19){
	      cout << "Sorry, you did not find a dragon of that rarity.\n";
      }
      else{
        m_myDragons.push_back(eggs[randEgg]);
        cout << "You found a " <<eggs[randEgg].GetName()<< " dragon!\n";
      }
    }
    
    // What to do if user chooses rarity 10
    else if(m_rarity == 10){
      if(searchEgg > 10){
	      cout << "Sorry, you did not find a dragon of that rarity.\n";
      }
      else{
        m_myDragons.push_back(eggs[randEgg]);
        cout << "You found a " <<eggs[randEgg].GetName()<< " dragon!\n";
      }
    }
  } while(m_rarity > 10 || m_rarity < 1); // Input Validation
}

// Postconditions - m_myDragons is populated
void Game::HatchEgg(){

  // What to do if you have no eggs
  if(m_myDragons.size() == 0){
    cout << "You do not have any eggs to hatch!\n";
    return;
  }

  DisplayMyDragons(); 

  // Takes in what dragon the user wants to hatch  
  unsigned int dragon = 0;
  do{
    cout << "Which dragon would you like to try and hatch?\n";
    cin >> dragon;
  } while(dragon > m_myDragons.size() || dragon < 1); // Input Validation

  dragon = dragon - 1; // Adjust for index

  // Number generator to get chance of egg being hatched
  srand(time(NULL));  
  int eggHatch = rand() % 100 + 1;
  
  // Conditions for egg hatching
  if(eggHatch <= 50 || m_myDragons[dragon].GetIsHatched() == true){
    cout << "The dragon did not hatch or is already hatched.\n";
  }else{
    cout << "\nYour " << m_myDragons[dragon].GetName() << " egg hatches into a dragon!\n";
    m_myDragons[dragon].HatchDragon();
  }
}

// Postconditions - Continually checks to see if player has an egg or a dragon
void Game::StartGame(){
  MainMenu();
}

// Postconditions - Displays a numbered list of dragons
void Game::DisplayMyDragons(){

  // If they dont have any dragons
  if(m_myDragons.size() == 0){
    cout << "You do not have any dragons or eggs to display!\n";
    return;
  }
  
  // Header
  cout << m_name << "'s Dragons\n";
  
  // Column Headers for the dragons attributes
  cout << setw(30) << "Name" << setw(10) << "Type" << setw(15) << "Egg/Dragon" << setw(15) << "Current Size" << setw(10) << "Max Size\n";

  // Prints out each dragons and its attributes  
  for(unsigned int i = 0; i < m_myDragons.size(); i++){
    
    // Changes the boolean values of whether the dragon is hatched or not into strings of if its a dragon or egg 
    string dragonStatus;
    if(m_myDragons[i].GetIsHatched()){
      dragonStatus = "dragon";
    }else{dragonStatus = "egg";}

    // Prints out each attribute
    cout << i + 1  << "." << setw(28) << m_myDragons.at(i).GetName();
    cout << setw(10) << m_myDragons.at(i).GetType();
    cout << setw(15) << dragonStatus;
    cout << setw(15) << m_myDragons.at(i).GetCurSize();
    cout << setw(10) << m_myDragons.at(i).GetMaxSize() << endl;
  }
}

// Postconditions - Returns number indicating exit
int Game::MainMenu(){

  int option;

  // Menu Options with input validation
  do{
    cout << "What would you like to do?\n";
    cout << "1. Search for an egg\n";
    cout << "2. Try to hatch egg\n";
    cout << "3. Display all dragons and eggs\n";
    cout << "4. Attack!\n";
    cout << "5. Quit\n";
    cin >> option;
  } while(option < 1 or option > 5); // Input Validation

  // Search Egg 
  if(option == 1){
    cout << "\n";
    SearchEgg();
    cout << "\n";
    MainMenu();
  }
  // Hatch Egg
  else if(option == 2){
    cout << "\n";
    HatchEgg();
    cout << "\n";
    MainMenu();
  }
  // Display your dragons
  else if(option == 3){
    cout << "\n";
    DisplayMyDragons();
    cout << "\n";
    MainMenu();
  }
  // Attack
  else if(option == 4){
    cout << "\n";
    Attack();
    cout << "\n";
    MainMenu();
  }
  
  // Quit the game
  else{cout << "Thank you for playing Dragon Wars!\n";}
  
  return 0;
}

// Postconditions - Player attacks a random dragon of random size
void Game::Attack(){
 
  // Checks to see if you have any dragons to fight with
  int dragons = 0;
  for(unsigned int i = 0; i < m_myDragons.size(); i++){
    if(m_myDragons[i].GetIsHatched() == true){
      dragons += 1;}
  }
      
  if(dragons == 0){
    cout << "You do not have any hatched dragons to fight with!\n";
    return;
  } else{
    
    cout << "Attack!\n";
    
    int opponent = rand() % m_dragons.size() + 1; // Chooses a random dragon for the user to fight
    cout << "You found a " << m_dragons[opponent].GetName() << " to fight!\n";
    
    string fight;
    cout << "Do you want to fight it? (y/n)\n";
    cin >> fight;
   
    // Checks if they want to fight or not
    if(fight == "n"){
      return;
    }
    else{
      unsigned int fighter = 0;
      do{
        // Takes in what dragon the user wants to fight with
        DisplayMyDragons();
        cout << "Which dragon would you like to fight with?\n";
        cin >> fighter;
	
      } while(fighter > m_myDragons.size() || fighter < 1); // Input Validation
      
      // Random number generator for the size of the opponent dragon
      srand(time(NULL));
      int opponentSize = rand() % m_dragons[opponent].GetMaxSize() + 1;
      dragonSize enSize[] = {tiny,small,medium,large,huge};
      dragonSize enemySize;
      enemySize = enSize[opponentSize];
      m_dragons[opponent].SetCurSize(enemySize);
      
      fighter = fighter - 1; // Adjust for index
      
      // Winning or losing outcomes
      if(m_myDragons[fighter].AttackDragon(m_dragons[opponent]) == true){
	      return;
      }
      else{
        m_myDragons.erase(m_myDragons.begin() + (fighter));
      }
    }
  }
}

// Postconditions - m_dragons is displayed (all relevant data from m_dragons)
void Game::DisplayAllDragons(){
  
  cout << m_dragons.size() << endl;
  cout << m_name << "'s Dragons\n";
  for(unsigned int i = 0; i < m_dragons.size(); i++){
    cout << m_dragons.at(i).GetName() << " ";
    cout << m_dragons.at(i).GetType() << " ";
    cout << m_dragons.at(i).GetIsHatched() << " ";
    cout << m_dragons.at(i).GetCurSize() << " ";
    cout << m_dragons.at(i).GetMaxSize() << endl;

  }  
}
 
