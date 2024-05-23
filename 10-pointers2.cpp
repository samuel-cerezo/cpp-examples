#include <iostream>
using namespace std;

// & --> "dirección de"

void Duplicate1(int& a, int& b, int& c){ //pasamos las direcciones, no es que pasamos el valor. 
                                        // si pasaramos el valor, no podriamos modificar el valor de la variable (porque se copiaria el valor nomas)
                                        // se denomina paso por referencia.
    a *= 2;
    b *= 2;
    c *= 2;

}

void Duplicate2(int *a, int *b, int *c){    // es lo mismo pero como se hacia en C antes.
    // en este caso a, b y c son punteros.
    *a *= 2;
    *b *= 2;
    *c *= 2; 
}

int main(){
    int x=1;
    int y=3;
    int z=7;

    cout << "x: " << x << " y: " << y << " z: " << z << endl;

    Duplicate1(x,y,z);

    cout << "Variables duplicadas:" << endl;
    cout << "x: " << x << " y: " << y << " z: " << z << endl;

    Duplicate2(&x,&y,&z);   // como usamos punteros, les paso direcciones, no variables

    cout << "Variables duplicadas:" << endl;
    cout << "x: " << x << " y: " << y << " z: " << z << endl;


}