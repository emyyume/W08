#pragma once
#include <iostream>
#include <string>
using namespace std;

class FaceInterface {
public:
	FaceInterface() = default;
	virtual void Show() const = 0;
	virtual FaceInterface* Clone() const = 0;
	virtual ~FaceInterface() = default;
};

class Face :public FaceInterface {
public:
	Face();
	Face(const string &shape);
	FaceInterface* Clone() const;
	virtual void Show() const;
protected:
	string _shape;
};

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

void TestFace(FaceInterface* face_interface);