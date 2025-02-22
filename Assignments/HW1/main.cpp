#include <iostream>
#include "starwars.h"

using namespace std;
using namespace starwars;

int main()
{
    string Jname;
    cout<<"Enter Jedi name: ";
    getline(cin, Jname);
                     //nombre,health,LSS, forcePower 
    Jedi *j1 = new Jedi(Jname, 100, 50, 75);
    Sith *s1 = new Sith("Sith", 120, 60);

    j1->saveToFile();
    j1->loadFromFile();

    cout<<"        FIGHT: ";
    cout<<"/n Both are attaking each other... ";
    
    while(j1->getHealth()>0 && s1->getHealth() >0)
    {
    }



    delete j1;
    delete s1;

    return 0;
}