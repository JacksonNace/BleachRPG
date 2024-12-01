#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character {
protected:
    string name;
    int level;
    int health;
    int stamina;
    int attack;
    int defense;
    int experience;

public:
    Character(const string& name, int level, int health, int stamina, int attack, int defense, int experience); // constructor

    virtual void powerup1();
    virtual void powerup2();
    virtual void attack();  // virtual allows these to be overridden
    void rest();                     
    void save() const;               
    void load() const;                     

    virtual void displayStats() const; 
    virtual ~Character() = default;    // destructor?
};


class Shinigami : public Character {
public:
    Shinigami(const string& name); // constructor

    void powerup1() override;   //shikai
    void powerup2() override;   //bankai
    void attack() override; // flash step attack
};

class Quincy : public Character {
public:
    Quincy(const string& name);

    void powerup1() override; // LetztStil
    void powerup2() override; // vollstandig
    void attack() override; // holy arrow
};

class Hollow : public Character {
public:
    Hollow(const string& name);
    void powerup1() override; // Ressurricion
    void powerup2() override; // visor       
    void attack() override; //la cero       
};


//fight function? may make the main.cpp code easier to read.
// wait until hp drops, tell player to rest or force rest if stamina dips below amount required, 
// force list dependent on class like 1. attack 2. cero 3. rest 4. bankai etc until one of the characters in the battle's hp reaches 0

#endif
