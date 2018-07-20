#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class Bike {
public:
	Bike();
	Bike(const char* brand);
	~Bike();
	virtual void Move(const int &number);
private:
	char* _brand;
};

class EBike :public Bike {
public:
	EBike();
	void Move(const int &number);
};

void Display(Bike &bike, EBike &ebike);