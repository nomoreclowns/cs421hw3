#include <iostream>
#include <string>

#include "identClass.h"
#include "realNum.h"
#include "integer.h"

using namespace std;

int main()
{

	identDFA idDFA;
	realNum num;
	integer intNum;
	
	string user = " ";
	int check = -1;
	
	cin >> user;
	
	while(true)
	{
		if((idDFA.ident_token(user)) == true)
		{
			check = 0;
		}
	
		if((num.realNumber(user)) == true)
		{
			check = 1;
		}
		
		if((intNum.integer_token(user)) == true)
		{
			check = 2;
		}
		
		switch(check)
		{
			case 0:
			
				cout << "The string is an identifier..." << endl;
				break;
			
			case 1:
			
				cout << "The string is a real number..." <<endl;
				break;
			
			case 2:
			
				cout << "The string is an integer number..." << endl;
				break;
			
			default:
				cout << "Lexical error: the string is not in my language..." << endl;
				break;
		}
		
		break;
	}
	
	
	
	return 0;
}
