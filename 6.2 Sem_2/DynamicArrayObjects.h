#pragma once
#include "SpaceObject.h"
class DynamicArrayObjects
{
	SpaceObject** array;
	int cnt = 0;
	int curNumElements = 0;
public:
	DynamicArrayObjects();

	//template<typename T>
	//DynamicArrayObjects(T object);

	//SpaceObject** getArray()
	//{
	//	return this->array;
	//}

	void readFile();
	void writeFile();

	template<typename T>
	void addObject(T object);		// 1
	void deleteObject(int index);	// 2
	void createArray();				// 3
	void deleteArray();				// 4
	void outArray();				// 5

};