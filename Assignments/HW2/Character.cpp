#include "starwars.h"

 //Constructor
 starwars::Character::Character(string _name, int _health, int _forcePower)
 {
    name = _name;
    health = _health;
    forcePower = _forcePower;
 }
 //Getters
 string starwars::Character::getName()
 {
     return name;
 }
 int starwars::Character::getHealth()
 {
    return health;
 }
 int starwars::Character::getAttackPower()
 {
     return forcePower;
 }
 //Methods
 void starwars::Character::takeDamage(int damage)
 {
    health = health - damage;
 }

