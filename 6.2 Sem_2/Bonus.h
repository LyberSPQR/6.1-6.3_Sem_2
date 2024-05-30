#pragma once
#include "SpaceObject.h"

class Bonus : public  SpaceObject
{
	int cntAmmunition;
	int existingTime;
public:

	Bonus();

	void setCntAmmunition(int data);
	int getCntAmmunition();
	void outputCntAmmunition();
	void setExistingTime(int data);
	int getExistingTime();
	void outputExistingTime();
	void outData() override;
	string getClassName() override;
	void writeFile(ostream& out) override;
	void readFile(istream& in) override;

};
