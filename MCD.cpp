// este script computa el MAXIMO COMUN DIVISOR entre dos numeros enteros
// para esto se usa el algoritmo euclideo.

#include <iostream>
using namespace std;

int main() {
//variables declaration
    int a, b, t;

//-------  entering "a" ----
    cout << "Enter the first integer: ";  // prompt the user for input
    cin >> a;
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

      cout << "Enter the first integer: ";  // prompt the user for input
      cin >> a;
    }
    
//-------  entering "b" ----
    cout << "Enter the second integer: ";  // prompt the user for input
    cin >> b;
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

      cout << "Enter the second integer: ";  // prompt the user for input
      cin >> b;
    }

if (a == b){
    cout << "El Maximo Comun Divisor (MCD) es: " << b << endl;
} 
else{

    while(b != 0){
        t = b;
        b = a % b;
        a = t;
    }
    
    cout << "El MCD es: " << a << endl;
}

}