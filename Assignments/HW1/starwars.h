#pragma once
#include <iostream>
using namespace std;

namespace starwars
{
    class Jedi
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

    class Sith
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