#include "Character.h"
#include <iostream>
using namespace std;







int main() {
  Character* playerCharacter = nullptr;
  int choice;
  string name;
  cout << "Bleach RPG Turn-Based Battle Game\n";
  cout << "1. Create New Character\n";
  cout << "2. Load Previous Character\n";
  cout << "3. Exit\n";
  cout << "Enter your choice: ";
  cin >> choice;

  switch (choice) {
      case 1: 
        cout << "Welcome to the character creation menu!\n";
        cout << "Pick your character class and one of the three storymodes.\n";
        cout << "1. Shinigami | The Missing Soul King!\n";
        cout << "2. Quincy | The Quincies Revenge!";
        cout << "3. Hollow | The Hollow Uprising";
        cin >> choice;
        switch (choice){
          case 1:
            playerCharacter = new Shinigami(name);
            cout << "Shinigami character created successfully.\n";
            break;
          case 2:
            playerCharacter = new Quincy(name);
            cout << "Quincy character created successfully.\n";
            break;
          case 3:
            playerCharacter = new Hollow(name);
            cout << "Hollow character created successfully.\n";            
            break;
          default:
            cout << "Invalid choice. \nQuitting.";
            break;
        }
      case 2: // take in previous character data and load position in game
        // load data
        break;
      case 3:
          cout << "Are you sure you want to exit? (Y/N): ";
          // Exit
          break;
      default:
          cout << "Invalid selection. Please try again.\n";
          break;
  }
  // The character should be loaded by now


//fight function for enemy class?


  // switch statement to tell which level a player is at and start them there?

  return 0;
}
