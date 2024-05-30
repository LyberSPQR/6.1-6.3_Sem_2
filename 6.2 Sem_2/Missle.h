#pragma once
#include "SpaceObject.h"
class Missle : public  SpaceObject
{
	int explosivePower;
	int fuelTime;
public:

	Missle();

	void setExplosivePower(int data);
	void outputExplosivePower();
	void setFuelTime(int data);
	int getExplosivePower();
	int getFuelTime();
	void outputFuelTime();
	void outData() override;
	string getClassName() override;
	void writeFile(ostream& out) override;
	void readFile(istream& in) override;
};