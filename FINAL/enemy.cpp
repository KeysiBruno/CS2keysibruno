#include "game.h"

using namespace game;

Enemy::Enemy(string name, int health, int damage) : name(name), health(health), damage(damage) 
{}

void Enemy::attack()
{
    cout<<name<<" attacks with: "<<damage<<" damage!"<<endl;
}

void Enemy::takeDamage(int damage)
{
    health = health-damage;
    if(health < 0)
    {
        health = 0;
    } 
    cout<<name<<" takes "<<damage<<" damage."<<endl;
    cout<<"Remaining health: "<<health<<endl;
}

//Getters
int Enemy::getDamage()
{
    return damage;
}

int Enemy::getHealth()
{
    return health;
}

string Enemy::getName()
{
    return name;
}

bool Enemy::is_defeated()
{
    return health <= 0;
}
