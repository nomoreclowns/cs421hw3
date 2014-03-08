#include <string>
using namespace std;
#include "indentClass.h"

int main()
{
    return 0;
}
// IDENT DFA
//Author: Alejandro Sosa
//uses a for loop to iterate over an string
//
bool indentDFA::ident_token(string s)
{
    unsigned int size= s.size();
    int state = 0;

    for(unsigned int index = 0; index < size; index++)
    {
        switch(state)
        {
            case 0:
                state = q0(s[index]);
            case 1:
                state = q1(s[index]);
            default:
                return false;
        }

    }

    if(state == 1)
    {
        return true;
    }
    return false;
}


int indentDFA::q0(char input)
{
    switch(input)
    {
    case 'a':
    case 'b':
        return 1;
    default:
        return -1;
    }
}

int indentDFA::q1(char input)
{
    switch(input)
    {
    case 'a':
    case 'b':
    case '2':
    case '3':
    case '_':
        return 1;
    default:
        return -1;
    }
}
