#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace game 
{

    class Item;
    class Player;

    class Item 
    {
    private:
        string name;
        string effect;
        int value;

    public:
        Item(string name = "", string effect = "", int value = 0);

        void use(Player& player);
        string getName();
        string getEffect();
        int getValue();
    };

    class Player 
    {
    private:
        string name;
        int health;
        vector<Item> inventory;

    public:
        Player(string name, int health = 100);

        void attack();
        void takeDamage(int amount);
        void addToInventory(Item& item);
        void useItem(int index);

        int getHealth();
        string getName();
        void displayInventory();
    };

    class Enemy 
    {
    private:
        string name;
        int health;
        int damage;

    public:
        Enemy(string name, int health, int damage);

        void attack();
        void takeDamage(int amount);

        int getDamage()   ;
        int getHealth()   ;
        string getName()   ;
        bool isDefeated()   ;
    };

    class Room 
    {
        private:
            std::string description;
            Enemy* enemy;
            Item* item;
            int roomNumber;
    
        public:
            Room(string desc = "", Enemy* e = nullptr, Item* i = nullptr, int number = 0);
    
            std::string getDescription()   ;
            void setDescription(   std::string& desc);
    
            Enemy* getEnemy()   ;
            void setEnemy(Enemy* e);
    
            Item* getItem()   ;
            void setItem(Item* i);
    
            int getRoomNumber()   ;
            void setRoomNumber(int number);
    
            void clearEnemy();  // after defeated
            void clearItem();   // after picked up
        };
} // namespace game
