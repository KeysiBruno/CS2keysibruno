#include "starwars.h"
#include <fstream>

using namespace std;

 //Consrtuctor
 starwars::Jedi::Jedi(string _name, int _health,int _lightsaberSkill, int _forcePower) : name(_name), health(_health), lightsaberSkill(_lightsaberSkill), forcePower(_forcePower) 
 {
 }
 //Destructor
 starwars::Jedi::~Jedi()
 {
 }
 //Setters
 void starwars::Jedi::setJedi(string _name, int _health, int _lightsaberSkill, int _forcePower)
 {
    name = _name;
    health = _health;
    lightsaberSkill = _lightsaberSkill;
    forcePower = _forcePower;
 }
 //getters
 string starwars::Jedi::getName()
 {
     return name;
 }
 int starwars::Jedi::getHealth()
 {
      return health;
 }  
 int starwars::Jedi::getLightsaberSkill()
 {
      return lightsaberSkill;
 }
 int starwars::Jedi::getForcePower()
 {
      return forcePower;
 }

 //Methods
 void starwars::Jedi::attack()
 {
     cout<<name<<" has "<<lightsaberSkill<<" of light saber skill. "<<endl;
 }
 int starwars::Jedi::useForce(int power)
 {
     return forcePower-power;
 }
 int starwars::Jedi::takeDamage(int damage)
 {
     return health-damage;

 }
 void starwars::Jedi::saveToFile(string filename)
 {
     ofstream file;

     file.open(filename.c_str(), ios::out);
     if(file.fail())
     {
        cout<<"File was not open. "<<endl;
        exit(1);
     }
     file<<name<<health<<lightsaberSkill<<forcePower;
 }

 void starwars::Jedi::loadFromFile(string filename)
 {
     ifstream file;
     string text;
     
     file.open(filename, ios::in);

     if(file.fail())
     {
        cout<<"File was not open. "<<endl;
        exit(1);
     }

     while(!file.eof())
     {
       getline(file, text);
     }
 }