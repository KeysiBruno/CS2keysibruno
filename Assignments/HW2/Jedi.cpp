#include "starwars.h"
#include <iostream>
#include <fstream>

using namespace std;

 //Consrtuctor
 starwars::Jedi::Jedi(string _name, int _health,int _lightsaberSkill, int _forcePower) : Character(_name, _health, _forcePower)
 {
    lightsaberSkill=_lightsaberSkill;
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
 int starwars::Jedi::attack()
 {
     return lightsaberSkill;
 }
 void starwars::Jedi::useForce(int power)
 {
     forcePower=forcePower-power;
 }
 void starwars::Jedi::takeDamage(int damage)
 {
     health=health-damage;

 }
 void starwars::Jedi::saveToFile()
 {
     ofstream file;

     file.open("savedFile.txt", ios::out);
     if(file.fail())
     {
        cout<<"File was not open. "<<endl;
        exit(1);
     }
     file<<name<<"\n"
     <<health<<"\n"
     <<lightsaberSkill<<"\n"
     <<forcePower<<"\n";

     file.close();
 }

 void starwars::Jedi::loadFromFile()
 {
     ifstream file;
     file.open("savedFile.txt", ios::in);
 
     if(file.fail())
     {
         cout<<"File was not opened. "<<endl;
         exit(1);
     }
 
     string line;
 
     getline(file, name);
     file >> health >> lightsaberSkill >> forcePower;
 
     cout<<"name: "<<name<<endl;
     cout<<"Health: "<<health<<endl;
     cout<<"Lightsaber skill: "<<lightsaberSkill<<endl;
     cout<<"Force power: "<<forcePower<<endl;
 
     file.close();
 }
 