
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>
using namespace std;


int main(){


    int my_int=46;  //normal integer variable

    // declare a pointer and make it point to my_variable

    int *my_pointer = &my_int;

    cout << "my_int: "<< my_int << endl;
    *my_pointer = 107;
    cout << "my_pointer: " << *my_pointer << endl;
    cout << "my_int: " << my_int << endl;


}