/*
Example 7: Next steps with decomposition - Your first day on the job
You have just gotten a position as a salesperson for the ExerShoe company, 
specializing in high-end exercise shoes costing around $225 per pair. 
Your boss has given you three options for compensation, which you must choose before you begin your first day:

1) Straight salary of $600 per week;
2) A salary of $7.00 per hour plus a 10% commission on sales;
3) No salary, but 20% commissions and $20 for each pair of shoes sold
*/

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
using namespace std;

int salaryPerWeek, salaryPerHour;

int weeklySalary(){
    int userNumber;
    cout << "Enter the numer of weekly sales: " << endl;
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

          cout << "Enter the numer of weekly sales: ";  // prompt the user for input
          cin >> userNumber;
        }

return userNumber;
}

int Method1(){
    return (salaryPerWeek*4);
}

int Method2(int NumberOfSales){
    return (salaryPerHour*8*5*4 + 0.1*225*NumberOfSales);
}

int Method3(int NumberOfSales){
    return (0.2*225*NumberOfSales + 20*NumberOfSales);
}



int main(){

int val1,val2,val3, sales;

salaryPerHour = 7;
salaryPerWeek = 600;

sales = weeklySalary();
val1 = Method1();
val2 = Method2(sales);
val3 = Method3(sales);

cout << "With the Method1 the monthly salary is: " << val1 << endl;
cout << "With the Method2 the monthly salary is: " << val2 << endl;
cout << "With the Method3 the monthly salary is: " << val3 << endl;



}