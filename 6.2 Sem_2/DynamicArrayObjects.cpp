#include "DynamicArrayObjects.h"
#include "Asteroid.h"
#include "Spaceship.h"
#include "Missle.h"
#include "Bonus.h"
#include <iostream>
#include <fstream>

DynamicArrayObjects :: DynamicArrayObjects()
{
	cnt = 0;
	curNumElements = 10; // Задаем начальное количество элементов равным 10
	array = new SpaceObject * [10]; // Выделяем память для массива с начальным размером 10
}
//template<typename T>
//DynamicArrayObjects :: DynamicArrayObjects(T object)
//{
//	array = new SpaceObject * [10];
//	this->array[cnt] = dynamic_cast<SpaceObject*>(new T(object));
//}
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