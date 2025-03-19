#include "starwars.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace starwars;

int main()
{
    string jediName;
    cout << "Enter Jedi's name: ";
    getline(cin, jediName);
    
    Jedi* j1 = new Jedi(jediName);
    
    j1->saveToFile();
    cout << "DEBUG: Jedi saved successfully.\n";
    
    j1->loadFromFile();
    
    Sith* s1 = new Sith("Keysi");
    cout << "\nThe oponent comes... he is ! " << s1->getName() << "\n";
    
    while (j1->getHealth()>0 && s1->getHealth()>0)
    {
        cout << "\n"<<j1->attack()<<" attacks!\n";
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
    delete s1;
    
    return 0;
}
