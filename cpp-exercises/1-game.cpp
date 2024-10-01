
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>
using namespace std;
int fireDistance, relatDistance,objectPosition, killed=0;
int Gravity, Velocity,shots, time_in_air;
bool hitted = false;
double angleRadians, in_angle;

int Fire(){
/* Its 1D movement. 
   Tiro de cañon: se lanza a un cierto angulo, siempre a una velocidad constante.*/
  Velocity = 200.0; // initial velocity of 200 ft/sec
  Gravity = 32.2; // gravity for distance calculation
  hitted = false;

  do{
    cout << "What angle? ";
    cin >> angleRadians;
    shots += shots;

    in_angle = (angleRadians * 3.14) / 180.0;

    // in_angle is the angle the player has entered, converted to radians.
    time_in_air = (2.0 * Velocity * sin(in_angle)) / Gravity;
    fireDistance = round((Velocity * cos(in_angle)) * time_in_air);
    relatDistance = objectPosition - fireDistance;

    if (relatDistance < 0){
      cout << "You under shot by " << abs(relatDistance) << endl;
    }else if (relatDistance > 0){
      cout << "You over shot by " << abs(relatDistance) << endl;
    }else if (relatDistance == 0){
      cout << "You hit him!!" << " It took you " << shots << " shots.";
      hitted = true;
    }
    cout << "objeto: " << objectPosition << endl;
  }while(hitted!=true);

  killed += killed;
  return killed;

}

void primerMsg(){
  cout << "Welcome to Artillery\n You are in the middle of a war and being charged by thousands of enemies.\n You have one cannon, which you can shoot at any angle.\n You only have 10 cannonballs for this target.." << endl;
  cout << "Let's begin..." << endl;
}

int main() {
  int randNum, done;

  primerMsg();

  srand (time(NULL));  /* initialize random seed: */
  objectPosition = rand() % 200 + 1;    /* generate secret number between 1 and 10: 
 this defines the distance of the enemy for each round.*/
  
  cout << "The enemy is " << objectPosition << " feet away!." << endl;

  killed = 0;
  do{

    killed = Fire();
    cout << "I see another one, care to shoot again? (y/n)." << endl;
    cin >> done;

  }while(done != 'n');

cout << "You killed " << killed << " of the enemy."<< endl;




  return 0;
}

