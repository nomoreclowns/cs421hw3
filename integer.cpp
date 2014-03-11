#include "integer.h"

using namespace std;

integer::integer()
{
		intNum = " "; 
}

bool integer::integer_token(const string &s)
{

  int state = 0;
  int charpos = 0;

  while (s[charpos] != '\0')
    {
      cout << "current state: " << state << endl;
      cout << "character: " << s[charpos] << endl;
    
        if (state == 0 && ((s[charpos] == '2')||(s[charpos] == '3')))
          state = 1;
        else
          if (state == 1 && ( (s[charpos] == '2')||(s[charpos] == '3')||(s[charpos] == '\0') ) )
            state = 1;
          else
            {
              //cout << "I am stuck in state " << state << endl;
              return(false);
            }
      charpos++;
    }//end of while

  if (state == 1) return(true);  // end in a final state
  else return(false);
}

/*
int main()
{
	string user = " ";
	cin >> user;
	
	if((integer_token(user)) == true)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}
*/
