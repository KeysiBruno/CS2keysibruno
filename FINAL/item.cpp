#include "game.h"

using namespace game;

Item::Item(string name, const string effect, int value) : name(name), effect(effect), value(value) 
{}

void Item::use(Player &player)
{
    if(effect=="heal") 
    {
        cout <<"Using "<<name<<": Healing "<<value<<" HP."<< endl;
        player.takeDamage(-value);
    } 
    else if(effect=="boost") 
    {
        cout <<"Using "<<name<<": Boosting attack."<< endl;
        player + value;
    } 
    else 
    {
        cout<<"Item "<<name<<" has no recognizable effect."<<endl;
    }
}

string Item::getName()
{
    return name;
}

string Item::getEffect()
{
    return effect;
}

int Item::getValue()
{
    return value;
}
