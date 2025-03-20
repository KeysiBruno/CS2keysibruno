#pragma once
#include <iostream>
using namespace std;

namespace starwars
{
    class Character
    {
        private:
        string name;
        int health;
        int attackPower;
        
        public:
        //Constructor
        Character(string, int, int);
        //Destructor
        ~Character();
        //Getters
        string getName();
        int getHealth();
        int getAttackPower();
        //Setters
        void setCharacter(string, int, int);
        virtual void takeDamage(int);
    };

    class Jedi : public Character
    {
        private:
        string name;
        int health;
        int lightsaberSkill;
        int forcePower; 
        
        public:
        //Consrtuctor
        Jedi(string="Unknown Jedi ", int=100 ,int =50, int =75);
        //Destructor
        ~Jedi();
        //Setters
        void setJedi(string, int, int, int);
        //getters
        string getName();
        int getHealth();
        int getLightsaberSkill();
        int getForcePower();

        //Methods
        int attack();
        void useForce(int);
        void takeDamage(int);

        void saveToFile();
        void loadFromFile();
    };



    class Sith : public Character
    {
       private:
       string name;
       int health;
       int lightsaberSkill;
       int forcePower;

       public:
       //Constructor
        Sith(string="Unknown Sith", int=120, int=60, int=75);
        //Destructor
        ~Sith();
        //setters
          void setSith(string, int, int, int);
        //getters
        string getName();
        int getHealth();
        int getLigthsaberSkill();
        int getForcePower();
       //Methods
        int attack();
        void useForce(int);
        void takeDamage(int);
    };
}