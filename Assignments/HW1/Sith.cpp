#include "starwars.h"

using namespace std;

//Constructor
starwars::Sith::Sith(string _name, int _health, int _lightsaberSkill) : name(_name), health(_health), lightsaberSkill(_lightsaberSkill)
{
}
//Destructor
starwars::Sith::~Sith()
{
}
//setters
  void starwars::Sith::setSith(string _name, int _health, int _lightsaberSkill)
  {
    name = _name;
    health = _health;
    lightsaberSkill = _lightsaberSkill;
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
