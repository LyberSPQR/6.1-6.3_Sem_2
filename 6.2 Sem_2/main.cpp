// 6.2 Sem_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "SpaceObject.h"
#include "Asteroid.h"
#include "Spaceship.h"
#include "Missle.h"
#include "Bonus.h"
using namespace std;

class DynamicArrayObjects
{
	SpaceObject** array;
	int cnt = 0;
	int curNumElements = 0;
public:

	DynamicArrayObjects();

	template<typename T>
	DynamicArrayObjects(T object);

	SpaceObject** getArray()
	{
		return this->array;
	}
	void readFile();
	void writeFile();

	template<typename T>
	void addObject(T object);

	void deleteObject(int index);
	void createArray();
	void deleteArray();
	void outArray();

};

int main()
{
	Asteroid aster;
	Spaceship ship;
	Missle missl;
	Bonus bonu;

////	Asteroid
//	vector<int> dataAster = { 1,1,1 };
//	aster.setCoordinates(dataAster);
//	aster.setSpeed(dataAster);
//	aster.setMaxSize(1);
//	aster.outData();
//
////  Spaceship
//	vector<int> dataSpaceship = { 2,2,2 };
//	ship.setCoordinates(dataSpaceship);
//	ship.setSpeed(dataSpaceship);
//	ship.setMaxSpeed(2);
//	ship.setAmmunition(2);
//	ship.outData();
//
//
//
//	//  Missle
//	vector<int> dataMissle = { 3,3,3 };
//	missl.setCoordinates(dataMissle);
//	missl.setSpeed(dataMissle);
//	missl.setExplosivePower(3);
//	missl.setFuelTime(3);
//	missl.outData();

	//  Bonus
	// vector<int> dataBonus = { 4,4,4 };
	//bonu.setCoordinates(dataBonus);
	//bonu.setSpeed(dataBonus);
	//bonu.setCntAmmunition(3);
	//bonu.setExistingTime(3);
	//bonu.outData();

	DynamicArrayObjects arr;
	
	arr.createArray();

/*	arr.readFile();	*/			// 6.3
	arr.addObject(aster);
	arr.addObject(ship);
	arr.addObject(missl);
	arr.addObject(bonu);
	//arr.deleteObject(3);
	//arr.outArray();
	arr.writeFile();			// 6.3
	
	arr.outArray();


	return 0;

}




DynamicArrayObjects::DynamicArrayObjects()
{
	cnt = 0;
	curNumElements = 0; // Задаем начальное количество элементов равным 10
//	array = new SpaceObject * [10]; // Выделяем память для массива с начальным размером 10
}
template<typename T>
DynamicArrayObjects :: DynamicArrayObjects(T object)
{
	array = new SpaceObject * [10];
	this->array[cnt] = dynamic_cast<SpaceObject*>(new T(object));
}
void DynamicArrayObjects::readFile()
{
	ifstream inputFile("data.txt");

	if (!inputFile.is_open())
	{
		cout << "Не удалось открыть файл." << endl;
	}

	int temp;
	inputFile >> temp;
	this->curNumElements = temp;

	for (int i = 0; i < curNumElements; i++)
	{

		string tempClassName;
		inputFile >> tempClassName;

		if (tempClassName == "Asteroid")
		{
			Asteroid astero;
			astero.readFile(inputFile);
			this->array[cnt] = dynamic_cast<SpaceObject*>(new Asteroid(astero));
			this->cnt++;
		}
		else if (tempClassName == "Missle")
		{
			Missle miss;
			miss.readFile(inputFile);
			this->array[cnt] = dynamic_cast<SpaceObject*>(new Missle(miss));
			this->cnt++;
		}
		else if (tempClassName == "Spaceship")
		{
			Spaceship spacesh;
			spacesh.readFile(inputFile);
			this->array[cnt] = dynamic_cast<SpaceObject*>(new Spaceship(spacesh));
			this->cnt++;
		}
		else if (tempClassName == "Bonus")
		{
			Bonus bon;
			bon.readFile(inputFile);
			this->array[cnt] = dynamic_cast<SpaceObject*>(new Bonus(bon));
			this->cnt++;
		}
		else
			break;
	}
}
void DynamicArrayObjects::writeFile()
{
	ofstream outputFile("data.txt");
	//if (outputFile.good())
	//{
	//	cout << "File already exist";
	//	return;
	//}
	if (!outputFile.is_open())
	{
		cout << "Не удалось открыть файл." << endl;
	}
	outputFile << this->curNumElements << '\n';
	for (int i = 0; i < curNumElements; i++)
	{

		string tempClassName;
		tempClassName = array[i]->getClassName();

		if (tempClassName == "Asteroid")
		{
			outputFile << tempClassName << " ";
			array[i]->writeFile(outputFile);

		}
		else if (tempClassName == "Missle")
		{
			outputFile << tempClassName << " ";
			array[i]->writeFile(outputFile);
		}
		else if (tempClassName == "Spaceship")
		{
			outputFile << tempClassName << " ";
			array[i]->writeFile(outputFile);
		}

		else if (tempClassName == "Bonus")
		{
			outputFile << tempClassName << " ";
			array[i]->writeFile(outputFile);
		}
		else
			break;
	}
}
void DynamicArrayObjects::deleteObject(int index)
{
	this->array[index] = this->array[curNumElements - 1];
	this->array[curNumElements - 1] = nullptr;
	this->curNumElements--;
}
void DynamicArrayObjects::deleteArray()
{
	delete[] this->array;
}
void DynamicArrayObjects::outArray()
{
	bool flag = 0;
	cout << "outArray" << endl;
	for (int i = 0; i < curNumElements; i++)
	{

		cout << "INDEX: " << i << endl;
		this->array[i]->outData();
	}
}
void DynamicArrayObjects::createArray()
{
	this->array = new SpaceObject * [10];
}
template<typename T>
void DynamicArrayObjects::addObject(T object)
{
	cout << "addObject" << endl;
	this->array[cnt] = dynamic_cast<SpaceObject*>(new T(object));
	this->cnt++;
	this->curNumElements++;
}