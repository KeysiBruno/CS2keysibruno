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
        Jedi(string="Unknown Jedi ", int=100 ,int =50, int = 75);
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
        void attack();
        int useForce(int);
        int takeDamage(int);

        void saveToFile(string);
        void loadFromFile(string);
    };

    class Sith
    {
       private:
       string name;
       int health;
       int lightsaberSkill;

       public:
       //Constructor
        Sith(string="Unknown Sith", int=120, int=60);
        //Destructor
        ~Sith();
        //setters
          void setSith(string, int, int);
        //getters
        string getName();
        int getHealth();
        int getLigthsaberSkill();
    };
}