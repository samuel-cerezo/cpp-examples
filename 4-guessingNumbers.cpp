/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
using namespace std;

/*
You can use cin.good() or cin.fail() to determine whether cin could successfully deal with the input value provided. 
You can then use cin.clear(), if necessary, to clear the error state before continuing processing.
*/


int main ()
{
  int iSecret, userNumber;

  srand (time(NULL));  /* initialize random seed: */
  iSecret = rand() % 10 + 1;  /* generate secret number between 1 and 10: */

// cycle
  do {
      cout << "Guess the number (1 to 10): " << endl;
      cin >> userNumber;
    // error-ckecking here
        while (true)
        {
          if (cin.fail())
          {
            cout << "That was not an integer. Try again." << endl;
            cin.clear();
            cin.ignore();
            
          }
          else break;

          cout << "Guess again (1 to 10):  ";  // prompt the user for input
          cin >> userNumber;
        }
  

    if (iSecret<userNumber) cout << "The secret number is lower" << endl;
    else if (iSecret>userNumber) cout << "The secret number is higher"<< endl;
  } while (iSecret!=userNumber);

  cout << "Congratulations!";
  return 0;
}