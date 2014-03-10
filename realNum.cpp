#include "realNum.h"

using namespace std;

realNum::realNum()
{
	user = " ";
}

bool realNum::realNumber(const string &user)
{
	unsigned int position = 0;
	unsigned int state = 0;
	unsigned int dotCount = 0; //there can only be one... HIGHLANDER!!!
	unsigned int counter = 0;
	
	/*this checks to make sure the string does not end with 
	 * with just a '.'.
	 * */
	
	if(user[user.size()-1] == '.')
	{
		return (false);
	}
	
	/*this checks to see if there are more than one '.' in the string
	 * after the first check. if there is more than one then
	 * the string is an error. 
	 * */

	for(counter = 0; counter < user.size()-1; counter++)
	{
		if((user[counter]) == '.')
		{
			dotCount++;
		}
		
		if(dotCount > 1)
		{
			cout << "too many '.'\n";
			return (false);
		}
	}
	
	while((user[position]) != '\0')
	{
		
			/*if the state is zero and the character in the string is a '.'
			* than jump to the next state. otherwise as long as it is either
			* 2 or 3 i will keep cycling through the first state...
			*/
				 
			if( (state == 0) && (user[position] == '.') ) 
			{
				
				/*if the current string is a '.', the dotCount is increased
				 * and will be used to the string for any additional '.'
				 * if there are additional 
				 * */
				 
				//dotCount++;
				position++;			
				state++;
			}
			else
			{
				
				/*if the state is 1, the string is checked to see if it has 
				* the digits of either 2 or 3 
				* */
			
				if( (state == 1) && (checkTheNumber(user[position])) )
				{
					state++;
					position++;
				}
				else
				{
					
					/*if the current character in the string is not a '.'
				 * then it checks to see if the character is a number 
				 * either 2 or 3. if true the next character of the string
				 * will go through the same process of being checked. if it
				 * is false then the whole string is an error
				 * 
				 * the state will still remain the same until the scanner
				 * finds a '.' in the string
				 * */
				 
					if(checkTheNumber(user[position]) == true)
					{
						position++;
					}
					else
					{
						cout << "number must be 2 or 3" << endl;
						return (false);
					}
					
				}
				
			}//end of else	
			
	}//end of while

	/*if the entire string manages to get checked all the way through
	 * then that indicates the string is valid...
	 * */

	return (true);
	
}//end of realNumber

bool realNum::checkTheNumber(const char &userChar)
{
	
	
	/*this takes a character from the what realNumber has passed
	 * in and checks to see if the character is either a 2 or a 3.
	 * if the character is either a 2 or a 3 then the function returns 
	 * true back to realNumber. if the character does not match either 2 or 3
	 * then a false is passed back to realNumber
	 * */
	 
	if(userChar >= '2' && userChar <= '3')
	{
		return (true);
	}
	else
	{
		return (false);
	}
	
}//end of checkTheNumber

