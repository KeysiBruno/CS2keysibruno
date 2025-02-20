#include "starwars.h"

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