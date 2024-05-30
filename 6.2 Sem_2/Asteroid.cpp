#include "SpaceObject.h"
#include "Asteroid.h"
#include <iostream>
using namespace std;
Asteroid::Asteroid()
{
	maxSize = 0;
}

void Asteroid::setMaxSize(int data)
{
	if (data < 0)
	{
		cout << "Incorrect value" << endl;
		return;
	}
	maxSize = data;


}
int Asteroid::getMaxSize()
{
	return maxSize;
}
void Asteroid::outputMaxSize()
{
	cout << "maxSize: " << maxSize << endl;
}
void Asteroid::outputAsteroidData()
{
	cout << endl;
	cout << "Asteroid: " << endl;
	outputCoordinates();
	outputSpeed();
	outputMaxSize();
	cout << endl;
}
void Asteroid::outData()
{
	cout << endl;
	cout << "Asteroid: " << endl;
	outputCoordinates();
	outputSpeed();
	outputMaxSize();
	cout << endl;
}
string Asteroid::getClassName()
{
	return "Asteroid";
}
void Asteroid::writeFile(ostream& out)
{
	out << getSpeed()[0] << " " << getSpeed()[1] << " " << getSpeed()[2] << " ";
	out << getCoordinates()[0] << " " << getCoordinates()[1] << " " << getCoordinates()[2] << " ";
	out << maxSize << " ";
	out << '\n';
}
void Asteroid::readFile(istream& in)
{
	vector <int>tempArray{ 0 ,0 ,0 };
	in >> tempArray[0] >> tempArray[1] >> tempArray[2];
	setSpeedFile(tempArray);
	in >> tempArray[0] >> tempArray[1] >> tempArray[2];
	setCoordinatesFile(tempArray);
	in >> maxSize;
	/* out << '\n';*/
}