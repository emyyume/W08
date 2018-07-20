# Assignment 2
***ID:*** 1753071
**Fullname:** Huong Dat Minh
---
### a)
```cpp
class EyedFace :public Face {
public:
	EyedFace();
	EyedFace(const string &shape, const int &eyes);
	~EyedFace();
	void Show() const;
	FaceInterface* Clone() const;
private:
	string _shape;
	int _eyes;
};

EyedFace::EyedFace() :Face("EyedFace"), _eyes(2) {}
EyedFace::EyedFace(const string &shape, const int &eyes) :Face(shape), _eyes(eyes) {}
EyedFace::~EyedFace() {}
void EyedFace::Show() const {
	Face::Show();
	cout << "Eyes: " << this->_eyes << endl;
}
FaceInterface* EyedFace::Clone() const {
	return new EyedFace(*this);
}
```

### b)

The main funciton can't run because the `Clone` method is **virtual** in **FaceInterface**, when the **Face** inherits it, inside the **Face** class we don't override this method, so the **Face** class will be an abstract class and we can't create an object in this class, because it just an interface!!!

The result is:
```
Shape: Rectangle
Shape: Rectangle
Shape: Rectangle
The same 3 lines?
```

### c)
```cpp
void TestFace(FaceInterface* face_interface) {
	//...
	for (auto &i : array_of_faces)
		delete i;
}
```
We have to de-allocate 3 pointer in the array.