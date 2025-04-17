#include "starwars.h"

using namespace std;

//Constructor
starwars::Sith::Sith(string _name, int _health, int _lightsaberSkill, int _forcePower) : Character(_name, _health, _forcePower)
{
    lightsaberSkill=_lightsaberSkill;
}
//setters
  void starwars::Sith::setSith(string _name, int _health, int _lightsaberSkill, int _forcePower)
  {
    name = _name;
    health = _health;
    lightsaberSkill = _lightsaberSkill;
    forcePower = _forcePower;
    
  }
//getters
string starwars::Sith::getName()
{
    return name;
}
int starwars::Sith::getHealth()
{
   return health;
}
int starwars::Sith::getLigthsaberSkill()
{
    return lightsaberSkill;
}
int starwars::Sith::getForcePower()
{
    return forcePower;
}

//Methods
int starwars::Sith::attack()
{
     return lightsaberSkill;
}
 void starwars::Sith::takeDamage(int damage)
{
     health=health-damage;
}
void starwars::Sith::useForce(int power)
{
    forcePower=forcePower-power;
}
