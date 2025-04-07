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
        int forcePower;
        
        public:
        //Constructor
        Character(string = "Normal person", int=10, int=10);
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
        virtual int attack();
        virtual void useForce(int);
        virtual void takeDamage(int);

        void saveToFile();
        void loadFromFile();
    };

         class Guardian : public Jedi
         {
            private:
            string name;
            int health;
            int lightsaberSkill;
            int forcePower; 
            
            public:
            //Consrtuctor
            Guardian(string _name, int _health=150 ,int _lightsaberSkill=70, int _forcePower) : Jedi(name, forcePower)
            {
               health = _health;
               lightsaberSkill = _lightsaberSkill;
            }           
            //Destructor
            ~Guardian(){}
            //getters
            int getHealth(){return health;}
            int getLightsaberSkill(){return lightsaberSkill;}

            //Methods
            int attack(){return lightsaberSkill;}
            void useForce(int power){forcePower = forcePower-power;}
            void takeDamage(int damage){health = health-damage;}

         };
         class Consular : public Jedi
         {
           private:
            string name;
            int health;
            int lightsaberSkill;
            int forcePower; 
            
            public:
            //Consrtuctor
            Consular(string _name, int _health=100 ,int _lightsaberSkill, int _forcePower=120) : Jedi(name, lightsaberSkill)
            {
               health = _health;
               forcePower = _forcePower;
            }           
            //Destructor
            ~Consular(){}
            //getters
            int getHealth(){return health;}
            int getforcePower(){return forcePower;}

            //Methods
            int attack(){return lightsaberSkill;}
            void useForce(int power){forcePower = forcePower-power;}
            void takeDamage(int damage){health = health-damage;}
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
        virtual int attack();
        virtual void useForce(int);
        virtual void takeDamage(int);
    };
         class Acolyte : public Sith
         {
            private:
            string name;
            int health;
            int lightsaberSkill;
            int forcePower; 
            
            public:
            //Consrtuctor
            Acolyte(string _name, int _health=80 ,int _lightsaberSkill, int _forcePower=40) : Sith(name, lightsaberSkill)
            {
               health = _health;
               forcePower = _forcePower;
            }           
            //Destructor
            ~Acolyte(){}
            //getters
            int getHealth(){return health;}
            int getForcePower(){return forcePower;}

            //Methods
            int attack(){return lightsaberSkill;}
            void useForce(int power){forcePower = forcePower-power;}
            void takeDamage(int damage){health = health-damage;}
         };
         class Darth : public Sith
         {
           private:
            string name;
            int health;
            int lightsaberSkill;
            int forcePower; 
            
            public:
            //Consrtuctor
            Darth(string _name, int _health=200 ,int _lightsaberSkill, int _forcePower=100) : Sith(name, lightsaberSkill)
            {
               health = _health;
               forcePower = _forcePower;
            }           
            //Destructor
            ~Darth(){}
            //getters
            int getHealth(){return health;}
            int getForcePower(){return forcePower;}

            //Methods
            int attack(){return lightsaberSkill;}
            void useForce(int power){forcePower = forcePower-power;}
            void takeDamage(int damage){health = health-damage;}
         };

}