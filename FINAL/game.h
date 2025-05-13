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
        Item(string name="", string effect ="", int value=0);

        void use(Player& player);
        //Getters
        string getName();
        string getEffect();
        int getValue();
    };

    class Player 
    {
    private:
        string name;
        int health;
        int forcePower;
        vector<Item> inventory;

    public:
        Player(string name="", int health=0, int forcePower=0);

        void attack();
        void takeDamage(int amount);
        void addToInventory(Item item);
        void useItem(int num_items);

        int getHealth();
        string getName();
        int getFocePower();
        void displayInventory();

        Player* operator+(int);
    };

    class Enemy 
    {
    private:
        string name;
        int health;
        int damage;

    public:
        Enemy(string name="", int health=0, int damage=0);

        void attack();
        void takeDamage(int amount);

        int getDamage();
        int getHealth();
        string getName();
        bool is_defeated();
    };

    class Room 
    {
        private:
            string description;
            Enemy *enemy;
            Item *item;
            int roomNumber;
    
        public:
            Room(string d1="", Enemy *e=nullptr, Item *i=nullptr, int number=0);
    
            string getDescription();
            void setDescription(string d1);
    
            Enemy *getEnemy();
            void setEnemy(Enemy* e);
    
            Item *getItem();
            void setItem(Item *i);
    
            int getRoomNumber()   ;
            void setRoomNumber(int number);
    
            void clearEnemy();
            void clearItem();
        };
} 
