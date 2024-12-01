#include "Character.h"
#include <iostream>
#include <fstream>
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
    case 1: {
      cout << "Welcome to the character creation menu!\n";
      cout << "Enter your character's name: ";
      cin.ignore();
      getline(cin, name);
      cout << "Pick your character class. (1,2, or 3)\n";
      cout << "1. Shinigami\n";
      cout << "2. Quincy\n";
      cout << "3. Hollow\n";
      cout << "Enter your choice: ";
      cin >> choice;

      switch (choice) {
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
          cout << "Invalid choice. Exiting character creation.\n";
          return -1;
      }
      break;
    }
    case 2: {
      cout << "Enter the name of your saved character: ";
      cin.ignore();
      getline(cin, name);
      ifstream inFile(name + "_character.txt");
      if (inFile.is_open()) {
        int level, health, stamina, attack, defense, experience, stage;
        string classType;
        inFile >> classType >> level >> health >> stamina >> attack >> defense >> experience >> stage;

        if (classType == "Shinigami") {
          playerCharacter = new Shinigami(name);
        } else if (classType == "Quincy") {
          playerCharacter = new Quincy(name);
        } else if (classType == "Hollow") {
          playerCharacter = new Hollow(name);
        } else {
          cout << "Invalid character class in file.\n";
          return -1;
        }
        playerCharacter->load();
      } else {
        cout << "No saved character found.\n";
        return -1;
      }
      break;
    }
    case 3:
      cout << "Are you sure you want to exit? (Y/N): ";
      char confirm;
      cin >> confirm;
      if (toupper(confirm) == 'Y') {
        cout << "Goodbye!\n";
        return 0;
      }
      break;
    default:
      cout << "Invalid selection. Please try again.\n";
      return -1;
  }

  if (!playerCharacter) {
    cout << "No character loaded or created. Exiting.\n";
    return -1;
  }

  while (true) {
    cout << "\n=== Main Menu ===\n";
    cout << "1. Display Stats\n";
    cout << "2. Rest\n";
    cout << "3. Fight Enemy\n";
    cout << "4. Save and Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (cin.fail()) {
      cout << "Invalid input. Please try inputting an integer 1-4.\n";
      cin.clear();
      break;
    }

    switch (choice) {
      case 1:
        playerCharacter->displayStats();
        break;
      case 2:
        playerCharacter->rest();
        break;
      case 3: {
        cout << "Choose an enemy to fight:\n";
        cout << "1. Angry Hollow | Tutorial level.\n";
        cout << "2. Aizen | Reccomended level 3+.\n";
        cout << "3. Yhwach | Reccomended level 5+\n";
        cout << "Enter your choice: ";
        int enemyChoice;
        cin >> enemyChoice;

        Enemy* enemy = nullptr;
        switch (enemyChoice) {
          case 1:
            enemy = new Enemy("Angry Hollow", 50, 15, 5);
            break;
          case 2:
            enemy = new Enemy("Aizen", 100, 25, 10);
            break;
          case 3:
            enemy = new Enemy("Yhwach", 150, 30, 15);
            break;
          default:
            cout << "Invalid enemy choice.\n";
            continue;
        }

        if (enemy) {
          fight(*playerCharacter, *enemy);
          delete enemy;
        }
        break;
      }
      case 4:
        playerCharacter->save();
        cout << "Game saved successfully. Goodbye!\n";
        delete playerCharacter;
        return 0;
      default:
        cout << "Invalid choice. Try again.\n";
        break;
    }
  }
}
