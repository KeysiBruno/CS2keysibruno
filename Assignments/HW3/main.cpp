#include "starwars.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
using namespace starwars;

int option;
void Jedichose(Jedi*& jedi, string name);
void RandomSith(Sith*& random);

int main()
{
    string jediName;
    cout << "Enter Jedi's name: ";
    getline(cin, jediName);
    
    Jedi *j1 = new Jedi(jediName);
    
    cout<<"Enter your Jedy type : "
    <<endl<<"1. Guardian. "<<endl<<"2. Consular. \n"<<"Option: ";
    cin>>option;
    Jedichose(j1, jediName);
   
    cout<<*j1;
    
    Sith *random = nullptr;
    RandomSith(random);
    cout<<"Here comes Sith, and attacks ..."<<endl;

    char option;
    cout<<"Do you want to add your Jedi health?(y/n): ";
    cin>>option;
    if(option=='y')
    {
        int addhealth;
        cout<<"Enter additional health: ";
        cin>>addhealth;
        j1 = j1 + addhealth;
    }
    else
    {
        return;
    }
    //helping jedi 
    random = random-5;

    while (j1>0 && random>0)
    {
        cout << "\nYou attack!\n";
        random=random-j1->attack();
        cout << random->getName() << " health is: " << random->getHealth() << "\n";
        
        if (random <= 0) {
            cout << "You win!!!"<<endl;
            break;
        }
        
        cout << "\n" << random->getName() << " strikes back!\n";
        j1=j1-random->attack();
        cout << "Your Jedi's health: " << j1->getHealth() << "\n";
        
        if (j1 <= 0) {
            cout << "You loose! "<<endl;
            break;
        }
    }
    
    delete j1;
    delete random;
    
    return 0;
}

void Jedichose(Jedi*& jedi, string name)
{
   if(option==1)
   {
    delete jedi;
    jedi = new Guardian(name);

   }
   else if(option == 2)
   {
    delete jedi;
    jedi = new Consular(name);
   }
   else{
    cout<<"You entered a wrong number. "<<endl;
   }  
}

void RandomSith(Sith*& random)
{
    random = nullptr;
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