#pragma once

#include <vector>
#include <string>
using namespace std;
class SpaceObject
{
	vector<int> Coordinates;
	vector<int> Speed;

public:
	SpaceObject();
	vector<int> getCoordinates();
	vector<int> getSpeed();
	void setCoordinates(vector<int>& data);
	void setSpeed(vector<int> data);
	void outputSpeed();
	void outputCoordinates();
	virtual void outData();
	void setCoordinatesFile(vector<int>& vec);
	void setSpeedFile(vector<int>& vec);
	virtual string getClassName();
	virtual void writeFile(ostream& out);
	virtual void readFile(istream& in);

};
