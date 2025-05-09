#include "game.h"

using namespace std;
using namespace game; 

Room::Room(string desc, Enemy* e, Item* i, int number) : description(desc), enemy(e), item(i), roomNumber(number) 
{}

string Room::getDescription()
{
    return description;
}

void Room::setDescription(string &desc) 
{
    description = desc;
}

Enemy* Room::getEnemy()
{
    return enemy;
}

void Room::setEnemy(Enemy *e) 
{
    enemy = e;
}

Item* Room::getItem()
{
    return item;
}

void Room::setItem(Item* i) 
{
    item = i;
}

int Room::getRoomNumber()
{
    return roomNumber;
}

void Room::setRoomNumber(int number) 
{
    roomNumber = number;
}

void Room::clearEnemy() 
{
    enemy = nullptr;
}

void Room::clearItem() 
{
    item = nullptr;
}