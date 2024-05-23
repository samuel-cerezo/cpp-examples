/*
Write a function called accelerate() that takes as input the speed of a vehicle, and an amount. 
The function adds the amount to the speed to accelerate the vehicle. 
The speed parameter should be passed by reference, and amount by value. 
*/

#include<iostream>
using namespace std;

void accelerate(int &speed, int amount){

    speed += amount;

}


int main(){
    int *speed;
    int amount;
    speed = new int;
    
    cout << "Ingrese velocidad: " << endl;
    cin >> *speed;
    cout << "Ingrese aumento: " << endl;
    cin >> amount;
    accelerate(*speed, amount);
    cout << "Speed: " << *speed << ", amount: " << amount << endl;

}