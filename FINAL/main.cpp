#include <iostream>
#include "game.h"
#include "player.cpp"
#include "enemy.cpp"
#include "item.cpp"
#include "room.cpp"
#include "node.h"
#include "list.h"

using namespace std;
using namespace game;

void room_information(Room &);
void combat(Player &, Enemy &);
void game_play(Player &, List<Room> &);

int main(int argc, char *argv[])
{
    Player player("Cristiano", 100, 10);

    Item *potion = new Item("Potion to recover health...", "heal", 50);
    Item *gun = new Item("A gun", "boost", 30);

    Enemy *ToxicTaco = new Enemy("ToxicTaco", 30, 5);
    Enemy *Caike = new Enemy("Caike", 50, 10);
    Enemy *final_boss = new Enemy("Final boss", 150, 20);

    Room room1("You enter a damp, cold cave. Something stirs...", ToxicTaco, nullptr, 1);
    Room room2("An weird silence fills, this is Caike wainting for killing you, but ", nullptr, potion, 2);
    Room room3("The sound of metal echoes. A beast awaits!", Caike, nullptr, 3);
    Room room4("you found a chest with something inside...", nullptr, gun, 4);
    Room room5("The final boss found you, it's time to fight...", final_boss, nullptr, 5);
    Room room6("A golden door stands before you. The treasure is near...", nullptr, nullptr, 6);

    List<Room> dungeon;
    dungeon.push_back(room1);
    dungeon.push_back(room2);
    dungeon.push_back(room3);
    dungeon.push_back(room4);
    dungeon.push_back(room5);
    dungeon.push_back(room6);

    game_play(player, dungeon);

    delete ToxicTaco;
    delete Caike;
    delete final_boss;
    delete potion;
    delete gun;

    return 0;
}

void room_information(Room &room) 
{
    cout << "Room "<<room.getRoomNumber()<<": "<<room.getDescription()<<endl;
    cout<<"\n";

    if(room.getEnemy()) 
    {
        cout<<"An enemy appears: "<<room.getEnemy()->getName()<<" (Health: "<<room.getEnemy()->getHealth()<<")"<< endl;
    }

    if(room.getItem()) 
    {
        cout<<"You see an item: "<<room.getItem()->getName()<<" (" << room.getItem()->getEffect()<<")" << endl;
    }
}

void combat(Player &player, Enemy &enemy) 
{
    while (enemy.getHealth() > 0 && player.getHealth() > 0) 
    {
        cout<<"What will you do? (Press 1 to attack): ";
        int choice;
        cin >> choice;

        if(choice == 1) 
        {
            enemy.takeDamage(player.getFocePower());
            cout << "You attack "<<enemy.getName()<<" for "<<player.getFocePower()<<" damage!"<< endl;

            if (enemy.is_defeated()) 
            {
                cout<<"You defeated "<<enemy.getName()<<"!"<<endl;
                break;
            }

            player.takeDamage(enemy.getDamage());
            cout << enemy.getName()<<" attacks you for "<< enemy.getDamage()<<" damage!"<< endl;

        } 
        else 
        {
            cout<<"Invalid choice."<<endl;
        }
    }

    if(player.getHealth()<= 0) 
    {
        cout<<"You were defeated :("<<endl;
    }
}

void game_play(Player &player, List<Room> &dungeon) 
{
    Node<Room> *current = dungeon.getHead();

    while(current!=nullptr && player.getHealth()>0) 
    {
        Room room = current->getData();

        room_information(room);

        if(room.getEnemy() != nullptr) 
        {
            combat(player, *room.getEnemy());
            if(player.getHealth() <= 0) break;
        }

        if(room.getItem() != nullptr) 
        {
            cout << "Do you want to take the item? (y/n): ";
            char takeItem;
            cin >> takeItem;

            if(takeItem=='y' || takeItem=='Y') 
            {
                player.addToInventory(*room.getItem());
                Item i2 = *room.getItem();
                i2.use(player);
                room.clearItem();
            }
        }

        cout << "Do you want to move to the next room? (y/n): ";
        char moveChoice;
        cin >> moveChoice;

        if(moveChoice=='y' || moveChoice=='Y') 
        {
            current = current->getNext();
        } 
        else
        {
            cout<<"I knew it, you're COWARD";
            break;
        }
    }

    if(player.getHealth() > 0) 
    {
        cout << "You completed the dungeon! WIN" << endl;
    } 
    else 
    {
        cout << "Game Over! You were defeated." << endl;
    }
}