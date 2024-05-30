#pragma once
#include "SpaceObject.h"
using namespace std;
class Asteroid : public  SpaceObject
{
	int maxSize;

public:

	Asteroid();

	void setMaxSize(int data);
	int getMaxSize();
	void outputMaxSize();
	void outputAsteroidData();
	void outData() override;
	string getClassName() override;
	void writeFile(ostream& out) override;
	void readFile(istream& in) override;
};