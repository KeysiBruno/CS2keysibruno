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

void RoomInfo(Room& room) 
{
    cout << "Room "<<room.getRoomNumber()<<": "<<room.getDescription()<<endl;

    if (room.getEnemy()) 
    {
        cout<<"An enemy appears: "<<room.getEnemy()->getName()<<" (HP: "<<room.getEnemy()->getHealth()<<")"<< endl;
    }

    if (room.getItem()) 
    {
        cout << "You see an item: "<<room.getItem()->getName()<<" (" << room.getItem()->getEffect()<<")" << endl;
    }
}

void combat(Player& player, Enemy& enemy) 
{
    while (enemy.getHealth() > 0 && player.getHealth() > 0) 
    {
        cout<<"What will you do? (1: Attack, 2: Flee): ";
        int choice;
        cin >> choice;

        if (choice == 1) 
        {
            enemy.takeDamage(10);  // player attack (simple fixed damage for now)
            cout << "You attack "<<enemy.getName()<<" for 10 damage!"<< endl;

            if (enemy.isDefeated()) 
            {
                cout<<"You defeated "<<enemy.getName()<<"!"<<endl;
                break;
            }

            player.takeDamage(enemy.getDamage());  // enemy attacks
            cout << enemy.getName() << " attacks you for " << enemy.getDamage() << " damage!" << endl;

        } 
        else if (choice == 2) 
        {
            cout<<"You flee from the battle!"<<endl;
            break;
        }
        else 
        {
            cout<<"Invalid choice!"<<endl;
        }
    }

    if (player.getHealth() <= 0) 
    {
        cout<<"You were defeated!"<<endl;
    }
}

void gameLoop(Player& player, List<Room>& dungeon) {
    Node<Room> *current = dungeon.getHead();  // use public getter

    while (current != nullptr && player.getHealth() > 0) {
        Room room = current->getData();

        RoomInfo(room);

        if (room.getEnemy() != nullptr) {
            combat(player, *room.getEnemy());
            if (player.getHealth() <= 0) break;
        }

        if (room.getItem() != nullptr) {
            cout << "Do you want to take the item? (y/n): ";
            char takeItem;
            cin >> takeItem;

            if (takeItem == 'y' || takeItem == 'Y') {
                player.addToInventory(*room.getItem());
                room.clearItem();
            }
        }

        cout << "Do you want to move to the next room? (y/n): ";
        char moveChoice;
        cin >> moveChoice;

        if (moveChoice == 'y' || moveChoice == 'Y') {
            current = current->getNext();
        } else {
            break;
        }
    }

    if (player.getHealth() > 0) {
        cout << "🎉 Congratulations! You completed the dungeon!" << endl;
    } else {
        cout << "☠️ Game Over! You were defeated." << endl;
    }
}


int main() {
    // Create player
    Player player("Hero");

    // Create items
    Item* potion = new Item("Health Potion", "heal", 20);
    Item* sword = new Item("Iron Sword", "boost", 10);

    // Create enemies
    Enemy* goblin = new Enemy("Goblin", 30, 5);
    Enemy* orc = new Enemy("Orc", 50, 10);

    // Create rooms
    Room room1("You enter a damp, cold cave. Something stirs...", goblin, nullptr, 1);
    Room room2("An eerie silence fills this torch-lit hallway.", nullptr, potion, 2);
    Room room3("The sound of metal echoes. A beast awaits!", orc, sword, 3);
    Room room4("A golden door stands before you. The treasure is near...", nullptr, nullptr, 4);

    // Add rooms to dungeon
    List<Room> dungeon;
    dungeon.push_back(room1);
    dungeon.push_back(room2);
    dungeon.push_back(room3);
    dungeon.push_back(room4);

    // Run the game loop
    gameLoop(player, dungeon);

    // Cleanup
    delete goblin;
    delete orc;
    delete potion;
    delete sword;

    return 0;
}
