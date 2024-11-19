#ifndef CHARACTER_H
#define CHARACTER_H

class Character // Use inheritance and the virtual qualifier when needed
{
    private:
        std::string name;
        int level;
        int health;
        int spiritual;
        int stamina;
        int atk_power;
        int defense;
        int experience;
        //ascii art converter
        // enemy class (yhawaba, hollows)
    public:
        ();
        void print() const;
        ~Computer() { };
};

#endif