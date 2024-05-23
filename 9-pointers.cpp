/*

1. A pointer is a special type of variable that contains a memory address rather than a data value.


int *intptr; // Declare a pointer that holds the address
             // of a memory location that can store an integer.
             // Note the use of * to indicate this is a pointer variable.

intptr = new int; // Allocate memory for the integer.
*intptr = 5; // Store 5 in the memory address stored in intptr.


*/

#include <iostream>
using namespace std;


int main() {

    int* x;
    int* y;  // dos punteros

    x = new int; // x apunta a un entero.
    y = new int; // y apunta a un entero.

    *x = 42; //almacenamos 42 en la direccion donde apunta x
    *y = 13; // almacenamos 13 en la dirección donde apunta y
    y = x; // hacemos que y apunte donde apunta x.
    *y = 13; // esto tmb modificaria el valor a donde apunta x.

    /////////////////

    int my_int = 46; // variable normal
    
    int* my_pointer = &my_int; //mi nuevo puntero apunta en la direccion donde se almacena "my_int"
    cout << "Valor anterior: " << my_int << endl;
    *my_pointer = 107;  //modificamos el valor donde apunta el puntero.
    cout << "Valor luego: " << my_int << endl;
    cout << "Valor luego: " << *my_pointer << endl;

    /////////////
    int *ptr1; //declaramos un puntero a un entero
    ptr1 = new int; //reservamos memoria y apuntamos

    float *ptr2 = new float;

    delete ptr1; //liberamos almacenamiento

    *ptr1 = 50;
    cout << "fin" << endl;


}   



