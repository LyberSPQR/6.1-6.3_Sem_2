#include "SpaceObject.h"
#include "Missle.h"
#include <iostream>
using namespace std;

Missle::Missle()
{
    explosivePower = 0;
    fuelTime = 0;
}

void Missle::setExplosivePower(int data)
{
    if (data < 0)
    {
        cout << "Incorrect value" << endl;
        return;
    }
    explosivePower = data;
}

void Missle::outputExplosivePower()
{
    cout << "explosivePower: " << explosivePower << endl;
}

void Missle::setFuelTime(int data)
{

    if (data < 0)
    {
        cout << "Incorrect value" << endl;
        return;
    }
    fuelTime = data;
}
int Missle::getFuelTime()
{
    return fuelTime;
}
int Missle::getExplosivePower()
{
    return explosivePower;
}
void Missle::outputFuelTime()
{
    cout << "fuelTime: " << fuelTime << endl;
}

void Missle::outData()
{
	cout << endl;
	cout << "Missle: " << endl;
	outputCoordinates();
	outputSpeed();
	outputExplosivePower();
	outputFuelTime();
	cout << endl;
}
string Missle::getClassName()
{
    return "Missle";
}
void Missle::writeFile(ostream& out)
{
    out << getSpeed()[0] << " " << getSpeed()[1] << " " << getSpeed()[2] << " ";
    out << getCoordinates()[0] << " " << getCoordinates()[1] << " " << getCoordinates()[2] << " ";
    out << explosivePower << " ";
    out << fuelTime << " ";
    out << '\n';
}
void Missle::readFile(istream& in)
{
    vector <int>tempArray{ 0 ,0 ,0 };
    in >> tempArray[0] >> tempArray[1] >> tempArray[2];
    setSpeedFile(tempArray);
    in >> tempArray[0] >> tempArray[1] >> tempArray[2];
    setCoordinatesFile(tempArray);
    in >> explosivePower;
    in >> fuelTime;
    /* out << '\n';*/
}