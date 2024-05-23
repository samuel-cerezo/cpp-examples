#include<iostream>
using namespace std;

void DoIT(int &foo, int goo){
    foo = goo + 3; //13
    goo = foo + 4;  // 17
    foo = goo + 3;  // 20
    goo = foo;  
}

int main(){
    int *foo;
    int *goo; //dos punteros

    foo = new int;
    goo = new int;

    *foo=1;
    *goo = 3;
    *foo = *goo + 3;
    foo = goo;  // foo y goo apuntan a la misma direccion de goo, donde esta el 3 almacenado.
    *goo = 5;   // ahora ambos apuntan al 5
    *foo = *goo + *foo;  // ahora ambos apuntan a 10.
    DoIT(*foo, *goo);
    cout << "*foo = " << (*foo) << endl;


}