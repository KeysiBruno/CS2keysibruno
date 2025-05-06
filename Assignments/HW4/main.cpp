#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"
#include <cassert>

using namespace std;

void tests();
int evaluateRPN(string);

int main(int argc, char *argv[])
{
    if (argc == 3 && string(argv[1]) == "-p") {
        string input = argv[2];
        int result = evaluateRPN(input);
        cout << "Result: " << result << endl;
    } else {
        tests();
    }
  return 0;
}

int evaluateRPN(string expression)
{
    int a, b, result;
    Stack s1;
   //evaluate if its a digit
   //evaluate if its an operator
   //evaluate if its a useful expression
   for(char c : expression)
   {
    if(isdigit(c))
     {
        int num = c - '0';
        s1.push(num);
     }

     else if(c=='+' || c=='-' || c=='*' || c=='/')
     {
        if(s1.size() < 2)
        {
            cout<<"There are no numbers to make an operation. "<<endl;
            return NAN;
        }
        a =  s1.top();
        s1.pop();
        b = s1.top();
        s1.pop();

        if(c=='+')
        {
           // cout<<"DEBUG: b is: "<<b<<"  and a is: "<<a<<endl;
            result = b + a;
        }
        else if(c=='-')
        {
            //cout<<"DEBUG: b is: "<<b<<"  and a is: "<<a<<endl;
            result = b - a;
        }
        else if(c=='*')
        {
            //cout<<"DEBUG: b is: "<<b<<"  and a is: "<<a<<endl;
            result = b * a;
        }
        else if(c=='/')
        {
            //cout<<"DEBUG: b is: "<<b<<"  and a is: "<<a<<endl;
            if(a == 0) return NAN;
            result = b / a;
        }
        s1.push(result);  
      }
      else
      {
        cout<<"Invalid expression. "<<endl;
        return NAN;
      }
   }
   return result;
}
void tests()
{
    assert(evaluateRPN("23+") == 5);       // 2 + 3 = 5
    assert(evaluateRPN("234-+") == 1);     // 3 - 4 = -1, 2 + (-1) = 1
    assert(evaluateRPN("23-4+") == 3);     // 2 - 3 = -1, -1 + 4 = 3
    assert(evaluateRPN("23*4+") == 10);    // 2 * 3 = 6, 6 + 4 = 10
    assert(evaluateRPN("92/") == 4);       // 9 / 2 = 4 
    assert(evaluateRPN("52/3+") == 5);     // 5 / 2 = 2, 2 + 3 = 5
    assert(evaluateRPN("34+56-*") == -7);  // (3 + 4) * (5 - 6) = 7 * -1 = -7

    cout<<"All tests passed. "<<endl;
}