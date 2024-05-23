#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int ventas_semanales;

void solicitarNroVentas(void){
    cout << "Enter a number of sales: ";  // prompt the user for input
    cin >> ventas_semanales;

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

    cout << "Enter a number of sales: ";  // prompt the user for input
    cin >> ventas_semanales;
    }
}

void metodo1(void){
    //Straight salary of $600 per week;
    int monthSalary;

    monthSalary = 600*4;
    cout << "M1. Month salary: " << monthSalary << endl;
}


void metodo2(void){
// A salary of $7.00 per hour plus a 10% commission on sales;
    int monthSalary;

    monthSalary = 7*8*5*4 + 0.1*225*ventas_semanales;
    cout << "M2. Month salary: " << monthSalary << endl;
}


void metodo3(void){
//No salary, but 20% commissions and $20 for each pair of shoes sold
    int monthSalary;

    monthSalary =  0.2*225*ventas_semanales + 20*ventas_semanales;
    cout << "M3. Month salary: " << monthSalary << endl;
}

int main () {

solicitarNroVentas();
metodo1();
metodo2();
metodo3();


}