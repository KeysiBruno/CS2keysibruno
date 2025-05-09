#include "game.h"

using namespace game;

Enemy::Enemy(string name, int health, int damage) : name(name), health(health), damage(damage) 
{}

void Enemy::attack()
{
    cout << name << " attacks for " << damage << " damage!" << endl;
}

void Enemy::takeDamage(int amount)
{
    health -= amount;
    if (health < 0) health = 0;
    cout << name << " takes " << amount << " damage. Remaining health: " << health << endl;
}

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

bool Enemy::isDefeated()
{
    return health <= 0;
}
