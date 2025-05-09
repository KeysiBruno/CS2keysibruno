#include "game.h"

using namespace std;
using namespace game; 

Room::Room(string d1, Enemy *e1, Item *i1, int number) : description(d1), enemy(e1), item(i1), roomNumber(number) 
{}

//Getters
string Room::getDescription()
{
    return description;
}

void Room::setDescription(string d1) 
{
    description = d1;
}

Enemy* Room::getEnemy()
{
    return enemy;
}

void Room::setEnemy(Enemy *e1) 
{
    enemy = e1;
}

Item* Room::getItem()
{
    return item;
}

int Room::getRoomNumber()
{
    return roomNumber;
}

void Room::setItem(Item *i1) 
{
    item = i1;
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