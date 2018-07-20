#include "class.h"

Bike::Bike() :_brand(new char[5]) {
	strcpy(this->_brand, "Bike");
}
Bike::Bike(const char* brand) {
	this->_brand = new char[strlen(brand) + 1];
	strcpy(this->_brand, brand);
}
Bike::~Bike() {
	delete[] this->_brand;
}
void Bike::Move(const int &number) {
	cout << this->_brand << ": " << number * 12 << ' ';
}

EBike::EBike() :Bike("EBike") {}
void EBike::Move(const int &number) {
	Bike::Move(number * 2);
}

void Display(Bike &bike, EBike &ebike) {
	bike.Move(2), ebike.Move(2);
}