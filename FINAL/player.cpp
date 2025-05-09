#include "game.h"

using namespace game; 

Player::Player(string name, int health) : name(name), health(health) 
{}

void Player::attack() 
{
    cout << name << " attacks!" << endl;
}

void Player::takeDamage(int amount) 
{
    health -= amount;
    if (health < 0) health = 0;
    cout << name << " takes " << amount << " damage. Remaining health: " << health << endl;
}

void Player::addToInventory(Item& item) 
{
    inventory.push_back(item);
    cout << item.getName() << " added to inventory." << endl;
}

void Player::useItem(int index) 
{
    if (index >= 0 && index < inventory.size()) {
        inventory[index].use(*this);
        inventory.erase(inventory.begin() + index);
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

void Player::displayInventory()
{
    cout << name << "'s Inventory:" << endl;
    for (int i = 0; i < inventory.size(); ++i)
    {
        cout << i << ": " << inventory[i].getName() << " (" << inventory[i].getEffect() << ")" << endl;
    }
}
