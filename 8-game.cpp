/*
Welcome to Artillery.
You are in the middle of a war and being charged by thousands of enemies.
You have one cannon, which you can shoot at any angle.
You only have 10 cannonballs for this target..
Let's begin...
*/

#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <math.h>
#include <iostream>
using namespace std;

double EnemyDistance;
double angleRad;
int cannonballsFlag;

double ObtainAngle()
{
    double angle;
    cout << "What angle(degrees)? ";
    cin >> angle;
    cin.ignore(100, '\n'); // Why do I need this line?

    /* error-ckecking here
    while (true)
    {
        if (cin.fail())
        {
            cout << "That was not an integer. Try again." << endl;
            cin.clear();
            cin.ignore();
        }
        else
            break;

        cout << "What angle(degrees)?  "; // prompt the user for input
        cin >> angle;
    }
    */
    return angle;
}

void instructions()
{
    cout << "Welcome to Artillery.\nYou are in the middle of a war and being charged by thousands of enemies.\nYou have one cannon, which you can shoot at any angle.\nYou only have 10 cannonballs for this target.\nLet's begin...\n" << endl;
}

void shootingLoop()
{
    int shots,hitted;
    double angle;
    double Velocity, Gravity, time_in_air, distance;

    hitted = 0;
    shots = 0;

    do{
        angle = ObtainAngle();     // angle in degrees
        cin.clear();
        angleRad = (angle / 180.0 ) * 3.14;
        
        // In case you are a little rusty on physics, here are the calculations:

        Velocity = 200.0; // initial velocity of 200 ft/sec
        Gravity = 32.2; // gravity for distance calculation

        // in_angle is the angle the player has entered, converted to radians.
        time_in_air = (2.0 * Velocity * sin(angleRad)) / Gravity;
        distance = round((Velocity * cos(angleRad)) * time_in_air);

        //cout << "The shooting distance is: " << distance << endl; 
        if(distance > EnemyDistance){
            cout << "You over shot by " << distance - EnemyDistance << " feets." << endl;
        }else if(distance < EnemyDistance){
            cout << "You under shot by " << EnemyDistance - distance << " feets." << endl;
        }else if(distance == EnemyDistance){
            cout << "Enemy down." << endl;
            cout << "It took you " << shots << " shots. " << endl;
            hitted = 1;
        }
        shots += 1;
        //cout << "you made " << shots << " shots. " << endl;
        if(shots > 9){
            cannonballsFlag = 1;
            break;
        }

    }while(hitted != 1);

}

double generateRandDistance(){
    double distance;
    int rndNumber;
    srand(time(NULL));         /* initiaclize random seed: */
    rndNumber = rand() % 600 + 300; /* generate secret number between 300 and 600. Distance in feet */
    distance = double(rndNumber);
    cout << "The enemy is " << distance << " feet away!!!\n";
    return distance;
}

// main
int main()
{
    int userNumber, killed;
    char done;

    instructions();
    killed = 0;
    cannonballsFlag = 0;
    do{
        EnemyDistance = generateRandDistance();
        shootingLoop();
        if (cannonballsFlag == 1){
            cout << "You are out of cannonballs!!" << endl;
            break;
        }
        killed += 1;
        cout << "I see another one, care to shoot again? (y/n) ";
        cin >> done;
        cin.ignore(100, '\n'); // Why do I need this line?
    } while (done != 'n');
    
    cout << "\nYou have killed " << killed << " enemies.\nEnd of the game." << endl;

return -1;
}