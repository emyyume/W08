#include "service.h"

int main() {
	Service service;

	service.Registration();
	service.NoticeOfPayment();

	_getwch();
	return 0;
}