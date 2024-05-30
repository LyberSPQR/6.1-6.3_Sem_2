#include "SpaceObject.h"
#include "Spaceship.h"
#include <iostream>
using namespace std;

Spaceship::Spaceship()
{
    maxSpeed = 0;
    ammunition = 0;
}

void Spaceship::setMaxSpeed(int data)
{

    if (data < 0)
    {
        cout << "Incorrect value" << endl;
        return;
    }
    maxSpeed = data;
}

void Spaceship::outputMaxSpeed()
{
    cout << "maxSpeed: " << maxSpeed << endl;
}

void Spaceship::setAmmunition(int data)
{

    if (data < 0)
    {
        cout << "Incorrect value" << endl;
        return;
    }
    ammunition = data;
}
int Spaceship::getAmmunition()
{
    return ammunition;
}
int Spaceship::getMaxSpeed()
{
    return maxSpeed;
}


void Spaceship::outputAmmunition()
{
    cout << "Ammunition: " << ammunition << endl;
}

void Spaceship::outData()
{
	cout << endl;
	cout << "Spaceship: " << endl;
	outputCoordinates();
	outputSpeed();
	outputMaxSpeed();
	outputAmmunition();
	cout << endl;
}
string Spaceship::getClassName()
{
    return "Spaceship";
}
void Spaceship::writeFile(ostream& out)
{
    out << getSpeed()[0] << " " << getSpeed()[1] << " " << getSpeed()[2] << " ";
    out << getCoordinates()[0] << " " << getCoordinates()[1] << " " << getCoordinates()[2] << " ";
    out << maxSpeed << " ";
    out << ammunition << " ";
    out << '\n';
}
void Spaceship::readFile(istream& in)
{
    vector <int>tempArray{ 0,0,0 };
    in >> tempArray[0] >> tempArray[1] >> tempArray[2];
    setSpeedFile(tempArray);
    in >> tempArray[0] >> tempArray[1] >> tempArray[2];
    setCoordinatesFile(tempArray);
    in >> maxSpeed;
    in >> ammunition;
    /* out << '\n';*/
}