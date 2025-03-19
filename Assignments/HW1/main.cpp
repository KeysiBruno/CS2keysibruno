#include "starwars.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace starwars;

int main()
{
    string jediName;
    cout << "Enter your Jedi's name: ";
    getline(cin, jediName);
    
    Jedi* j1 = new Jedi(jediName);
    
    j1->saveToFile();
    cout << "Jedi saved successfully.\n";
    
    j1->loadFromFile();
    
    Sith* s1 = new Sith("Messi");
    cout << "\nA Sith Lord approaches! " << s1->getName() << "\n";
    
    while (j1->getHealth()>0 && s1->getHealth()>0)
    {
        cout << "\nYour Jedi attacks!\n";
        s1->takeDamage(j1->attack());
        cout << s1->getName() << " health is: " << s1->getHealth() << "\n";
        
        if (s1->getHealth() <= 0) {
            cout << "You win!!! "<<endl;
            break;
        }
        
        cout << "\n" << s1->getName() << " strikes back!\n";
        j1->takeDamage(s1->attack());
        cout << "Your Jedi's health: " << s1->getHealth() << "\n";
        
        if (j1->getHealth() <= 0) {
            cout << "You loose! "<<endl;
            break;
        }
    }
    
    delete j1;
    delete opponent;
    
    return 0;
}
