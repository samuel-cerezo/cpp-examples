
#include <iostream>
using namespace std;

int main() {

  //variables declaration
  int rand_numb, x;

  // random number generation 
  srand (time(NULL)); // inicia la semilla
  rand_numb = rand() %10+1 ;         // v1 in the range 1 to 10

  // guessing the number
  while(true){
    cout << "Guessing the random number..." << endl;  // prompt the user for input
    cout << "Enter your guess: ";
    cin >> x;

      // error-ckecing here
    while (true)
    {
      if (cin.fail())
      {
        cout << "That was not an integer. Try again." << endl;
        cin.clear();
        cin.ignore();
        
      }
      else break;

      cout << "Enter an integer: ";  // prompt the user for input
      cin >> x;
    }

    if (x > rand_numb){
      cout << "Calm down bro, the number is lower..." << endl;
    }
    else if(x<rand_numb){
      cout << "Rise up, put more energy on that engine..." << endl;
    }
    else if (x == rand_numb){
      cout << "Succeed!!!!" << endl;
      break;
    }



  }


  
  cout << "Has ingresado un entero!!" << endl;
  cout << rand_numb << endl;
  cout << "usted ingresó el numero: " << x << endl;

  return 0;
  
} 