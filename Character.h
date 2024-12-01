#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character {
protected:

public:
  string name;
  int level;
  int health;
  int stamina;
  int ATK;
  int defense;
  int experience;
  int stage;

  Character(const string& name, int level, int health, int stamina, int ATK, int defense, int experience, int stage);
  
  virtual void powerup1();
  virtual void powerup2();
  virtual void attack(Character& target);
  void rest();
  void gainExperience(int xp);
  void levelUp();
  void save() const;
  void load();
  virtual string getClassName() const = 0;
  virtual void displayStats() const;
};

class Shinigami : public Character {
public:
  Shinigami(const string& name);
  void powerup1() override;
  void powerup2() override;
  void attack(Character& target) override;
  string getClassName() const override {
    return "Shinigami";
  }
};

class Quincy : public Character {
public:
  Quincy(const string& name);
  void powerup1() override;
  void powerup2() override;
  void attack(Character& target) override;
  string getClassName() const override {
    return "Quincy";
  }
};

class Hollow : public Character {
public:
  Hollow(const string& name);
  void powerup1() override;
  void powerup2() override;
  void attack(Character& target) override;
  string getClassName() const override {
    return "Hollow";
  }
};

class Enemy : public Character {
public:
  Enemy(const string& name, int health, int attack, int defense);

  string getClassName() const override;

  void attack(Character& target) override;

  void displayStats() const override;

  bool isDefeated() const;
};

void fight(Character& player, Enemy& enemy);
void chooseClass(Character*& player);
void loadPlayer(Character*& player);

#endif
