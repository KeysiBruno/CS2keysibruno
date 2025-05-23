#pragma once
#include <iostream>
using namespace std;

namespace starwars
{
    class Character
    {
        protected:
        string name;
        int health;
        int forcePower;
        
        public:
        //Constructor
        Character(string = "Normal person", int=10, int=10);
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
        protected:
        int lightsaberSkill;
        
        public:
        //Consrtuctor
        Jedi(string="Unknown Jedi ", int=100 ,int =50, int =75);
        //Setters
        void setJedi(string, int, int, int);
        //getters
        string getName();
        int getHealth();
        int getLightsaberSkill();
        int getForcePower();

        //Methods
        virtual int attack();
        virtual void useForce(int);
        virtual void takeDamage(int);

        void saveToFile();
        void loadFromFile();
    };

         class Guardian : public Jedi
         {
            public:
            //Consrtuctor
            Guardian(string _name, int _health=150 ,int _lightsaberSkill=70, int _forcePower=90) : Jedi(_name, _health, _lightsaberSkill, _forcePower)
            {}           
            //Methods
            int attack(){return Jedi::getLightsaberSkill();}
            void useForce(int power){Jedi::useForce(power);}
            void takeDamage(int damage){Jedi::takeDamage(damage);}

         };
         class Consular : public Jedi
         {
            public:
            //Consrtuctor
            Consular(string _name, int _health=100 ,int _lightsaberSkill=50, int _forcePower=120) : Jedi(_name, _health, _lightsaberSkill, _forcePower)
            {}

            //Methods
            int attack(){return Jedi::getLightsaberSkill();}
            void useForce(int power){Jedi::useForce(power);}
            void takeDamage(int damage){Jedi::takeDamage(damage);}
         };

    class Sith : public Character
    {
       protected:
       int lightsaberSkill;

       public:
       //Constructor
        Sith(string="Unknown Sith", int=120, int=60, int=75);

          void setSith(string, int, int, int);
        //getters
        string getName();
        int getHealth();
        int getLigthsaberSkill();
        int getForcePower();
        //Methods
        virtual int attack();
        virtual void useForce(int);
        virtual void takeDamage(int);
    };
         class Acolyte : public Sith
         {
            public:
            //Consrtuctor
            Acolyte(string _name, int _health=80 ,int _lightsaberSkill=60, int _forcePower=40) : Sith(_name, _health, _lightsaberSkill, _forcePower)
            {}           
            //Methods
            int attack(){return Sith::getLigthsaberSkill();}
            void useForce(int power){Sith::useForce(power);}
            void takeDamage(int damage){Sith::takeDamage(damage);}
         };
         class Darth : public Sith
         {
            public:
            //Consrtuctor
            Darth(string _name, int _health=200 ,int _lightsaberSkill=90, int _forcePower=100) : Sith(_name, _health, _lightsaberSkill, _forcePower)
            {}           
            //Methods
            int attack(){return Sith::getLigthsaberSkill();}
            void useForce(int power){Sith::useForce(power);}
            void takeDamage(int damage){Sith::takeDamage(damage);}
         };

}