#include "SpaceObject.h"
#include <iostream>
#include <vector>
using namespace std;

SpaceObject::SpaceObject()
{
    cout << "Base initialization" << endl;
    for (int i = 0; i < 3; i++)
    {
        Coordinates.push_back(0);
        Speed.push_back(0);
    }
}

vector<int> SpaceObject::getCoordinates()
{
    return this->Coordinates;
}

vector<int> SpaceObject::getSpeed()
{
    return this->Speed;
}

void SpaceObject::setCoordinates(vector<int> data)
{

    for (int i = 0; i < 3; i++)
    {
        Coordinates[i] = data[i];
    }
}

void SpaceObject::setSpeed(vector<int> data)
{
    for (int i = 0; i < 3; i++)
    {
        Speed[i] = data[i];
    }
}

void SpaceObject::outputSpeed()
{
    cout << "Speed V(x), V(y), V(z)" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << Speed[i] << "  ";
    }
    cout << endl;
}

void SpaceObject::setCoordinatesFile(vector<int>& vec)
{
    for (int i = 0; i < 3; i++)
    {
        Coordinates[i] = vec[i];
    }
}
void SpaceObject::setSpeedFile(vector<int>& vec)
{
    for (int i = 0; i < 3; i++)
    {
        Speed[i] = vec[i];
    }
}
void SpaceObject::outputCoordinates()
{
    cout << "Coordinates (X, Y, Z)" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << Coordinates[i] << "  ";
    }
    cout << endl;
}
 void  SpaceObject::outData()
{
	cout << "why you see that?" << endl;
}
 string SpaceObject::getClassName()
 {
     cout << "Why you see that 2?" << endl;
     return "Error";
 }
 void SpaceObject::writeFile(ostream& out)
 {
     cout << "Why you see that 3?" << endl;
 }
 void SpaceObject::readFile(istream& in)
 {
     cout << "Why you see that 4?" << endl;
 }
