#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

enum StoryMode {
    SOULKING_MISSING,
    QUINCY_REVENGE, 
    HOLLOW_UPRISING
};

class Character {
protected:
    string name;
    int level;
    int health;
    int stamina;
    int attack;
    int defense;
    int experience;
    StoryMode storymode;

public:
    Character(const string& name, int level, int health, int stamina, int attack, int defense, int experience, StoryMode storymode);

    void attack(Character& opponent); 
    void defend(int damage);
    void rest();                     
    void save() const;               
    void load();                     

    virtual void displayStats() const; 
    virtual ~Character() = default;   
};


class Shinigami : public Character {
public:
    Shinigami(const string& name);

    void shikai();   
    void bankai();   
    void flashStep();
};

class Quincy : public Character {
public:
    Quincy(const string& name);

    void letztStil();
    void vollstandig(); 
    void holyArrow(); 
};

class Hollow : public Character {
public:
    Hollow(const string& name);

    void visor();           
    void hollowification(); 
    void laCero();          
    void bite();       
};

#endif
