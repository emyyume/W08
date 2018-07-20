#include "class.h"

Face::Face() :_shape("Face") {}
Face::Face(const string &shape) : _shape(shape) {}
void Face::Show() const {
	cout << "Shape: " << this->_shape << endl;
}
FaceInterface* Face::Clone() const {
	return new Face(*this);
}


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


void TestFace(FaceInterface* face_interface) {
	FaceInterface* array_of_faces[3] = { face_interface, face_interface->Clone(), face_interface->Clone() };
	for (int i = 0; i < 3; ++i)
		array_of_faces[i]->Show();
	cout << "The same 3 lines?";
	for (auto &i : array_of_faces)
		delete i;
}