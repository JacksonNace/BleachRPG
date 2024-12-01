#include "Character.h"
#include <iostream>
#include <fstream>

using namespace std;

Character::Character(const string& name, int level, int health, int stamina, int ATK, int defense, int experience, int stage)
  : name(name), level(level), health(health), stamina(stamina), ATK(ATK), defense(defense), experience(experience), stage(stage) {}

void Character::powerup1() {
  cout << name << " used Powerup 1. Stamina increased by 10.\n";
  stamina += 10;
}

void Character::powerup2() {
  cout << name << " used Powerup 2. ATK increased by 5.\n";
  ATK += 5;
}

void Character::attack(Character& target) {
  int damage = ATK - target.defense;
  if (damage < 0) damage = 0;
  target.health -= damage;
  cout << name << " attacked " << target.name << " dealing " << damage << " damage.\n";
}

void Character::rest() {
  stamina += 10;
  health += 10;
  cout << name << " rested. Health and stamina restored by 10 points.\n";
}

void Character::gainExperience(int xp) {
  experience += xp;
  cout << name << " gained " << xp << " experience points.\n";
  levelUp();
}

void Character::levelUp() {
  while (experience >= 100) {
    experience -= 100;
    level++;
    health += 20;
    stamina += 10;
    ATK += 5;
    defense += 3;
    cout << name << " leveled up! Now at level " << level << ".\n";
  }
}

void Character::save() const {
  ofstream outFile(name + "_character.txt");
  if (outFile.is_open()) {
    outFile << getClassName() << '\n'
            << level << ' ' << health << ' ' << stamina << ' ' << ATK << ' '
            << defense << ' ' << experience << ' ' << stage << '\n';
    outFile.close();
    cout << "Character saved successfully.\n";
  } else {
    cout << "Error saving character.\n";
  }
}

void Character::load() {
  ifstream inFile(name + "_character.txt");
  if (inFile.is_open()) {
    string classType;
    inFile >> classType;

    if (classType != getClassName()) {
      cout << "Invalid character class in file.\n";
      inFile.close();
      return;
    }

    inFile >> level >> health >> stamina >> ATK >> defense >> experience >> stage;
    inFile.close();
    cout << "Character loaded successfully.\n";
  } else {
    cout << "Error loading character.\n";
  }
}

void Character::displayStats() const {
  cout << "\n\nName: " << name << "\nLevel: " << level << "\nHealth: " << health
       << "\nStamina: " << stamina << "\nAttack: " << ATK
       << "\nDefense: " << defense << "\nExperience: " << experience
       << "\nStage: " << stage << "\n";
}

Shinigami::Shinigami(const string& name)
  : Character(name,  1, 100, 50, 20, 10, 0, 1) {}

void Shinigami::powerup1() {
  cout << name << " unleashes Shikai!\n";
  stamina -= 10;
  ATK += 5;
}

void Shinigami::powerup2() {
  cout << name << " uses Bankai!\n";
  stamina -= 20;
  ATK += 10;
}

void Shinigami::attack(Character& target) {
  int damage = ATK * 2 - target.defense;
  if (damage < 0) damage = 0;
  target.health -= damage;
  cout << name << " (Shinigami) unleashed a powerful attack on " << target.name << ", dealing " << damage << " damage.\n";
}

Quincy::Quincy(const string& name)
  : Character(name, 1, 80, 60, 25, 8, 0, 1) {}

void Quincy::powerup1() {
  cout << name << " uses Letzt Stil\n";
  stamina -= 10;
  ATK += 5;
}

void Quincy::powerup2() {
  cout << name << " unleashes Vollstandig!\n";
  stamina -= 20;
  ATK += 10;
}

void Quincy::attack(Character& target) {
  int damage = ATK - target.defense;
  if (stamina > 10) {
    damage += 10;
    stamina -= 10;
  }
  if (damage < 0) damage = 0;
  target.health -= damage;
  cout << name << " (Quincy) fired an arrow at " << target.name << ", dealing " << damage << " damage.\n";
}

Hollow::Hollow(const string& name)
  : Character(name, 1, 120, 40, 30, 12, 0, 1) {}

void Hollow::powerup1() {
  cout << name << " uses Visor!\n";
  stamina -= 10;
  ATK += 5;
}
void Hollow::powerup2() {
  cout << name << " uses Ressurrecion!\n";
  stamina -= 20;
  health += 10;
}

void Hollow::attack(Character& target) {
  int damage = ATK - target.defense / 2;
  if (damage < 0) damage = 0;
  target.health -= damage;
  cout << name << " (Hollow) attacked viciously, dealing " << damage << " damage to " << target.name << ".\n";
}

Enemy::Enemy(const string& name, int health, int attack, int defense)
  : Character(name, 1, health, 0, attack, defense, 0, 0) {}

string Enemy::getClassName() const {
  return "Enemy";
}

void Enemy::attack(Character& target) {
  int damage = ATK - target.defense;
  if (damage < 0) damage = 0;
  target.health -= damage;
  cout << name << " attacked " << target.name << " dealing " << damage << " damage.\n";
}

void Enemy::displayStats() const {
  cout << "Enemy: " << name << "\nHealth: " << health
       << "\nAttack: " << ATK << "\nDefense: " << defense << "\n";
}

bool Enemy::isDefeated() const {
  return health <= 0;
}

void fight(Character& player, Enemy& enemy) {
  cout << "Battle starts between " << player.name << " and " << enemy.name << "!\n";

  while (player.health > 0 && !enemy.isDefeated()) {
    cout << "\nIt's your turn! Choose an action:\n";
    cout << "1. Normal Attack\n";
    cout << "2. Power-Up 1\n";
    cout << "3. Power-Up 2\n";
    cout << "Enter your choice: ";
    
    int choice;
    cin >> choice;

    switch (choice) {
      case 1:
        player.attack(enemy);
        break;
      case 2:
        player.powerup1();
        break;
      case 3:
        player.powerup2();
        break;
      default:
        cout << "Invalid choice. You lose your turn!\n";
        break;
    }

    if (!enemy.isDefeated()) {
      cout << "\n" << enemy.name << " attacks " << player.name << "!\n";
      enemy.attack(player);
    }
  }

  if (player.health > 0) {
    cout << player.name << " defeated " << enemy.name << "!\n";
    player.gainExperience(50);
  } else {
    cout << player.name << " was defeated by " << enemy.name << ".\n";
  }
}
