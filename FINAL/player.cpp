#include "game.h"

using namespace game; 

Player::Player(string name, int health, int forcePower) : name(name), health(health), forcePower(forcePower)
{}

void Player::attack() 
{
    cout<<name<<" attacks..."<<endl;
}

void Player::takeDamage(int damage) 
{
    health = health-damage;
    if(health < 0)
    {
        health = 0;
    }

    cout<<name<<" takes "<<damage<<" damage."<<endl;
    cout<<"Remaining health: "<<health<<endl;
}

void Player::addToInventory(Item &item) 
{
    inventory.push_back(item);
    cout <<item.getName()<<" added to inventory."<< endl;
}

void Player::useItem(int num_items) 
{
    if(num_items>=0 && num_items<inventory.size()) 
    {
        inventory[num_items].use(*this);
        inventory.erase(inventory.begin() + num_items);
    } 
    else 
    {
        cout << "Invalid item index!" << endl;
    }
}

int Player::getHealth()
{
    return health;
}

string Player::getName()
{
    return name;
}

int Player::getFocePower()
{
    return forcePower;
}

void Player::displayInventory()
{
    cout << name << "'s Inventory:" << endl;
    for (int i = 0; i < inventory.size(); ++i)
    {
        cout<<i<<": "<<inventory[i].getName()<<" ("<<inventory[i].getEffect()<<")"<<endl;
    }
}

Player* Player::operator+(int value)
{
    this->forcePower=this->forcePower + value;
    return this;
}