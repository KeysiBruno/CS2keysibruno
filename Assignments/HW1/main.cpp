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
    Sith *s1 = new Sith("Sith", 120, 60, 50);

    j1->saveToFile();
    j1->loadFromFile();

    cout<<"        FIGHT: ";
    cout<<"\n Both are attaking each other... ";
    
    while(j1->getHealth()>0 && s1->getHealth() >0)
    {
        s1->takeDamage(j1->attack());
        j1->takeDamage(s1->attack());
    }
    if(j1->getHealth() > 0)
    {
        cout<<"\n"<<Jname<<" won!. "<<endl;
    }
    else
    {
        cout<<"\n"<<s1->getName()<<" won!. "<<endl;
    }

    delete j1;
    delete s1;

    return 0;
}