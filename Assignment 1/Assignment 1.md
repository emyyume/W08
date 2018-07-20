# Assignment 1

**ID:** 1753071
**Fullname:** Huong Dat Minh
---
### a) Hãy cài đặt bổ sung các phương thức cần thiết để giải quyết các vấn đề về thuộc tính con trỏ cho lớp đối tượng Bike.

```cpp
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

int main() {
	EBike ebike1, ebike2;
	Display(ebike1, ebike2);
	return 0;
}
```

### b) Cho biết kết quả xuất ra màn hình của chương trình trên (sau khi đã bổ sung code đầy đủ ở câu (**a)**). Giải thích ngắn gọn.

**Result is `EBike: 48 EBike: 48`**
**We need to pay attention to the 3 functions below:**

```cpp
virtual void Move(const int &number); //1
void Bike::Move(const int &number) {
	cout << this->_brand << ": " << number * 12 << ' ';
}

void Move(const int &number); //2
void EBike::Move(const int &number) {
	Bike::Move(number * 2);
}

void Display(Bike &bike, EBike &ebike) { //3
	bike.Move(2), ebike.Move(2);
}
```

First, 2 parameters of the `Display(Bike &bike, EBike &ebike)` function are 2 entities representing 2 different objects, in this case, the `EBike` class inherits from the `Bike` class.
So when the program executes, 2 **EBike** objects are **passed by reference** to the `Display` function. Then, the first parameter is a reference to the base class object, and the object being passed at this time belongs to the inheritance class, but since it is referencing, this **ebike1** is still an **EBike** object, so it can call the `Move` method of the `EBike` class.

### c) Nêu sự khác biệt giữa lớp đối tượng (class) và đối tượng cụ thể (object, instance). Liệt kê các lớp đối tượng và các đối tượng cụ thể trong đoạn mã nguồn trên.

**Class:** are an expanded concept of data structures: like data structures, they can contain data members, but they can also contain functions as members.

**Object:**  is an instantiation of a class. In terms of variables, a class would be the type, and an object would be the variable.

In the example above, I have 2 classes, which are `Bike` and `EBike` and 2 objects which are `ebike1` and `ebike2`.