#include "class.h"
/*
The main funciton can't run because the "Clone" method is virtual in "FaceInterface", when the "Face" inherits it,
inside the "Face" class we don't override this method, so the "Face" class will be an abstract class and we can't create
an object in this class, because it just an interface!!!
*/
int main() {
	Face face;
	Face face1("Rectangle");

	TestFace(&face1);

	_getwch();
	return 0;
}