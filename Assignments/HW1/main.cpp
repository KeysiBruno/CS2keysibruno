#include "starwars.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
using namespace starwars;

int main()
{
    string jediName;
    cout << "Enter your Jedi's name: ";
    getline(cin, jediName);
    
    Jedi* playerJedi = new Jedi(jediName);
    
    playerJedi->saveToFile();
    cout << "Jedi saved successfully.\n";
    
    Jedi* loadedJedi = new Jedi();
    loadedJedi->loadFromFile();
    
    Sith* opponent = new Sith("Messi");
    cout << "\nA Sith Lord approaches! " << opponent->getName() << "\n";
    
    while (playerJedi->getHealth()>0 && opponent->getHealth()>0)
    {
        cout << "\nYour Jedi attacks!\n";
        opponent->takeDamage(playerJedi->attack());
        cout << opponent->getName() << " health is: " << opponent->getHealth() << "\n";
        
        if (opponent->getHealth() <= 0) {
            cout << "You win!!! " << opponent->getName() << "!\n";
            break;
        }
        
        cout << "\n" << opponent->getName() << " strikes back!\n";
        playerJedi->takeDamage(opponent->attack());
        cout << "Your Jedi's health: " << playerJedi->getHealth() << "\n";
        
        if (playerJedi->getHealth() <= 0) {
            cout << "You loose! " << opponent->getName() << "!\n";
            break;
        }
    }
    
    delete playerJedi;
    delete loadedJedi;
    delete opponent;
    
    return 0;
}
