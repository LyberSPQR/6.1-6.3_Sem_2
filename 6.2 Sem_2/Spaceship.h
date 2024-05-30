#pragma once
#include "SpaceObject.h"
class Spaceship : public  SpaceObject
{
	int maxSpeed;
	int ammunition;

public:

	Spaceship();

	void setMaxSpeed(int data);
	int getMaxSpeed();
	int getAmmunition();
	void outputMaxSpeed();
	void setAmmunition(int data);
	void outputAmmunition();
	void outData() override;
	string getClassName() override;
	void writeFile(ostream& out) override;
	void readFile(istream& in) override;
};