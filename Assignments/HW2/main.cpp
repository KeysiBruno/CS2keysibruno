#include "starwars.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
using namespace starwars;

int option;
void Jedichose(string);
void RandomSith(Sith *);

int main()
{
    string jediName;
    cout << "Enter Jedi's name: ";
    getline(cin, jediName);
    
    Jedi* j1 = new Jedi(jediName);
    
    j1->saveToFile();
    cout << "DEBUG: Jedi saved successfully.\n";
    
    cout<<"Enter your Jedy type : "
    <<endl<<"1. Guardian. "<<endl<<"2. Consular. \n"<<"Option: ";
    cin>>option;
    Jedichose(jediName);

    j1->loadFromFile();
    
    Sith *random;
    RandomSith(random);
    cout<<"Here comes Sith, and attacks ..."<<endl;

    while (j1->getHealth()>0 && random->getHealth()>0)
    {
        cout << "\n"<<j1->attack()<<" attacks!\n";
        random->takeDamage(j1->attack());
        cout << random->getName() << " health is: " << random->getHealth() << "\n";
        
        if (random->getHealth() <= 0) {
            cout << "You win!!!"<<endl;
            break;
        }
        
        cout << "\n" << random->getName() << " strikes back!\n";
        j1->takeDamage(random->attack());
        cout << "Your Jedi's health: " << random->getHealth() << "\n";
        
        if (j1->getHealth() <= 0) {
            cout << "You loose! "<<endl;
            break;
        }
    }
    
    delete j1;
    delete s1;
    
    return 0;
}

void Jedichose(string name)
{
   if(option==1)
   {
       Guardian *g1 = new Guardian(name);

   }
   else if(option == 2)
   {
      Consular *c1 = new Consular(name);
   }
   else{
    cout<<"You entered a wrong number. "<<endl;
   }  
}

void RandomSith(Sith *random)
{
    int num = rand()%2;
    if (num==0)
    {
        Acolyte *a1 = new Acolyte("Keysi");
        random = a1;
    }
    if (num==1)
    {
        Darth *d1 = new Darth("Keysi");
        random = d1;
    }
}