#include "SpaceObject.h"
#include "Bonus.h"
#include <iostream>
using namespace std;

Bonus::Bonus()
{
	cntAmmunition = 0;
	existingTime = 0;
}
Bonus::~Bonus()
{}
void Bonus::setCntAmmunition(int data)
{
	cout << "Enter cntAmmunition" << endl;

	if (data < 0)
	{
		cout << "Incorrect value" << endl;
		return;
	}
	cntAmmunition = data;
}
int Bonus::getCntAmmunition()
{
	return cntAmmunition;
}
void Bonus::outputCntAmmunition()
{
	cout << "cntAmmunition : " << cntAmmunition << endl;
}
void Bonus::setExistingTime(int data)
{
	if (data < 0)
	{
		cout << "Incorrect value" << endl;
		return;
	}
	existingTime = data;
}
int Bonus::getExistingTime()
{
	return existingTime;
}
void Bonus::outputExistingTime()
{
	cout << "existingTime: " << existingTime << endl;
}
void Bonus::outData()
{
	cout << endl;
	cout << "Bonus: " << endl;
	outputCoordinates();
	outputSpeed();
	outputCntAmmunition();
	outputExistingTime();
	cout << endl;
}
string Bonus::getClassName()
{
	return "Bonus";
}
void Bonus::writeFile(ostream& out)
{
	out << getSpeed()[0] << " " << getSpeed()[1] << " " << getSpeed()[2] << " ";
	out << getCoordinates()[0] << " " << getCoordinates()[1] << " " << getCoordinates()[2] << " ";
	out << cntAmmunition << " ";
	out << existingTime << " ";
	out << '\n';
}
void Bonus::readFile(istream& in)
{
	vector <int>tempArray{ 0 ,0 ,0 };
	in >> tempArray[0] >> tempArray[1] >> tempArray[2];
	setSpeedFile(tempArray);
	in >> tempArray[0] >> tempArray[1] >> tempArray[2];
	setCoordinatesFile(tempArray);
	in >> cntAmmunition;
	in >> existingTime;
	/* out << '\n';*/
}
