#include "Character.h"
#include <iostream>
#include <fstream> // used for file saving and loading
//    Character(const string& name, int level, int health, int stamina, int attack, int defense, int experience); // constructor

//void attack(); 
//void rest();                     
//void save() const;               
//void load(); 

// constructor definition
Character::Character()

void Character::rest(){}
void Character::save() const {

}
void Character::load() const {
}

//shinigami
Shinigami::Shinigami(const string& name) : Character(name, level, health, stamina, attack, defense, experience){}

//void shikai();   
//void bankai();   
//void flashStep();


//quincy 
//    Quincy(const string& name);

//void letztStil();
//void vollstandig(); 
//void holyArrow(); 

//hollow
//Hollow(const string& name);

//void visor();           
//void resserreccion(); 
//void laCero();          